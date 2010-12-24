// YateComServer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <yatecbase.h>
#include <atlcom.h>
#include "YATE_i.h"
#include "resource.h"
#include <string>
#include "Utility.h"

// Fix for ATL exe module from http://msmvps.com/blogs/vandooren/archive/2009/04/15/solving-the-race-condition-in-catlexemodulet.aspx
template <typename T>
class CAtlExeModuleT_NoRace : public CAtlExeModuleT<T>
{
public:
	typedef CAtlExeModuleT<T> base;
#if _ATL_VER < 0x0A00
	LONG Lock(void) { CoAddRefServerProcess(); return base::Lock(); }
	LONG Unlock(void) { CoReleaseServerProcess(); return base::Unlock(); }
#endif
};

class CMyAtlModule : public CAtlExeModuleT< CMyAtlModule > {
public:
	DECLARE_LIBID(LIBID_YateComServerLib)
	// Not sure if we need it http://blogs.msdn.com/b/larryosterman/archive/2006/01/04/509436.aspx
	//DECLARE_REGISTRY_APPID_RESOURCEID(IDR_YATECOMSERVER, "{57B10F25-5D27-46d0-BD9A-C7868F8D12A0}")
	static LPCOLESTR GetAppId() throw()
	{
		return OLESTR("{57B10F25-5D27-46d0-BD9A-C7868F8D12A0}");
	}
	static TCHAR* GetAppIdT() throw()
	{
		return _T("{57B10F25-5D27-46d0-BD9A-C7868F8D12A0}");
	}
	static HRESULT WINAPI UpdateRegistryAppId(BOOL bRegister) throw()
	{
		ATL::_ATL_REGMAP_ENTRY aMapEntries [] =
		{
			{ OLESTR("APPID"), GetAppId() },
			{ NULL, NULL }
		};
		return UpdateRegistryFromResourceEx(GetCurrentModule(), IDR_YATECOMSERVER, bRegister, aMapEntries);
	}
public:
	void Terminate()
	{
		::PostThreadMessage(m_dwMainThreadID, WM_QUIT, 0, 0);
	}
};

CMyAtlModule _AtlModule;
static bool s_embedding = false;

// A thread which runs windows message loop
class CAtlMainThread:public TelEngine::Thread
{
public:
	void run()
	{
		_AtlComModule.m_hInstTypeLib = GetCurrentModule();
		_AtlBaseModule.m_hInst = ::GetModuleHandle(NULL);
		TelEngine::Output("comserver: entering message loop, thread: %X", ::GetCurrentThreadId());
		_AtlModule.Run();
		//_AtlModule.WinMain(TRUE);
		TelEngine::Output("comserver: leaved message loop");
		if(s_embedding)
			TelEngine::Engine::halt(0);
	}
};

class ComServerModule : public TelEngine::Module
{
public:
	ComServerModule()
		: TelEngine::Module("comserver", "misc"), m_init(false), m_pMsgLoopThread(0)
	{
	}
	virtual void initialize();
	virtual bool received(TelEngine::Message &msg,int id);
	HRESULT RegisterCOMServer(bool reg, bool peruser = false);
protected:
	virtual bool commandExecute(TelEngine::String& retVal, const TelEngine::String& line);
	virtual bool commandComplete(TelEngine::Message& msg, const TelEngine::String& partLine, const TelEngine::String& partWord);
private:
	enum
	{
		CallRoute = Private + 1
	} PrivateRelayID;

	bool m_init;
	CAtlMainThread* m_pMsgLoopThread;
};

INIT_PLUGIN(ComServerModule);

void ComServerModule::initialize()
{
	HRESULT hr;
	//hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	//_AtlModule.InitializeCom();
	//hr = _AtlModule.Init(NULL, ::GetModuleHandle(NULL));
	TelEngine::Output("Initializing module ComServer");
	TelEngine::Output("comserver: thread: %X", ::GetCurrentThreadId());
	if(!m_init) {
		Module::setup(); // enable command completion etc.
		m_pMsgLoopThread = new CAtlMainThread();
		installRelay(Halt);
		installRelay(Execute);
		installRelay(Help);
		//TelEngine::Engine::install(new TelEngine::MessageRelay("call.route",this,CallRoute,55));
		m_pMsgLoopThread->startup();
		m_init = true;
	}
}

bool ComServerModule::received(TelEngine::Message &msg, int id)
{
//	if(id != Timer)
//		TelEngine::Output("comserver: received %s (%d)", msg.c_str(), id);

	static const char* s_cmdsLine = "comserver {register|unregister)";

	switch(id) {
	case Help:
		{
			TelEngine::String line = msg.getValue("line");
			if (line.null()) {
				msg.retValue() << "  " << s_cmdsLine << "\r\n";
				return false;
			}
			if (line != name())
				return false;
			msg.retValue() << "Commands used to control the COM Server module\r\n";
			msg.retValue() << s_cmdsLine << "\r\n";
			return true;
		}
	case Halt:
		_AtlModule.Terminate();
		return false;
	case Status:
		{
			TelEngine::String target = msg.getValue("module");
			if (!target || target == name()) {
				msg.retValue() << "name=" << name() << ",type=" << type();
				unsigned int count = _AtlModule.GetLockCount();
				msg.retValue() << ";count=" << count << "\r\n";
				return true;
			}
		}
		return Module::received(msg, id);
	default:
		return TelEngine::Module::received(msg, id);
	}
	return false;
}
HRESULT ComServerModule::RegisterCOMServer(bool reg, bool peruser)
{
	HRESULT hr;
	if(peruser) {
		hr = AtlSetPerUserRegistration(true);
		if(FAILED(hr))
			return hr;
	}

	if(reg) {
		hr = _AtlModule.RegisterServer(TRUE);
		if(SUCCEEDED(hr))
			hr = _AtlModule.RegisterAppId();
	} else {
		hr = _AtlModule.UnregisterServer(TRUE);
		if(SUCCEEDED(hr))
			hr = _AtlModule.UnregisterAppId();
	}
	return hr;
}

bool ComServerModule::commandExecute(TelEngine::String& retVal, const TelEngine::String& line)
{
	TelEngine::String l = line;
	if(line == "-Embedding") { // XXX May be use _AtlModule.ParseCommandLine ?
		s_embedding = true;
		return true;
	} else if(line == "/RegServer") {
		RegisterCOMServer(true, false);
		return true;
	} else if(line == "/UnregServer") {
		RegisterCOMServer(false, false);
		return true;
	}

	if(! l.startSkip(name()))
		return false;
	l.trimSpaces();
	bool starts_with_UN = l.startSkip("un", false);
	if(l.startSkip("register")) {
		HRESULT hr = RegisterCOMServer(!starts_with_UN, false);
		if(SUCCEEDED(hr)) {
			retVal << "OK\r\n";
		} else {
			retVal << "Error: " << DecodeHresult(hr).c_str() << "\r\n";
		}
		return true;
	}
	return false;
}
bool ComServerModule::commandComplete(TelEngine::Message& msg, const TelEngine::String& partLine, const TelEngine::String& partWord)
{
	// Commands handled by this module
	static const char* s_cmds[] = {
		"register",    // Register COM server
		"unregister",  // Unregister COM server
		0
	};

	if (partLine.null() && partWord.null())
		return false;
	if (partLine.null() || (partLine == "help"))
		Module::itemComplete(msg.retValue(), name(), partWord);
	else if (partLine == name()) {
		for (const char** list = s_cmds; *list; list++)
			Module::itemComplete(msg.retValue(), *list, partWord);
		return true;
	}

#if 0
	bool status = partLine.startsWith("status");
	if (!status)
		return Module::commandComplete(msg, partLine, partWord);
#endif

	return Module::commandComplete(msg, partLine, partWord);
}




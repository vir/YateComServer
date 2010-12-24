// YateEngine.cpp : Implementation of CYateEngine

#include "stdafx.h"
#include "YateEngine.h"


//
// Usage: SetThreadName (-1, "MainThread");
//
typedef struct tagTHREADNAME_INFO
{
	DWORD dwType; // must be 0x1000
	LPCSTR szName; // pointer to name (in user addr space)
	DWORD dwThreadID; // thread ID (-1=caller thread)
	DWORD dwFlags; // reserved for future use, must be zero
} THREADNAME_INFO;

void SetThreadName( DWORD dwThreadID, LPCSTR szThreadName)
{
	THREADNAME_INFO info;
	info.dwType = 0x1000;
	info.szName = szThreadName;
	info.dwThreadID = dwThreadID;
	info.dwFlags = 0;

	__try
	{
		RaiseException( 0x406D1388, 0, sizeof(info)/sizeof(DWORD), (DWORD*)&info );
	}
	__except(EXCEPTION_CONTINUE_EXECUTION)
	{
	}
}


using namespace TelEngine;

// CYateEngine
STDMETHODIMP CYateEngine::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = { &IID_IYateEngine };
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CYateEngine::FinalConstruct()
{
	//ATLTRACE("Creating YATE engine\n");
	return S_OK;
}

void CYateEngine::FinalRelease()
{
	ATLTRACE("Destroying YATE Engine\n");
}

STDMETHODIMP CYateEngine::Dispatch(IYateMessage** ppMessage, VARIANT_BOOL* pHandled)
{
	if(!ppMessage || !pHandled)
		return E_POINTER;
	CComQIPtr<IYateOrigPointer> msg(*ppMessage);
	if(!msg)
		return Error(_T("IYateOrigPointer interface is not supported by passed Message object"), IID_IYateEngine, E_NOINTERFACE);
	TelEngine::Message * m;
	if(FAILED(msg->get_OrigPtr((void**)&m)) || !m)
		return E_UNEXPECTED;
	bool handled = TelEngine::Engine::dispatch(m);
	*pHandled = handled ? VARIANT_TRUE : VARIANT_FALSE;
	return handled ? S_OK : S_FALSE;
}

STDMETHODIMP CYateEngine::Enqueue(IYateMessage* pMessage)
{
	CComQIPtr<IYateOrigPointer> msg(pMessage);
	if(!msg)
		return Error(_T("IYateOrigPointer interface is not supported by passed Message object"), IID_IYateEngine, E_NOINTERFACE);
	TelEngine::Message * m;
	if(FAILED(msg->get_OrigPtr((void**)&m)) || !m)
		return E_UNEXPECTED;
	if(! TelEngine::Engine::enqueue(m))
		return Error(_T("Message is already queued"), IID_IYateEngine, E_FAIL);
	msg->put_OrigPtr(NULL);
	return S_OK;
}

STDMETHODIMP CYateEngine::InstallMessageRelay(BSTR Name, LONG Priority, LONG IdNum)
{
	std::string name(UTF16toUTF8(Name));
	std::map<std::string, TelEngine::MessageRelay*>::iterator it = m_relay_map.find(name);
	if(it != m_relay_map.end()) {
		Engine::uninstall(it->second);
		delete it->second;
	}
	MessageRelay* relay = new MessageRelay(name.c_str(), this, IdNum, Priority);
	it = m_relay_map.insert(std::make_pair(name, relay)).first;
	bool ok = Engine::install(relay);
	return ok ? S_OK : E_FAIL;
}

STDMETHODIMP CYateEngine::UninstallMessageRelay(BSTR Name)
{
	std::string name(UTF16toUTF8(Name));
	std::map<std::string, TelEngine::MessageRelay*>::iterator it = m_relay_map.find(name);
	if(it == m_relay_map.end())
		return Error(_T("Message relay not found"), IID_IYateEngine, E_FAIL);
	MessageHandler* handler = it->second;
	Engine::uninstall(handler);
	m_relay_map.erase(it);
	delete handler;
	return S_OK;
}

bool CYateEngine::received(TelEngine::Message& m, int IdNum)
{
	VARIANT_BOOL handled = VARIANT_FALSE;
	Message* p = &m;
	CComPtr<IYateMessage> msg;
	if(FAILED(msg.CoCreateInstance(CLSID_YateMessage)))
		return false;
	CComQIPtr<IYateOrigPointer> xmsg(msg);
	if(!xmsg)
		return false;
	xmsg->put_OrigPtr(p);
	xmsg->put_DeleteOrigObject(FALSE);
	HRESULT hr;
//	hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
//	ATLASSERT(SUCCEEDED(hr));
	hr = Fire_OnMessage(msg, &handled);
//	::CoUninitialize();
	return SUCCEEDED(hr) && handled == VARIANT_TRUE;
}


// YateEngine.h : Declaration of the CYateEngine

#pragma once
#include "resource.h"       // main symbols

#include "YATE_i.h"
#include "ATLCPImplMT.h"
// Firing events across apartments: http://support.microsoft.com/kb/280512
#include "_IYateEngineEvents_CP.h"

#include "yatengine.h" // that is YATE header, not this file!
#include <string>
#include <map>
#include "Utility.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CYateEngine

class ATL_NO_VTABLE CYateEngine :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CYateEngine, &CLSID_YateEngine>,
	public IConnectionPointContainerImpl<CYateEngine>,
	public IDispatchImpl<IYateEngine, &IID_IYateEngine, &LIBID_YateComServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISupportErrorInfo,
	public TelEngine::MessageReceiver,
	public CProxy_IYateEngineEvents<CYateEngine>,
	public IProvideClassInfo2Impl<&CLSID_YateEngine, &__uuidof(_IYateEngineEvents), &LIBID_YateComServerLib, 1, 0>
{
public:
	DECLARE_CLASSFACTORY();
	CYateEngine()
	{
	}
//DECLARE_CLASSFACTORY_SINGLETON(CYateEngine)
//DECLARE_REGISTRY_RESOURCEID(IDR_YATEENGINE)
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) throw()
	{
		return UpdateRegistryFromResourceEx(GetCurrentModule(), IDR_YATEENGINE, bRegister);
	}

BEGIN_COM_MAP(CYateEngine)
	COM_INTERFACE_ENTRY(IYateEngine)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CYateEngine)
	CONNECTION_POINT_ENTRY(__uuidof(_IYateEngineEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct();
	void FinalRelease();

	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
private:
	std::map<std::string, TelEngine::MessageRelay*> m_relay_map;
	// TelEngine::MessageReceiver
	bool received(TelEngine::Message& m, int IdNum);
public:

	STDMETHOD(Dispatch)(IYateMessage** ppMessage, VARIANT_BOOL* pHandled);
	STDMETHOD(Enqueue)(IYateMessage* pMessage);
	STDMETHOD(InstallMessageRelay)(BSTR Name, LONG Priority, LONG IdNum);
	STDMETHOD(UninstallMessageRelay)(BSTR Name);
};

OBJECT_ENTRY_AUTO(__uuidof(YateEngine), CYateEngine)

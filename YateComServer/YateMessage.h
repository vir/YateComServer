// YateMessage.h : Declaration of the CYateMessage

#pragma once
#include "resource.h"       // main symbols

#include "YATE_i.h"
#include <atlcom.h>
#include "Utility.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

// preleclare classes
namespace TelEngine {
	class Message;
}

// CYateMessage

class ATL_NO_VTABLE CYateMessage :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CYateMessage, &CLSID_YateMessage>,
//	public IDispatchImpl<IYateMessage, &IID_IYateMessage, &LIBID_ClientCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<IYateMessage, &IID_IYateMessage, &LIBID_YateComServerLib, /* wMajor = */ 1, /* wMinor = */ 0>,
	public IDispatchImpl<IYateNamedList, &IID_IYateNamedList, &LIBID_YateComServerLib, /* wMajor = */ 1, /* wMinor = */ 0>,
	public IYateOrigPointer
{
public:
	DECLARE_CLASSFACTORY();
	CYateMessage()
		: m_origmsg(0)
		, m_delete_msg(FALSE)
	{
		m_pUnkMarshaler = NULL;
	}

//	DECLARE_REGISTRY_RESOURCEID(IDR_YATEMESSAGE)
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) throw()
	{
		return UpdateRegistryFromResourceEx(GetCurrentModule(), IDR_YATEMESSAGE, bRegister);
	}


	BEGIN_COM_MAP(CYateMessage)
		COM_INTERFACE_ENTRY(IYateMessage)
		COM_INTERFACE_ENTRY2(IYateNamedList, IYateMessage)
		COM_INTERFACE_ENTRY(IYateOrigPointer)
		COM_INTERFACE_ENTRY2(IDispatch, IYateMessage)
		COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct();
	void FinalRelease();

	CComPtr<IUnknown> m_pUnkMarshaler;

private:
	CComAutoCriticalSection m_mutex;
	typedef CComCritSecLock<CComAutoCriticalSection> Locker;
	TelEngine::Message* m_origmsg;
	BOOL m_delete_msg;
	void check_create();

	// IYateMessage Methods
public:
	STDMETHOD(get_RetValue)(BSTR * pVal);
	STDMETHOD(put_RetValue)(BSTR newVal);

	// IYateNamedList Methods
public:
	STDMETHOD(get_Name)( BSTR * pVal);
	STDMETHOD(put_Name)( BSTR newVal);
	STDMETHOD(get_ParamsCount)( ULONG * pVal);
	STDMETHOD(GetNth)( ULONG Index,  BSTR * Key,  BSTR * Value);
	STDMETHOD(GetParam)( BSTR Key,  BSTR * Value);
	STDMETHOD(SetParam)( BSTR Key,  BSTR Value);
	STDMETHOD(AddParam)( BSTR Key,  BSTR Value);
	STDMETHOD(ClearParam)( BSTR Key);

	// IYateOrigPointer Methods
public:
	STDMETHOD(get_OrigPtr)( void * * pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = m_origmsg;
		return S_OK;
	}
	STDMETHOD(put_OrigPtr)( void * newVal)
	{
		m_origmsg = reinterpret_cast<TelEngine::Message*>(newVal);
		return S_OK;
	}
	STDMETHOD(get_DeleteOrigObject)(BOOL* pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = m_delete_msg;
		return S_OK;
	}
	STDMETHOD(put_DeleteOrigObject)(BOOL newVal)
	{
		m_delete_msg = newVal;
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(YateMessage), CYateMessage)

// YatePhone.h : Declaration of the CYatePhone

#pragma once
#include "resource.h"       // main symbols

#include "YATE_i.h"
#include "ATLCPImplMT.h"
// Firing events across apartments: http://support.microsoft.com/kb/280512
#include "_IYatePhoneEvents_CP.h"

#include "yatengine.h" // that is YATE header, not this file!
#include <string>
#include <map>
#include "Utility.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CYatePhone

class ATL_NO_VTABLE CYatePhone :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CYatePhone, &CLSID_YatePhone>,
	public IConnectionPointContainerImpl<CYatePhone>,
	public IDispatchImpl<IYatePhone, &IID_IYatePhone, &LIBID_YateComServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISupportErrorInfo,
	public TelEngine::MessageReceiver,
	public CProxy_IYatePhoneEvents<CYatePhone>,
	public IProvideClassInfo2Impl<&CLSID_YatePhone, &__uuidof(_IYatePhoneEvents), &LIBID_YateComServerLib, 1, 0>
{
public:
	DECLARE_CLASSFACTORY();
	CYatePhone()
		:m_state(YATE_PHONE_IDLE)
	{
	}
//DECLARE_REGISTRY_RESOURCEID(IDR_YATEPHONE)
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) throw()
	{
		return UpdateRegistryFromResourceEx(GetCurrentModule(), IDR_YATEPHONE, bRegister);
	}


BEGIN_COM_MAP(CYatePhone)
	COM_INTERFACE_ENTRY(IYatePhone)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CYatePhone)
	CONNECTION_POINT_ENTRY(__uuidof(_IYatePhoneEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct();
	void FinalRelease();

	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
private:
	std::string m_account;
	TelEngine::String m_protocol, m_domain, m_server, m_username, m_password;
	// TelEngine::MessageReceiver
	bool received(TelEngine::Message& m, int IdNum);
	EnumYatePhoneState m_state;
	void SetState(EnumYatePhoneState newstate);
public:

	STDMETHOD(Login)();
	STDMETHOD(Dial)(/* [in] */ BSTR CalledNumber, /* [retval][out] */ VARIANT_BOOL *pSuccess);
	STDMETHOD(Answer)(/* [retval][out] */ VARIANT_BOOL *pSuccess);
	STDMETHOD(Hangup)();
	STDMETHOD(Logout)();
	STDMETHOD(get_Protocol)(/* [retval][out] */ BSTR *pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = CString(m_protocol.c_str()).AllocSysString();
		return S_OK;
	}
	STDMETHOD(put_Protocol)(/* [in] */ BSTR newVal)
	{
		m_protocol = UTF16toUTF8(newVal);
		return S_OK;
	}
	STDMETHOD(get_Domain)(/* [retval][out] */ BSTR *pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = CString(m_domain.c_str()).AllocSysString();
		return S_OK;
	}
	STDMETHOD(put_Domain)(/* [in] */ BSTR newVal)
	{
		m_domain = UTF16toUTF8(newVal);
		return S_OK;
	}
	STDMETHOD(get_Server)(/* [retval][out] */ BSTR *pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = CString(m_server.c_str()).AllocSysString();
		return S_OK;
	}
	STDMETHOD(put_Server)(/* [in] */ BSTR newVal)
	{
		m_server = UTF16toUTF8(newVal);
		return S_OK;
	}
	STDMETHOD(get_Username)(/* [retval][out] */ BSTR *pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = CString(m_username.c_str()).AllocSysString();
		return S_OK;
	}
	STDMETHOD(put_Username)(/* [in] */ BSTR newVal)
	{
		m_username = UTF16toUTF8(newVal);
		return S_OK;
	}
	STDMETHOD(get_Password)(/* [retval][out] */ BSTR *pVal)
	{
		if(!pVal)
			return E_POINTER;
		*pVal = CString(m_password.c_str()).AllocSysString();
		return S_OK;
	}
	STDMETHOD(put_Password)(/* [in] */ BSTR newVal)
	{
		m_password = UTF16toUTF8(newVal);
		return S_OK;
	}
	STDMETHOD(get_State)(/* [retval][out] */ EnumYatePhoneState *pVal)
	{
		return m_state;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(YatePhone), CYatePhone)

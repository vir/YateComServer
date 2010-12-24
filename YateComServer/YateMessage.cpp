// YateMessage.cpp : Implementation of CYateMessage

#include "stdafx.h"
#include "YateMessage.h"
#include "yatengine.h" // that is YATE header


// CYateMessage
HRESULT CYateMessage::FinalConstruct()
{
	return CoCreateFreeThreadedMarshaler(
		GetControllingUnknown(), &m_pUnkMarshaler.p);
}
void CYateMessage::FinalRelease()
{
	m_pUnkMarshaler.Release();
	if(m_delete_msg && m_origmsg) {
		delete m_origmsg;
		m_origmsg = NULL;
	}
}

void CYateMessage::check_create()
{
	if(!m_origmsg) {
		m_origmsg = new TelEngine::Message("");
		m_delete_msg = TRUE;
	}
}

STDMETHODIMP CYateMessage::get_Name(BSTR * pVal)
{
	if(!pVal)
		return E_POINTER;
	Locker lock(m_mutex);
	check_create();
	CStringW v = UTF8toUTF16(m_origmsg->c_str());
	*pVal = v.AllocSysString();
	return S_OK;
}
STDMETHODIMP CYateMessage::put_Name(BSTR newVal)
{
	Locker lock(m_mutex);
	check_create();
	TelEngine::String v(UTF16toUTF8(newVal));
	*m_origmsg = v;
	return S_OK;
}
STDMETHODIMP CYateMessage::get_ParamsCount(ULONG * pVal)
{
	if(!pVal)
		return E_POINTER;
	Locker lock(m_mutex);
	check_create();
	*pVal = m_origmsg->count();
	return S_OK;
}
STDMETHODIMP CYateMessage::GetNth(ULONG Index, BSTR * pKey, BSTR * pValue)
{
	if(!pKey || !pValue)
		return E_POINTER;
	Locker lock(m_mutex);
	check_create();
	TelEngine::NamedString * ns = m_origmsg->getParam(Index);
	if(!ns)
		return E_FAIL;
	*pKey = UTF8toUTF16(ns->name().c_str()).AllocSysString();
	*pValue = UTF8toUTF16(ns->c_str()).AllocSysString();
	return S_OK;
}
STDMETHODIMP CYateMessage::GetParam(BSTR Key, BSTR * pValue)
{
	if(!pValue)
		return E_POINTER;
	Locker lock(m_mutex);
	check_create();
	const char * s = m_origmsg->getValue(TelEngine::String(UTF16toUTF8(Key)));
	if(s)
		*pValue = UTF8toUTF16(s).AllocSysString();
	else
		*pValue = NULL;
	return S_OK;
}
STDMETHODIMP CYateMessage::SetParam(BSTR Key, BSTR Value)
{
	Locker lock(m_mutex);
	check_create();
	m_origmsg->setParam(UTF16toUTF8(Key), UTF16toUTF8(Value));
	return S_OK;
}
STDMETHODIMP CYateMessage::AddParam(BSTR Key, BSTR Value)
{
	Locker lock(m_mutex);
	check_create();
	m_origmsg->addParam(UTF16toUTF8(Key), UTF16toUTF8(Value));
	return E_NOTIMPL;
}
STDMETHODIMP CYateMessage::ClearParam(BSTR Key)
{
	Locker lock(m_mutex);
	check_create();
	m_origmsg->clearParam((const char*)UTF16toUTF8(Key));
	return E_NOTIMPL;
}

STDMETHODIMP CYateMessage::get_RetValue(BSTR * pVal)
{
	if(!pVal)
		return E_POINTER;
	Locker lock(m_mutex);
	check_create();
	*pVal = UTF8toUTF16(m_origmsg->retValue().c_str()).AllocSysString();
	return S_OK;
}
STDMETHODIMP CYateMessage::put_RetValue(BSTR newVal)
{
	Locker lock(m_mutex);
	check_create();
	m_origmsg->retValue() = UTF16toUTF8(newVal);
	return S_OK;
}


// YatePhone.cpp : Implementation of CYatePhone

#include "stdafx.h"
#include "YatePhone.h"
#include <yatecbase.h> // for  Client::self()->buildOutgoingChannel()

class MyClientLogic:public TelEngine::ClientLogic
{
private:
	static TelEngine::Mutex s_mutex;
	bool m_comInitialized;
	inline void comInit()
	{
		// Calls should come from mai gui thread only, so we do not have to mess with mutexes
		if(!m_comInitialized) {
			HRESULT hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
			ATLASSERT(SUCCEEDED(hr));
			m_comInitialized = true;
		}
	}
public:
	MyClientLogic()
		: ClientLogic("comserver client logic", -100) // priority has to be < 0 or mentioned in config file to work
		, m_comInitialized(false)
	{
	}
	static MyClientLogic& CheckInstance()
	{
		s_mutex.lock();
		static MyClientLogic instance;
		MyClientLogic& r = instance;
		s_mutex.unlock();
		return r;
	}
	virtual bool defaultMsgHandler (TelEngine::Message& msg, int id, bool& stopLogic)
	{
		if(msg != "call.initiate")
			return false;
		stopLogic = true;
		return TelEngine::Client::self()->buildOutgoingChannel(msg);
	}
};

TelEngine::Mutex MyClientLogic::s_mutex;

using namespace TelEngine;

// CYateEngine
STDMETHODIMP CYatePhone::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = { &IID_IYatePhone };
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CYatePhone::FinalConstruct()
{
	MyClientLogic::CheckInstance();
//	TelEngine::Client::self()->addLogic(&MyClientLogic::CheckInstance());
	return S_OK;
}

void CYatePhone::FinalRelease()
{
//	TelEngine::Client::self()->removeLogic(&MyClientLogic::CheckInstance());
}

STDMETHODIMP CYatePhone::Login()
{
	m_account = m_username;
	m_account += '@';
	m_account += m_domain;

	TelEngine::Message* m = new TelEngine::Message("user.login");
	m->addParam("account", m_account.c_str());
	m->addParam("operation", "login");
	m->addParam("enabled", "true");
	m->addParam("protocol", m_protocol);
	m->addParam("username", m_username);
	m->addParam("password", m_password);
	m->addParam("domain", m_domain);
	m->addParam("server", m_server.null()?m_domain:m_server);
	if(! TelEngine::Engine::enqueue(m))
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CYatePhone::Dial(/* [in] */ BSTR CalledNumber, /* [retval][out] */ VARIANT_BOOL *pSuccess)
{
	TelEngine::Message m("call.initiate");
	m.addParam("line", m_account.c_str());
	m.addParam("protocol", m_protocol);
	m.addParam("account", m_account.c_str());
	m.addParam("caller", m_username);
	m.addParam("callername", m_username);
	m.addParam("domain", m_domain);
	m.addParam("target", UTF16toUTF8(CalledNumber));
	bool r = TelEngine::Client::self()->postpone(m, TelEngine::Client::MsgIdCount + 1);
	if(!r)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CYatePhone::Answer(/* [retval][out] */ VARIANT_BOOL *pSuccess)
{
	return E_NOTIMPL;
}

STDMETHODIMP CYatePhone::Hangup()
{
	TelEngine::Message m("call.drop");
	m.addParam("id", "client/1");
	m.addParam("error", "cancelled");
	m.addParam("reason", "cancelled");
	bool r = TelEngine::Engine::dispatch(m);
	return r ? S_OK : S_FALSE;
}

STDMETHODIMP CYatePhone::Logout()
{
	TelEngine::Message m("user.login");
	m.addParam("module", "comserver");
	m.addParam("operation", "logout");
	m.addParam("account", m_account.c_str());
	m.addParam("protocol", m_protocol);
	bool r = TelEngine::Engine::dispatch(m);
	return r ? S_OK : S_FALSE;
}

bool CYatePhone::received(TelEngine::Message& m, int IdNum)
{
#if 0
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
#endif
	return false;
}

void CYatePhone::SetState( EnumYatePhoneState newstate )
{
	m_state = newstate;
	bool inited = SUCCEEDED(::CoInitializeEx(NULL, COINIT_MULTITHREADED));
	Fire_OnStateChange(newstate);
	if(inited)
		::CoUninitialize();
}

/*
Sniffed 'user.login' time=1285067442.192149
thread=01F062F0 'Engine Worker'
data=00000000
retval='(null)'
param['account'] = '299'
param['operation'] = 'login'
param['enabled'] = 'true'
param['protocol'] = 'sip'
param['username'] = '299'
param['password'] = (hidden)
param['server'] = 'voip.ctm.ru'
param['domain'] = 'voip.ctm.ru'


call:
Sniffed 'call.route' time=1285067687.562731
thread=03DE33B0 'Call Router'
data=00000000
retval='(null)'
param['id'] = 'client/1'
param['module'] = 'client'
param['status'] = 'incoming'
param['billid'] = '1285067441-1'
param['answered'] = 'false'
param['called'] = '115'
param['account'] = '299'
Returned true 'call.route' delay=0.002363
thread=03DE33B0 'Call Router'
data=00000000
retval='sip/115'
param['id'] = 'client/1'
param['module'] = 'client'
param['status'] = 'incoming'
param['billid'] = '1285067441-1'
param['answered'] = 'false'
param['called'] = '115'
param['account'] = '299'
param['line'] = '299'

Sniffed 'call.execute' time=1285067687.562731
thread=03DE33B0 'Call Router'
data=03DFCA80
retval='(null)'
param['id'] = 'client/1'
param['module'] = 'client'
param['status'] = 'incoming'
param['billid'] = '1285067441-1'
param['answered'] = 'false'
param['called'] = '115'
param['account'] = '299'
param['line'] = '299'
param['callto'] = 'sip/115'
Returned true 'call.execute' delay=0.005908
thread=03DE33B0 'Call Router'
data=03DFCA80
retval='(null)'
param['id'] = 'client/1'
param['module'] = 'client'
param['status'] = 'incoming'
param['billid'] = '1285067441-1'
param['answered'] = 'false'
param['called'] = '115'
param['account'] = '299'
param['line'] = '299'
param['callto'] = 'sip/115'
param['peerid'] = 'sip/1'
param['targetid'] = 'sip/1'

Sniffed 'call.ringing' time=1285067688.146441
thread=01F062F0 'Engine Worker'
data=00000000
retval='(null)'
param['id'] = 'sip/1'
param['module'] = 'sip'
param['status'] = 'ringing'
param['address'] = '192.168.1.44:5060'
param['targetid'] = 'client/1'
param['billid'] = '1285067441-1'
param['peerid'] = 'client/1'
param['lastpeerid'] = 'client/1'
param['answered'] = 'false'
param['domain'] = 'voip.ctm.ru'
param['callid'] = 'sip/1819732031@voip.ctm.ru/1980912243/151425597'
param['sip_server'] = 'YATE/3.0.0'
param['sip_contact'] = '<sip:115@192.168.1.44:5060>'
param['sip_allow'] = 'ACK, INVITE, BYE, CANCEL, REGISTER, REFER, OPTIONS, INFO'
param['earlymedia'] = 'false'

Sniffed 'call.answered' time=1285067695.130879
thread=01F062F0 'Engine Worker'
data=00000000
retval='(null)'
param['id'] = 'sip/1'
param['module'] = 'sip'
param['status'] = 'answered'
param['address'] = '192.168.1.44:5060'
param['targetid'] = 'client/1'
param['billid'] = '1285067441-1'
param['peerid'] = 'client/1'
param['lastpeerid'] = 'client/1'
param['answered'] = 'true'
param['domain'] = 'voip.ctm.ru'
param['callid'] = 'sip/1819732031@voip.ctm.ru/1980912243/151425597'
param['sip_server'] = 'YATE/3.0.0'
param['sip_contact'] = '<sip:115@192.168.1.44:5060>'
param['sip_allow'] = 'ACK, INVITE, BYE, CANCEL, REGISTER, REFER, OPTIONS, INFO'
param['sip_content-type'] = 'application/sdp'
param['media'] = 'yes'
param['formats'] = 'mulaw,alaw,gsm,slin'
param['transport'] = 'RTP/AVP'
param['rtp_rfc2833'] = '101'




*/
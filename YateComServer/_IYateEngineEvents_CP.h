#pragma once
#include "ATLCPImplMT.h"

//template<class T>
//class CProxy_IYateEngineEvents :
//	public IConnectionPointImpl<T, &__uuidof(_IYateEngineEvents)>
template<class T>
class CProxy_IYateEngineEvents :
	public IConnectionPointImplMT<T, &__uuidof(_IYateEngineEvents)>
{
public:
	HRESULT Fire_OnMessage(IYateMessage* pMessage, VARIANT_BOOL * pHandled)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			//pThis->Lock();
			//CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			//pThis->Unlock();
			CComPtr<IUnknown> punkConnection; 
			punkConnection.Attach (GetInterfaceAt(iConnection));

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[2];
				avarParams[1] = pMessage;
				avarParams[0].byref = pHandled;
				avarParams[0].vt = VT_BOOL|VT_BYREF;
				CComVariant varResult;

				DISPPARAMS params = { avarParams, NULL, 2, 0 };
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
		return hr;
	}
};


#pragma once
#include "ATLCPImplMT.h"

template<class T>
class CProxy_IYatePhoneEvents :
	public IConnectionPointImplMT<T, &__uuidof(_IYatePhoneEvents)>
{
public:
	HRESULT Fire_OnStateChange(EnumYatePhoneState NewState)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			CComPtr<IUnknown> punkConnection; 
			punkConnection.Attach (GetInterfaceAt(iConnection));

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[1];
				avarParams[0] = (LONG)NewState;
				avarParams[0].vt = VT_UINT;
				CComVariant varResult;

				DISPPARAMS params = { avarParams, NULL, 1, 0 };
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
		return hr;
	}
};


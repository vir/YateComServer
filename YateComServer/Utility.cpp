#include "stdafx.h"
#include "Utility.h"
#include <WinNT.h>
#include <statreg.h>

HRESULT UpdateRegistryFromResourceEx(HINSTANCE hResourceInst, UINT nResID, BOOL bRegister, struct _ATL_REGMAP_ENTRY* pMapEntries /*= NULL*/) throw()
{
	CRegObject ro;
	HRESULT hr = ro.FinalConstruct();
	if (FAILED(hr))
	{
		return hr;
	}

	if (pMapEntries != NULL)
	{
		while (pMapEntries->szKey != NULL)
		{
			ATLASSERT(NULL != pMapEntries->szData);
			ro.AddReplacement(pMapEntries->szKey, pMapEntries->szData);
			pMapEntries++;
		}
	}

	hr = _pAtlModule->AddCommonRGSReplacements(&ro);
	if (FAILED(hr))
		return hr;

	USES_CONVERSION_EX;
	TCHAR szModule[MAX_PATH];
	HINSTANCE hInst = _AtlBaseModule.GetModuleInstance();
	DWORD dwFLen = GetModuleFileName(hInst, szModule, MAX_PATH);
	if( dwFLen == 0 )
		return AtlHresultFromLastError();
	else if( dwFLen == MAX_PATH )
		return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

	LPOLESTR pszModule = NULL;
	pszModule = T2OLE_EX(szModule, _ATL_SAFE_ALLOCA_DEF_THRESHOLD);

	// Get filename of reource module
	OLECHAR szResourceModule[MAX_PATH];
	dwFLen = GetModuleFileNameW(hResourceInst, szResourceModule, MAX_PATH);
	if( dwFLen == 0 )
		return AtlHresultFromLastError();
	else if( dwFLen == MAX_PATH )
		return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
#ifndef _UNICODE
	if(pszModule == NULL) 
		return E_OUTOFMEMORY;
#endif

	OLECHAR pszModuleUnquoted[_MAX_PATH * 2];
	_pAtlModule->EscapeSingleQuote(pszModuleUnquoted, _countof(pszModuleUnquoted), pszModule);

	HRESULT hRes;
	if ((hInst == NULL) || (hInst == GetModuleHandle(NULL))) // register as EXE
	{
		// If Registering as an EXE, then we quote the resultant path.
		// We don't do it for a DLL, because LoadLibrary fails if the path is
		// quoted
		OLECHAR pszModuleQuote[(_MAX_PATH + _ATL_QUOTES_SPACE)*2]; 		
		pszModuleQuote[0] = OLESTR('\"');
		if(!ocscpy_s(pszModuleQuote + 1, (_MAX_PATH + _ATL_QUOTES_SPACE)*2 - 1, pszModuleUnquoted))
		{
			return E_FAIL;
		}
		size_t nLen = ocslen(pszModuleQuote);
		pszModuleQuote[nLen] = OLESTR('\"');
		pszModuleQuote[nLen + 1] = 0;

		hRes = ro.AddReplacement(OLESTR("Module"), pszModuleQuote);
	}
	else
	{
		hRes = ro.AddReplacement(OLESTR("Module"), pszModuleUnquoted);
	}	

	if(FAILED(hRes))
		return hRes;

	hRes = ro.AddReplacement(OLESTR("Module_Raw"), pszModuleUnquoted);
	if(FAILED(hRes))
		return hRes;

	LPCOLESTR szType = OLESTR("REGISTRY");
	hr = (bRegister) ? ro.ResourceRegister(szResourceModule, nResID, szType) : ro.ResourceUnregister(szResourceModule, nResID, szType);
	return hr;
}



/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Oct 01 18:06:11 2010
 */
/* Compiler settings for .\YATE.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __YATE_i_h__
#define __YATE_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IYateNamedList_FWD_DEFINED__
#define __IYateNamedList_FWD_DEFINED__
typedef interface IYateNamedList IYateNamedList;
#endif 	/* __IYateNamedList_FWD_DEFINED__ */


#ifndef __IYateMessage_FWD_DEFINED__
#define __IYateMessage_FWD_DEFINED__
typedef interface IYateMessage IYateMessage;
#endif 	/* __IYateMessage_FWD_DEFINED__ */


#ifndef __IYateOrigPointer_FWD_DEFINED__
#define __IYateOrigPointer_FWD_DEFINED__
typedef interface IYateOrigPointer IYateOrigPointer;
#endif 	/* __IYateOrigPointer_FWD_DEFINED__ */


#ifndef __IYateEngine_FWD_DEFINED__
#define __IYateEngine_FWD_DEFINED__
typedef interface IYateEngine IYateEngine;
#endif 	/* __IYateEngine_FWD_DEFINED__ */


#ifndef __IYatePhone_FWD_DEFINED__
#define __IYatePhone_FWD_DEFINED__
typedef interface IYatePhone IYatePhone;
#endif 	/* __IYatePhone_FWD_DEFINED__ */


#ifndef ___IYateEngineEvents_FWD_DEFINED__
#define ___IYateEngineEvents_FWD_DEFINED__
typedef interface _IYateEngineEvents _IYateEngineEvents;
#endif 	/* ___IYateEngineEvents_FWD_DEFINED__ */


#ifndef __YateEngine_FWD_DEFINED__
#define __YateEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class YateEngine YateEngine;
#else
typedef struct YateEngine YateEngine;
#endif /* __cplusplus */

#endif 	/* __YateEngine_FWD_DEFINED__ */


#ifndef ___IYatePhoneEvents_FWD_DEFINED__
#define ___IYatePhoneEvents_FWD_DEFINED__
typedef interface _IYatePhoneEvents _IYatePhoneEvents;
#endif 	/* ___IYatePhoneEvents_FWD_DEFINED__ */


#ifndef __YatePhone_FWD_DEFINED__
#define __YatePhone_FWD_DEFINED__

#ifdef __cplusplus
typedef class YatePhone YatePhone;
#else
typedef struct YatePhone YatePhone;
#endif /* __cplusplus */

#endif 	/* __YatePhone_FWD_DEFINED__ */


#ifndef __YateMessage_FWD_DEFINED__
#define __YateMessage_FWD_DEFINED__

#ifdef __cplusplus
typedef class YateMessage YateMessage;
#else
typedef struct YateMessage YateMessage;
#endif /* __cplusplus */

#endif 	/* __YateMessage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IYateNamedList_INTERFACE_DEFINED__
#define __IYateNamedList_INTERFACE_DEFINED__

/* interface IYateNamedList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IYateNamedList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6341B06D-41D2-4a56-9F6A-4CFBFF66A922")
    IYateNamedList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParamsCount( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNth( 
            /* [in] */ ULONG Index,
            /* [out] */ BSTR *pKey,
            /* [out] */ BSTR *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParam( 
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParam( 
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddParam( 
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearParam( 
            /* [in] */ BSTR Key) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IYateNamedListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IYateNamedList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IYateNamedList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IYateNamedList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IYateNamedList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IYateNamedList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IYateNamedList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IYateNamedList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IYateNamedList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IYateNamedList * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParamsCount )( 
            IYateNamedList * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNth )( 
            IYateNamedList * This,
            /* [in] */ ULONG Index,
            /* [out] */ BSTR *pKey,
            /* [out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IYateNamedList * This,
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParam )( 
            IYateNamedList * This,
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddParam )( 
            IYateNamedList * This,
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearParam )( 
            IYateNamedList * This,
            /* [in] */ BSTR Key);
        
        END_INTERFACE
    } IYateNamedListVtbl;

    interface IYateNamedList
    {
        CONST_VTBL struct IYateNamedListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IYateNamedList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IYateNamedList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IYateNamedList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IYateNamedList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IYateNamedList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IYateNamedList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IYateNamedList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IYateNamedList_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IYateNamedList_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IYateNamedList_get_ParamsCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ParamsCount(This,pVal) ) 

#define IYateNamedList_GetNth(This,Index,pKey,pValue)	\
    ( (This)->lpVtbl -> GetNth(This,Index,pKey,pValue) ) 

#define IYateNamedList_GetParam(This,Key,pValue)	\
    ( (This)->lpVtbl -> GetParam(This,Key,pValue) ) 

#define IYateNamedList_SetParam(This,Key,Value)	\
    ( (This)->lpVtbl -> SetParam(This,Key,Value) ) 

#define IYateNamedList_AddParam(This,Key,Value)	\
    ( (This)->lpVtbl -> AddParam(This,Key,Value) ) 

#define IYateNamedList_ClearParam(This,Key)	\
    ( (This)->lpVtbl -> ClearParam(This,Key) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IYateNamedList_INTERFACE_DEFINED__ */


#ifndef __IYateMessage_INTERFACE_DEFINED__
#define __IYateMessage_INTERFACE_DEFINED__

/* interface IYateMessage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IYateMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8C6F5C25-1E8E-4db5-9DE3-1FACC52945BE")
    IYateMessage : public IYateNamedList
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RetValue( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RetValue( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IYateMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IYateMessage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IYateMessage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IYateMessage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IYateMessage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IYateMessage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IYateMessage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IYateMessage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IYateMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IYateMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParamsCount )( 
            IYateMessage * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNth )( 
            IYateMessage * This,
            /* [in] */ ULONG Index,
            /* [out] */ BSTR *pKey,
            /* [out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            IYateMessage * This,
            /* [in] */ BSTR Key,
            /* [retval][out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParam )( 
            IYateMessage * This,
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddParam )( 
            IYateMessage * This,
            /* [in] */ BSTR Key,
            /* [in] */ BSTR Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearParam )( 
            IYateMessage * This,
            /* [in] */ BSTR Key);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetValue )( 
            IYateMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RetValue )( 
            IYateMessage * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IYateMessageVtbl;

    interface IYateMessage
    {
        CONST_VTBL struct IYateMessageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IYateMessage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IYateMessage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IYateMessage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IYateMessage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IYateMessage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IYateMessage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IYateMessage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IYateMessage_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IYateMessage_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IYateMessage_get_ParamsCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ParamsCount(This,pVal) ) 

#define IYateMessage_GetNth(This,Index,pKey,pValue)	\
    ( (This)->lpVtbl -> GetNth(This,Index,pKey,pValue) ) 

#define IYateMessage_GetParam(This,Key,pValue)	\
    ( (This)->lpVtbl -> GetParam(This,Key,pValue) ) 

#define IYateMessage_SetParam(This,Key,Value)	\
    ( (This)->lpVtbl -> SetParam(This,Key,Value) ) 

#define IYateMessage_AddParam(This,Key,Value)	\
    ( (This)->lpVtbl -> AddParam(This,Key,Value) ) 

#define IYateMessage_ClearParam(This,Key)	\
    ( (This)->lpVtbl -> ClearParam(This,Key) ) 


#define IYateMessage_get_RetValue(This,pVal)	\
    ( (This)->lpVtbl -> get_RetValue(This,pVal) ) 

#define IYateMessage_put_RetValue(This,newVal)	\
    ( (This)->lpVtbl -> put_RetValue(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IYateMessage_INTERFACE_DEFINED__ */


#ifndef __IYateOrigPointer_INTERFACE_DEFINED__
#define __IYateOrigPointer_INTERFACE_DEFINED__

/* interface IYateOrigPointer */
/* [unique][helpstring][hidden][restricted][uuid][local][object] */ 


EXTERN_C const IID IID_IYateOrigPointer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A92F04A-95DC-46cf-B4AB-A8DEBE343C24")
    IYateOrigPointer : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_OrigPtr( 
            /* [retval][out] */ void **pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_OrigPtr( 
            /* [in] */ void *newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DeleteOrigObject( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DeleteOrigObject( 
            /* [in] */ BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IYateOrigPointerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IYateOrigPointer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IYateOrigPointer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IYateOrigPointer * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OrigPtr )( 
            IYateOrigPointer * This,
            /* [retval][out] */ void **pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OrigPtr )( 
            IYateOrigPointer * This,
            /* [in] */ void *newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeleteOrigObject )( 
            IYateOrigPointer * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeleteOrigObject )( 
            IYateOrigPointer * This,
            /* [in] */ BOOL newVal);
        
        END_INTERFACE
    } IYateOrigPointerVtbl;

    interface IYateOrigPointer
    {
        CONST_VTBL struct IYateOrigPointerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IYateOrigPointer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IYateOrigPointer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IYateOrigPointer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IYateOrigPointer_get_OrigPtr(This,pVal)	\
    ( (This)->lpVtbl -> get_OrigPtr(This,pVal) ) 

#define IYateOrigPointer_put_OrigPtr(This,newVal)	\
    ( (This)->lpVtbl -> put_OrigPtr(This,newVal) ) 

#define IYateOrigPointer_get_DeleteOrigObject(This,pVal)	\
    ( (This)->lpVtbl -> get_DeleteOrigObject(This,pVal) ) 

#define IYateOrigPointer_put_DeleteOrigObject(This,newVal)	\
    ( (This)->lpVtbl -> put_DeleteOrigObject(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IYateOrigPointer_INTERFACE_DEFINED__ */


#ifndef __IYateEngine_INTERFACE_DEFINED__
#define __IYateEngine_INTERFACE_DEFINED__

/* interface IYateEngine */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IYateEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0354B1A2-EF68-43aa-9F51-0DCD2F51C954")
    IYateEngine : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dispatch( 
            /* [out][in] */ IYateMessage **ppMessage,
            /* [retval][out] */ VARIANT_BOOL *pHandled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Enqueue( 
            /* [in] */ IYateMessage *pMessage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallMessageRelay( 
            /* [in] */ BSTR Name,
            /* [in] */ LONG Priority,
            /* [in] */ LONG IdNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UninstallMessageRelay( 
            /* [in] */ BSTR Name) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IYateEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IYateEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IYateEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IYateEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IYateEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IYateEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IYateEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IYateEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dispatch )( 
            IYateEngine * This,
            /* [out][in] */ IYateMessage **ppMessage,
            /* [retval][out] */ VARIANT_BOOL *pHandled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Enqueue )( 
            IYateEngine * This,
            /* [in] */ IYateMessage *pMessage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallMessageRelay )( 
            IYateEngine * This,
            /* [in] */ BSTR Name,
            /* [in] */ LONG Priority,
            /* [in] */ LONG IdNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UninstallMessageRelay )( 
            IYateEngine * This,
            /* [in] */ BSTR Name);
        
        END_INTERFACE
    } IYateEngineVtbl;

    interface IYateEngine
    {
        CONST_VTBL struct IYateEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IYateEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IYateEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IYateEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IYateEngine_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IYateEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IYateEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IYateEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IYateEngine_Dispatch(This,ppMessage,pHandled)	\
    ( (This)->lpVtbl -> Dispatch(This,ppMessage,pHandled) ) 

#define IYateEngine_Enqueue(This,pMessage)	\
    ( (This)->lpVtbl -> Enqueue(This,pMessage) ) 

#define IYateEngine_InstallMessageRelay(This,Name,Priority,IdNum)	\
    ( (This)->lpVtbl -> InstallMessageRelay(This,Name,Priority,IdNum) ) 

#define IYateEngine_UninstallMessageRelay(This,Name)	\
    ( (This)->lpVtbl -> UninstallMessageRelay(This,Name) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IYateEngine_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_YATE_0000_0004 */
/* [local] */ 

typedef /* [public][public][public][public][uuid] */  DECLSPEC_UUID("54C34A85-F18A-4edf-9A66-B08A9D0D329F") 
enum __MIDL___MIDL_itf_YATE_0000_0004_0001
    {	YATE_PHONE_IDLE	= 0,
	YATE_PHONE_REGISTERED	= 1,
	YATE_PHONE_CALLING	= 2,
	YATE_PHONE_RINGING	= 3,
	YATE_PHONE_TALKING	= 4
    } 	EnumYatePhoneState;



extern RPC_IF_HANDLE __MIDL_itf_YATE_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_YATE_0000_0004_v0_0_s_ifspec;

#ifndef __IYatePhone_INTERFACE_DEFINED__
#define __IYatePhone_INTERFACE_DEFINED__

/* interface IYatePhone */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IYatePhone;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7D4257E-B43D-4000-A8EB-52C173888407")
    IYatePhone : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Login( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dial( 
            /* [in] */ BSTR CalledNumber,
            /* [retval][out] */ VARIANT_BOOL *pSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Answer( 
            /* [retval][out] */ VARIANT_BOOL *pSuccess) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hangup( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logout( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Protocol( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Protocol( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Domain( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Domain( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Server( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Server( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Username( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Username( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ EnumYatePhoneState *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IYatePhoneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IYatePhone * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IYatePhone * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IYatePhone * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IYatePhone * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IYatePhone * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IYatePhone * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IYatePhone * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Login )( 
            IYatePhone * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dial )( 
            IYatePhone * This,
            /* [in] */ BSTR CalledNumber,
            /* [retval][out] */ VARIANT_BOOL *pSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Answer )( 
            IYatePhone * This,
            /* [retval][out] */ VARIANT_BOOL *pSuccess);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hangup )( 
            IYatePhone * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Logout )( 
            IYatePhone * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Protocol )( 
            IYatePhone * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Protocol )( 
            IYatePhone * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Domain )( 
            IYatePhone * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Domain )( 
            IYatePhone * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Server )( 
            IYatePhone * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Server )( 
            IYatePhone * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Username )( 
            IYatePhone * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Username )( 
            IYatePhone * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IYatePhone * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IYatePhone * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IYatePhone * This,
            /* [retval][out] */ EnumYatePhoneState *pVal);
        
        END_INTERFACE
    } IYatePhoneVtbl;

    interface IYatePhone
    {
        CONST_VTBL struct IYatePhoneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IYatePhone_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IYatePhone_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IYatePhone_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IYatePhone_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IYatePhone_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IYatePhone_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IYatePhone_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IYatePhone_Login(This)	\
    ( (This)->lpVtbl -> Login(This) ) 

#define IYatePhone_Dial(This,CalledNumber,pSuccess)	\
    ( (This)->lpVtbl -> Dial(This,CalledNumber,pSuccess) ) 

#define IYatePhone_Answer(This,pSuccess)	\
    ( (This)->lpVtbl -> Answer(This,pSuccess) ) 

#define IYatePhone_Hangup(This)	\
    ( (This)->lpVtbl -> Hangup(This) ) 

#define IYatePhone_Logout(This)	\
    ( (This)->lpVtbl -> Logout(This) ) 

#define IYatePhone_get_Protocol(This,pVal)	\
    ( (This)->lpVtbl -> get_Protocol(This,pVal) ) 

#define IYatePhone_put_Protocol(This,newVal)	\
    ( (This)->lpVtbl -> put_Protocol(This,newVal) ) 

#define IYatePhone_get_Domain(This,pVal)	\
    ( (This)->lpVtbl -> get_Domain(This,pVal) ) 

#define IYatePhone_put_Domain(This,newVal)	\
    ( (This)->lpVtbl -> put_Domain(This,newVal) ) 

#define IYatePhone_get_Server(This,pVal)	\
    ( (This)->lpVtbl -> get_Server(This,pVal) ) 

#define IYatePhone_put_Server(This,newVal)	\
    ( (This)->lpVtbl -> put_Server(This,newVal) ) 

#define IYatePhone_get_Username(This,pVal)	\
    ( (This)->lpVtbl -> get_Username(This,pVal) ) 

#define IYatePhone_put_Username(This,newVal)	\
    ( (This)->lpVtbl -> put_Username(This,newVal) ) 

#define IYatePhone_get_Password(This,pVal)	\
    ( (This)->lpVtbl -> get_Password(This,pVal) ) 

#define IYatePhone_put_Password(This,newVal)	\
    ( (This)->lpVtbl -> put_Password(This,newVal) ) 

#define IYatePhone_get_State(This,pVal)	\
    ( (This)->lpVtbl -> get_State(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IYatePhone_INTERFACE_DEFINED__ */



#ifndef __YateComServerLib_LIBRARY_DEFINED__
#define __YateComServerLib_LIBRARY_DEFINED__

/* library YateComServerLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_YateComServerLib;

#ifndef ___IYateEngineEvents_DISPINTERFACE_DEFINED__
#define ___IYateEngineEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IYateEngineEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IYateEngineEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("65A38DAD-52EF-469B-BF1F-31658CC4C49F")
    _IYateEngineEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IYateEngineEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IYateEngineEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IYateEngineEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IYateEngineEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IYateEngineEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IYateEngineEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IYateEngineEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IYateEngineEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IYateEngineEventsVtbl;

    interface _IYateEngineEvents
    {
        CONST_VTBL struct _IYateEngineEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IYateEngineEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IYateEngineEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IYateEngineEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IYateEngineEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IYateEngineEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IYateEngineEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IYateEngineEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IYateEngineEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_YateEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("A5683D87-78EC-4eab-A76D-B6334DE6F7FB")
YateEngine;
#endif

#ifndef ___IYatePhoneEvents_DISPINTERFACE_DEFINED__
#define ___IYatePhoneEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IYatePhoneEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IYatePhoneEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DFBC5262-A1DD-4019-B338-8A68BE0CBCD7")
    _IYatePhoneEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IYatePhoneEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IYatePhoneEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IYatePhoneEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IYatePhoneEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IYatePhoneEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IYatePhoneEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IYatePhoneEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IYatePhoneEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IYatePhoneEventsVtbl;

    interface _IYatePhoneEvents
    {
        CONST_VTBL struct _IYatePhoneEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IYatePhoneEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IYatePhoneEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IYatePhoneEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IYatePhoneEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IYatePhoneEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IYatePhoneEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IYatePhoneEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IYatePhoneEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_YatePhone;

#ifdef __cplusplus

class DECLSPEC_UUID("65354AA7-C3B0-4973-BE66-EEA879AFB090")
YatePhone;
#endif

EXTERN_C const CLSID CLSID_YateMessage;

#ifdef __cplusplus

class DECLSPEC_UUID("F049EC7F-53A6-4F28-B3D0-41CE0426BD59")
YateMessage;
#endif
#endif /* __YateComServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



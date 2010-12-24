

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IYateNamedList,0x6341B06D,0x41D2,0x4a56,0x9F,0x6A,0x4C,0xFB,0xFF,0x66,0xA9,0x22);


MIDL_DEFINE_GUID(IID, IID_IYateMessage,0x8C6F5C25,0x1E8E,0x4db5,0x9D,0xE3,0x1F,0xAC,0xC5,0x29,0x45,0xBE);


MIDL_DEFINE_GUID(IID, IID_IYateOrigPointer,0x8A92F04A,0x95DC,0x46cf,0xB4,0xAB,0xA8,0xDE,0xBE,0x34,0x3C,0x24);


MIDL_DEFINE_GUID(IID, IID_IYateEngine,0x0354B1A2,0xEF68,0x43aa,0x9F,0x51,0x0D,0xCD,0x2F,0x51,0xC9,0x54);


MIDL_DEFINE_GUID(IID, IID_IYatePhone,0xA7D4257E,0xB43D,0x4000,0xA8,0xEB,0x52,0xC1,0x73,0x88,0x84,0x07);


MIDL_DEFINE_GUID(IID, LIBID_YateComServerLib,0x7D62D7AA,0x8842,0x4a39,0x9A,0x40,0x30,0xA6,0x67,0x84,0x32,0xE4);


MIDL_DEFINE_GUID(IID, DIID__IYateEngineEvents,0x65A38DAD,0x52EF,0x469B,0xBF,0x1F,0x31,0x65,0x8C,0xC4,0xC4,0x9F);


MIDL_DEFINE_GUID(CLSID, CLSID_YateEngine,0xA5683D87,0x78EC,0x4eab,0xA7,0x6D,0xB6,0x33,0x4D,0xE6,0xF7,0xFB);


MIDL_DEFINE_GUID(IID, DIID__IYatePhoneEvents,0xDFBC5262,0xA1DD,0x4019,0xB3,0x38,0x8A,0x68,0xBE,0x0C,0xBC,0xD7);


MIDL_DEFINE_GUID(CLSID, CLSID_YatePhone,0x65354AA7,0xC3B0,0x4973,0xBE,0x66,0xEE,0xA8,0x79,0xAF,0xB0,0x90);


MIDL_DEFINE_GUID(CLSID, CLSID_YateMessage,0xF049EC7F,0x53A6,0x4F28,0xB3,0xD0,0x41,0xCE,0x04,0x26,0xBD,0x59);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




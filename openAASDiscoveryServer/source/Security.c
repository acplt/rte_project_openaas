
/******************************************************************************
*
*   FILE
*   ----
*   Security.c
*
*   History
*   -------
*   2018-05-04   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_openAASDiscoveryServer
#define OV_COMPILE_LIBRARY_openAASDiscoveryServer
#endif


#include "openAASDiscoveryServer.h"
#include "ov_macros.h"
#include "ov_path.h"

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_AddURMSWrapper_set(
    OV_INSTPTR_openAASDiscoveryServer_Security          pobj,
    const OV_BOOL  value
) {
    pobj->v_AddURMSWrapper = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_RemoveURMSWrapper_set(
    OV_INSTPTR_openAASDiscoveryServer_Security          pobj,
    const OV_BOOL  value
) {
    pobj->v_RemoveURMSWrapper = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_AddCAWrapper_set(
    OV_INSTPTR_openAASDiscoveryServer_Security          pobj,
    const OV_BOOL  value
) {
    pobj->v_AddCAWrapper = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_RemoveCAWrapper_set(
    OV_INSTPTR_openAASDiscoveryServer_Security          pobj,
    const OV_BOOL  value
) {
    pobj->v_RemoveCAWrapper = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_ProcessSecurityMessage_set(
    OV_INSTPTR_openAASDiscoveryServer_Security          pobj,
    const OV_BOOL  value
) {
    pobj->v_ProcessSecurityMessage = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_ACCESS openAASDiscoveryServer_Security_getaccess(
	OV_INSTPTR_ov_object	pobj,
	const OV_ELEMENT		*pelem,
	const OV_TICKET			*pticket
) {
    /*    
    *   local variables
    */
	switch(pelem->elemtype) {
		case OV_ET_VARIABLE:
			if(pelem->elemunion.pvar->v_offset >= offsetof(OV_INST_ov_object,__classinfo)) {
				if(pelem->elemunion.pvar->v_vartype == OV_VT_CTYPE)
					return OV_AC_NONE;
				else{
					if(pelem->elemunion.pvar->v_flags == 256) { // InputFlag is set
						return OV_AC_READWRITE;
					}
					/* Nicht FB? */
					if(pelem->elemunion.pvar->v_varprops & OV_VP_SETACCESSOR) {
						return OV_AC_READWRITE;
					}
					return OV_AC_READ;
				}
			}
		break;
		default:
		break;
	}

	return ov_object_getaccess(pobj, pelem, pticket);
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    //OV_INSTPTR_openAASDiscoveryServer_Security pinst = Ov_StaticPtrCast(openAASDiscoveryServer_Security, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = openAASDiscoveryServer_Part_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */


    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_addURMSWrapper(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *URMSWrapper, OV_UINT veclen) {
	OV_INSTPTR_ov_object pobj = NULL;
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	for (OV_UINT i = 0; i < veclen; i++){
		pobj = ov_path_getobjectpointer(URMSWrapper[i], 2);
		if (Ov_CanCastTo(openAASDiscoveryServer_CAWrapper, pobj) == FALSE){
			return OV_ERR_BADOBJTYPE;
		}
		if (pSecurity->v_URMSWrapper.veclen == 0){
			Ov_SetDynamicVectorLength(&pSecurity->v_URMSWrapper, pSecurity->v_URMSWrapper.veclen + 1, STRING);
			ov_string_setvalue(&pSecurity->v_URMSWrapper.value[pSecurity->v_URMSWrapper.veclen - 1], URMSWrapper[i]);
			continue;
		}
		for (OV_UINT j = 0; j < pSecurity->v_URMSWrapper.veclen; j++){
			if (ov_string_compare(URMSWrapper[i], pSecurity->v_URMSWrapper.value[j]) == OV_STRCMP_EQUAL){
				break;
			}
			if (j == pSecurity->v_URMSWrapper.veclen - 1){
				Ov_SetDynamicVectorLength(&pSecurity->v_URMSWrapper, pSecurity->v_URMSWrapper.veclen + 1, STRING);
				ov_string_setvalue(&pSecurity->v_URMSWrapper.value[pSecurity->v_URMSWrapper.veclen - 1], URMSWrapper[i]);
			}
		}
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_removeURMSWrapper(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *URMSWrapper, OV_UINT veclen) {
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	for (OV_UINT i = 0; i < veclen; i++){
		for (OV_UINT j = 0; j < pSecurity->v_URMSWrapper.veclen; j++){
			if (ov_string_compare(URMSWrapper[i], pSecurity->v_URMSWrapper.value[j]) == OV_STRCMP_EQUAL){
				for(OV_UINT k = j; k < pSecurity->v_URMSWrapper.veclen-1; k++){
					ov_string_setvalue(&pSecurity->v_URMSWrapper.value[k], pSecurity->v_URMSWrapper.value[k+1]);
				}
				Ov_SetDynamicVectorLength(&pSecurity->v_URMSWrapper, pSecurity->v_URMSWrapper.veclen - 1, STRING);
			}
		}
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_addCAWrapper(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *CAWrapper, OV_UINT veclen) {
	OV_INSTPTR_ov_object pobj = NULL;
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	for (OV_UINT i = 0; i < veclen; i++){
		pobj = ov_path_getobjectpointer(CAWrapper[i], 2);
		if (Ov_CanCastTo(openAASDiscoveryServer_CAWrapper, pobj) == FALSE){
			return OV_ERR_BADOBJTYPE;
		}
		if (pSecurity->v_CAWrapper.veclen == 0){
			Ov_SetDynamicVectorLength(&pSecurity->v_CAWrapper, pSecurity->v_CAWrapper.veclen + 1, STRING);
			ov_string_setvalue(&pSecurity->v_CAWrapper.value[pSecurity->v_CAWrapper.veclen - 1], CAWrapper[i]);
			continue;
		}
		for (OV_UINT j = 0; j < pSecurity->v_CAWrapper.veclen; j++){
			if (ov_string_compare(CAWrapper[i], pSecurity->v_CAWrapper.value[j]) == OV_STRCMP_EQUAL){
				break;
			}
			if (j == pSecurity->v_CAWrapper.veclen - 1){
				Ov_SetDynamicVectorLength(&pSecurity->v_CAWrapper, pSecurity->v_CAWrapper.veclen + 1, STRING);
				ov_string_setvalue(&pSecurity->v_CAWrapper.value[pSecurity->v_CAWrapper.veclen - 1], CAWrapper[i]);
			}
		}
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_removeCAWrapper(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *CAWrapper, OV_UINT veclen) {
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	for (OV_UINT i = 0; i < veclen; i++){
		for (OV_UINT j = 0; j < pSecurity->v_CAWrapper.veclen; j++){
			if (ov_string_compare(CAWrapper[i], pSecurity->v_CAWrapper.value[j]) == OV_STRCMP_EQUAL){
				for(OV_UINT k = j; k < pSecurity->v_CAWrapper.veclen-1; k++){
					ov_string_setvalue(&pSecurity->v_CAWrapper.value[k], pSecurity->v_CAWrapper.value[k+1]);
				}
				Ov_SetDynamicVectorLength(&pSecurity->v_CAWrapper, pSecurity->v_CAWrapper.veclen - 1, STRING);
			}
		}
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_addDSService(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *DSService, OV_UINT veclen) {
    /*    
    *   local variables
    */
	OV_INSTPTR_ov_object pobj = NULL;
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	for (OV_UINT i = 0; i < veclen; i++){
		pobj = ov_path_getobjectpointer(DSService[i], 2);
		if (Ov_CanCastTo(openAASDiscoveryServer_DSSecurityService, pobj) == FALSE){
			return OV_ERR_BADOBJTYPE;
		}
		if (pSecurity->v_DSService.veclen == 0){
			Ov_SetDynamicVectorLength(&pSecurity->v_DSService, pSecurity->v_DSService.veclen + 1, STRING);
			ov_string_setvalue(&pSecurity->v_DSService.value[pSecurity->v_DSService.veclen - 1], DSService[i]);
			continue;
		}
		for (OV_UINT j = 0; j < pSecurity->v_DSService.veclen; j++){
			if (ov_string_compare(DSService[i], pSecurity->v_DSService.value[j]) == OV_STRCMP_EQUAL){
				break;
			}
			if (j == pSecurity->v_DSService.veclen - 1){
				Ov_SetDynamicVectorLength(&pSecurity->v_DSService, pSecurity->v_DSService.veclen + 1, STRING);
				ov_string_setvalue(&pSecurity->v_DSService.value[pSecurity->v_DSService.veclen - 1], DSService[i]);
			}
		}
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_removeDSService(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *DSService, OV_UINT veclen) {
    /*    
    *   local variables
    */
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	for (OV_UINT i = 0; i < veclen; i++){
		for (OV_UINT j = 0; j < pSecurity->v_DSService.veclen; j++){
			if (ov_string_compare(DSService[i], pSecurity->v_DSService.value[j]) == OV_STRCMP_EQUAL){
				for(OV_UINT k = j; k < pSecurity->v_DSService.veclen-1; k++){
					ov_string_setvalue(&pSecurity->v_DSService.value[k], pSecurity->v_DSService.value[k+1]);
				}
				Ov_SetDynamicVectorLength(&pSecurity->v_DSService, pSecurity->v_DSService.veclen - 1, STRING);
			}
		}
	}
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_configureDSService(OV_INSTPTR_openAASDiscoveryServer_Part pinst, OV_STRING *DBWrapper, OV_UINT veclenDBWrapper, OV_STRING *URMSWrapper, OV_UINT veclenURMSWrapper, OV_STRING *CAWrapper, OV_UINT veclenCAWrapper, OV_STRING *SEWrapper, OV_UINT veclenSEWrapper, OV_STRING DSService) {
    /*    
    *   local variables
    */
	OV_INSTPTR_ov_object pobj = NULL;
	OV_INSTPTR_openAASDiscoveryServer_Security pSecurity = NULL;
	pSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_Security, pinst);
	if (!pSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	// Is Service registered?
	OV_BOOL foundDSService = FALSE;
	for (OV_UINT j = 0; j < pSecurity->v_DSService.veclen; j++){
		if (ov_string_compare(DSService, pSecurity->v_DSService.value[j]) == OV_STRCMP_EQUAL){
			foundDSService = TRUE;
			break;
		}
	}
	if(foundDSService == FALSE){
		return OV_ERR_BADSELECTOR;
	}

	pobj = ov_path_getobjectpointer(DSService, 2);
	if (!pobj){
		return OV_ERR_NOACCESS;
	}
	OV_INSTPTR_openAASDiscoveryServer_DSSecurityService pDSSecurity = NULL;
	pDSSecurity = Ov_DynamicPtrCast(openAASDiscoveryServer_DSSecurityService, pobj);
	if (!pDSSecurity){
		return OV_ERR_BADOBJTYPE;
	}
	OV_BOOL foundDBWrapper = TRUE;
	for (OV_UINT i = 0; i < veclenDBWrapper; i++){
		for (OV_UINT j = 0; j < pSecurity->v_DBWrapper.veclen; j++){
			if (ov_string_compare(DBWrapper[i], pSecurity->v_DBWrapper.value[j]) == OV_STRCMP_EQUAL){
				break;
			}
			if (j == pSecurity->v_DBWrapper.veclen - 1){
				foundDBWrapper = FALSE;
			}
		}
	}
	if (foundDBWrapper == FALSE){
		return OV_ERR_BADSELECTOR;
	}
	Ov_SetDynamicVectorValue(&pDSSecurity->v_DBWrapperUsed, DBWrapper, veclenDBWrapper, STRING);

	OV_BOOL foundCAWrapper = TRUE;
	for (OV_UINT i = 0; i < veclenCAWrapper; i++){
		for (OV_UINT j = 0; j < pSecurity->v_CAWrapper.veclen; j++){
			if (ov_string_compare(SEWrapper[i], pSecurity->v_CAWrapper.value[j]) == OV_STRCMP_EQUAL){
				break;
			}
			if (j == pSecurity->v_CAWrapper.veclen - 1){
				foundCAWrapper = FALSE;
			}
		}
	}
	if (foundCAWrapper == FALSE){
		return OV_ERR_BADSELECTOR;
	}
	Ov_SetDynamicVectorValue(&pDSSecurity->v_CAWrapperUsed, CAWrapper, veclenCAWrapper, STRING);

	OV_BOOL foundURMSWrapper = TRUE;
	for (OV_UINT i = 0; i < veclenURMSWrapper; i++){
		for (OV_UINT j = 0; j < pSecurity->v_URMSWrapper.veclen; j++){
			if (ov_string_compare(URMSWrapper[i], pSecurity->v_URMSWrapper.value[j]) == OV_STRCMP_EQUAL){
				break;
			}
			if (j == pSecurity->v_URMSWrapper.veclen - 1){
				foundURMSWrapper = FALSE;
			}
		}
	}
	if (foundURMSWrapper == FALSE){
		return OV_ERR_BADSELECTOR;
	}
	Ov_SetDynamicVectorValue(&pDSSecurity->v_URMSWrapperUsed, URMSWrapper, veclenURMSWrapper, STRING);


    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openAASDiscoveryServer_Security_getSecurityMessage(OV_INSTPTR_openAASDiscoveryServer_Part pinst, const json_data body, OV_STRING *JsonOutput, OV_STRING *errorMessage) {
	OV_INSTPTR_ov_object pobj = NULL;
	OV_INSTPTR_openAASDiscoveryServer_DSSecurityService pService = NULL;
	OV_STRING tmpJsonOutput = NULL;
	*JsonOutput = NULL;
	for (OV_UINT i = 0; i < pinst->v_UsedDSServicePaths.veclen; i++){
		pobj = ov_path_getobjectpointer(pinst->v_UsedDSServicePaths.value[i], 2);
		if (!pobj){
			continue;
		}
		pService = Ov_DynamicPtrCast(openAASDiscoveryServer_DSSecurityService, pobj);
		if (!pService){
			continue;
		}
		OV_VTBLPTR_openAASDiscoveryServer_DSService pvtable = NULL;
		Ov_GetVTablePtr(openAASDiscoveryServer_DSService, pvtable, pService);
		if (i == 0)
			pvtable->m_executeService(Ov_DynamicPtrCast(openAASDiscoveryServer_DSService, pService), body, JsonOutput, errorMessage);
		else
			pvtable->m_executeService(Ov_DynamicPtrCast(openAASDiscoveryServer_DSService, pService), body, &tmpJsonOutput, errorMessage);
	}
	if (!*JsonOutput){
		if (pinst->v_UsedDSServicePaths.veclen == 0){
			ov_string_setvalue(errorMessage, "DSServices not configured");
		}
		ov_string_setvalue(JsonOutput, "\"body\"{}");
		return OV_ERR_GENERIC;
	}
	if (tmpJsonOutput){
		ov_logfile_info("%s", tmpJsonOutput);
		ov_string_setvalue(&tmpJsonOutput, NULL);
	}
    return OV_ERR_OK;
}


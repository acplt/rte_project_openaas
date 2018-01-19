
/******************************************************************************
*
*   FILE
*   ----
*   GetComfromASSIDService.c
*
*   History
*   -------
*   2018-01-17   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_subModelDiscovery
#define OV_COMPILE_LIBRARY_subModelDiscovery
#endif


#include "subModelDiscovery.h"
#include "libov/ov_macros.h"


OV_DLLFNCEXPORT OV_RESULT subModelDiscovery_GetAASEntryPointByAASIDService_CallMethod(
  OV_INSTPTR_services_Service pobj,       
  OV_UINT numberofInputArgs,       
  const void **packedInputArgList,       
  OV_UINT numberofOutputArgs,      
  void **packedOutputArgList,
  OV_UINT *typeArray       
) {
    /*    
    *   local variables
    */

	OV_STRING status = NULL;

	packedOutputArgList[0] = ov_database_malloc(sizeof(OV_STRING));
	*(OV_STRING*)packedOutputArgList[0] = NULL;
	typeArray[0] = OV_VT_STRING;

	packedOutputArgList[1] = ov_database_malloc(sizeof(OV_STRING_VEC));
	(*(OV_STRING_VEC*)packedOutputArgList[1]).value = NULL;
	(*(OV_STRING_VEC*)packedOutputArgList[1]).veclen = 0;
	typeArray[1] = OV_VT_STRING_VEC;

	OV_STRING tmpHexStringAAS = NULL;
	OV_STRING tmpHexString2 = NULL;
	ov_string_print(&tmpHexString2, "%i", *(OV_UINT*)packedInputArgList[0]);
	ov_string_print(&tmpHexStringAAS, "%x", tmpHexString2[0]);
	ov_string_setvalue(&tmpHexString2, NULL);

	for (OV_UINT i = 0; i < ov_string_getlength(*(OV_STRING*)(packedInputArgList[1])); i++){
		OV_STRING tmpHexString2 = NULL;
		ov_string_print(&tmpHexString2, "%x", (*(OV_STRING*)(packedInputArgList[1]))[i]);
		ov_string_append(&tmpHexStringAAS, tmpHexString2);
		ov_string_setvalue(&tmpHexString2, NULL);
	}

	OV_INSTPTR_openAASDiscoveryServer_OVDataForAAS pOvDataForAAS = NULL;
	OV_INSTPTR_openAASDiscoveryServer_DiscoveryServer pDiscoveryServer = NULL;
	OV_INSTPTR_subModelDiscovery_SubModelDiscovery pSubModel = NULL;
	OV_INSTPTR_openaasOPCUAInterface_interface pInterface = NULL;
	pSubModel = Ov_StaticPtrCast(subModelDiscovery_SubModelDiscovery, pobj->v_pouterobject);
	pDiscoveryServer = &pSubModel->p_DiscoveryServer;

	pOvDataForAAS = Ov_StaticPtrCast(openAASDiscoveryServer_OVDataForAAS, Ov_SearchChild(ov_containment, Ov_StaticPtrCast(ov_domain, &pDiscoveryServer->p_AASIDs), tmpHexStringAAS));
	if(pOvDataForAAS){
		OV_STRING ksinfo = NULL;
		ov_string_setvalue(&ksinfo, "KS:");
		ov_string_append(&ksinfo, pOvDataForAAS->v_ServerHost);
		ov_string_append(&ksinfo, ":7509/");
		ov_string_append(&ksinfo, pOvDataForAAS->v_ServerName);
		// delete .Componentmanager
		OV_STRING tmpString = NULL;
		OV_STRING *pList = NULL;
		OV_UINT len = 0;
		pList = ov_string_split(pOvDataForAAS->v_Path, ".", &len);
		ov_string_setvalue(&tmpString, pList[0]);
		if (len > 2){
			for (OV_UINT i = 1; i < len-1; i++){
				ov_string_append(&tmpString, ".");
				ov_string_setvalue(&tmpString, pList[i]);
			}
		}
		ov_string_append(&ksinfo, tmpString);
		ov_string_freelist(pList);

		OV_STRING opcuaInfo = NULL;
		OV_BOOL opcuaFound = FALSE;
		Ov_ForEachChildEx(ov_instantiation, pclass_openaasOPCUAInterface_interface, pInterface, openaasOPCUAInterface_interface){
			if(pInterface){
				ov_string_setvalue(&opcuaInfo, "opc.tcp://");
				ov_string_append(&opcuaInfo, pOvDataForAAS->v_ServerHost);
				ov_string_append(&opcuaInfo, ":16664/ns=");
				OV_STRING tmpString2 = NULL;
				ov_string_print(&tmpString2, "%i", pInterface->v_modelnamespace.index);
				ov_string_append(&opcuaInfo, tmpString2);
				ov_string_setvalue(&tmpString2, NULL);
				ov_string_append(&opcuaInfo, ",Type=String,Identifier=");
				ov_string_append(&opcuaInfo, tmpString);
				opcuaFound = TRUE;
			}
		}
		ov_string_setvalue(&tmpString, NULL);
		if (opcuaFound == TRUE){
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value = ov_database_malloc(2*sizeof(OV_STRING));
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value[0] = NULL;
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value[0] = ov_database_malloc(ov_string_getlength(ksinfo));
			strcpy((*(OV_STRING_VEC*)packedOutputArgList[1]).value[0], ksinfo);
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value[1] = NULL;
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value[1] = ov_database_malloc(ov_string_getlength(opcuaInfo));
			strcpy((*(OV_STRING_VEC*)packedOutputArgList[1]).value[1], opcuaInfo);
			(*(OV_STRING_VEC*)packedOutputArgList[1]).veclen = 2;
			ov_string_setvalue(&status, "KS and OPCUA Com found");
		}else{
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value = ov_database_malloc(1*sizeof(OV_STRING));
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value[0] = NULL;
			(*(OV_STRING_VEC*)packedOutputArgList[1]).value[0] = ov_database_malloc(ov_string_getlength(ksinfo));
			strcpy((*(OV_STRING_VEC*)packedOutputArgList[1]).value[0], ksinfo);
			(*(OV_STRING_VEC*)packedOutputArgList[1]).veclen = 1;
			ov_string_setvalue(&status, "KS Com found");
		}
	}else{

		ov_string_setvalue(&status, "ASSID not found");
	}

	ov_string_setvalue(&tmpHexString, NULL);

	*(OV_STRING*)packedOutputArgList[0] = ov_database_malloc(ov_string_getlength(status)+1);
	strcpy(*(OV_STRING*)packedOutputArgList[0], status);

    return OV_ERR_OK;
}


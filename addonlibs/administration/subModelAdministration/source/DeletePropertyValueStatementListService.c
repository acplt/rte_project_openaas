
/******************************************************************************
*
*   FILE
*   ----
*   DeletePropertyValueStatementListService.c
*
*   History
*   -------
*   2017-10-13   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_subModelAdministration
#define OV_COMPILE_LIBRARY_subModelAdministration
#endif


#include "subModelAdministration.h"
#include "libov/ov_macros.h"
#include "helper.h"

OV_DLLFNCEXPORT OV_RESULT subModelAdministration_DeletePropertyValueStatementListService_CallMethod(      
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

	OV_INSTPTR_ov_object pParent = NULL;
	IdentificationType pvslId;
	IdentificationType_init(&pvslId);
	OV_STRING status = NULL;
	OV_UINT result = 0;

	packedOutputArgList[0] = ov_database_malloc(sizeof(OV_STRING));
	*(OV_STRING*)packedOutputArgList[0] = NULL;
	typeArray[0] = OV_VT_STRING;

	if (*(OV_UINT*)packedInputArgList[1] != 0){
		ov_string_setvalue(&status, "Only Uri as identifier are implemented");
		goto FINALIZE;
	}

	pParent = ov_path_getobjectpointer(*(OV_STRING*)(packedInputArgList[0]), 2);
	if (pParent == NULL){
		ov_string_setvalue(&status, "Find no Object for PVSLId");
		goto FINALIZE;
	}

	result = (OV_UINT)checkForSameAAS(Ov_PtrUpCast(ov_object, pobj), pParent);
	if (result != OV_ERR_OK){
		ov_string_setvalue(&status, "PVSL is not in the same AAS as the method");
		goto FINALIZE;
	}

	ov_string_setvalue(&pvslId.IdSpec, *(OV_STRING*)(packedInputArgList[0]));
	pvslId.IdType = *(OV_UINT*)(packedInputArgList[1]);

	result = propertyValueStatement_modelmanager_deletePVSL(pvslId);
	ov_string_setvalue(&status, ov_result_getresulttext(result));

	FINALIZE:

	*(OV_STRING*)packedOutputArgList[0] = ov_database_malloc(ov_string_getlength(status)+1);
	strcpy(*(OV_STRING*)packedOutputArgList[0], status);
	IdentificationType_deleteMembers(&pvslId);

	return OV_ERR_OK;
}


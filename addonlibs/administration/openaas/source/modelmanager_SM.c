/******************************************************************************
 *
 *   FILE
 *   ----
 *   nodeStoreFunctions.c
 *
 *   History
 *   -------
 *   2014-10-21   File created
 *
 *******************************************************************************
 *
 *   This file is generated by the 'acplt_builder' command
 *
 ******************************************************************************/

#ifndef OV_COMPILE_LIBRARY_openaas
#define OV_COMPILE_LIBRARY_openaas
#endif

#include "openaas.h"


OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMAASIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_SMAASIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMAASIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_SMAASIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMParentIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_SMParentIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMParentIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_SMParentIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMModelIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_SMModelIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMModelIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_SMModelIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMName_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_SMName,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMRevision_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_SMRevision = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMVersion_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_SMVersion = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_SMIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_SMIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMCreate_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_BOOL  value
) {
	AASStatusCode result = AASSTATUSCODE_GOOD;
	pobj->v_SMCreate = value;
	if (pobj->v_SMCreate == TRUE){
		IdentificationType tmpAASId;
		tmpAASId.IdSpec = pobj->v_SMAASIdString;
		tmpAASId.IdType = pobj->v_SMAASIdType;

		IdentificationType tmpParentId;
		tmpParentId.IdSpec = pobj->v_SMParentIdString;
		tmpParentId.IdType = pobj->v_SMParentIdType;

		IdentificationType tmpModelId;
		tmpModelId.IdSpec = pobj->v_SMModelIdString;
		tmpModelId.IdType = pobj->v_SMModelIdType;

		result = openaas_modelmanager_createSubModel(tmpAASId, tmpParentId, tmpModelId, pobj->v_SMName, pobj->v_SMRevision, pobj->v_SMVersion);

	}
	pobj->v_AASStatus = result;
    pobj->v_SMCreate = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_SMDelete_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_BOOL  value
) {
	AASStatusCode result = AASSTATUSCODE_GOOD;
	pobj->v_SMDelete = value;
	if (pobj->v_SMDelete == TRUE){
		IdentificationType tmpAASId;
		tmpAASId.IdSpec = pobj->v_SMAASIdString;
		tmpAASId.IdType = pobj->v_SMAASIdType;

		IdentificationType tmpSMId;
		tmpSMId.IdSpec = pobj->v_SMIdString;
		tmpSMId.IdType = pobj->v_SMIdType;
		result = openaas_modelmanager_deleteSubModel(tmpAASId,tmpSMId);
	}
	pobj->v_SMDelete = FALSE;
	pobj->v_AASStatus = result;
    return OV_ERR_OK;
}


OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_createSubModel(IdentificationType aasId, IdentificationType parentID, IdentificationType modelId, OV_STRING smName, OV_UINT revision, OV_UINT version){
	OV_RESULT result = OV_ERR_OK;
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_openaas_SubModel pSubModel = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	OV_INSTPTR_ov_object ptr3 = NULL;
	OV_INSTPTR_ov_object ptr4 = NULL;
	OV_BOOL parentIsInAAS = FALSE;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			if (parentID.IdType != URI){
				return AASSTATUSCODE_BADSMID;
			}
			ptr2 = ov_path_getobjectpointer(parentID.IdSpec, 2);
			if (!ptr2)
				return AASSTATUSCODE_BADSMID;

			ptr3 = Ov_StaticPtrCast(ov_object, Ov_GetParent(ov_containment, ptr2));
			if (!ptr3){
				ptr3 = ptr2->v_pouterobject;
			}
			if (!ptr3){
				return AASSTATUSCODE_BADSMID;
			}
			do{
				if (paas == Ov_StaticPtrCast(openaas_aas, ptr3)){
					parentIsInAAS = TRUE;
					break;
				}
				ptr4 = Ov_StaticPtrCast(ov_object, Ov_GetParent(ov_containment, ptr3));
				if (!ptr4){
					ptr4 = ptr3->v_pouterobject;
				}
				ptr3 = ptr4;
			}while (ptr3);

			if (parentIsInAAS == FALSE){
				return AASSTATUSCODE_BADSMID;
			}

			result = Ov_CreateObject(openaas_SubModel, pSubModel, Ov_StaticPtrCast(ov_domain, ptr2), smName);
			if(Ov_Fail(result)){
				ov_logfile_error("Fatal: could not create SubModel object - reason: %s", ov_result_getresulttext(result));
				return openaas_modelmanager_ovresultToAASStatusCode(result);
			}

			ov_string_setvalue(&pSubModel->v_ModelIdString, modelId.IdSpec);
			pSubModel->v_ModelIdType = modelId.IdType;
			pSubModel->v_Revision = revision;
			pSubModel->v_Version = version;
		}else{
			return AASSTATUSCODE_BADAASID;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}


OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_deleteSubModel(IdentificationType aasId, IdentificationType smId) {
	OV_RESULT result = OV_ERR_OK;
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_openaas_SubModel pSubModel = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	OV_INSTPTR_ov_object ptr3 = NULL;
	OV_INSTPTR_ov_object ptr4 = NULL;
	OV_BOOL SMIsInAAS = FALSE;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			if (smId.IdType != URI){
				return AASSTATUSCODE_BADSMID;
			}
			ptr2 = ov_path_getobjectpointer(smId.IdSpec, 2);
			if (!ptr2)
				return AASSTATUSCODE_BADSMID;

			ptr3 = Ov_StaticPtrCast(ov_object, Ov_GetParent(ov_containment, ptr2));
			if (!ptr3){
				ptr3 = ptr2->v_pouterobject;
			}
			do{
				if (paas == Ov_StaticPtrCast(openaas_aas, ptr3)){
					SMIsInAAS = TRUE;
					break;
				}
				ptr4 = Ov_StaticPtrCast(ov_object, Ov_GetParent(ov_containment, ptr3));
				if (!ptr4){
					ptr4 = ptr3->v_pouterobject;
				}
				ptr3 = ptr4;
			}while (ptr3);

			if (SMIsInAAS == FALSE){
				return AASSTATUSCODE_BADSMID;
			}

			pSubModel = Ov_StaticPtrCast(openaas_SubModel, ptr2);
			if (pSubModel){
				result = Ov_DeleteObject(pSubModel);
				if(Ov_Fail(result)){
					ov_logfile_error("Fatal: could not delete SubModel object - reason: %s", ov_result_getresulttext(result));
					return openaas_modelmanager_ovresultToAASStatusCode(result);
				}
			}else{
				return AASSTATUSCODE_BADUNEXPECTEDERROR;
			}
		}else{
			return AASSTATUSCODE_BADAASID;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}


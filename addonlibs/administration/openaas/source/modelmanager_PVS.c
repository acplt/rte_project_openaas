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
#include "libov/ov_macros.h"
#include "libov/ov_result.h"
#include "openaas_helpers.h"


OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSAASIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSAASIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSAASIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_PVSAASIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSListIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSListIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSListIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_PVSListIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSName_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSName,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSValue_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_PVSValue, value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSMask_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_PVSMask = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSCarrierIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSCarrierIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSCarrierIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_PVSCarrierIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSExpressionLogic_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_INT  value
) {
    pobj->v_PVSExpressionLogic = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSExpressionSemantic_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_INT  value
) {
    pobj->v_PVSExpressionSemantic = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSPropertyIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSPropertyIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSPropertyIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_PVSPropertyIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSView_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_INT  value
) {
    pobj->v_PVSView = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSVisibility_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_INT  value
) {
    pobj->v_PVSVisibility = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_PVSIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSCreate_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_BOOL  value
) {
	AASStatusCode result = AASSTATUSCODE_GOOD;
	pobj->v_PVSCreate = value;
	if (pobj->v_PVSCreate == TRUE){
		IdentificationType tmpAASId;
		tmpAASId.IdSpec = pobj->v_PVSAASIdString;
		tmpAASId.IdType = pobj->v_PVSAASIdType;

		IdentificationType tmpListId;
		tmpListId.IdSpec = pobj->v_PVSListIdString;
		tmpListId.IdType = pobj->v_PVSListIdType;

		IdentificationType tmpCarrierId;
		tmpCarrierId.IdSpec = pobj->v_PVSCarrierIdString;
		tmpCarrierId.IdType = pobj->v_PVSCarrierIdType;

		IdentificationType tmpPropertyId;
		tmpPropertyId.IdSpec = pobj->v_PVSPropertyIdString;
		tmpPropertyId.IdType = pobj->v_PVSPropertyIdType;

		result = openaas_modelmanager_createPVS(tmpAASId, tmpListId, pobj->v_PVSName, pobj->v_PVSValue, pobj->v_PVSMask, tmpCarrierId, pobj->v_PVSExpressionLogic, pobj->v_PVSExpressionSemantic, tmpPropertyId, pobj->v_PVSView, pobj->v_PVSVisibility);
	}
	pobj->v_PVSCreate = FALSE;
	pobj->v_PVSStatus = result;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_PVSDelete_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_BOOL  value
) {
	AASStatusCode result = AASSTATUSCODE_GOOD;
	pobj->v_PVSDelete = value;
	if (pobj->v_PVSDelete == TRUE){
		IdentificationType tmpAASId;
		tmpAASId.IdSpec = pobj->v_PVSAASIdString;
		tmpAASId.IdType = pobj->v_PVSAASIdType;

		IdentificationType tmpPVSId;
		tmpPVSId.IdSpec = pobj->v_PVSIdString;
		tmpPVSId.IdType = pobj->v_PVSIdType;

		result = openaas_modelmanager_deletePVS(tmpAASId, tmpPVSId);
	}
	pobj->v_PVSDelete = FALSE;
	pobj->v_PVSStatus = result;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_createPVS(IdentificationType aasId, IdentificationType listId, OV_STRING pvsName, OV_ANY value, OV_UINT mask, IdentificationType carrierId, ExpressionLogicEnum expressionLogic, ExpressionSemanticEnum expressionSemantic, IdentificationType propertyId, ViewEnum view, VisibilityEnum visibility) {
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	OV_INSTPTR_ov_domain ptr3 = NULL;
	OV_BOOL listIsInAAS = FALSE;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			if (listId.IdType != URI){
				return AASSTATUSCODE_BADPARENTID;
			}
			ptr2 = ov_path_getobjectpointer(listId.IdSpec, 2);
			if (ptr2)
				return AASSTATUSCODE_BADPARENTID;

			ptr3 = Ov_GetParent(ov_containment, ptr2);
			do{
				if (paas == Ov_StaticPtrCast(openaas_aas, ptr3)){
					listIsInAAS = TRUE;
					break;
				}
				ptr3 = Ov_GetParent(ov_containment, ptr3);
			}while (ptr3);

			if (listIsInAAS == FALSE){
				return AASSTATUSCODE_BADPARENTID;
			}

		if (propertyValueStatement_modelmanager_createPVS(listId, pvsName, value, mask, carrierId, expressionLogic, expressionSemantic, propertyId, view, visibility) != PVSSTATUSCODE_GOOD)
			return AASSTATUSCODE_BADPVSERROR;
		}else{
			return AASSTATUSCODE_BADAASID;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}

OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_deletePVS(IdentificationType aasId, IdentificationType pvsId) {
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	OV_INSTPTR_ov_domain ptr3 = NULL;
	OV_BOOL pvsIsInAAS = FALSE;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			if (pvsId.IdType != URI){
				return AASSTATUSCODE_BADPVSLID;
			}
			ptr2 = ov_path_getobjectpointer(pvsId.IdSpec, 2);
			if (ptr2)
				return AASSTATUSCODE_BADPVSLID;

			ptr3 = Ov_GetParent(ov_containment, ptr2);
			do{
				if (paas == Ov_StaticPtrCast(openaas_aas, ptr3)){
					pvsIsInAAS = TRUE;
					break;
				}
				ptr3 = Ov_GetParent(ov_containment, ptr3);
			}while (ptr3);

			if (pvsIsInAAS == FALSE){
				return AASSTATUSCODE_BADPVSLID;
			}

		if (propertyValueStatement_modelmanager_deletePVS(pvsId) != PVSSTATUSCODE_GOOD)
			return AASSTATUSCODE_BADPVSERROR;
		}else{
			return AASSTATUSCODE_BADAASID;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}


OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_getPVS(IdentificationType aasId, IdentificationType pvsId, OV_STRING *pvsName, IdentificationType *carrierId, ExpressionLogicEnum *expressionLogic, ExpressionSemanticEnum *expressionSemantic, IdentificationType *propertyId, ViewEnum *view, VisibilityEnum *visibility, OV_ANY *value) {
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	OV_INSTPTR_ov_domain ptr3 = NULL;
	OV_BOOL pvsIsInAAS = FALSE;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			if (pvsId.IdType != URI){
				return AASSTATUSCODE_BADPARENTID;
			}
			ptr2 = ov_path_getobjectpointer(pvsId.IdSpec, 2);
			if (ptr2)
				return AASSTATUSCODE_BADPARENTID;

			ptr3 = Ov_GetParent(ov_containment, ptr2);
			do{
				if (paas == Ov_StaticPtrCast(openaas_aas, ptr3)){
					pvsIsInAAS = TRUE;
					break;
				}
				ptr3 = Ov_GetParent(ov_containment, ptr3);
			}while (ptr3);

			if (pvsIsInAAS == FALSE){
				return AASSTATUSCODE_BADPARENTID;
			}

		if (propertyValueStatement_modelmanager_getPVS(pvsId, pvsName, carrierId, expressionLogic, expressionSemantic, propertyId, view, visibility, value) != PVSSTATUSCODE_GOOD)
			return AASSTATUSCODE_BADPVSERROR;
		}else{
			return AASSTATUSCODE_BADAASID;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}

OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_setPVS(IdentificationType aasId, IdentificationType pvsId, OV_UINT mask, OV_STRING pvsName, IdentificationType carrierId, ExpressionLogicEnum expressionLogic, ExpressionSemanticEnum expressionSemantic, IdentificationType propertyId, ViewEnum view, VisibilityEnum visibility, OV_ANY value) {
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	OV_INSTPTR_ov_domain ptr3 = NULL;
	OV_BOOL pvsIsInAAS = FALSE;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			if (pvsId.IdType != URI){
				return AASSTATUSCODE_BADPARENTID;
			}
			ptr2 = ov_path_getobjectpointer(pvsId.IdSpec, 2);
			if (ptr2)
				return AASSTATUSCODE_BADPARENTID;

			ptr3 = Ov_GetParent(ov_containment, ptr2);
			do{
				if (paas == Ov_StaticPtrCast(openaas_aas, ptr3)){
					pvsIsInAAS = TRUE;
					break;
				}
				ptr3 = Ov_GetParent(ov_containment, ptr3);
			}while (ptr3);

			if (pvsIsInAAS == FALSE){
				return AASSTATUSCODE_BADPARENTID;
			}

		if (propertyValueStatement_modelmanager_setPVS(pvsId, mask, pvsName, carrierId, expressionLogic, expressionSemantic, propertyId, view, visibility, value) != PVSSTATUSCODE_GOOD)
			return AASSTATUSCODE_BADPVSERROR;
		}else{
			return AASSTATUSCODE_BADAASID;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}

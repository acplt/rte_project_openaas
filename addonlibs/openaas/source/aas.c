
/******************************************************************************
*
*   FILE
*   ----
*   aas.c
*
*   History
*   -------
*   2016-12-16   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_openaas
#define OV_COMPILE_LIBRARY_openaas
#endif

#if OV_SYSEM_NT == 1
#include <windows.h>
#elif OV_SYSTEM_LINUX == 1
#include <unistd.h>
#endif

#include "openaas.h"
#include "libov/ov_macros.h"
#include "openaas_helpers.h"
#include "jsonparsing.h"

extern OV_INSTPTR_openaas_nodeStoreFunctions pNodeStoreFunctions;


OV_DLLFNCEXPORT OV_RESULT openaas_aas_postoffice_set(
    OV_INSTPTR_openaas_aas          pobj,
    const OV_STRING  value
) {
	OV_RESULT resultOV = OV_ERR_OK;
	AASStatusCode result = AASSTATUSCODE_GOOD;

	// Save the Message in the object
	resultOV = ov_string_setvalue(&pobj->v_postoffice,value);
	if (resultOV)
		return resultOV;

	if (ov_string_compare(value, "") == OV_STRCMP_EQUAL){
		pobj->v_result = OV_ERR_OK;
		return OV_ERR_OK;
	}

	// Decoding the Message
	SRV_String *srvStringReceive = SRV_String_new();
	srvStringReceive->data = malloc(ov_string_getlength(value)*sizeof(char));
	memcpy(srvStringReceive->data, value, ov_string_getlength(value)*sizeof(char));
	srvStringReceive->length = ov_string_getlength(value);
	SRV_msgHeader *headerReceive = NULL;
	void *srvStructReceive = NULL;
	SRV_service_t srvTypeReceive;
	SRV_encoding_t encoding;
	resultOV = decodeMSG(srvStringReceive, &headerReceive, &srvStructReceive, &srvTypeReceive, &encoding);
	if (resultOV){
		SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
		SRV_msgHeader_t_delete(headerReceive);
		SRV_String_delete(srvStringReceive);
		pobj->v_result = resultOV;
		return OV_ERR_OK;
	}

	// For encoding the message
	SRV_String *srvStringSend = SRV_String_new();
	SRV_msgHeader *headerSend = SRV_msgHeader_t_new();
	void *srvStructSend = NULL;
	SRV_service_t srvTypeSend;

	// check the message
	IdentificationType sender;
	IdentificationType_init(&sender);
	ov_string_setvalue(&sender.IdSpec, headerReceive->sender.idSpec.data);
	sender.IdType = headerReceive->sender.idType;

	IdentificationType receiver;
	IdentificationType_init(&receiver);
	ov_string_setvalue(&receiver.IdSpec, headerReceive->receiver.idSpec.data);
	receiver.IdType = headerReceive->receiver.idType;

	IdentificationType aasId;
	IdentificationType_init(&aasId);
	ov_string_setvalue(&aasId.IdSpec, pobj->p_Header.p_Config.v_CarrierIdString);
	aasId.IdType = pobj->p_Header.p_Config.v_CarrierIdType;



	if (IdentificationTypeEqual(&receiver, &aasId)){ // MSG is for this AAS
		headerSend = SRV_msgHeader_t_reverseCopy(headerReceive);
		switch (srvTypeReceive){
		case SRV_createAASReq:{
			if (ov_string_compare(pobj->v_identifier, "ComCo") == OV_STRCMP_EQUAL){ // This AAS is the ComCo
				createAASReq_t *createAASReq = (createAASReq_t*)srvStructReceive;

				IdentificationType tmpOVAASId;
				IdentificationType_init(&tmpOVAASId);
				ov_string_setvalue(&tmpOVAASId.IdSpec, createAASReq->aasId.idSpec.data);
				tmpOVAASId.IdType = createAASReq->aasId.idType;

				OV_STRING tmpOVName = NULL;
				ov_string_setvalue(&tmpOVName, createAASReq->aasName.data);

				IdentificationType tmpOVAssetId;
				IdentificationType_init(&tmpOVAssetId);
				ov_string_setvalue(&tmpOVAssetId.IdSpec, createAASReq->assetId.idSpec.data);
				tmpOVAssetId.IdType = createAASReq->assetId.idType;

				result = openaas_modelmanager_createAAS(tmpOVAASId, tmpOVName, tmpOVAssetId);

				createAASRsp_t createAASRsp;
				createAASRsp_t_init(&createAASRsp);

				createAASRsp.status = result;

				srvStructSend = &createAASRsp;
				srvTypeSend = SRV_createAASRsp;

				resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

				createAASRsp_t_deleteMembers(&createAASRsp);
				IdentificationType_deleteMembers(&tmpOVAASId);
				IdentificationType_deleteMembers(&tmpOVAssetId);
				free(tmpOVName);
			}else{
				createAASRsp_t createAASRsp;
				createAASRsp_t_init(&createAASRsp);

				createAASRsp.status = AASSTATUSCODE_BADAASID;

				srvStructSend = &createAASRsp;
				srvTypeSend = SRV_createAASRsp;

				resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

				createAASRsp_t_deleteMembers(&createAASRsp);
			}
		}break;
		case SRV_createAASRsp:{
			// TODO: Check the answer
		}break;
		case SRV_deleteAASReq:{
			if (ov_string_compare(pobj->v_identifier, "ComCo") == OV_STRCMP_EQUAL){ // This AAS is the ComCo
				deleteAASReq_t *deleteAASReq = (deleteAASReq_t*)srvStructReceive;

				IdentificationType tmpOVAASId;
				IdentificationType_init(&tmpOVAASId);
				ov_string_setvalue(&tmpOVAASId.IdSpec, deleteAASReq->aasId.idSpec.data);
				tmpOVAASId.IdType = deleteAASReq->aasId.idType;


				result = openaas_modelmanager_deleteAAS(tmpOVAASId);

				deleteAASRsp_t deleteAASRsp;
				deleteAASRsp_t_init(&deleteAASRsp);

				deleteAASRsp.status = result;

				srvStructSend = &deleteAASRsp;
				srvTypeSend = SRV_deleteAASRsp;

				resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

				deleteAASRsp_t_deleteMembers(&deleteAASRsp);
				IdentificationType_deleteMembers(&tmpOVAASId);
			}else{
				deleteAASRsp_t deleteAASRsp;
				deleteAASRsp_t_init(&deleteAASRsp);

				deleteAASRsp.status = AASSTATUSCODE_BADAASID;

				srvStructSend = &deleteAASRsp;
				srvTypeSend = SRV_deleteAASRsp;

				resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

				deleteAASRsp_t_deleteMembers(&deleteAASRsp);
			}
		}break;
		case SRV_deleteAASRsp:{
			// TODO: Check the answer
		}break;
		case SRV_createPVSLReq:{
			createPVSLReq_t *createPVSLReq = (createPVSLReq_t*)srvStructReceive;

			OV_STRING tmpOVPVSLName = NULL;
			ov_string_setvalue(&tmpOVPVSLName, createPVSLReq->pvslName.data);

			IdentificationType tmpOVCarrier;
			IdentificationType_init(&tmpOVCarrier);
			ov_string_setvalue(&tmpOVCarrier.IdSpec, createPVSLReq->carrier.idSpec.data);
			tmpOVCarrier.IdType = createPVSLReq->carrier.idType;

			IdentificationType tmpOVCreatingInstance;
			IdentificationType_init(&tmpOVCreatingInstance);
			ov_string_setvalue(&tmpOVCreatingInstance.IdSpec, createPVSLReq->carrier.idSpec.data);
			tmpOVCreatingInstance.IdType = createPVSLReq->carrier.idType;

			result = openaas_modelmanager_createPVSL(aasId, tmpOVPVSLName, tmpOVCarrier, tmpOVCreatingInstance);

			createPVSLRsp_t createPVSLRsp;
			createPVSLRsp_t_init(&createPVSLRsp);

			createPVSLRsp.status = result;

			srvStructSend = &createPVSLRsp;
			srvTypeSend = SRV_createPVSLRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			createPVSLRsp_t_deleteMembers(&createPVSLRsp);
			IdentificationType_deleteMembers(&tmpOVCarrier);
			free(tmpOVPVSLName);
		}break;
		case SRV_createPVSLRsp:{
			// TODO: Check the answer
		}break;
		case SRV_deletePVSLReq:{
			deletePVSLReq_t *deletePVSLReq = (deletePVSLReq_t*)srvStructReceive;

			OV_STRING tmpOVPVSLName = NULL;
			ov_string_setvalue(&tmpOVPVSLName, deletePVSLReq->pvslName.data);

			result = openaas_modelmanager_deletePVSL(aasId, tmpOVPVSLName);

			deletePVSLRsp_t deletePVSLRsp;
			deletePVSLRsp_t_init(&deletePVSLRsp);

			deletePVSLRsp.status = result;

			srvStructSend = &deletePVSLRsp;
			srvTypeSend = SRV_deletePVSLRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			deletePVSLRsp_t_deleteMembers(&deletePVSLRsp);
			ov_database_free(tmpOVPVSLName);
		}break;
		case SRV_deletePVSLRsp:{
			// TODO: Check the answer
		}break;
		case SRV_createLCEReq:{
			createLCEReq_t *createLCEReq = (createLCEReq_t*)srvStructReceive;

			LifeCycleEntry lce;
			LifeCycleEntry_init(&lce);

			ov_string_setvalue(&lce.creatingInstance.IdSpec, createLCEReq->lce.creatingInstance.idSpec.data);
			lce.creatingInstance.IdType = createLCEReq->lce.creatingInstance.idType;

			ov_string_setvalue(&lce.writingInstance.IdSpec, createLCEReq->lce.writingInstance.idSpec.data);
			lce.writingInstance.IdType = createLCEReq->lce.writingInstance.idType;

			ov_string_setvalue(&lce.eventClass, createLCEReq->lce.eventClass.data);

			ov_string_setvalue(&lce.subject, createLCEReq->lce.subject.data);

			serviceValueToOVDataValue(&lce.data, createLCEReq->lce.dataType, createLCEReq->lce.data, createLCEReq->lce.dataTime);

			result = openaas_modelmanager_createLCE(aasId, lce);

			createLCERsp_t createLCERsp;
			createLCERsp_t_init(&createLCERsp);

			createLCERsp.status = result;

			srvStructSend = &createLCERsp;
			srvTypeSend = SRV_createLCERsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			createLCERsp_t_deleteMembers(&createLCERsp);
			LifeCycleEntry_deleteMembers(&lce);
		}break;
		case SRV_createLCERsp:{
			// TODO: Check the answer
		}break;
		case SRV_deleteLCEReq:{
			deleteLCEReq_t *deleteLCEReq = (deleteLCEReq_t*)srvStructReceive;

			OV_UINT64 tmpOVLCEId;
			tmpOVLCEId = deleteLCEReq->lceId;

			result = openaas_modelmanager_deleteLCE(aasId, tmpOVLCEId);

			deleteLCERsp_t deleteLCERsp;
			deleteLCERsp_t_init(&deleteLCERsp);

			deleteLCERsp.status = result;

			srvStructSend = &deleteLCERsp;
			srvTypeSend = SRV_deleteLCERsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			deleteLCERsp_t_deleteMembers(&deleteLCERsp);
		}break;
		case SRV_deleteLCERsp:{
			// TODO: Check the answer
		}break;
		case SRV_setLCEReq:{
			setLCEReq_t *setLCEReq = (setLCEReq_t*)srvStructReceive;

			LifeCycleEntry lce;
			LifeCycleEntry_init(&lce);

			lce.lceId = setLCEReq->lce.lceId;

			ov_string_setvalue(&lce.creatingInstance.IdSpec, setLCEReq->lce.creatingInstance.idSpec.data);
			lce.creatingInstance.IdType = setLCEReq->lce.creatingInstance.idType;

			ov_string_setvalue(&lce.writingInstance.IdSpec, setLCEReq->lce.writingInstance.idSpec.data);
			lce.writingInstance.IdType = setLCEReq->lce.writingInstance.idType;

			ov_string_setvalue(&lce.eventClass, setLCEReq->lce.eventClass.data);

			ov_string_setvalue(&lce.subject, setLCEReq->lce.subject.data);

			serviceValueToOVDataValue(&lce.data, setLCEReq->lce.dataType, setLCEReq->lce.data, setLCEReq->lce.dataTime);
			result = openaas_modelmanager_setLCE(aasId, lce);

			setLCERsp_t setLCERsp;
			setLCERsp_t_init(&setLCERsp);

			setLCERsp.status = result;

			srvStructSend = &setLCERsp;
			srvTypeSend = SRV_setLCERsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			setLCERsp_t_deleteMembers(&setLCERsp);
			LifeCycleEntry_deleteMembers(&lce);
		}break;
		case SRV_setLCERsp:{
			// TODO: Check the answer
		}break;
		case SRV_getLCEReq:{
			getLCEReq_t *getLCEReq = (getLCEReq_t*)srvStructReceive;

			OV_UINT64 tmpOVLCEId;
			tmpOVLCEId = getLCEReq->lceId;

			LifeCycleEntry lce;
			LifeCycleEntry_init(&lce);

			result = openaas_modelmanager_getLCE(aasId, tmpOVLCEId, &lce);

			getLCERsp_t getLCERsp;
			getLCERsp_t_init(&getLCERsp);

			ov_string_setvalue(&getLCERsp.lce.creatingInstance.idSpec.data, lce.creatingInstance.IdSpec);
			getLCERsp.lce.creatingInstance.idType = lce.creatingInstance.IdType;

			ov_string_setvalue(&getLCERsp.lce.writingInstance.idSpec.data, lce.writingInstance.IdSpec);
			getLCERsp.lce.writingInstance.idType = lce.writingInstance.IdType;

			ov_string_setvalue(&getLCERsp.lce.eventClass.data, lce.eventClass);
			getLCERsp.lce.hasEventClass = true;

			ov_string_setvalue(&getLCERsp.lce.subject.data, lce.subject);
			getLCERsp.lce.hasSubject = true;

			OVDataValueToserviceValue(lce.data, &getLCERsp.lce.dataType, &getLCERsp.lce.data, &getLCERsp.lce.dataTime);
			getLCERsp.lce.hastDataTime = true;

			getLCERsp.status = result;

			srvStructSend = &getLCERsp;
			srvTypeSend = SRV_getLCERsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			getLCERsp_t_deleteMembers(&getLCERsp);
			LifeCycleEntry_deleteMembers(&lce);
		}break;
		case SRV_getLCERsp:{
			// TODO: Check the answer
		}break;
		case SRV_createPVSReq:{
			createPVSReq_t *createPVSReq = (createPVSReq_t*)srvStructReceive;

			OV_STRING tmpOVPVSLName = NULL;
			ov_string_setvalue(&tmpOVPVSLName, createPVSReq->pvslName.data);

			PropertyValueStatement pvs;
			PropertyValueStatement_init(&pvs);

			ov_string_setvalue(&pvs.pvsName, createPVSReq->pvs.name.data);

			pvs.ExpressionLogic = createPVSReq->pvs.expressionSemantic;

			pvs.ExpressionSemantic = createPVSReq->pvs.expressionSemantic;

			serviceValueToOVDataValue(&pvs.value, createPVSReq->pvs.valType, createPVSReq->pvs.value, 0);

			ov_string_setvalue(&pvs.unit, createPVSReq->pvs.unit.data);

			ov_string_setvalue(&pvs.ID.IdSpec, createPVSReq->pvs.ID.idSpec.data);
			pvs.ID.IdType = createPVSReq->pvs.ID.idType;

			pvs.view = createPVSReq->pvs.view;

			pvs.Visibility = createPVSReq->pvs.visibility;

			result = openaas_modelmanager_createPVS(aasId, tmpOVPVSLName, pvs);

			createPVSRsp_t createPVSRsp;
			createPVSRsp_t_init(&createPVSRsp);

			createPVSRsp.status = result;

			srvStructSend = &createPVSRsp;
			srvTypeSend = SRV_createPVSRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			createPVSRsp_t_deleteMembers(&createPVSRsp);
			ov_database_free(tmpOVPVSLName);
			PropertyValueStatement_deleteMembers(&pvs);
		}break;
		case SRV_createPVSRsp:{
			// TODO: Check the answer
		}break;
		case SRV_deletePVSReq:{
			deletePVSReq_t *deletePVSReq = (deletePVSReq_t*)srvStructReceive;

			OV_STRING tmpOVPVSLName = NULL;
			ov_string_setvalue(&tmpOVPVSLName, deletePVSReq->pvslName.data);

			OV_STRING tmpOVPVSName = NULL;
			ov_string_setvalue(&tmpOVPVSName, deletePVSReq->pvsName.data);

			result = openaas_modelmanager_deletePVS(aasId, tmpOVPVSLName, tmpOVPVSName);

			deletePVSRsp_t deletePVSRsp;
			deletePVSRsp_t_init(&deletePVSRsp);

			deletePVSRsp.status = result;

			srvStructSend = &deletePVSRsp;
			srvTypeSend = SRV_deletePVSRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			deletePVSRsp_t_deleteMembers(&deletePVSRsp);
			ov_database_free(tmpOVPVSLName);
			ov_database_free(tmpOVPVSName);
		}break;
		case SRV_deletePVSRsp:{
			// TODO: Check the answer
		}break;
		case SRV_setPVSReq:{
			setPVSReq_t *setPVSReq = (setPVSReq_t*)srvStructReceive;

			OV_STRING tmpOVPVSLName = NULL;
			ov_string_setvalue(&tmpOVPVSLName, setPVSReq->pvslName.data);

			PropertyValueStatement pvs;
			PropertyValueStatement_init(&pvs);

			ov_string_setvalue(&pvs.pvsName, setPVSReq->pvs.name.data);

			pvs.ExpressionLogic = setPVSReq->pvs.expressionLogic;

			pvs.ExpressionSemantic = setPVSReq->pvs.expressionSemantic;

			serviceValueToOVDataValue(&pvs.value, setPVSReq->pvs.valType, setPVSReq->pvs.value, 0);

			ov_string_setvalue(&pvs.unit, setPVSReq->pvs.unit.data);

			ov_string_setvalue(&pvs.ID.IdSpec, setPVSReq->pvs.ID.idSpec.data);
			pvs.ID.IdType = setPVSReq->pvs.ID.idType;

			pvs.view = setPVSReq->pvs.view;

			pvs.Visibility = setPVSReq->pvs.visibility;

			result = openaas_modelmanager_createPVS(aasId, tmpOVPVSLName, pvs);

			setPVSRsp_t setPVSRsp;
			setPVSRsp_t_init(&setPVSRsp);

			setPVSRsp.status = result;

			srvStructSend = &setPVSRsp;
			srvTypeSend = SRV_setPVSRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			setPVSRsp_t_deleteMembers(&setPVSRsp);
			ov_database_free(tmpOVPVSLName);
			PropertyValueStatement_deleteMembers(&pvs);
		}break;
		case SRV_setPVSRsp:{
			// TODO: Check the answer
		}break;
		case SRV_getPVSReq:{
			getPVSReq_t *getPVSReq = (getPVSReq_t*)srvStructReceive;

			OV_STRING tmpOVPVSLName = NULL;
			ov_string_setvalue(&tmpOVPVSLName, getPVSReq->pvslName.data);

			OV_STRING tmpOVPVSName = NULL;
			ov_string_setvalue(&tmpOVPVSName, getPVSReq->pvsName.data);

			PropertyValueStatement pvs;
			PropertyValueStatement_init(&pvs);

			result = openaas_modelmanager_getPVS(aasId, tmpOVPVSLName, tmpOVPVSName, &pvs);

			getPVSRsp_t getPVSRsp;
			getPVSRsp_t_init(&getPVSRsp);

			getPVSRsp.pvs.expressionLogic = pvs.ExpressionLogic;

			getPVSRsp.pvs.expressionSemantic = pvs.ExpressionSemantic;

			OVDataValueToserviceValue(pvs.value, &getPVSRsp.pvs.valType, &getPVSRsp.pvs.value, &getPVSRsp.pvs.valTime);

			ov_string_setvalue(&getPVSRsp.pvs.unit.data, pvs.unit);
			getPVSRsp.pvs.hasUnit = true;

			ov_string_setvalue(&getPVSRsp.pvs.ID.idSpec.data, pvs.ID.IdSpec);
			getPVSRsp.pvs.ID.idType = pvs.ID.IdType;

			getPVSRsp.pvs.view = pvs.view;

			getPVSRsp.pvs.visibility = pvs.Visibility;

			getPVSRsp.status = result;

			srvStructSend = &getPVSRsp;
			srvTypeSend = SRV_getPVSRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);

			getPVSRsp_t_deleteMembers(&getPVSRsp);
			ov_database_free(tmpOVPVSLName);
			ov_database_free(tmpOVPVSName);
			PropertyValueStatement_deleteMembers(&pvs);
		}break;
		case SRV_getPVSRsp:{
			// TODO: Check the answer
		}break;
		case SRV_getCoreDataReq:{
			OV_UINT tmpNumber = 0;

			PropertyValueStatementList *ppvs = NULL;

			result = openaas_modelmanager_getCoreData(aasId, &tmpNumber, &ppvs);

			getCoreDataRsp_t getCoreDataRsp;
			getCoreDataRsp_t_init(&getCoreDataRsp);

			if (result){
				getCoreDataRsp.status = result;
			}else{
				getCoreDataRsp.numPvsl = tmpNumber;
				getCoreDataRsp.pvsl = malloc(sizeof(PVSL_t)*tmpNumber);
				for (OV_UINT i = 0; i < tmpNumber; i++){
					SRV_String_setCopy(&getCoreDataRsp.pvsl[i].carrier.idSpec, ppvs[i].Carrier.IdSpec, ov_string_getlength(ppvs[i].Carrier.IdSpec));
					getCoreDataRsp.pvsl[i].carrier.idType = ppvs[i].Carrier.IdType;
					SRV_String_setCopy(&getCoreDataRsp.pvsl[i].creatingInstance.idSpec, ppvs[i].CreatingInstance.IdSpec, ov_string_getlength(ppvs[i].CreatingInstance.IdSpec));
					getCoreDataRsp.pvsl[i].creatingInstance.idType = ppvs[i].CreatingInstance.IdType;
					getCoreDataRsp.pvsl[i].creationTime = ov_ovTimeTo1601nsTime(ppvs[i].CreationTime);
					getCoreDataRsp.pvsl[i].hasCreationTime = true;
					SRV_String_setCopy(&getCoreDataRsp.pvsl[i].name, ppvs[i].pvslName, ov_string_getlength(ppvs[i].pvslName));
					getCoreDataRsp.pvsl[i].hasName = true;
					getCoreDataRsp.pvsl[i].numPvs = ppvs[i].pvsNumber;
					getCoreDataRsp.pvsl[i].pvs = malloc(sizeof(PVS_t)*ppvs[i].pvsNumber);
					for (OV_UINT j = 0; j < ppvs[i].pvsNumber; j++){
						getCoreDataRsp.pvsl[i].pvs[j].expressionLogic = ppvs[i].pvs[j].ExpressionLogic;
						getCoreDataRsp.pvsl[i].pvs[j].expressionSemantic = ppvs[i].pvs[j].ExpressionSemantic;
						SRV_String_setCopy(&getCoreDataRsp.pvsl[i].pvs[j].ID.idSpec, ppvs[i].pvs[j].ID.IdSpec, ov_string_getlength(ppvs[i].pvs[j].ID.IdSpec));
						getCoreDataRsp.pvsl[i].pvs[j].ID.idType = ppvs[i].pvs[j].ID.IdType;
						SRV_String_setCopy(&getCoreDataRsp.pvsl[i].pvs[j].name, ppvs[i].pvs[j].pvsName, ov_string_getlength(ppvs[i].pvs[j].pvsName));
						getCoreDataRsp.pvsl[i].pvs[j].hasName = true;
						SRV_String_setCopy(&getCoreDataRsp.pvsl[i].pvs[j].unit, ppvs[i].pvs[j].unit, ov_string_getlength(ppvs[i].pvs[j].unit));
						getCoreDataRsp.pvsl[i].pvs[j].hasUnit = true;
						OVDataValueToserviceValue(ppvs[i].pvs[j].value, &getCoreDataRsp.pvsl[i].pvs[j].valType, &getCoreDataRsp.pvsl[i].pvs[j].value, &getCoreDataRsp.pvsl[i].pvs[j].valTime);
						getCoreDataRsp.pvsl[i].pvs[j].hasValTime = true;
						getCoreDataRsp.pvsl[i].pvs[j].view = ppvs[i].pvs[j].view;
						getCoreDataRsp.pvsl[i].pvs[j].visibility = ppvs[i].pvs[j].Visibility;
						ov_database_free(ppvs[i].pvs[j].ID.IdSpec);
						ov_database_free(ppvs[i].pvs[j].pvsName);
						ov_database_free(ppvs[i].pvs[j].unit);
					}
					ov_database_free(ppvs[i].pvs);
					ov_database_free(ppvs[i].Carrier.IdSpec);
					ov_database_free(ppvs[i].CreatingInstance.IdSpec);
					ov_database_free(ppvs[i].pvslName);
				}
				ov_database_free(ppvs);
			}

			srvStructSend = &getCoreDataRsp;
			srvTypeSend = SRV_getCoreDataRsp;

			resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);
			getCoreDataRsp_t_deleteMembers(&getCoreDataRsp);
		}break;
		case SRV_getCoreDataRsp:{
			getCoreDataRsp_t *getCoreDataRsp = (getCoreDataRsp_t*)srvStructReceive;

			if (!getCoreDataRsp->status){
				for (OV_UINT i = 0; i < getCoreDataRsp->numPvsl; i++){
					OV_STRING tmpOVPVSLName = NULL;
					ov_string_setvalue(&tmpOVPVSLName, getCoreDataRsp->pvsl[i].name.data);

					IdentificationType tmpOVCarrier;
					IdentificationType_init(&tmpOVCarrier);
					ov_string_setvalue(&tmpOVCarrier.IdSpec, getCoreDataRsp->pvsl[i].carrier.idSpec.data);
					tmpOVCarrier.IdType = getCoreDataRsp->pvsl[i].carrier.idType;

					IdentificationType tmpOVCreatingInstance;
					IdentificationType_init(&tmpOVCreatingInstance);
					ov_string_setvalue(&tmpOVCreatingInstance.IdSpec, getCoreDataRsp->pvsl[i].creatingInstance.idSpec.data);
					tmpOVCreatingInstance.IdType = getCoreDataRsp->pvsl[i].creatingInstance.idType;

					OV_TIME tmpOVCreatingTime  = ov_1601nsTimeToOvTime(getCoreDataRsp->pvsl[i].creationTime);

					result = openaas_modelmanager_createPVSLTime(aasId, tmpOVPVSLName, tmpOVCarrier, tmpOVCreatingInstance, tmpOVCreatingTime);
					for (OV_UINT j = 0; j < getCoreDataRsp->pvsl[i].numPvs; j++){
						OV_STRING tmpOVPVSLName = NULL;
						ov_string_setvalue(&tmpOVPVSLName, getCoreDataRsp->pvsl[i].name.data);

						PropertyValueStatement pvs;
						PropertyValueStatement_init(&pvs);

						ov_string_setvalue(&pvs.pvsName, getCoreDataRsp->pvsl[i].pvs[j].name.data);

						pvs.ExpressionLogic = getCoreDataRsp->pvsl[i].pvs[j].expressionSemantic;

						pvs.ExpressionSemantic = getCoreDataRsp->pvsl[i].pvs[j].expressionSemantic;

						serviceValueToOVDataValue(&pvs.value, getCoreDataRsp->pvsl[i].pvs[j].valType, getCoreDataRsp->pvsl[i].pvs[j].value, getCoreDataRsp->pvsl[i].pvs[j].valTime);

						ov_string_setvalue(&pvs.unit, getCoreDataRsp->pvsl[i].pvs[j].unit.data);

						ov_string_setvalue(&pvs.ID.IdSpec, getCoreDataRsp->pvsl[i].pvs[j].ID.idSpec.data);
						pvs.ID.IdType = getCoreDataRsp->pvsl[i].pvs[j].ID.idType;

						pvs.view = getCoreDataRsp->pvsl[i].pvs[j].view;

						pvs.Visibility = getCoreDataRsp->pvsl[i].pvs[j].visibility;

						result = openaas_modelmanager_createPVSTime(aasId, tmpOVPVSLName, pvs);
						PropertyValueStatement_deleteMembers(&pvs);
					}
					ov_database_free(tmpOVPVSLName);
					IdentificationType_deleteMembers(&tmpOVCarrier);
					IdentificationType_deleteMembers(&tmpOVCreatingInstance);
				}
			}

			SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
			SRV_msgHeader_t_delete(headerReceive);
			SRV_String_delete(srvStringReceive);

			SRV_msgHeader_t_delete(headerSend);
			SRV_String_delete(srvStringSend);
			pobj->v_result = resultOV;
			return OV_ERR_OK;
		}break;
		default:
			break;
		}
	}else{ // MSG is for another AAS => forward the MSG to the correct AAS

		srvStructSend = srvStructReceive;
		srvTypeSend = srvTypeReceive;

		headerSend = SRV_msgHeader_t_copy(headerReceive);
		resultOV = encodeMSG(&srvStringSend, headerSend, srvStructSend, srvTypeSend, encoding);
	}

	IdentificationType receiverNew;
	IdentificationType_init(&receiverNew);
	receiverNew.IdType = headerSend->receiver.idType;
	ov_string_setvalue(&receiverNew.IdSpec, headerSend->receiver.idSpec.data);


	// Get the pointer to object for send the Message
	OV_INSTPTR_ksapi_setVar psendAASMessage = NULL;
	Ov_ForEachChildEx(ov_instantiation, pclass_ksapi_setVar, psendAASMessage, ksapi_setVar){
		if(ov_string_compare(psendAASMessage->v_identifier, "SendAASMessage") == OV_STRCMP_EQUAL){
			break;
		}
	}
	OV_INSTPTR_ksapi_KSApiCommon pKSApiSendCommon = Ov_StaticPtrCast(ksapi_KSApiCommon, psendAASMessage);

	if (ov_string_compare(pobj->v_identifier, "ComCo") == OV_STRCMP_EQUAL){ // This AAS is the ComCo
		OV_INSTPTR_ov_object ptr = NULL;
		OV_INSTPTR_openaas_aas paas = NULL;
		ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(receiverNew), 2);
		if(ptr){ // receiverAASId is in this network => directly send message to it
			paas = Ov_StaticPtrCast(openaas_aas, ptr);
			if (paas){
				ov_string_setvalue(&psendAASMessage->v_serverHost, "localhost");
				OV_ANY tmpServername;
				ov_vendortree_getservername(&tmpServername, NULL);
				ov_string_setvalue(&psendAASMessage->v_serverName, tmpServername.value.valueunion.val_string);
				ov_memstack_lock();
				ov_string_setvalue(&psendAASMessage->v_path, ov_path_getcanonicalpath(Ov_PtrUpCast(ov_object, paas), 2));
				ov_string_append(&psendAASMessage->v_path, ".postoffice");
				ov_memstack_unlock();
			}else{
				SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
				SRV_msgHeader_t_delete(headerReceive);
				SRV_msgHeader_t_delete(headerSend);
				SRV_String_delete(srvStringReceive);
				SRV_String_delete(srvStringSend);
				IdentificationType_deleteMembers(&aasId);
				IdentificationType_deleteMembers(&sender);
				IdentificationType_deleteMembers(&receiver);
				pobj->v_result = OV_ERR_BADPATH;
				return OV_ERR_OK;
			}
		}else{ // receiverAASId is not in this network => send it to the ComCo of the receiverAAS network
			// GetAddress of ComCo of the receiverAAS network from AASDiscoveryServer

//			OV_INSTPTR_ksapi_getVar pGetComCoAddressFromAASDiscoveryServer = NULL;
//			Ov_ForEachChildEx(ov_instantiation, pclass_ksapi_getVar, pGetComCoAddressFromAASDiscoveryServer, ksapi_getVar){
//				if(ov_string_compare(pGetComCoAddressFromAASDiscoveryServer->v_identifier, "GetComCoAddressFromAASDiscoveryServer") == OV_STRCMP_EQUAL){
//					break;
//				}
//			}
//			OV_INSTPTR_ksapi_KSApiCommon pKSApiGetCommon = Ov_StaticPtrCast(ksapi_KSApiCommon, pGetComCoAddressFromAASDiscoveryServer);
//
//			OV_INSTPTR_openaas_nodeStoreFunctions pNodeStoreFunctions = NULL;
//			pNodeStoreFunctions = Ov_StaticPtrCast(openaas_nodeStoreFunctions, Ov_GetFirstChild(ov_instantiation, pclass_openaas_nodeStoreFunctions));
//
//
//			// Get ServerHost of ComCo
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_serverHost, pNodeStoreFunctions->v_IPAddressAASDiscoveryServer);
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_serverName, pNodeStoreFunctions->v_ManagerNameAASDiscoveryServer);
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_path, pNodeStoreFunctions->v_PathToAASDiscoveryServer);
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, "/");
//			OV_STRING getComCoAddressMsg = NULL;
//			ov_string_print(&getComCoAddressMsg, "%x", headerSend->receiver.idType);
//			for (OV_UINT i = 0; i < headerSend->receiver.idSpec.length; i++){
//				OV_STRING tmpHexString2 = NULL;
//				ov_string_print(&tmpHexString2, "%x", headerSend->receiver.idSpec.data[i]);
//				ov_string_append(&getComCoAddressMsg, tmpHexString2);
//			}
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, getComCoAddressMsg);
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, ".ServerHost");
//
//			ksapi_KSApiCommon_Reset_set(pKSApiGetCommon, FALSE);
//			ksapi_KSApiCommon_Reset_set(pKSApiGetCommon, TRUE);
//			ksapi_KSApiCommon_Submit_set(pKSApiGetCommon, FALSE);
//			ksapi_KSApiCommon_Submit_set(pKSApiGetCommon, TRUE);
//
//
//			if (pGetComCoAddressFromAASDiscoveryServer->v_status != 2){
//				SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
//				SRV_msgHeader_t_delete(headerReceive);
//				SRV_msgHeader_t_delete(headerSend);
//				SRV_String_delete(srvStringReceive);
//				SRV_String_delete(srvStringSend);
//				IdentificationType_deleteMembers(&aasId);
//				IdentificationType_deleteMembers(&sender);
//				IdentificationType_deleteMembers(&receiver);
//				pobj->v_result = OV_ERR_NOACCESS;
//				return OV_ERR_OK;
//			}
//
//			OV_STRING tmpServerHost = NULL;
//			ov_string_setvalue(&tmpServerHost, pGetComCoAddressFromAASDiscoveryServer->v_varValue.value.valueunion.val_string);
//
//			// Get Manager Name of ComCo
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_serverHost, pNodeStoreFunctions->v_IPAddressAASDiscoveryServer);
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_serverName, pNodeStoreFunctions->v_ManagerNameAASDiscoveryServer);
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_path, pNodeStoreFunctions->v_PathToAASDiscoveryServer);
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, "/");
//			getComCoAddressMsg = NULL;
//			ov_string_print(&getComCoAddressMsg, "%x", headerSend->receiver.idType);
//			for (OV_UINT i = 0; i < headerSend->receiver.idSpec.length; i++){
//				OV_STRING tmpHexString2 = NULL;
//				ov_string_print(&tmpHexString2, "%x", headerSend->receiver.idSpec.data[i]);
//				ov_string_append(&getComCoAddressMsg, tmpHexString2);
//			}
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, getComCoAddressMsg);
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, ".ServerName");
//
//			ksapi_KSApiCommon_Reset_set(pKSApiGetCommon, FALSE);
//			ksapi_KSApiCommon_Reset_set(pKSApiGetCommon, TRUE);
//			ksapi_KSApiCommon_Submit_set(pKSApiGetCommon, FALSE);
//			ksapi_KSApiCommon_Submit_set(pKSApiGetCommon, TRUE);
//
//			if (pGetComCoAddressFromAASDiscoveryServer->v_status != 2){
//				SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
//				SRV_msgHeader_t_delete(headerReceive);
//				SRV_msgHeader_t_delete(headerSend);
//				SRV_String_delete(srvStringReceive);
//				SRV_String_delete(srvStringSend);
//				IdentificationType_deleteMembers(&aasId);
//				IdentificationType_deleteMembers(&sender);
//				IdentificationType_deleteMembers(&receiver);
//				pobj->v_result = OV_ERR_NOACCESS;
//				return OV_ERR_OK;
//			}
//
//			OV_STRING tmpManagereName = NULL;
//			ov_string_setvalue(&tmpManagereName, pGetComCoAddressFromAASDiscoveryServer->v_varValue.value.valueunion.val_string);
//
//			// Get Path of ComCo
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_serverHost, pNodeStoreFunctions->v_IPAddressAASDiscoveryServer);
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_serverName, pNodeStoreFunctions->v_ManagerNameAASDiscoveryServer);
//			ov_string_setvalue(&pGetComCoAddressFromAASDiscoveryServer->v_path, pNodeStoreFunctions->v_PathToAASDiscoveryServer);
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, "/");
//			getComCoAddressMsg = NULL;
//			ov_string_print(&getComCoAddressMsg, "%x", headerSend->receiver.idType);
//			for (OV_UINT i = 0; i < headerSend->receiver.idSpec.length; i++){
//				OV_STRING tmpHexString2 = NULL;
//				ov_string_print(&tmpHexString2, "%x", headerSend->receiver.idSpec.data[i]);
//				ov_string_append(&getComCoAddressMsg, tmpHexString2);
//			}
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, getComCoAddressMsg);
//			ov_string_append(&pGetComCoAddressFromAASDiscoveryServer->v_path, ".Path");
//
//			ksapi_KSApiCommon_Reset_set(pKSApiGetCommon, FALSE);
//			ksapi_KSApiCommon_Reset_set(pKSApiGetCommon, TRUE);
//			ksapi_KSApiCommon_Submit_set(pKSApiGetCommon, FALSE);
//			ksapi_KSApiCommon_Submit_set(pKSApiGetCommon, TRUE);
//
//			if (pGetComCoAddressFromAASDiscoveryServer->v_status != 2){
//				SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
//				SRV_msgHeader_t_delete(headerReceive);
//				SRV_msgHeader_t_delete(headerSend);
//				SRV_String_delete(srvStringReceive);
//				SRV_String_delete(srvStringSend);
//				IdentificationType_deleteMembers(&aasId);
//				IdentificationType_deleteMembers(&sender);
//				IdentificationType_deleteMembers(&receiver);
//				pobj->v_result = OV_ERR_NOACCESS;
//				return OV_ERR_OK;
//			}
//
//			OV_STRING tmpPath = NULL;
//			ov_string_setvalue(&tmpPath, pGetComCoAddressFromAASDiscoveryServer->v_varValue.value.valueunion.val_string);

			// Get the pointer to object for send the Message

			OV_INSTPTR_openaas_ExternalPostOffice pExternalPost = NULL;
			pExternalPost = Ov_StaticPtrCast(openaas_ExternalPostOffice, Ov_GetFirstChild(ov_instantiation, pclass_openaas_ExternalPostOffice));

			ov_string_setvalue(&pExternalPost->v_ReceiverAASIdString, headerSend->receiver.idSpec.data);
			pExternalPost->v_ReceiverAASIdType = headerSend->receiver.idType;
			ov_string_setvalue(&psendAASMessage->v_serverHost, "localhost");
			ov_string_setvalue(&psendAASMessage->v_serverHost, "localhost");
			ov_string_setvalue(&psendAASMessage->v_serverName, "MANAGER");
			ov_string_setvalue(&psendAASMessage->v_path, "/TechUnits/openAAS/AASFolder/ExternalPostOffice.postoffice");
		}
	}else{ // This AAS is not the ComCo => send message to ComCoAAS
		ov_string_setvalue(&psendAASMessage->v_serverHost, "localhost");
		ov_string_setvalue(&psendAASMessage->v_serverName, "MANAGER");
		ov_string_setvalue(&psendAASMessage->v_path, "/TechUnits/openAAS/AASFolder/ComCo.postoffice");
	}

	// send message
	ov_string_setvalue(&psendAASMessage->v_varValue.value.valueunion.val_string, srvStringSend->data);
	psendAASMessage->v_varValue.value.vartype = OV_VT_STRING;

	ksapi_KSApiCommon_Reset_set(pKSApiSendCommon, FALSE);
	ksapi_KSApiCommon_Reset_set(pKSApiSendCommon, TRUE);
	ksapi_KSApiCommon_Submit_set(pKSApiSendCommon, FALSE);
	ksapi_KSApiCommon_Submit_set(pKSApiSendCommon, TRUE);

	ov_string_setvalue(&pobj->v_lastReceivedMessage, srvStringReceive->data);
	ov_string_setvalue(&pobj->v_lastSendMessage, srvStringSend->data);
	ov_string_setvalue(&pobj->v_postoffice,"");

	SRV_serviceGeneric_delete(srvStructReceive, srvTypeReceive);
	SRV_msgHeader_t_delete(headerReceive);
	SRV_msgHeader_t_delete(headerSend);
	SRV_String_delete(srvStringReceive);
	SRV_String_delete(srvStringSend);
	IdentificationType_deleteMembers(&aasId);
	IdentificationType_deleteMembers(&sender);
	IdentificationType_deleteMembers(&receiver);

	pobj->v_result = resultOV;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_ACCESS openaas_aas_getaccess(
	OV_INSTPTR_ov_object	pobj,
	const OV_ELEMENT		*pelem,
	const OV_TICKET			*pticket
) {
    /*
    *   local variables
    */
	return (OV_ACCESS)OV_AC_WRITE | OV_AC_READ | OV_AC_LINKABLE | OV_AC_UNLINKABLE | OV_AC_DELETEABLE | OV_AC_RENAMEABLE;
}


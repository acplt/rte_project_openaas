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

#ifndef OV_COMPILE_LIBRARY_lifeCycleEntryOPCUAInterface
#define OV_COMPILE_LIBRARY_lifeCycleEntryOPCUAInterface
#endif

#include "lifeCycleEntryOPCUAInterface.h"
#include "ov_macros.h"
#include "ksbase.h"
#include "opcua.h"
#include "opcua_helpers.h"
#include "NoneTicketAuthenticator.h"
#include "ov_path.h"
#include "ov_memstack.h"
#include "ks_logfile.h"
#include "nodeset_lifeCycleEntry.h"

extern OV_INSTPTR_lifeCycleEntryOPCUAInterface_interface pinterface;




OV_DLLFNCEXPORT UA_StatusCode lifeCycleEntryOPCUAInterface_interface_ovLifeCycleArchiveNodeToOPCUA(
		void *handle, const UA_NodeId *nodeId, UA_Node** opcuaNode) {
	UA_Node 				*newNode = NULL;
	UA_StatusCode 			result = UA_STATUSCODE_GOOD;
	OV_PATH 				path;
	OV_INSTPTR_ov_object	pobj = NULL;
	OV_TICKET 				*pTicket = NULL;
	OV_VTBLPTR_ov_object	pVtblObj = NULL;
	OV_ACCESS				access;
	UA_NodeClass 			nodeClass;
	OV_ELEMENT				element;

	ov_memstack_lock();
	result = opcua_nodeStoreFunctions_resolveNodeIdToPath(*nodeId, &path);
	if(result != UA_STATUSCODE_GOOD){
		ov_memstack_unlock();
		return result;
	}
	element = path.elements[path.size-1];
	ov_memstack_unlock();
	result = opcua_nodeStoreFunctions_getVtblPointerAndCheckAccess(&(element), pTicket, &pobj, &pVtblObj, &access);
	if(result != UA_STATUSCODE_GOOD){
		return result;
	}

	nodeClass = UA_NODECLASS_OBJECT;
	newNode = (UA_Node*)UA_calloc(1, sizeof(UA_ObjectNode));


	// Basic Attribute
	// BrowseName
	UA_QualifiedName qName;
	qName.name = UA_String_fromChars(pobj->v_identifier);
	qName.namespaceIndex = nodeId->namespaceIndex;
	newNode->browseName = qName;

	// Description
	OV_STRING tempString = pVtblObj->m_getcomment(pobj, &element);
	UA_LocalizedText lText;
	UA_LocalizedText_init(&lText);
	lText.locale = UA_String_fromChars("en");
	if(tempString){
		lText.text = UA_String_fromChars(tempString);
	} else {
		lText.text = UA_String_fromChars("");
	}
	UA_LocalizedText_copy(&lText,&newNode->description);
	UA_LocalizedText_deleteMembers(&lText);

	// DisplayName
	UA_LocalizedText displayName;
	UA_LocalizedText_init(&displayName);
	displayName.locale = UA_String_fromChars("en");
	displayName.text = UA_String_fromChars(pobj->v_identifier);
	UA_LocalizedText_copy(&displayName, &newNode->displayName);
	UA_LocalizedText_deleteMembers(&displayName);

	// NodeId
	UA_NodeId_copy(nodeId, &newNode->nodeId);

	// NodeClass
	newNode->nodeClass 	= nodeClass;

	// WriteMask
	UA_UInt32 writeMask = 0;
	if(element.elemtype != OV_ET_VARIABLE){
		if(access & OV_AC_WRITE){
			writeMask |= (1<<2);	//	BrowseName
			writeMask |= (1<<6);	//	DisplayName
		}
		if(access & OV_AC_RENAMEABLE){
			writeMask |= (1<<14);	//	NodeId
		}
	}
	newNode->writeMask 	= writeMask;

	// Object specific attributes
	((UA_ObjectNode*)newNode)->eventNotifier = 0;



	// References
	UA_Node tmpNode;
	UA_NodeId_copy(nodeId, &tmpNode.nodeId);


	addReference(&tmpNode);
	UA_NodeId tmpNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASTYPEDEFINITION);
	OV_UINT lceCount = 0;
	for (size_t i = 0; i < tmpNode.referencesSize; i++){
		if (UA_NodeId_equal(&tmpNode.references[i].referenceTypeId, &tmpNodeId)){
			tmpNode.references[i].targetId = UA_EXPANDEDNODEID_NUMERIC(pinterface->v_modelnamespace.index, UA_NSLIFECYCLEENTRYID_LIFECYCLEARCHIVETYPE);
		}
		ov_memstack_lock();
		result = opcua_nodeStoreFunctions_resolveNodeIdToPath(tmpNode.references[i].targetId.nodeId, &path);
		if(result != UA_STATUSCODE_GOOD){
			ov_memstack_unlock();
			return result;
		}
		element = path.elements[path.size-1];
		ov_memstack_unlock();
		result = opcua_nodeStoreFunctions_getVtblPointerAndCheckAccess(&(element), pTicket, &pobj, &pVtblObj, &access);
		if(result != UA_STATUSCODE_GOOD){
			return result;
		}

		if (Ov_CanCastTo(lifeCycleEntry_LifeCycleEntry, pobj)){
			lceCount = lceCount + 1;
		}
	}
	UA_NodeId_deleteMembers(&tmpNodeId);

	newNode->referencesSize = tmpNode.referencesSize - lceCount; //For LCEs
	newNode->referencesSize = newNode->referencesSize + 2; //For create/deleteLifeCycleEntry
	newNode->referencesSize = newNode->referencesSize + 1; //For createLifeCycleEntrySimple
	newNode->referencesSize = newNode->referencesSize + 2; //For get/setLifeCycleEntry
	newNode->referencesSize = newNode->referencesSize + 2; //For get/setLifeCycleEntrySimple
	newNode->referencesSize = newNode->referencesSize + 1; //For getLastLCEs
	newNode->referencesSize = newNode->referencesSize + 1; //For LifeCycleEntries
	newNode->references = UA_calloc(newNode->referencesSize, sizeof(UA_ReferenceNode));

	// delete References to LCEs
	OV_UINT newReferenceCount = 0;
	for (size_t i = 0; i < tmpNode.referencesSize; i++){
		ov_memstack_lock();
		result = opcua_nodeStoreFunctions_resolveNodeIdToPath(tmpNode.references[i].targetId.nodeId, &path);
		if(result != UA_STATUSCODE_GOOD){
			ov_memstack_unlock();
			return result;
		}
		element = path.elements[path.size-1];
		ov_memstack_unlock();
		result = opcua_nodeStoreFunctions_getVtblPointerAndCheckAccess(&(element), pTicket, &pobj, &pVtblObj, &access);
		if(result != UA_STATUSCODE_GOOD){
			return result;
		}

		if (!Ov_CanCastTo(lifeCycleEntry_LifeCycleEntry, pobj)){
			UA_NodeId_copy(&(tmpNode.references[i].referenceTypeId), &(newNode->references[newReferenceCount].referenceTypeId));
			UA_ExpandedNodeId_copy(&(tmpNode.references[i].targetId), &(newNode->references[newReferenceCount].targetId));
			newNode->references[newReferenceCount].isInverse = tmpNode.references[i].isInverse;
			newReferenceCount = newReferenceCount + 1;
		}
	}
	UA_Array_delete(tmpNode.references, tmpNode.referencesSize, &UA_TYPES[UA_TYPES_REFERENCENODE]);

	// createLifeCycleEntry
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	OV_STRING tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "createLCE");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// deleteLifeCycleEntry
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "deleteLCE");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// createLifeCycleEntrySimple
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "createLCESimple");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// setLifeCycleEntry
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "setLCE");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// getLifeCycleEntry
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "getLCE");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// setLifeCycleEntrySimple
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "setLCESimple");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// getLifeCycleEntrySimple
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "getLCESimple");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// getLastLifeCycleEntry
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "||");
	ov_string_append(&tmpString, "getLastLCEs");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);
	newReferenceCount = newReferenceCount + 1;

	// LifeCycleEntries
	newNode->references[newReferenceCount].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
	newNode->references[newReferenceCount].isInverse = UA_FALSE;
	tmpString = NULL;
	copyOPCUAStringToOV(nodeId->identifier.string, &tmpString);
	ov_string_append(&tmpString, "|||");
	ov_string_append(&tmpString, "LifeCycleEntries");
	newNode->references[newReferenceCount].targetId = UA_EXPANDEDNODEID_STRING_ALLOC(pinterface->v_interfacenamespace.index, tmpString);
	ov_string_setvalue(&tmpString, NULL);

	*opcuaNode = newNode;
	return UA_STATUSCODE_GOOD;
}


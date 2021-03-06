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

#ifndef OV_COMPILE_LIBRARY_propertyValueStatementOPCUAInterface
#define OV_COMPILE_LIBRARY_propertyValueStatementOPCUAInterface
#endif

#include "propertyValueStatementOPCUAInterface.h"
#include "ov_macros.h"
#include "ksbase.h"
#include "opcua.h"
#include "opcua_helpers.h"
#include "NoneTicketAuthenticator.h"
#include "ov_path.h"
#include "ov_memstack.h"
#include "ks_logfile.h"
#include "nodeset_propertyValueStatement.h"

extern OV_INSTPTR_propertyValueStatementOPCUAInterface_interface pinterface;




OV_DLLFNCEXPORT UA_StatusCode propertyValueStatementOPCUAInterface_interface_ovPropertyValueStatementNodeToOPCUA(
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

	nodeClass = UA_NODECLASS_VARIABLE;
	newNode = (UA_Node*)UA_calloc(1, sizeof(UA_VariableNode));


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

	// Variable specific attributes
	// arrayDemensions
	((UA_VariableNode*)newNode)->arrayDimensionsSize = 0;
	((UA_VariableNode*)newNode)->arrayDimensions = NULL; // UA_Array_new(((UA_VariableNode*)newNode)->arrayDimensionsSize, &UA_TYPES[UA_TYPES_INT32]);	/*	scalar or one dimension	*/

	// value
	OV_ELEMENT tmpPart;
	tmpPart.elemtype = OV_ET_NONE;
	OV_ELEMENT tmpParrent;
	tmpParrent.pobj = pobj;
	tmpParrent.elemtype = OV_ET_OBJECT;
	UA_Variant tmpValue;
	UA_Variant_init(&tmpValue);
	OV_ANY tmpValue2;
	tmpValue2.value.vartype = OV_VT_VOID;
	Ov_SetAnyValue(&tmpValue2, NULL);
	do {
		ov_element_getnextpart(&tmpParrent, &tmpPart, OV_ET_VARIABLE);
		if (tmpPart.elemtype == OV_ET_NONE)
			break;
		if (ov_string_compare(tmpPart.elemunion.pvar->v_identifier, "Value") == OV_STRCMP_EQUAL){
			ov_AnyToVariant((OV_ANY*)tmpPart.pvalue, &tmpValue);
			Ov_SetAnyValue(&tmpValue2, (OV_ANY*)tmpPart.pvalue);
			break;
		}
	} while(TRUE);

	result = ov_AnyToVariant(&tmpValue2, &(((UA_VariableNode*)newNode)->value.data.value.value));
	((UA_VariableNode*)newNode)->value.data.value.hasValue = TRUE;
	((UA_VariableNode*)newNode)->valueSource = UA_VALUESOURCE_DATA;
	((UA_VariableNode*)newNode)->dataType = ov_varTypeToNodeId(tmpValue2.value.vartype);
	Ov_SetAnyValue(&tmpValue2, NULL);
	UA_Variant_deleteMembers(&tmpValue);

	// valuerank
	switch(((OV_ANY*)tmpPart.pvalue)->value.vartype & OV_VT_KSMASK){
	case OV_VT_ANY:
	case OV_VT_VOID:
		((UA_VariableNode*)newNode)->valueRank = -3;	/*	scalar or one dimension	*/
		result = UA_STATUSCODE_GOOD;
		break;
	default:
		if(((OV_ANY*)tmpPart.pvalue)->value.vartype & OV_VT_ISVECTOR){
			((UA_VariableNode*)newNode)->valueRank = 1;	/*	one dimension	*/
			result = UA_STATUSCODE_GOOD;
		} else {
			((UA_VariableNode*)newNode)->valueRank = -1;	/*	scalar	*/
			result = UA_STATUSCODE_GOOD;
		}
		break;
	}


	// accessLevel
	UA_Byte accessLevel = 0;
	if(access & OV_AC_READ){
		accessLevel |= (1<<0);
	}
	if(access & OV_AC_WRITE){
		accessLevel |= (1<<1);
	}
	((UA_VariableNode*)newNode)->accessLevel = accessLevel;
	// minimumSamplingInterval
	((UA_VariableNode*)newNode)->minimumSamplingInterval = -1;
	// historizing
	((UA_VariableNode*)newNode)->historizing = UA_FALSE;


	// References
	addReference(newNode);
	UA_NodeId tmpNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASTYPEDEFINITION);
	for (size_t i = 0; i < newNode->referencesSize; i++){
		if (UA_NodeId_equal(&newNode->references[i].referenceTypeId, &tmpNodeId)){
			newNode->references[i].targetId = UA_EXPANDEDNODEID_NUMERIC(pinterface->v_modelnamespace.index, UA_NSPROPERTYVALUESTATEMENTID_PROPERTYVALUESTATEMENTTYPE);
			continue;
		}
		if (newNode->references[i].targetId.nodeId.namespaceIndex == pinterface->v_interfacenamespace.index){
			newNode->references[i].referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY);
		}
	}
	UA_NodeId_deleteMembers(&tmpNodeId);

	*opcuaNode = newNode;
	return UA_STATUSCODE_GOOD;
}


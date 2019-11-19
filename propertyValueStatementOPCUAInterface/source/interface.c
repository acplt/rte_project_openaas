
/******************************************************************************
*
*   FILE
*   ----
*   interface.c
*
*   History
*   -------
*   2017-06-26   File created
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
#include "ov_result.h"
#include "nodeset_propertyValueStatement.h"
#include "ua_propertyValueStatement_generated.h"

OV_INSTPTR_propertyValueStatementOPCUAInterface_interface pinterface = NULL;

OV_DLLFNCEXPORT OV_RESULT propertyValueStatementOPCUAInterface_interface_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_propertyValueStatementOPCUAInterface_interface pinst = Ov_StaticPtrCast(propertyValueStatementOPCUAInterface_interface, pobj);
    OV_RESULT    result;
	OV_INSTPTR_ov_object pOtherObject = NULL;
	OV_INSTPTR_identificationOPCUAInterface_interface pIdentificationOPCUAInterface = NULL;
	OV_INSTPTR_ov_domain pcommunication = NULL;
	OV_INSTPTR_ov_domain pDomOPCUA = NULL;

    /* do what the base class does first */
    result = ov_object_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */
    Ov_ForEachChild(ov_instantiation, pclass_propertyValueStatementOPCUAInterface_interface, pOtherObject){
		if(pOtherObject != pobj){
			ov_logfile_error("%s: cannot instantiate - interface instance already exists", pinst->v_identifier);
			return OV_ERR_ALREADYEXISTS;
		}
	}

    // create identificationOPCUAInterface
	Ov_ForEachChildEx(ov_instantiation, pclass_identificationOPCUAInterface_interface, pIdentificationOPCUAInterface, identificationOPCUAInterface_interface){
		break;
	}
	if(!pIdentificationOPCUAInterface){
		pcommunication = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, &(pdb->root), "communication"));
		if(!pcommunication) {
			result = Ov_CreateObject(ov_domain, pcommunication, &(pdb->root), "communication");
			if(Ov_Fail(result)) {
				ov_logfile_error("Fatal: Could not create Object 'communication'");
				return result;
			}
		}
		else if(!Ov_CanCastTo(ov_domain, (OV_INSTPTR_ov_object) pcommunication)){
			ov_logfile_error("Fatal: communication object found but not domain (or derived)");
			return OV_ERR_GENERIC;
		}

		pDomOPCUA = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, pcommunication, "opcua"));
		if(!pDomOPCUA) {
			result = Ov_CreateObject(ov_domain, pDomOPCUA, pcommunication, "opcua");
			if(Ov_Fail(result)){
				ov_logfile_error("Fatal: could not create opcua domain");
				return result;
			}
		}
		else if(!Ov_CanCastTo(ov_domain, (OV_INSTPTR_ov_object) pDomOPCUA)){
			ov_logfile_error("Fatal: opcua object found but not domain (or derived)");
			return OV_ERR_GENERIC;
		}
		result = Ov_CreateObject(identificationOPCUAInterface_interface, pIdentificationOPCUAInterface, pDomOPCUA, "IdentificationOPCUAInterface");
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create IdentificationOPCUAInterface");
			return result;
		}
	}

	pinterface = pinst;
	pinst->v_modelnamespaceIndexIdentification = pIdentificationOPCUAInterface->v_modelnamespace.index;

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT void propertyValueStatementOPCUAInterface_interface_startup(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_propertyValueStatementOPCUAInterface_interface pinst = Ov_StaticPtrCast(propertyValueStatementOPCUAInterface_interface, pobj);

    /* do what the base class does first */
    ov_object_startup(pobj);

    /* do what */
    UA_String tmpNamespaceName = UA_String_fromChars("http://acplt.org/propertyValueStatement/");
	UA_Namespace_init(&pinst->v_modelnamespace, &tmpNamespaceName);
	UA_String_deleteMembers(&tmpNamespaceName);
	pinst->v_modelnamespace.dataTypes = UA_PROPERTYVALUESTATEMENT;
	pinst->v_modelnamespace.dataTypesSize = UA_PROPERTYVALUESTATEMENT_COUNT;

	tmpNamespaceName = UA_String_fromChars("http://acplt.org/propertyValueStatement/Ov");
	UA_Namespace_init(&pinst->v_interfacenamespace, &tmpNamespaceName);
	UA_String_deleteMembers(&tmpNamespaceName);
	pinst->v_interfacenamespace.nodestore = propertyValueStatementOPCUAInterface_interface_ovNodeStoreInterfacePropertyValueStatementNew();

	UA_Namespace** nsArray = UA_malloc(2 * sizeof(UA_Namespace*));
	nsArray[0] = &pinst->v_modelnamespace;
	nsArray[1] = &pinst->v_interfacenamespace;

	OV_STRING startFolder[2];
	startFolder[0] = NULL;
	startFolder[1] = NULL;

	// Add InformationModel & NodeStoreInterface & Reference to AASFolder
	UA_StatusCode ret = UA_STATUSCODE_GOOD;
	ret = opcua_uaServer_addInformationModel(nsArray, 2, startFolder, nodeset_returnNamespaces);
	startFolder[1] = NULL;
	if (ret != UA_STATUSCODE_GOOD){
		ov_logfile_error("openaas: Fatal: Couldn't add InformationModel");
		UA_Namespace_deleteMembers(&(pinst->v_modelnamespace));
		UA_Namespace_deleteMembers(&(pinst->v_interfacenamespace));
		return;
	}
	UA_free(nsArray);

    return;
}

OV_DLLFNCEXPORT void propertyValueStatementOPCUAInterface_interface_destructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    //OV_INSTPTR_propertyValueStatementOPCUAInterface_interface pinst = Ov_StaticPtrCast(propertyValueStatementOPCUAInterface_interface, pobj);

    /* do what */

    /* destroy object */
    ov_object_destructor(pobj);

    return;
}

OV_DLLFNCEXPORT OV_ACCESS propertyValueStatementOPCUAInterface_interface_getaccess(
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
					if((pelem->elemunion.pvar->v_varprops & OV_VP_DERIVED)){
						if((pelem->elemunion.pvar->v_varprops & OV_VP_SETACCESSOR)){
							return OV_AC_READWRITE;
						} else {
							return OV_AC_READ;
						}
					} else {
						return OV_AC_READWRITE;
					}
				}
			}
		break;
		default:
		break;
	}

	return ov_object_getaccess(pobj, pelem, pticket);
}


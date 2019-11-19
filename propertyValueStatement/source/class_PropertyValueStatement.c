/******************************************************************************
*
*   FILE
*   ----
*   PropertyValueStatement.c
*
*   History
*   -------
*   2017-06-22   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_propertyValueStatement
#define OV_COMPILE_LIBRARY_propertyValueStatement
#endif


#include "propertyValueStatement.h"
#include "ov_macros.h"


OV_DLLFNCEXPORT OV_ACCESS propertyValueStatement_PropertyValueStatement_getaccess(
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

OV_DLLFNCEXPORT OV_RESULT propertyValueStatement_PropertyValueStatement_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_propertyValueStatement_PropertyValueStatement pinst = Ov_StaticPtrCast(propertyValueStatement_PropertyValueStatement, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = ov_object_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */
    OV_INSTPTR_ov_domain pparent = NULL;
	pparent = Ov_GetParent(ov_containment, pobj);
	if (!Ov_CanCastTo(propertyValueStatement_PropertyValueStatementList, pparent)){
		ov_logfile_error("%s: cannot instantiate - Parent have to be from class propertyValueStatementList", pinst->v_identifier);
		return OV_ERR_ALREADYEXISTS;
	}

	OV_BOOL CarrierIdFound = FALSE;
	OV_BOOL PropertyIdFound = FALSE;
	OV_BOOL ExpressionLogicFound = FALSE;
	OV_BOOL ExpressionSemanticFound = FALSE;
	OV_BOOL ViewFound = FALSE;
	OV_BOOL VisibilityFound = FALSE;
	OV_INSTPTR_ov_object pchild = NULL;
	Ov_ForEachChild(ov_containment, pparent, pchild){
		if (Ov_CanCastTo(propertyValueStatement_CarrierId, pchild)){
			CarrierIdFound = TRUE;
		}else if(Ov_CanCastTo(propertyValueStatement_PropertyId, pchild)){
			PropertyIdFound = TRUE;
		}else if(Ov_CanCastTo(propertyValueStatement_ExpressionLogic, pchild)){
			ExpressionLogicFound = TRUE;
		}else if(Ov_CanCastTo(propertyValueStatement_ExpressionSemantic, pchild)){
			ExpressionSemanticFound = TRUE;
		}else if(Ov_CanCastTo(propertyValueStatement_View, pchild)){
			ViewFound = TRUE;
		}else if(Ov_CanCastTo(propertyValueStatement_Visibility, pchild)){
			VisibilityFound = TRUE;
		}
	}

	if (CarrierIdFound == FALSE){
		//result = Ov_CreateObject(propertyValueStatement_CarrierId, pchild, Ov_DynamicPtrCast(ov_domain, pobj), "CarrierId");
		result = ov_class_createobject(pclass_propertyValueStatement_CarrierId, Ov_DynamicPtrCast(ov_domain, pobj),
				"CarrierId", OV_PMH_DEFAULT,  NULL, NULL, NULL, &pchild);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create CarrierId");
			return result;
		}
	}
	if (PropertyIdFound == FALSE){
		//result = Ov_CreateObject(propertyValueStatement_PropertyId, pchild, Ov_DynamicPtrCast(ov_domain, pobj), "PropertyId");
		result = ov_class_createobject(pclass_propertyValueStatement_PropertyId, Ov_DynamicPtrCast(ov_domain, pobj),
				"PropertyId", OV_PMH_DEFAULT,  NULL, NULL, NULL, &pchild);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create PropertyId");
			return result;
		}
	}
	if (ExpressionLogicFound == FALSE){
		//result = Ov_CreateObject(propertyValueStatement_ExpressionLogic, pchild, Ov_DynamicPtrCast(ov_domain, pobj), "ExpressionLogic");#
		result = ov_class_createobject(pclass_propertyValueStatement_ExpressionLogic, Ov_DynamicPtrCast(ov_domain, pobj),
				"ExpressionLogic", OV_PMH_DEFAULT,  NULL, NULL, NULL, &pchild);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create ExpressionLogic");
			return result;
		}
	}
	if (ExpressionSemanticFound == FALSE){
		//result = Ov_CreateObject(propertyValueStatement_ExpressionSemantic, pchild, Ov_DynamicPtrCast(ov_domain, pobj), "ExpressionSemantic");
		result = ov_class_createobject(pclass_propertyValueStatement_ExpressionSemantic, Ov_DynamicPtrCast(ov_domain, pobj),
				"ExpressionSemantic", OV_PMH_DEFAULT,  NULL, NULL, NULL, &pchild);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create ExpressionSemantic");
			return result;
		}
	}
	if (ViewFound == FALSE){
		//result = Ov_CreateObject(propertyValueStatement_View, pchild, Ov_DynamicPtrCast(ov_domain, pobj), "View");
		result = ov_class_createobject(pclass_propertyValueStatement_View, Ov_DynamicPtrCast(ov_domain, pobj),
				"View", OV_PMH_DEFAULT,  NULL, NULL, NULL, &pchild);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create View");
			return result;
		}
	}
	if (VisibilityFound == FALSE){
		//result = Ov_CreateObject(propertyValueStatement_Visibility, pchild, Ov_DynamicPtrCast(ov_domain, pobj), "Visibility");
		result = ov_class_createobject(pclass_propertyValueStatement_Visibility, Ov_DynamicPtrCast(ov_domain, pobj),
				"Visibility", OV_PMH_DEFAULT,  NULL, NULL, NULL, &pchild);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create Visibility");
			return result;
		}
	}
    return OV_ERR_OK;
}


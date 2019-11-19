
/******************************************************************************
*
*   FILE
*   ----
*   LCEGenerator.c
*
*   History
*   -------
*   2017-02-16   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_subModelLifeCycleEntry
#define OV_COMPILE_LIBRARY_subModelLifeCycleEntry
#endif


#include "subModelLifeCycleEntry.h"
#include "ov_macros.h"


OV_DLLFNCEXPORT OV_RESULT subModelLifeCycleEntry_LCEGenerator_StartLCEGenerator_set(
    OV_INSTPTR_subModelLifeCycleEntry_LCEGenerator          pobj,
    const OV_BOOL  value
) {
    pobj->v_StartLCEGenerator = value;
	pobj->v_actimode = 1;
	pobj->v_iexreq = TRUE;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT subModelLifeCycleEntry_LCEGenerator_StopLCEGenerator_set(
    OV_INSTPTR_subModelLifeCycleEntry_LCEGenerator          pobj,
    const OV_BOOL  value
) {
    pobj->v_StopLCEGenerator = value;
    pobj->v_actimode = 0;
	pobj->v_iexreq = FALSE;
	return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_ACCESS subModelLifeCycleEntry_LCEGenerator_getaccess(
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

OV_DLLFNCEXPORT void subModelLifeCycleEntry_LCEGenerator_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_subModelLifeCycleEntry_LCEGenerator pinst = Ov_StaticPtrCast(subModelLifeCycleEntry_LCEGenerator, pfb);


	switch(pinst->v_State){
	case 0:
		if(pinst->v_Generate == TRUE)
			pinst->v_State = 1;
		break;
	case 1:
	{
		LifeCycleEntry lce;
		LifeCycleEntry_init(&lce);

		ov_string_setvalue(&lce.creatingInstance.IdSpec, pinst->v_LCECreatingInstanceIdString);
		lce.creatingInstance.IdType =  pinst->v_LCECreatingInstanceIdType;

		ov_string_setvalue(&lce.writingInstance.IdSpec,  pinst->v_LCEWritingInstanceIdString);
		lce.writingInstance.IdType =  pinst->v_LCEWritingInstanceIdType;

		ov_string_setvalue(&lce.eventClass,  pinst->v_LCEEventClass);

		ov_string_setvalue(&lce.subject,  pinst->v_LCESubject);

		Ov_SetAnyValue(&lce.data, &pinst->v_LCEValue);

		if (pinst->v_LCETimeStampExtern == FALSE)
			ov_time_gettime(&lce.data.time);
		else
			lce.data.time = pinst->v_LCETimeStamp;

		OV_INSTPTR_ov_object pModel = NULL;
		pModel = ov_path_getobjectpointer(pinst->v_LCESubModelPath, 2);
		if (pModel == NULL){
			pinst->v_Status = OV_ERR_BADPATH;
			pinst->v_State = 2;
			break;
		}

		OV_INSTPTR_subModelLifeCycleEntry_SubModelLifeCycleEntry pSM = NULL;
		pSM = Ov_DynamicPtrCast(subModelLifeCycleEntry_SubModelLifeCycleEntry, pModel);
		if (pSM == NULL){
			pinst->v_Status = OV_ERR_BADTYPE;
			pinst->v_State = 2;
		}

		lifeCycleEntry_LifeCycleArchive_createLCE(&pSM->p_LifeCycleArchiv, lce);
		LifeCycleEntry_deleteMembers(&lce);
	}
		pinst->v_State = 2;
		break;
	case 2:
		if(pinst->v_Generate == FALSE)
			pinst->v_State = 0;
		break;
	}
    return;
}


OV_DLLFNCEXPORT OV_RESULT subModelLifeCycleEntry_LCEGenerator_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*
    *   local variables
    */
    OV_INSTPTR_subModelLifeCycleEntry_LCEGenerator pinst = Ov_StaticPtrCast(subModelLifeCycleEntry_LCEGenerator, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = fb_functionblock_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */
    pinst->v_LCEValue.value.vartype = OV_VT_VOID;

    return OV_ERR_OK;
}




/******************************************************************************
*
*   FILE
*   ----
*   HMIHelperLCEData2.c
*
*   History
*   -------
*   2017-03-28   File created
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


OV_DLLFNCEXPORT void openaas_HMIHelperLCEData2_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	OV_RESULT result = 0;
	OV_INSTPTR_openaas_HMIHelperLCEData2 pinst = Ov_StaticPtrCast(openaas_HMIHelperLCEData2, pfb);
	OV_INSTPTR_ov_object pobj = NULL;
	OV_INSTPTR_openaas_LifeCycleEntry pchild = NULL;
	OV_INSTPTR_openaas_LifeCycleEntry pstartLCE = NULL;
	OV_INSTPTR_openaas_LifeCycleEntry pstopLCE = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;

	pinst->v_OutputType = 0;
	Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, 0, TIME);
	Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, 0, DOUBLE);
	ov_string_setvalue(&pinst->v_yUnitStatic, "");
	pinst->v_yValueDynamic = 0;
	ov_string_setvalue(&pinst->v_yUnitDynamic, "");
	pinst->v_Error = FALSE;
	ov_string_setvalue(&pinst->v_ErrorText, "");
	pinst->v_ErrorDynamic = FALSE;
	ov_string_setvalue(&pinst->v_ErrorTextDynamic, "");
	pinst->v_ErrorStatic = FALSE;
	ov_string_setvalue(&pinst->v_ErrorTextStatic, "");

	OV_UINT len = 0;
	OV_STRING *pathList = NULL;
	OV_STRING path = NULL;
	pathList = ov_string_split(pinst->v_AASPath, "/", &len);

	if(ov_string_compare(pathList[5], "AssemblyGroupAcceleration") == OV_STRCMP_EQUAL)
		pinst->v_FastValues = TRUE;
	else
		pinst->v_FastValues = FALSE;

	for (OV_UINT i = 4; i < len; i++){
		if (i == 4)
			ov_string_setvalue(&path, "/");
		else
			ov_string_append(&path, "/");
		ov_string_append(&path, pathList[i]);
	}
	ov_string_freelist(pathList);

	pobj = ov_path_getobjectpointer(path,2);
	ov_database_free(path);
	if (!pobj){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Could not find an object for this path");
		return;
	}

	paas = Ov_DynamicPtrCast(openaas_aas, pobj);
	if (!paas){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Object is not of aas-Type");
		return;
	}

	// for static
	OV_UINT i = 0;
	OV_TIME startTime;
	OV_TIME stopTime;
	result = ov_time_asciitotime_local(&startTime, pinst->v_StartTime);
	if (result){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Converting StartTime failed");
		return;
	}
	result = ov_time_asciitotime_local(&stopTime, pinst->v_StopTime);
	if (result){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Converting StopTime failed");
		return;
	}
	if (ov_time_compare(&startTime, &stopTime) ==  OV_TIMECMP_AFTER){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "StartTime is after StopTime");
		return;
	}

	OV_TIME_SPAN difftime;
	OV_TIME_SPAN maxTimeSpan;
	if (pinst->v_FastValues == TRUE)
		maxTimeSpan = pinst->v_maxTimeSpanFastValues;
	else
		maxTimeSpan = pinst->v_maxTimeSpanSlowValues;

	ov_time_diff(&difftime, &stopTime, &startTime);
	if (difftime.secs > maxTimeSpan.secs ||  (difftime.secs == maxTimeSpan.secs && difftime.usecs > maxTimeSpan.usecs)){
		startTime.secs = stopTime.secs - maxTimeSpan.secs;
		startTime.usecs = stopTime.usecs - maxTimeSpan.usecs;
	}

	// Search for Start and Stop LCE
	OV_UINT lceCount = 0;
	Ov_ForEachChildEx(ov_containment, &paas->p_LifeCycleArchive, pchild, openaas_LifeCycleEntry){
		if (ov_string_compare(pchild->v_EventClass, pinst->v_EventClass) == OV_STRCMP_EQUAL && ov_string_compare(pchild->v_Subject, pinst->v_Subject) == OV_STRCMP_EQUAL){
			lceCount++;
			// StartLCE
			switch(ov_time_compare(&pchild->v_TimeStamp, &startTime)){
				case OV_TIMECMP_AFTER:
					if (!pstartLCE)
						pstartLCE = pchild;
				break;
				case OV_TIMECMP_EQUAL:
				case OV_TIMECMP_BEFORE:
					pstartLCE = pchild;
				break;
			}
			// StopLCE
			switch(ov_time_compare(&pchild->v_TimeStamp, &stopTime)){
				case OV_TIMECMP_AFTER:
					if (!pstopLCE)
						pstopLCE = pchild;
				break;
				case OV_TIMECMP_EQUAL:
				case OV_TIMECMP_BEFORE:
					pstopLCE = pchild;
				break;
			}
		}
	}

	if (lceCount == 0){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Could not find an object in LifeCycleArchive");
		return;
	}

	if (!pstartLCE){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Could not find an object after StartTime");
		return;
	}

	if (!pstopLCE){
		pinst->v_Error = TRUE;
		ov_string_setvalue(&pinst->v_ErrorText, "Could not find an object before StopTime");
		return;
	}


	// printing x- and y-values
	OV_TIME xValue;
	// TODO: The timeSpan between the Values have to be saved, maybe in an object under the LCE object
	OV_TIME_SPAN timeSpan; // Static for the HMI2017 with EvoSoft
	timeSpan.secs = 0;
	timeSpan.usecs = 8000;
	OV_BOOL endLCE = FALSE;
	OV_STRING tmpString = NULL;

	lceCount = 0;
	do {
		endLCE = FALSE;
		if (lceCount == 0){
			pchild = pstartLCE;
		}else{
			pobj = NULL;
			pobj = Ov_GetNextChild(ov_containment, pchild);
			pchild = NULL;
			pchild = Ov_DynamicPtrCast(openaas_LifeCycleEntry, pobj);
			if (!pchild){
				continue;
			}
		}
		if (pchild == pstopLCE){
			endLCE = TRUE;
		}

		if (ov_string_compare(pchild->v_EventClass, pinst->v_EventClass) != OV_STRCMP_EQUAL || ov_string_compare(pchild->v_Subject, pinst->v_Subject) != OV_STRCMP_EQUAL){
			continue;
		}

		if(!(pchild->v_Data.value.vartype & OV_VT_ISVECTOR)){
			if (pinst->v_ErrorStatic == FALSE){
				pinst->v_ErrorStatic = TRUE;
				ov_string_setvalue(&pinst->v_ErrorTextStatic, "Only Arrays in Data supported");
			}
		}else{
			switch (pchild->v_Data.value.vartype & OV_VT_KSMASK) {
				case OV_VT_UINT_VEC:
					xValue = pchild->v_TimeStamp;
					for (OV_UINT arrayCount = 0; arrayCount < pchild->v_Data.value.valueunion.val_uint_vec.veclen; arrayCount++){
						pinst->v_OutputType = 1;
						if (arrayCount > 0)
							ov_time_add(&xValue, &xValue, &timeSpan);
						switch(ov_time_compare(&xValue, &startTime)){
							case OV_TIMECMP_AFTER:
							case OV_TIMECMP_EQUAL:
								if (endLCE == TRUE){
									switch(ov_time_compare(&xValue, &stopTime)){
										case OV_TIMECMP_AFTER:
											break;
										break;
										case OV_TIMECMP_EQUAL:
										case OV_TIMECMP_BEFORE:
											Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
											pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
											Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
											pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_uint_vec.value[arrayCount];
											break;
									}
								}else{
									Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
									pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
									Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
									pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_uint_vec.value[arrayCount];
									}
								break;
							case OV_TIMECMP_BEFORE:
								// Do nothing
							break;
						}
					}
				break;
				case OV_VT_INT_VEC:
					xValue = pchild->v_TimeStamp;
					for (OV_UINT arrayCount = 0; arrayCount < pchild->v_Data.value.valueunion.val_int_vec.veclen; arrayCount++){
						pinst->v_OutputType = 1;
						if (arrayCount > 0)
							ov_time_add(&xValue, &xValue, &timeSpan);
						switch(ov_time_compare(&xValue, &startTime)){
							case OV_TIMECMP_AFTER:
							case OV_TIMECMP_EQUAL:
								if (endLCE == TRUE){
									switch(ov_time_compare(&xValue, &stopTime)){
										case OV_TIMECMP_AFTER:
											break;
										break;
										case OV_TIMECMP_EQUAL:
										case OV_TIMECMP_BEFORE:
											Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
											pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
											Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
											pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_int_vec.value[arrayCount];
										break;
									}
								}else{
									Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
									pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
									Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
									pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_int_vec.value[arrayCount];
								}
								break;
							case OV_TIMECMP_BEFORE:
								// Do nothing
							break;
						}
					}
				break;
				case OV_VT_SINGLE_VEC:
					xValue = pchild->v_TimeStamp;
					for (OV_UINT arrayCount = 0; arrayCount < pchild->v_Data.value.valueunion.val_single_vec.veclen; arrayCount++){
						pinst->v_OutputType = 1;
						if (arrayCount > 0)
							ov_time_add(&xValue, &xValue, &timeSpan);
						switch(ov_time_compare(&xValue, &startTime)){
							case OV_TIMECMP_AFTER:
							case OV_TIMECMP_EQUAL:
								if (endLCE == TRUE){
									switch(ov_time_compare(&xValue, &stopTime)){
										case OV_TIMECMP_AFTER:
											break;
										break;
										case OV_TIMECMP_EQUAL:
										case OV_TIMECMP_BEFORE:
										Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
										pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
										Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
										pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_single_vec.value[arrayCount];
										break;
									}
								}else{
									Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
									pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
									Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
									pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_single_vec.value[arrayCount];
								}
								break;
							case OV_TIMECMP_BEFORE:
								// Do nothing
							break;
						}
					}
				break;
				case OV_VT_DOUBLE_VEC:
					xValue = pchild->v_TimeStamp;
					for (OV_UINT arrayCount = 0; arrayCount < pchild->v_Data.value.valueunion.val_double_vec.veclen; arrayCount++){
						pinst->v_OutputType = 1;
						if (arrayCount > 0)
							ov_time_add(&xValue, &xValue, &timeSpan);
						switch(ov_time_compare(&xValue, &startTime)){
							case OV_TIMECMP_AFTER:
							case OV_TIMECMP_EQUAL:
								if (endLCE == TRUE){
									switch(ov_time_compare(&xValue, &stopTime)){
										case OV_TIMECMP_AFTER:
											break;
										break;
										case OV_TIMECMP_EQUAL:
										case OV_TIMECMP_BEFORE:
											Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
											pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
											Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
											pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_double_vec.value[arrayCount];
										break;
									}
								}else{
									Ov_SetDynamicVectorLength(&pinst->v_xValueStatic, pinst->v_xValueStatic.veclen + 1, TIME);
									pinst->v_xValueStatic.value[pinst->v_xValueStatic.veclen-1] = xValue;
									Ov_SetDynamicVectorLength(&pinst->v_yValueStatic, pinst->v_yValueStatic.veclen + 1, DOUBLE);
									pinst->v_yValueStatic.value[pinst->v_yValueStatic.veclen-1] = pchild->v_Data.value.valueunion.val_double_vec.value[arrayCount];
								}
								break;
							case OV_TIMECMP_BEFORE:
								// Do nothing
							break;
						}
					}
				break;
				default:
					if (pinst->v_ErrorStatic == FALSE){
						pinst->v_ErrorStatic = TRUE;
						ov_string_print(&pinst->v_ErrorTextStatic, "DataType of LCE:%s not supported", pchild->v_identifier);
					}
				break;
			}
		}
		lceCount++;
	}while(endLCE == FALSE);

	// for dynamic
	pobj = NULL;
	pchild = NULL;
	i = 0;
	do{
		if (i == 0){
			i++;
			pobj = Ov_GetLastChild(ov_containment, &paas->p_LifeCycleArchive);
			pchild = Ov_DynamicPtrCast(openaas_LifeCycleEntry, pobj);
			if (!pchild){
				continue;
			}
		}

		pobj = Ov_GetPreviousChild(ov_containment, pchild);
		if (!pobj){
			if (pinst->v_ErrorDynamic == FALSE){
				pinst->v_ErrorDynamic = TRUE;
				ov_string_setvalue(&pinst->v_ErrorTextDynamic, "Could not find an object for dynamic values");
			}
			break;
		}
		pchild = Ov_DynamicPtrCast(openaas_LifeCycleEntry, pobj);
		if (!pchild){
			continue;
		}
	}while(ov_string_compare(pchild->v_EventClass, pinst->v_EventClass) != OV_STRCMP_EQUAL || ov_string_compare(pchild->v_Subject, pinst->v_Subject) != OV_STRCMP_EQUAL);

	if (pinst->v_ErrorDynamic == FALSE){
		if(!(pchild->v_Data.value.vartype & OV_VT_ISVECTOR)){
			switch(pchild->v_Data.value.vartype & OV_VT_KSMASK){
				case OV_VT_DOUBLE:
					pinst->v_yValueDynamic = pchild->v_Data.value.valueunion.val_double;
					pinst->v_OutputType = 2;
				break;
				case OV_VT_INT:
					pinst->v_yValueDynamic = pchild->v_Data.value.valueunion.val_int;
					pinst->v_OutputType = 2;
				break;
				case OV_VT_UINT:
					pinst->v_yValueDynamic = pchild->v_Data.value.valueunion.val_uint;
					pinst->v_OutputType = 2;
				break;
				case OV_VT_SINGLE:
					pinst->v_yValueDynamic = pchild->v_Data.value.valueunion.val_single;
					pinst->v_OutputType = 2;
				break;
				case OV_VT_BOOL:
				case OV_VT_STRING:
				default:
					if (pinst->v_ErrorDynamic == FALSE){
						pinst->v_ErrorDynamic = TRUE;
						ov_string_setvalue(&pinst->v_ErrorTextDynamic, "DataType not supported");
						pinst->v_yValueDynamic = 0;
					}
				break;
			}
		}else{
			if (pinst->v_ErrorDynamic == FALSE){
				pinst->v_ErrorDynamic = TRUE;
				ov_string_setvalue(&pinst->v_ErrorTextDynamic, "Arrays are not supported");
				pinst->v_yValueDynamic = 0;
			}
		}
	}



	ov_database_free(tmpString);

	return;
}


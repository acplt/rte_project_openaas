
/******************************************************************************
*
*   FILE
*   ----
*   HMIHelperPVSL.c
*
*   History
*   -------
*   2017-03-08   File created
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
#include "libov/ov_time.h"



OV_DLLFNCEXPORT OV_ACCESS openaas_HMIHelperPVSL_getaccess(
	OV_INSTPTR_ov_object	pobj,
	const OV_ELEMENT		*pelem,
	const OV_TICKET			*pticket
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_openaas_HMIHelperPVSL pinst = Ov_StaticPtrCast(openaas_HMIHelperPVSL, pobj);

    return (OV_ACCESS)0;
}

OV_DLLFNCEXPORT void openaas_HMIHelperPVSL_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    

    *   local variables
    */


	OV_INSTPTR_openaas_HMIHelperPVSL pinst = Ov_StaticPtrCast(openaas_HMIHelperPVSL, pfb);
	OV_INSTPTR_ov_object pList = NULL;
	OV_INSTPTR_openaas_PropertyValueStatement pchild = NULL;



	OV_UINT len = 0;
	OV_UINT len2 = 0;
	OV_STRING tmpString_header = NULL ;
	OV_STRING *pathList = NULL;
	OV_STRING *pathList2 = NULL;
	OV_STRING path = NULL;
	pathList = ov_string_split(pinst->v_Path, "/", &len);

	ov_string_append(&tmpString_header, ".Header.");


	if (len == 8){
			    	pathList2 = ov_string_split(pathList[7], ".",&len2);


				for (OV_UINT i = 4; i < len; i++){
					ov_string_append(&path, "/");
					ov_string_append(&path, pathList[i]);
					if ( (i==6) && (len2>1) ){
						ov_string_append(&path, "/");
						ov_string_append(&path, pathList2[0]);
						ov_string_append(&path, tmpString_header);
						ov_string_append(&path, pathList2[1]);
						break;
					}
				}
			    }

				else	if (len == 9){

						for (OV_UINT i = 4; i < len; i++){
							ov_string_append(&path, "/");

							ov_string_append(&path, pathList[i]);
							if(i==7)
								ov_string_append(&path, ".Body");

						}
				}




	pList = ov_path_getobjectpointer(path,2);



	ov_string_setvalue(&pinst->v_ExpressionLogic, "");
	ov_string_setvalue(&pinst->v_ExpressionSemantic, "");
	ov_string_setvalue(&pinst->v_IDSpecification, "");
	ov_string_setvalue(&pinst->v_IDType, "");
	ov_string_setvalue(&pinst->v_TimeStamp, "");
	ov_string_setvalue(&pinst->v_Unit, "");
	ov_string_setvalue(&pinst->v_View, "");
	ov_string_setvalue(&pinst->v_Visibility, "");
	ov_string_setvalue(&pinst->v_Name, "");

	ov_string_setvalue(&pinst->v_Value, "");


	OV_STRING tmpString = NULL;
	OV_UINT i = 0;
	Ov_ForEachChildEx(ov_containment, Ov_DynamicPtrCast(ov_domain,pList), pchild, openaas_PropertyValueStatement){
		if (i != 0){
			ov_string_append(&pinst->v_ExpressionLogic, ";");
			ov_string_append(&pinst->v_ExpressionSemantic, ";");
			ov_string_append(&pinst->v_IDSpecification, ";");
			ov_string_append(&pinst->v_IDType, ";");
			ov_string_append(&pinst->v_TimeStamp, ";");
			ov_string_append(&pinst->v_Unit, ";");
			ov_string_append(&pinst->v_View, ";");
			ov_string_append(&pinst->v_Visibility, ";");
			ov_string_append(&pinst->v_Name, ";");
			ov_string_append(&pinst->v_Value, ";");
		}

		ov_string_print(&tmpString, "%i", pchild->v_ExpressionLogic);
		ov_string_append(&pinst->v_ExpressionLogic, tmpString);

		ov_string_print(&tmpString, "%i", pchild->v_ExpressionSemantic);
		ov_string_append(&pinst->v_ExpressionSemantic, tmpString);

		ov_string_append(&pinst->v_IDSpecification, pchild->v_IDIdString);

		ov_string_print(&tmpString, "%i", pchild->v_IDIdType);
		ov_string_append(&pinst->v_IDType, tmpString);

		ov_string_append(&pinst->v_TimeStamp, ov_time_timetoascii(&pchild->v_TimeStamp));

		ov_string_append(&pinst->v_Unit, pchild->v_Unit);

		ov_string_print(&tmpString, "%i", pchild->v_View);
		ov_string_append(&pinst->v_View, tmpString);

		ov_string_print(&tmpString, "%i", pchild->v_Visibility);
		ov_string_append(&pinst->v_Visibility, tmpString);



		ov_string_append(&pinst->v_Name, pchild->v_identifier);



	/*	switch(pchild->v_ExpressionSemantic){
		case 0:
			ov_string_append(&pinst->v_ExpressionSemantic, "A");
			break;
		case 1:
			ov_string_append(&pinst->v_ExpressionSemantic, "S");
			break;
		case 2:
			ov_string_append(&pinst->v_ExpressionSemantic, "M");
			break;
		case 3:
			ov_string_append(&pinst->v_ExpressionSemantic, "R");
			break;
			default:
			break;


		}

		switch(pchild->v_ExpressionLogic){
			case 0:
				ov_string_append(&pinst->v_ExpressionLogic, "GT");
				break;
			case 1:
				ov_string_append(&pinst->v_ExpressionLogic, "GE");
				break;
			case 2:
				ov_string_append(&pinst->v_ExpressionLogic, "E");
				break;
			case 3:
				ov_string_append(&pinst->v_ExpressionLogic, "NE");
				break;
			case 4:
				ov_string_append(&pinst->v_ExpressionLogic, "LE");
				break;
			case 5:
				ov_string_append(&pinst->v_ExpressionLogic, "LT");
				break;
				default:
				break;


			}
		switch(pchild->v_View){
				case 0:
					ov_string_append(&pinst->v_View, "B");
					break;
				case 1:
					ov_string_append(&pinst->v_View, "C");
					break;
				case 2:
					ov_string_append(&pinst->v_View, "P");
					break;
				case 3:
					ov_string_append(&pinst->v_View, "F");
					break;
				case 4:
					ov_string_append(&pinst->v_View, "L");
					break;
				case 5:
					ov_string_append(&pinst->v_View, "S");
					break;
				case 6:
					ov_string_append(&pinst->v_View, "N");
					break;
				case 7:
					ov_string_append(&pinst->v_View, "L");
					break;
				case 8:
					ov_string_append(&pinst->v_View, "H");
					break;
					default:
					break;


				}


		switch(pchild->v_Visibility){
				case 0:
					ov_string_append(&pinst->v_Visibility, "PR");
					break;
				case 1:
					ov_string_append(&pinst->v_Visibility, "C");
					break;
				case 2:
					ov_string_append(&pinst->v_Visibility, "PU");
					break;
					default:
					break;


				}


*/

		/*switch(pchild->v_Value.value.vartype & OV_VT_KSMASK){
			case OV_VT_BOOL:
				if (pchild->v_Value.value.valueunion.val_bool == TRUE)
					ov_string_append(&pinst->v_Value, "true");
				else
					ov_string_append(&pinst->v_Value, "false");
			break;
			case OV_VT_STRING:
				ov_string_print(&tmpString, "%s", pchild->v_Value.value.valueunion.val_string);
				ov_string_append(&pinst->v_Value, tmpString);
			break;
			case OV_VT_DOUBLE:
			    ov_string_print(&tmpString, "%lf", pchild->v_Value.value.valueunion.val_double);
			    ov_string_append(&pinst->v_Value, tmpString);
			break;
			case OV_VT_INT:
				ov_string_print(&tmpString, "%i", pchild->v_Value.value.valueunion.val_int);
				ov_string_append(&pinst->v_Value, tmpString);
			break;
			case OV_VT_UINT:
				ov_string_print(&tmpString, "%u", pchild->v_Value.value.valueunion.val_uint);
				ov_string_append(&pinst->v_Value, tmpString);
			break;
			case OV_VT_SINGLE:
				ov_string_print(&tmpString, "%f", pchild->v_Value.value.valueunion.val_single);
				ov_string_append(&pinst->v_Value, tmpString);
			break;
			default:
			break;
		}
*/

		i++;
		}

	ov_database_free(tmpString);
	  ov_string_freelist(pathList);
	    ov_string_freelist(pathList2);
	    ov_database_free(path);
	    	ov_database_free(tmpString_header);
    return;
}






















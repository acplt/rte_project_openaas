#ifndef __DSHELPER_H_
#define __DSHELPER_H_


#include "DSServices.h"
#include "ov_path.h"
#include "ov_macros.h"

OV_RESULT checkSecurityKey(OV_STRING_VEC DBWrapperPath, OV_STRING componentID, OV_STRING securityKey);
OV_RESULT checkSecurityKeySQLC(OV_STRING_VEC DBWrapperPath, OV_STRING componentID, OV_STRING securityKey);
#endif

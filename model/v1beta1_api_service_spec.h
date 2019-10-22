/*
 * v1beta1_api_service_spec.h
 *
 * APIServiceSpec contains information for locating and communicating with a server. Only https is supported, though you are able to disable certificate verification.
 */

#ifndef _v1beta1_api_service_spec_H_
#define _v1beta1_api_service_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "apiregistration_v1beta1_service_reference.h"



typedef struct v1beta1_api_service_spec_t {
    char caBundle; //Byte
    char *group; // string
    int groupPriorityMinimum; //numeric
    int insecureSkipTLSVerify; //boolean
    apiregistration_v1beta1_service_reference_t *service; //model
    char *version; // string
    int versionPriority; //numeric

} v1beta1_api_service_spec_t;

v1beta1_api_service_spec_t *v1beta1_api_service_spec_create(
    char caBundle,
    char *group,
    int groupPriorityMinimum,
    int insecureSkipTLSVerify,
    apiregistration_v1beta1_service_reference_t *service,
    char *version,
    int versionPriority
);

void v1beta1_api_service_spec_free(v1beta1_api_service_spec_t *v1beta1_api_service_spec);

v1beta1_api_service_spec_t *v1beta1_api_service_spec_parseFromJSON(cJSON *v1beta1_api_service_specJSON);

cJSON *v1beta1_api_service_spec_convertToJSON(v1beta1_api_service_spec_t *v1beta1_api_service_spec);

#endif /* _v1beta1_api_service_spec_H_ */


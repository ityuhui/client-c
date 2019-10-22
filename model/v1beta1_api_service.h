/*
 * v1beta1_api_service.h
 *
 * APIService represents a server for a particular GroupVersion. Name must be \&quot;version.group\&quot;.
 */

#ifndef _v1beta1_api_service_H_
#define _v1beta1_api_service_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta1_api_service_spec.h"
#include "v1beta1_api_service_status.h"



typedef struct v1beta1_api_service_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1beta1_api_service_spec_t *spec; //model
    v1beta1_api_service_status_t *status; //model

} v1beta1_api_service_t;

v1beta1_api_service_t *v1beta1_api_service_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_api_service_spec_t *spec,
    v1beta1_api_service_status_t *status
);

void v1beta1_api_service_free(v1beta1_api_service_t *v1beta1_api_service);

v1beta1_api_service_t *v1beta1_api_service_parseFromJSON(cJSON *v1beta1_api_serviceJSON);

cJSON *v1beta1_api_service_convertToJSON(v1beta1_api_service_t *v1beta1_api_service);

#endif /* _v1beta1_api_service_H_ */


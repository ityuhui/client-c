/*
 * v1_api_service_list.h
 *
 * APIServiceList is a list of APIService objects.
 */

#ifndef _v1_api_service_list_H_
#define _v1_api_service_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_api_service.h"
#include "v1_list_meta.h"



typedef struct v1_api_service_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1_api_service_list_t;

v1_api_service_list_t *v1_api_service_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_api_service_list_free(v1_api_service_list_t *v1_api_service_list);

v1_api_service_list_t *v1_api_service_list_parseFromJSON(cJSON *v1_api_service_listJSON);

cJSON *v1_api_service_list_convertToJSON(v1_api_service_list_t *v1_api_service_list);

#endif /* _v1_api_service_list_H_ */


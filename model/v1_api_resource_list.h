/*
 * v1_api_resource_list.h
 *
 * APIResourceList is a list of APIResource, it is used to expose the name of the resources supported in a specific group and version, and if the resource is namespaced.
 */

#ifndef _v1_api_resource_list_H_
#define _v1_api_resource_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_api_resource.h"



typedef struct v1_api_resource_list_t {
    char *apiVersion; // string
    char *groupVersion; // string
    char *kind; // string
    list_t *resources; //nonprimitive container

} v1_api_resource_list_t;

v1_api_resource_list_t *v1_api_resource_list_create(
    char *apiVersion,
    char *groupVersion,
    char *kind,
    list_t *resources
);

void v1_api_resource_list_free(v1_api_resource_list_t *v1_api_resource_list);

v1_api_resource_list_t *v1_api_resource_list_parseFromJSON(cJSON *v1_api_resource_listJSON);

cJSON *v1_api_resource_list_convertToJSON(v1_api_resource_list_t *v1_api_resource_list);

#endif /* _v1_api_resource_list_H_ */


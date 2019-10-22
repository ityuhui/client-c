/*
 * v1_api_resource.h
 *
 * APIResource specifies the name of a resource and whether it is namespaced.
 */

#ifndef _v1_api_resource_H_
#define _v1_api_resource_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_api_resource_t {
    list_t *categories; //primitive container
    char *group; // string
    char *kind; // string
    char *name; // string
    int namespaced; //boolean
    list_t *shortNames; //primitive container
    char *singularName; // string
    char *storageVersionHash; // string
    list_t *verbs; //primitive container
    char *version; // string

} v1_api_resource_t;

v1_api_resource_t *v1_api_resource_create(
    list_t *categories,
    char *group,
    char *kind,
    char *name,
    int namespaced,
    list_t *shortNames,
    char *singularName,
    char *storageVersionHash,
    list_t *verbs,
    char *version
);

void v1_api_resource_free(v1_api_resource_t *v1_api_resource);

v1_api_resource_t *v1_api_resource_parseFromJSON(cJSON *v1_api_resourceJSON);

cJSON *v1_api_resource_convertToJSON(v1_api_resource_t *v1_api_resource);

#endif /* _v1_api_resource_H_ */


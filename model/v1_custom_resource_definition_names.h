/*
 * v1_custom_resource_definition_names.h
 *
 * CustomResourceDefinitionNames indicates the names to serve this CustomResourceDefinition
 */

#ifndef _v1_custom_resource_definition_names_H_
#define _v1_custom_resource_definition_names_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_custom_resource_definition_names_t {
    list_t *categories; //primitive container
    char *kind; // string
    char *listKind; // string
    char *plural; // string
    list_t *shortNames; //primitive container
    char *singular; // string

} v1_custom_resource_definition_names_t;

v1_custom_resource_definition_names_t *v1_custom_resource_definition_names_create(
    list_t *categories,
    char *kind,
    char *listKind,
    char *plural,
    list_t *shortNames,
    char *singular
);

void v1_custom_resource_definition_names_free(v1_custom_resource_definition_names_t *v1_custom_resource_definition_names);

v1_custom_resource_definition_names_t *v1_custom_resource_definition_names_parseFromJSON(cJSON *v1_custom_resource_definition_namesJSON);

cJSON *v1_custom_resource_definition_names_convertToJSON(v1_custom_resource_definition_names_t *v1_custom_resource_definition_names);

#endif /* _v1_custom_resource_definition_names_H_ */


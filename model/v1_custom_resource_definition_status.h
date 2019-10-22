/*
 * v1_custom_resource_definition_status.h
 *
 * CustomResourceDefinitionStatus indicates the state of the CustomResourceDefinition
 */

#ifndef _v1_custom_resource_definition_status_H_
#define _v1_custom_resource_definition_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_custom_resource_definition_condition.h"
#include "v1_custom_resource_definition_names.h"



typedef struct v1_custom_resource_definition_status_t {
    v1_custom_resource_definition_names_t *acceptedNames; //model
    list_t *conditions; //nonprimitive container
    list_t *storedVersions; //primitive container

} v1_custom_resource_definition_status_t;

v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_create(
    v1_custom_resource_definition_names_t *acceptedNames,
    list_t *conditions,
    list_t *storedVersions
);

void v1_custom_resource_definition_status_free(v1_custom_resource_definition_status_t *v1_custom_resource_definition_status);

v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_parseFromJSON(cJSON *v1_custom_resource_definition_statusJSON);

cJSON *v1_custom_resource_definition_status_convertToJSON(v1_custom_resource_definition_status_t *v1_custom_resource_definition_status);

#endif /* _v1_custom_resource_definition_status_H_ */


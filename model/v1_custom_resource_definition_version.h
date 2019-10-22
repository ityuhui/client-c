/*
 * v1_custom_resource_definition_version.h
 *
 * CustomResourceDefinitionVersion describes a version for CRD.
 */

#ifndef _v1_custom_resource_definition_version_H_
#define _v1_custom_resource_definition_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_custom_resource_column_definition.h"
#include "v1_custom_resource_subresources.h"
#include "v1_custom_resource_validation.h"



typedef struct v1_custom_resource_definition_version_t {
    list_t *additionalPrinterColumns; //nonprimitive container
    char *name; // string
    v1_custom_resource_validation_t *schema; //model
    int served; //boolean
    int storage; //boolean
    v1_custom_resource_subresources_t *subresources; //model

} v1_custom_resource_definition_version_t;

v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_create(
    list_t *additionalPrinterColumns,
    char *name,
    v1_custom_resource_validation_t *schema,
    int served,
    int storage,
    v1_custom_resource_subresources_t *subresources
);

void v1_custom_resource_definition_version_free(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version);

v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_parseFromJSON(cJSON *v1_custom_resource_definition_versionJSON);

cJSON *v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version);

#endif /* _v1_custom_resource_definition_version_H_ */


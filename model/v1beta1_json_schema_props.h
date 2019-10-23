/*
 * v1beta1_json_schema_props.h
 *
 * JSONSchemaProps is a JSON-Schema following Specification Draft 4 (http://json-schema.org/).
 */

#ifndef _v1beta1_json_schema_props_H_
#define _v1beta1_json_schema_props_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"
#include "v1beta1_external_documentation.h"



typedef struct v1beta1_json_schema_props_t {
    char *$ref; // string
    char *$schema; // string
    object_t *additionalItems; //object
    object_t *additionalProperties; //object
    list_t *allOf; //nonprimitive container
    list_t *anyOf; //nonprimitive container
    object_t *default_; //object
    list_t* definitions; //map
    list_t* dependencies; //map
    char *description; // string
    list_t *enum_; //nonprimitive container
    object_t *example; //object
    int exclusiveMaximum; //boolean
    int exclusiveMinimum; //boolean
    v1beta1_external_documentation_t *externalDocs; //model
    char *format; // string
    char *id; // string
    object_t *items; //object
    long maxItems; //numeric
    long maxLength; //numeric
    long maxProperties; //numeric
    double maximum; //numeric
    long minItems; //numeric
    long minLength; //numeric
    long minProperties; //numeric
    double minimum; //numeric
    double multipleOf; //numeric
    struct v1beta1_json_schema_props_t *not_; //model
    int nullable; //boolean
    list_t *oneOf; //nonprimitive container
    char *pattern; // string
    list_t* patternProperties; //map
    list_t* properties; //map
    list_t *required; //primitive container
    char *title; // string
    char *type; // string
    int uniqueItems; //boolean
    int x_kubernetes_embedded_resource; //boolean
    int x_kubernetes_int_or_string; //boolean
    list_t *x_kubernetes_list_map_keys; //primitive container
    char *x_kubernetes_list_type; // string
    int x_kubernetes_preserve_unknown_fields; //boolean

} v1beta1_json_schema_props_t;

v1beta1_json_schema_props_t *v1beta1_json_schema_props_create(
    char *$ref,
    char *$schema,
    object_t *additionalItems,
    object_t *additionalProperties,
    list_t *allOf,
    list_t *anyOf,
    object_t *default_,
    list_t* definitions,
    list_t* dependencies,
    char *description,
    list_t *enum_,
    object_t *example,
    int exclusiveMaximum,
    int exclusiveMinimum,
    v1beta1_external_documentation_t *externalDocs,
    char *format,
    char *id,
    object_t *items,
    long maxItems,
    long maxLength,
    long maxProperties,
    double maximum,
    long minItems,
    long minLength,
    long minProperties,
    double minimum,
    double multipleOf,
    v1beta1_json_schema_props_t *not_,
    int nullable,
    list_t *oneOf,
    char *pattern,
    list_t* patternProperties,
    list_t* properties,
    list_t *required,
    char *title,
    char *type,
    int uniqueItems,
    int x_kubernetes_embedded_resource,
    int x_kubernetes_int_or_string,
    list_t *x_kubernetes_list_map_keys,
    char *x_kubernetes_list_type,
    int x_kubernetes_preserve_unknown_fields
);

void v1beta1_json_schema_props_free(v1beta1_json_schema_props_t *v1beta1_json_schema_props);

v1beta1_json_schema_props_t *v1beta1_json_schema_props_parseFromJSON(cJSON *v1beta1_json_schema_propsJSON);

cJSON *v1beta1_json_schema_props_convertToJSON(v1beta1_json_schema_props_t *v1beta1_json_schema_props);

#endif /* _v1beta1_json_schema_props_H_ */


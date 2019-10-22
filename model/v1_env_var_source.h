/*
 * v1_env_var_source.h
 *
 * EnvVarSource represents a source for the value of an EnvVar.
 */

#ifndef _v1_env_var_source_H_
#define _v1_env_var_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_config_map_key_selector.h"
#include "v1_object_field_selector.h"
#include "v1_resource_field_selector.h"
#include "v1_secret_key_selector.h"



typedef struct v1_env_var_source_t {
    v1_config_map_key_selector_t *configMapKeyRef; //model
    v1_object_field_selector_t *fieldRef; //model
    v1_resource_field_selector_t *resourceFieldRef; //model
    v1_secret_key_selector_t *secretKeyRef; //model

} v1_env_var_source_t;

v1_env_var_source_t *v1_env_var_source_create(
    v1_config_map_key_selector_t *configMapKeyRef,
    v1_object_field_selector_t *fieldRef,
    v1_resource_field_selector_t *resourceFieldRef,
    v1_secret_key_selector_t *secretKeyRef
);

void v1_env_var_source_free(v1_env_var_source_t *v1_env_var_source);

v1_env_var_source_t *v1_env_var_source_parseFromJSON(cJSON *v1_env_var_sourceJSON);

cJSON *v1_env_var_source_convertToJSON(v1_env_var_source_t *v1_env_var_source);

#endif /* _v1_env_var_source_H_ */


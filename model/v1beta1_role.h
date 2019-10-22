/*
 * v1beta1_role.h
 *
 * Role is a namespaced, logical grouping of PolicyRules that can be referenced as a unit by a RoleBinding.
 */

#ifndef _v1beta1_role_H_
#define _v1beta1_role_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta1_policy_rule.h"



typedef struct v1beta1_role_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    list_t *rules; //nonprimitive container

} v1beta1_role_t;

v1beta1_role_t *v1beta1_role_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
);

void v1beta1_role_free(v1beta1_role_t *v1beta1_role);

v1beta1_role_t *v1beta1_role_parseFromJSON(cJSON *v1beta1_roleJSON);

cJSON *v1beta1_role_convertToJSON(v1beta1_role_t *v1beta1_role);

#endif /* _v1beta1_role_H_ */


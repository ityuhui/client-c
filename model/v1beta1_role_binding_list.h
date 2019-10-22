/*
 * v1beta1_role_binding_list.h
 *
 * RoleBindingList is a collection of RoleBindings
 */

#ifndef _v1beta1_role_binding_list_H_
#define _v1beta1_role_binding_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_list_meta.h"
#include "v1beta1_role_binding.h"



typedef struct v1beta1_role_binding_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1beta1_role_binding_list_t;

v1beta1_role_binding_list_t *v1beta1_role_binding_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta1_role_binding_list_free(v1beta1_role_binding_list_t *v1beta1_role_binding_list);

v1beta1_role_binding_list_t *v1beta1_role_binding_list_parseFromJSON(cJSON *v1beta1_role_binding_listJSON);

cJSON *v1beta1_role_binding_list_convertToJSON(v1beta1_role_binding_list_t *v1beta1_role_binding_list);

#endif /* _v1beta1_role_binding_list_H_ */


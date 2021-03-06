/*
 * v1beta1_cluster_role_list.h
 *
 * ClusterRoleList is a collection of ClusterRoles
 */

#ifndef _v1beta1_cluster_role_list_H_
#define _v1beta1_cluster_role_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_list_meta.h"
#include "v1beta1_cluster_role.h"



typedef struct v1beta1_cluster_role_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1beta1_cluster_role_list_t;

v1beta1_cluster_role_list_t *v1beta1_cluster_role_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta1_cluster_role_list_free(v1beta1_cluster_role_list_t *v1beta1_cluster_role_list);

v1beta1_cluster_role_list_t *v1beta1_cluster_role_list_parseFromJSON(cJSON *v1beta1_cluster_role_listJSON);

cJSON *v1beta1_cluster_role_list_convertToJSON(v1beta1_cluster_role_list_t *v1beta1_cluster_role_list);

#endif /* _v1beta1_cluster_role_list_H_ */


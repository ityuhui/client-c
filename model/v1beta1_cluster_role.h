/*
 * v1beta1_cluster_role.h
 *
 * ClusterRole is a cluster level, logical grouping of PolicyRules that can be referenced as a unit by a RoleBinding or ClusterRoleBinding.
 */

#ifndef _v1beta1_cluster_role_H_
#define _v1beta1_cluster_role_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta1_aggregation_rule.h"
#include "v1beta1_policy_rule.h"



typedef struct v1beta1_cluster_role_t {
    v1beta1_aggregation_rule_t *aggregationRule; //model
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    list_t *rules; //nonprimitive container

} v1beta1_cluster_role_t;

v1beta1_cluster_role_t *v1beta1_cluster_role_create(
    v1beta1_aggregation_rule_t *aggregationRule,
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
);

void v1beta1_cluster_role_free(v1beta1_cluster_role_t *v1beta1_cluster_role);

v1beta1_cluster_role_t *v1beta1_cluster_role_parseFromJSON(cJSON *v1beta1_cluster_roleJSON);

cJSON *v1beta1_cluster_role_convertToJSON(v1beta1_cluster_role_t *v1beta1_cluster_role);

#endif /* _v1beta1_cluster_role_H_ */


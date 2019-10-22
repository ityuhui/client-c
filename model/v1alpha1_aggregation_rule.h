/*
 * v1alpha1_aggregation_rule.h
 *
 * AggregationRule describes how to locate ClusterRoles to aggregate into the ClusterRole
 */

#ifndef _v1alpha1_aggregation_rule_H_
#define _v1alpha1_aggregation_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"



typedef struct v1alpha1_aggregation_rule_t {
    list_t *clusterRoleSelectors; //nonprimitive container

} v1alpha1_aggregation_rule_t;

v1alpha1_aggregation_rule_t *v1alpha1_aggregation_rule_create(
    list_t *clusterRoleSelectors
);

void v1alpha1_aggregation_rule_free(v1alpha1_aggregation_rule_t *v1alpha1_aggregation_rule);

v1alpha1_aggregation_rule_t *v1alpha1_aggregation_rule_parseFromJSON(cJSON *v1alpha1_aggregation_ruleJSON);

cJSON *v1alpha1_aggregation_rule_convertToJSON(v1alpha1_aggregation_rule_t *v1alpha1_aggregation_rule);

#endif /* _v1alpha1_aggregation_rule_H_ */


/*
 * v1beta1_pod_disruption_budget.h
 *
 * PodDisruptionBudget is an object to define the max disruption that can be caused to a collection of pods
 */

#ifndef _v1beta1_pod_disruption_budget_H_
#define _v1beta1_pod_disruption_budget_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta1_pod_disruption_budget_spec.h"
#include "v1beta1_pod_disruption_budget_status.h"



typedef struct v1beta1_pod_disruption_budget_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1beta1_pod_disruption_budget_spec_t *spec; //model
    v1beta1_pod_disruption_budget_status_t *status; //model

} v1beta1_pod_disruption_budget_t;

v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_pod_disruption_budget_spec_t *spec,
    v1beta1_pod_disruption_budget_status_t *status
);

void v1beta1_pod_disruption_budget_free(v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget);

v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget_parseFromJSON(cJSON *v1beta1_pod_disruption_budgetJSON);

cJSON *v1beta1_pod_disruption_budget_convertToJSON(v1beta1_pod_disruption_budget_t *v1beta1_pod_disruption_budget);

#endif /* _v1beta1_pod_disruption_budget_H_ */


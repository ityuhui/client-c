/*
 * v1beta1_pod_disruption_budget_status.h
 *
 * PodDisruptionBudgetStatus represents information about the status of a PodDisruptionBudget. Status may trail the actual state of a system.
 */

#ifndef _v1beta1_pod_disruption_budget_status_H_
#define _v1beta1_pod_disruption_budget_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_pod_disruption_budget_status_t {
    int currentHealthy; //numeric
    int desiredHealthy; //numeric
    list_t* disruptedPods; //map
    int disruptionsAllowed; //numeric
    int expectedPods; //numeric
    long observedGeneration; //numeric

} v1beta1_pod_disruption_budget_status_t;

v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_create(
    int currentHealthy,
    int desiredHealthy,
    list_t* disruptedPods,
    int disruptionsAllowed,
    int expectedPods,
    long observedGeneration
);

void v1beta1_pod_disruption_budget_status_free(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status);

v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_statusJSON);

cJSON *v1beta1_pod_disruption_budget_status_convertToJSON(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status);

#endif /* _v1beta1_pod_disruption_budget_status_H_ */


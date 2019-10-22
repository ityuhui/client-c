/*
 * v1_pod_condition.h
 *
 * PodCondition contains details for the current condition of this pod.
 */

#ifndef _v1_pod_condition_H_
#define _v1_pod_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_pod_condition_t {
    char *lastProbeTime; //date time
    char *lastTransitionTime; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_pod_condition_t;

v1_pod_condition_t *v1_pod_condition_create(
    char *lastProbeTime,
    char *lastTransitionTime,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_pod_condition_free(v1_pod_condition_t *v1_pod_condition);

v1_pod_condition_t *v1_pod_condition_parseFromJSON(cJSON *v1_pod_conditionJSON);

cJSON *v1_pod_condition_convertToJSON(v1_pod_condition_t *v1_pod_condition);

#endif /* _v1_pod_condition_H_ */


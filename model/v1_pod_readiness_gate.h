/*
 * v1_pod_readiness_gate.h
 *
 * PodReadinessGate contains the reference to a pod condition
 */

#ifndef _v1_pod_readiness_gate_H_
#define _v1_pod_readiness_gate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_pod_readiness_gate_t {
    char *conditionType; // string

} v1_pod_readiness_gate_t;

v1_pod_readiness_gate_t *v1_pod_readiness_gate_create(
    char *conditionType
);

void v1_pod_readiness_gate_free(v1_pod_readiness_gate_t *v1_pod_readiness_gate);

v1_pod_readiness_gate_t *v1_pod_readiness_gate_parseFromJSON(cJSON *v1_pod_readiness_gateJSON);

cJSON *v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_t *v1_pod_readiness_gate);

#endif /* _v1_pod_readiness_gate_H_ */


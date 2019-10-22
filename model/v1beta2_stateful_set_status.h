/*
 * v1beta2_stateful_set_status.h
 *
 * StatefulSetStatus represents the current state of a StatefulSet.
 */

#ifndef _v1beta2_stateful_set_status_H_
#define _v1beta2_stateful_set_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta2_stateful_set_condition.h"



typedef struct v1beta2_stateful_set_status_t {
    int collisionCount; //numeric
    list_t *conditions; //nonprimitive container
    int currentReplicas; //numeric
    char *currentRevision; // string
    long observedGeneration; //numeric
    int readyReplicas; //numeric
    int replicas; //numeric
    char *updateRevision; // string
    int updatedReplicas; //numeric

} v1beta2_stateful_set_status_t;

v1beta2_stateful_set_status_t *v1beta2_stateful_set_status_create(
    int collisionCount,
    list_t *conditions,
    int currentReplicas,
    char *currentRevision,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    char *updateRevision,
    int updatedReplicas
);

void v1beta2_stateful_set_status_free(v1beta2_stateful_set_status_t *v1beta2_stateful_set_status);

v1beta2_stateful_set_status_t *v1beta2_stateful_set_status_parseFromJSON(cJSON *v1beta2_stateful_set_statusJSON);

cJSON *v1beta2_stateful_set_status_convertToJSON(v1beta2_stateful_set_status_t *v1beta2_stateful_set_status);

#endif /* _v1beta2_stateful_set_status_H_ */


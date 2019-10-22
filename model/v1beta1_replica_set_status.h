/*
 * v1beta1_replica_set_status.h
 *
 * ReplicaSetStatus represents the current status of a ReplicaSet.
 */

#ifndef _v1beta1_replica_set_status_H_
#define _v1beta1_replica_set_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_replica_set_condition.h"



typedef struct v1beta1_replica_set_status_t {
    int availableReplicas; //numeric
    list_t *conditions; //nonprimitive container
    int fullyLabeledReplicas; //numeric
    long observedGeneration; //numeric
    int readyReplicas; //numeric
    int replicas; //numeric

} v1beta1_replica_set_status_t;

v1beta1_replica_set_status_t *v1beta1_replica_set_status_create(
    int availableReplicas,
    list_t *conditions,
    int fullyLabeledReplicas,
    long observedGeneration,
    int readyReplicas,
    int replicas
);

void v1beta1_replica_set_status_free(v1beta1_replica_set_status_t *v1beta1_replica_set_status);

v1beta1_replica_set_status_t *v1beta1_replica_set_status_parseFromJSON(cJSON *v1beta1_replica_set_statusJSON);

cJSON *v1beta1_replica_set_status_convertToJSON(v1beta1_replica_set_status_t *v1beta1_replica_set_status);

#endif /* _v1beta1_replica_set_status_H_ */


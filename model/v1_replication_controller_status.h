/*
 * v1_replication_controller_status.h
 *
 * ReplicationControllerStatus represents the current status of a replication controller.
 */

#ifndef _v1_replication_controller_status_H_
#define _v1_replication_controller_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_replication_controller_condition.h"



typedef struct v1_replication_controller_status_t {
    int availableReplicas; //numeric
    list_t *conditions; //nonprimitive container
    int fullyLabeledReplicas; //numeric
    long observedGeneration; //numeric
    int readyReplicas; //numeric
    int replicas; //numeric

} v1_replication_controller_status_t;

v1_replication_controller_status_t *v1_replication_controller_status_create(
    int availableReplicas,
    list_t *conditions,
    int fullyLabeledReplicas,
    long observedGeneration,
    int readyReplicas,
    int replicas
);

void v1_replication_controller_status_free(v1_replication_controller_status_t *v1_replication_controller_status);

v1_replication_controller_status_t *v1_replication_controller_status_parseFromJSON(cJSON *v1_replication_controller_statusJSON);

cJSON *v1_replication_controller_status_convertToJSON(v1_replication_controller_status_t *v1_replication_controller_status);

#endif /* _v1_replication_controller_status_H_ */


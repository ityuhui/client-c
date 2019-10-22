/*
 * v1_replication_controller_condition.h
 *
 * ReplicationControllerCondition describes the state of a replication controller at a certain point.
 */

#ifndef _v1_replication_controller_condition_H_
#define _v1_replication_controller_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_replication_controller_condition_t {
    char *lastTransitionTime; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_replication_controller_condition_t;

v1_replication_controller_condition_t *v1_replication_controller_condition_create(
    char *lastTransitionTime,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_replication_controller_condition_free(v1_replication_controller_condition_t *v1_replication_controller_condition);

v1_replication_controller_condition_t *v1_replication_controller_condition_parseFromJSON(cJSON *v1_replication_controller_conditionJSON);

cJSON *v1_replication_controller_condition_convertToJSON(v1_replication_controller_condition_t *v1_replication_controller_condition);

#endif /* _v1_replication_controller_condition_H_ */


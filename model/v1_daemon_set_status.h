/*
 * v1_daemon_set_status.h
 *
 * DaemonSetStatus represents the current status of a daemon set.
 */

#ifndef _v1_daemon_set_status_H_
#define _v1_daemon_set_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_daemon_set_condition.h"



typedef struct v1_daemon_set_status_t {
    int collisionCount; //numeric
    list_t *conditions; //nonprimitive container
    int currentNumberScheduled; //numeric
    int desiredNumberScheduled; //numeric
    int numberAvailable; //numeric
    int numberMisscheduled; //numeric
    int numberReady; //numeric
    int numberUnavailable; //numeric
    long observedGeneration; //numeric
    int updatedNumberScheduled; //numeric

} v1_daemon_set_status_t;

v1_daemon_set_status_t *v1_daemon_set_status_create(
    int collisionCount,
    list_t *conditions,
    int currentNumberScheduled,
    int desiredNumberScheduled,
    int numberAvailable,
    int numberMisscheduled,
    int numberReady,
    int numberUnavailable,
    long observedGeneration,
    int updatedNumberScheduled
);

void v1_daemon_set_status_free(v1_daemon_set_status_t *v1_daemon_set_status);

v1_daemon_set_status_t *v1_daemon_set_status_parseFromJSON(cJSON *v1_daemon_set_statusJSON);

cJSON *v1_daemon_set_status_convertToJSON(v1_daemon_set_status_t *v1_daemon_set_status);

#endif /* _v1_daemon_set_status_H_ */


/*
 * v1_container_state_terminated.h
 *
 * ContainerStateTerminated is a terminated state of a container.
 */

#ifndef _v1_container_state_terminated_H_
#define _v1_container_state_terminated_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_container_state_terminated_t {
    char *containerID; // string
    int exitCode; //numeric
    char *finishedAt; //date time
    char *message; // string
    char *reason; // string
    int signal; //numeric
    char *startedAt; //date time

} v1_container_state_terminated_t;

v1_container_state_terminated_t *v1_container_state_terminated_create(
    char *containerID,
    int exitCode,
    char *finishedAt,
    char *message,
    char *reason,
    int signal,
    char *startedAt
);

void v1_container_state_terminated_free(v1_container_state_terminated_t *v1_container_state_terminated);

v1_container_state_terminated_t *v1_container_state_terminated_parseFromJSON(cJSON *v1_container_state_terminatedJSON);

cJSON *v1_container_state_terminated_convertToJSON(v1_container_state_terminated_t *v1_container_state_terminated);

#endif /* _v1_container_state_terminated_H_ */


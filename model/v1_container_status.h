/*
 * v1_container_status.h
 *
 * ContainerStatus contains details for the current status of this container.
 */

#ifndef _v1_container_status_H_
#define _v1_container_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_container_state.h"



typedef struct v1_container_status_t {
    char *containerID; // string
    char *image; // string
    char *imageID; // string
    v1_container_state_t *lastState; //model
    char *name; // string
    int ready; //boolean
    int restartCount; //numeric
    int started; //boolean
    v1_container_state_t *state; //model

} v1_container_status_t;

v1_container_status_t *v1_container_status_create(
    char *containerID,
    char *image,
    char *imageID,
    v1_container_state_t *lastState,
    char *name,
    int ready,
    int restartCount,
    int started,
    v1_container_state_t *state
);

void v1_container_status_free(v1_container_status_t *v1_container_status);

v1_container_status_t *v1_container_status_parseFromJSON(cJSON *v1_container_statusJSON);

cJSON *v1_container_status_convertToJSON(v1_container_status_t *v1_container_status);

#endif /* _v1_container_status_H_ */


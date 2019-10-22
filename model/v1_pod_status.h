/*
 * v1_pod_status.h
 *
 * PodStatus represents information about the status of a pod. Status may trail the actual state of a system, especially if the node that hosts the pod cannot contact the control plane.
 */

#ifndef _v1_pod_status_H_
#define _v1_pod_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_container_status.h"
#include "v1_pod_condition.h"
#include "v1_pod_ip.h"



typedef struct v1_pod_status_t {
    list_t *conditions; //nonprimitive container
    list_t *containerStatuses; //nonprimitive container
    list_t *ephemeralContainerStatuses; //nonprimitive container
    char *hostIP; // string
    list_t *initContainerStatuses; //nonprimitive container
    char *message; // string
    char *nominatedNodeName; // string
    char *phase; // string
    char *podIP; // string
    list_t *podIPs; //nonprimitive container
    char *qosClass; // string
    char *reason; // string
    char *startTime; //date time

} v1_pod_status_t;

v1_pod_status_t *v1_pod_status_create(
    list_t *conditions,
    list_t *containerStatuses,
    list_t *ephemeralContainerStatuses,
    char *hostIP,
    list_t *initContainerStatuses,
    char *message,
    char *nominatedNodeName,
    char *phase,
    char *podIP,
    list_t *podIPs,
    char *qosClass,
    char *reason,
    char *startTime
);

void v1_pod_status_free(v1_pod_status_t *v1_pod_status);

v1_pod_status_t *v1_pod_status_parseFromJSON(cJSON *v1_pod_statusJSON);

cJSON *v1_pod_status_convertToJSON(v1_pod_status_t *v1_pod_status);

#endif /* _v1_pod_status_H_ */


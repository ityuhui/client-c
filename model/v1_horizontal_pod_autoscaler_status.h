/*
 * v1_horizontal_pod_autoscaler_status.h
 *
 * current status of a horizontal pod autoscaler
 */

#ifndef _v1_horizontal_pod_autoscaler_status_H_
#define _v1_horizontal_pod_autoscaler_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_horizontal_pod_autoscaler_status_t {
    int currentCPUUtilizationPercentage; //numeric
    int currentReplicas; //numeric
    int desiredReplicas; //numeric
    char *lastScaleTime; //date time
    long observedGeneration; //numeric

} v1_horizontal_pod_autoscaler_status_t;

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_create(
    int currentCPUUtilizationPercentage,
    int currentReplicas,
    int desiredReplicas,
    char *lastScaleTime,
    long observedGeneration
);

void v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status);

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_statusJSON);

cJSON *v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status);

#endif /* _v1_horizontal_pod_autoscaler_status_H_ */


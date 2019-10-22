/*
 * v2beta1_resource_metric_status.h
 *
 * ResourceMetricStatus indicates the current value of a resource metric known to Kubernetes, as specified in requests and limits, describing each pod in the current scale target (e.g. CPU or memory).  Such metrics are built in to Kubernetes, and have special scaling options on top of those available to normal per-pod metrics using the \&quot;pods\&quot; source.
 */

#ifndef _v2beta1_resource_metric_status_H_
#define _v2beta1_resource_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v2beta1_resource_metric_status_t {
    int currentAverageUtilization; //numeric
    char *currentAverageValue; // string
    char *name; // string

} v2beta1_resource_metric_status_t;

v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_create(
    int currentAverageUtilization,
    char *currentAverageValue,
    char *name
);

void v2beta1_resource_metric_status_free(v2beta1_resource_metric_status_t *v2beta1_resource_metric_status);

v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_parseFromJSON(cJSON *v2beta1_resource_metric_statusJSON);

cJSON *v2beta1_resource_metric_status_convertToJSON(v2beta1_resource_metric_status_t *v2beta1_resource_metric_status);

#endif /* _v2beta1_resource_metric_status_H_ */


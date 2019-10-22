/*
 * v2beta1_object_metric_status.h
 *
 * ObjectMetricStatus indicates the current value of a metric describing a kubernetes object (for example, hits-per-second on an Ingress object).
 */

#ifndef _v2beta1_object_metric_status_H_
#define _v2beta1_object_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v2beta1_cross_version_object_reference.h"



typedef struct v2beta1_object_metric_status_t {
    char *averageValue; // string
    char *currentValue; // string
    char *metricName; // string
    v1_label_selector_t *selector; //model
    v2beta1_cross_version_object_reference_t *target; //model

} v2beta1_object_metric_status_t;

v2beta1_object_metric_status_t *v2beta1_object_metric_status_create(
    char *averageValue,
    char *currentValue,
    char *metricName,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target
);

void v2beta1_object_metric_status_free(v2beta1_object_metric_status_t *v2beta1_object_metric_status);

v2beta1_object_metric_status_t *v2beta1_object_metric_status_parseFromJSON(cJSON *v2beta1_object_metric_statusJSON);

cJSON *v2beta1_object_metric_status_convertToJSON(v2beta1_object_metric_status_t *v2beta1_object_metric_status);

#endif /* _v2beta1_object_metric_status_H_ */


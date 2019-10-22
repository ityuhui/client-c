/*
 * v2beta1_object_metric_source.h
 *
 * ObjectMetricSource indicates how to scale on a metric describing a kubernetes object (for example, hits-per-second on an Ingress object).
 */

#ifndef _v2beta1_object_metric_source_H_
#define _v2beta1_object_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v2beta1_cross_version_object_reference.h"



typedef struct v2beta1_object_metric_source_t {
    char *averageValue; // string
    char *metricName; // string
    v1_label_selector_t *selector; //model
    v2beta1_cross_version_object_reference_t *target; //model
    char *targetValue; // string

} v2beta1_object_metric_source_t;

v2beta1_object_metric_source_t *v2beta1_object_metric_source_create(
    char *averageValue,
    char *metricName,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target,
    char *targetValue
);

void v2beta1_object_metric_source_free(v2beta1_object_metric_source_t *v2beta1_object_metric_source);

v2beta1_object_metric_source_t *v2beta1_object_metric_source_parseFromJSON(cJSON *v2beta1_object_metric_sourceJSON);

cJSON *v2beta1_object_metric_source_convertToJSON(v2beta1_object_metric_source_t *v2beta1_object_metric_source);

#endif /* _v2beta1_object_metric_source_H_ */


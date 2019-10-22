/*
 * v2beta1_pods_metric_source.h
 *
 * PodsMetricSource indicates how to scale on a metric describing each pod in the current scale target (for example, transactions-processed-per-second). The values will be averaged together before being compared to the target value.
 */

#ifndef _v2beta1_pods_metric_source_H_
#define _v2beta1_pods_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"



typedef struct v2beta1_pods_metric_source_t {
    char *metricName; // string
    v1_label_selector_t *selector; //model
    char *targetAverageValue; // string

} v2beta1_pods_metric_source_t;

v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_create(
    char *metricName,
    v1_label_selector_t *selector,
    char *targetAverageValue
);

void v2beta1_pods_metric_source_free(v2beta1_pods_metric_source_t *v2beta1_pods_metric_source);

v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_parseFromJSON(cJSON *v2beta1_pods_metric_sourceJSON);

cJSON *v2beta1_pods_metric_source_convertToJSON(v2beta1_pods_metric_source_t *v2beta1_pods_metric_source);

#endif /* _v2beta1_pods_metric_source_H_ */


/*
 * v2beta2_pods_metric_source.h
 *
 * PodsMetricSource indicates how to scale on a metric describing each pod in the current scale target (for example, transactions-processed-per-second). The values will be averaged together before being compared to the target value.
 */

#ifndef _v2beta2_pods_metric_source_H_
#define _v2beta2_pods_metric_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v2beta2_metric_identifier.h"
#include "v2beta2_metric_target.h"



typedef struct v2beta2_pods_metric_source_t {
    v2beta2_metric_identifier_t *metric; //model
    v2beta2_metric_target_t *target; //model

} v2beta2_pods_metric_source_t;

v2beta2_pods_metric_source_t *v2beta2_pods_metric_source_create(
    v2beta2_metric_identifier_t *metric,
    v2beta2_metric_target_t *target
);

void v2beta2_pods_metric_source_free(v2beta2_pods_metric_source_t *v2beta2_pods_metric_source);

v2beta2_pods_metric_source_t *v2beta2_pods_metric_source_parseFromJSON(cJSON *v2beta2_pods_metric_sourceJSON);

cJSON *v2beta2_pods_metric_source_convertToJSON(v2beta2_pods_metric_source_t *v2beta2_pods_metric_source);

#endif /* _v2beta2_pods_metric_source_H_ */


/*
 * v2beta2_external_metric_status.h
 *
 * ExternalMetricStatus indicates the current value of a global metric not associated with any Kubernetes object.
 */

#ifndef _v2beta2_external_metric_status_H_
#define _v2beta2_external_metric_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v2beta2_metric_identifier.h"
#include "v2beta2_metric_value_status.h"



typedef struct v2beta2_external_metric_status_t {
    v2beta2_metric_value_status_t *current; //model
    v2beta2_metric_identifier_t *metric; //model

} v2beta2_external_metric_status_t;

v2beta2_external_metric_status_t *v2beta2_external_metric_status_create(
    v2beta2_metric_value_status_t *current,
    v2beta2_metric_identifier_t *metric
);

void v2beta2_external_metric_status_free(v2beta2_external_metric_status_t *v2beta2_external_metric_status);

v2beta2_external_metric_status_t *v2beta2_external_metric_status_parseFromJSON(cJSON *v2beta2_external_metric_statusJSON);

cJSON *v2beta2_external_metric_status_convertToJSON(v2beta2_external_metric_status_t *v2beta2_external_metric_status);

#endif /* _v2beta2_external_metric_status_H_ */


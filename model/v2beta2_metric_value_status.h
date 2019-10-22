/*
 * v2beta2_metric_value_status.h
 *
 * MetricValueStatus holds the current value for a metric
 */

#ifndef _v2beta2_metric_value_status_H_
#define _v2beta2_metric_value_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v2beta2_metric_value_status_t {
    int averageUtilization; //numeric
    char *averageValue; // string
    char *value; // string

} v2beta2_metric_value_status_t;

v2beta2_metric_value_status_t *v2beta2_metric_value_status_create(
    int averageUtilization,
    char *averageValue,
    char *value
);

void v2beta2_metric_value_status_free(v2beta2_metric_value_status_t *v2beta2_metric_value_status);

v2beta2_metric_value_status_t *v2beta2_metric_value_status_parseFromJSON(cJSON *v2beta2_metric_value_statusJSON);

cJSON *v2beta2_metric_value_status_convertToJSON(v2beta2_metric_value_status_t *v2beta2_metric_value_status);

#endif /* _v2beta2_metric_value_status_H_ */


/*
 * v2beta2_metric_spec.h
 *
 * MetricSpec specifies how to scale based on a single metric (only &#x60;type&#x60; and one other matching field should be set at once).
 */

#ifndef _v2beta2_metric_spec_H_
#define _v2beta2_metric_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v2beta2_external_metric_source.h"
#include "v2beta2_object_metric_source.h"
#include "v2beta2_pods_metric_source.h"
#include "v2beta2_resource_metric_source.h"



typedef struct v2beta2_metric_spec_t {
    v2beta2_external_metric_source_t *external; //model
    v2beta2_object_metric_source_t *object; //model
    v2beta2_pods_metric_source_t *pods; //model
    v2beta2_resource_metric_source_t *resource; //model
    char *type; // string

} v2beta2_metric_spec_t;

v2beta2_metric_spec_t *v2beta2_metric_spec_create(
    v2beta2_external_metric_source_t *external,
    v2beta2_object_metric_source_t *object,
    v2beta2_pods_metric_source_t *pods,
    v2beta2_resource_metric_source_t *resource,
    char *type
);

void v2beta2_metric_spec_free(v2beta2_metric_spec_t *v2beta2_metric_spec);

v2beta2_metric_spec_t *v2beta2_metric_spec_parseFromJSON(cJSON *v2beta2_metric_specJSON);

cJSON *v2beta2_metric_spec_convertToJSON(v2beta2_metric_spec_t *v2beta2_metric_spec);

#endif /* _v2beta2_metric_spec_H_ */


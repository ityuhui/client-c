/*
 * v2beta2_horizontal_pod_autoscaler_spec.h
 *
 * HorizontalPodAutoscalerSpec describes the desired functionality of the HorizontalPodAutoscaler.
 */

#ifndef _v2beta2_horizontal_pod_autoscaler_spec_H_
#define _v2beta2_horizontal_pod_autoscaler_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v2beta2_cross_version_object_reference.h"
#include "v2beta2_metric_spec.h"



typedef struct v2beta2_horizontal_pod_autoscaler_spec_t {
    int maxReplicas; //numeric
    list_t *metrics; //nonprimitive container
    int minReplicas; //numeric
    v2beta2_cross_version_object_reference_t *scaleTargetRef; //model

} v2beta2_horizontal_pod_autoscaler_spec_t;

v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_create(
    int maxReplicas,
    list_t *metrics,
    int minReplicas,
    v2beta2_cross_version_object_reference_t *scaleTargetRef
);

void v2beta2_horizontal_pod_autoscaler_spec_free(v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec);

v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_specJSON);

cJSON *v2beta2_horizontal_pod_autoscaler_spec_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec);

#endif /* _v2beta2_horizontal_pod_autoscaler_spec_H_ */


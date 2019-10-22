/*
 * v1_horizontal_pod_autoscaler_spec.h
 *
 * specification of a horizontal pod autoscaler.
 */

#ifndef _v1_horizontal_pod_autoscaler_spec_H_
#define _v1_horizontal_pod_autoscaler_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_cross_version_object_reference.h"



typedef struct v1_horizontal_pod_autoscaler_spec_t {
    int maxReplicas; //numeric
    int minReplicas; //numeric
    v1_cross_version_object_reference_t *scaleTargetRef; //model
    int targetCPUUtilizationPercentage; //numeric

} v1_horizontal_pod_autoscaler_spec_t;

v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_create(
    int maxReplicas,
    int minReplicas,
    v1_cross_version_object_reference_t *scaleTargetRef,
    int targetCPUUtilizationPercentage
);

void v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec);

v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_specJSON);

cJSON *v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec);

#endif /* _v1_horizontal_pod_autoscaler_spec_H_ */


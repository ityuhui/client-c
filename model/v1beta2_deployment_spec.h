/*
 * v1beta2_deployment_spec.h
 *
 * DeploymentSpec is the specification of the desired behavior of the Deployment.
 */

#ifndef _v1beta2_deployment_spec_H_
#define _v1beta2_deployment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"
#include "v1beta2_deployment_strategy.h"



typedef struct v1beta2_deployment_spec_t {
    int minReadySeconds; //numeric
    int paused; //boolean
    int progressDeadlineSeconds; //numeric
    int replicas; //numeric
    int revisionHistoryLimit; //numeric
    v1_label_selector_t *selector; //model
    v1beta2_deployment_strategy_t *strategy; //model
    v1_pod_template_spec_t *template; //model

} v1beta2_deployment_spec_t;

v1beta2_deployment_spec_t *v1beta2_deployment_spec_create(
    int minReadySeconds,
    int paused,
    int progressDeadlineSeconds,
    int replicas,
    int revisionHistoryLimit,
    v1_label_selector_t *selector,
    v1beta2_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *template
);

void v1beta2_deployment_spec_free(v1beta2_deployment_spec_t *v1beta2_deployment_spec);

v1beta2_deployment_spec_t *v1beta2_deployment_spec_parseFromJSON(cJSON *v1beta2_deployment_specJSON);

cJSON *v1beta2_deployment_spec_convertToJSON(v1beta2_deployment_spec_t *v1beta2_deployment_spec);

#endif /* _v1beta2_deployment_spec_H_ */


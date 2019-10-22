/*
 * apps_v1beta1_deployment_spec.h
 *
 * DeploymentSpec is the specification of the desired behavior of the Deployment.
 */

#ifndef _apps_v1beta1_deployment_spec_H_
#define _apps_v1beta1_deployment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "apps_v1beta1_deployment_strategy.h"
#include "apps_v1beta1_rollback_config.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct apps_v1beta1_deployment_spec_t {
    int minReadySeconds; //numeric
    int paused; //boolean
    int progressDeadlineSeconds; //numeric
    int replicas; //numeric
    int revisionHistoryLimit; //numeric
    apps_v1beta1_rollback_config_t *rollbackTo; //model
    v1_label_selector_t *selector; //model
    apps_v1beta1_deployment_strategy_t *strategy; //model
    v1_pod_template_spec_t *template; //model

} apps_v1beta1_deployment_spec_t;

apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_create(
    int minReadySeconds,
    int paused,
    int progressDeadlineSeconds,
    int replicas,
    int revisionHistoryLimit,
    apps_v1beta1_rollback_config_t *rollbackTo,
    v1_label_selector_t *selector,
    apps_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *template
);

void apps_v1beta1_deployment_spec_free(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec);

apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_parseFromJSON(cJSON *apps_v1beta1_deployment_specJSON);

cJSON *apps_v1beta1_deployment_spec_convertToJSON(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec);

#endif /* _apps_v1beta1_deployment_spec_H_ */


/*
 * apps_v1beta1_rolling_update_deployment.h
 *
 * Spec to control the desired behavior of rolling update.
 */

#ifndef _apps_v1beta1_rolling_update_deployment_H_
#define _apps_v1beta1_rolling_update_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct apps_v1beta1_rolling_update_deployment_t {
    object_t *maxSurge; //object
    object_t *maxUnavailable; //object

} apps_v1beta1_rolling_update_deployment_t;

apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_create(
    object_t *maxSurge,
    object_t *maxUnavailable
);

void apps_v1beta1_rolling_update_deployment_free(apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment);

apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *apps_v1beta1_rolling_update_deploymentJSON);

cJSON *apps_v1beta1_rolling_update_deployment_convertToJSON(apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment);

#endif /* _apps_v1beta1_rolling_update_deployment_H_ */


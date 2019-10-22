/*
 * v1_rolling_update_deployment.h
 *
 * Spec to control the desired behavior of rolling update.
 */

#ifndef _v1_rolling_update_deployment_H_
#define _v1_rolling_update_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1_rolling_update_deployment_t {
    object_t *maxSurge; //object
    object_t *maxUnavailable; //object

} v1_rolling_update_deployment_t;

v1_rolling_update_deployment_t *v1_rolling_update_deployment_create(
    object_t *maxSurge,
    object_t *maxUnavailable
);

void v1_rolling_update_deployment_free(v1_rolling_update_deployment_t *v1_rolling_update_deployment);

v1_rolling_update_deployment_t *v1_rolling_update_deployment_parseFromJSON(cJSON *v1_rolling_update_deploymentJSON);

cJSON *v1_rolling_update_deployment_convertToJSON(v1_rolling_update_deployment_t *v1_rolling_update_deployment);

#endif /* _v1_rolling_update_deployment_H_ */


/*
 * extensions_v1beta1_rolling_update_deployment.h
 *
 * Spec to control the desired behavior of rolling update.
 */

#ifndef _extensions_v1beta1_rolling_update_deployment_H_
#define _extensions_v1beta1_rolling_update_deployment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct extensions_v1beta1_rolling_update_deployment_t {
    object_t *maxSurge; //object
    object_t *maxUnavailable; //object

} extensions_v1beta1_rolling_update_deployment_t;

extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_create(
    object_t *maxSurge,
    object_t *maxUnavailable
);

void extensions_v1beta1_rolling_update_deployment_free(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment);

extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *extensions_v1beta1_rolling_update_deploymentJSON);

cJSON *extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment);

#endif /* _extensions_v1beta1_rolling_update_deployment_H_ */


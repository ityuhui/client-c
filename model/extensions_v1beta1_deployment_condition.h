/*
 * extensions_v1beta1_deployment_condition.h
 *
 * DeploymentCondition describes the state of a deployment at a certain point.
 */

#ifndef _extensions_v1beta1_deployment_condition_H_
#define _extensions_v1beta1_deployment_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct extensions_v1beta1_deployment_condition_t {
    char *lastTransitionTime; //date time
    char *lastUpdateTime; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} extensions_v1beta1_deployment_condition_t;

extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition_create(
    char *lastTransitionTime,
    char *lastUpdateTime,
    char *message,
    char *reason,
    char *status,
    char *type
);

void extensions_v1beta1_deployment_condition_free(extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition);

extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition_parseFromJSON(cJSON *extensions_v1beta1_deployment_conditionJSON);

cJSON *extensions_v1beta1_deployment_condition_convertToJSON(extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition);

#endif /* _extensions_v1beta1_deployment_condition_H_ */


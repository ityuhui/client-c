/*
 * v1_deployment_condition.h
 *
 * DeploymentCondition describes the state of a deployment at a certain point.
 */

#ifndef _v1_deployment_condition_H_
#define _v1_deployment_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_deployment_condition_t {
    char *lastTransitionTime; //date time
    char *lastUpdateTime; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_deployment_condition_t;

v1_deployment_condition_t *v1_deployment_condition_create(
    char *lastTransitionTime,
    char *lastUpdateTime,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_deployment_condition_free(v1_deployment_condition_t *v1_deployment_condition);

v1_deployment_condition_t *v1_deployment_condition_parseFromJSON(cJSON *v1_deployment_conditionJSON);

cJSON *v1_deployment_condition_convertToJSON(v1_deployment_condition_t *v1_deployment_condition);

#endif /* _v1_deployment_condition_H_ */


/*
 * apps_v1beta1_deployment_status.h
 *
 * DeploymentStatus is the most recently observed status of the Deployment.
 */

#ifndef _apps_v1beta1_deployment_status_H_
#define _apps_v1beta1_deployment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "apps_v1beta1_deployment_condition.h"



typedef struct apps_v1beta1_deployment_status_t {
    int availableReplicas; //numeric
    int collisionCount; //numeric
    list_t *conditions; //nonprimitive container
    long observedGeneration; //numeric
    int readyReplicas; //numeric
    int replicas; //numeric
    int unavailableReplicas; //numeric
    int updatedReplicas; //numeric

} apps_v1beta1_deployment_status_t;

apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status_create(
    int availableReplicas,
    int collisionCount,
    list_t *conditions,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    int unavailableReplicas,
    int updatedReplicas
);

void apps_v1beta1_deployment_status_free(apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status);

apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status_parseFromJSON(cJSON *apps_v1beta1_deployment_statusJSON);

cJSON *apps_v1beta1_deployment_status_convertToJSON(apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status);

#endif /* _apps_v1beta1_deployment_status_H_ */


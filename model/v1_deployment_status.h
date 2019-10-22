/*
 * v1_deployment_status.h
 *
 * DeploymentStatus is the most recently observed status of the Deployment.
 */

#ifndef _v1_deployment_status_H_
#define _v1_deployment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_deployment_condition.h"



typedef struct v1_deployment_status_t {
    int availableReplicas; //numeric
    int collisionCount; //numeric
    list_t *conditions; //nonprimitive container
    long observedGeneration; //numeric
    int readyReplicas; //numeric
    int replicas; //numeric
    int unavailableReplicas; //numeric
    int updatedReplicas; //numeric

} v1_deployment_status_t;

v1_deployment_status_t *v1_deployment_status_create(
    int availableReplicas,
    int collisionCount,
    list_t *conditions,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    int unavailableReplicas,
    int updatedReplicas
);

void v1_deployment_status_free(v1_deployment_status_t *v1_deployment_status);

v1_deployment_status_t *v1_deployment_status_parseFromJSON(cJSON *v1_deployment_statusJSON);

cJSON *v1_deployment_status_convertToJSON(v1_deployment_status_t *v1_deployment_status);

#endif /* _v1_deployment_status_H_ */


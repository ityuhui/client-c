/*
 * extensions_v1beta1_deployment_status.h
 *
 * DeploymentStatus is the most recently observed status of the Deployment.
 */

#ifndef _extensions_v1beta1_deployment_status_H_
#define _extensions_v1beta1_deployment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_deployment_condition.h"



typedef struct extensions_v1beta1_deployment_status_t {
    int availableReplicas; //numeric
    int collisionCount; //numeric
    list_t *conditions; //nonprimitive container
    long observedGeneration; //numeric
    int readyReplicas; //numeric
    int replicas; //numeric
    int unavailableReplicas; //numeric
    int updatedReplicas; //numeric

} extensions_v1beta1_deployment_status_t;

extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_create(
    int availableReplicas,
    int collisionCount,
    list_t *conditions,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    int unavailableReplicas,
    int updatedReplicas
);

void extensions_v1beta1_deployment_status_free(extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status);

extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_parseFromJSON(cJSON *extensions_v1beta1_deployment_statusJSON);

cJSON *extensions_v1beta1_deployment_status_convertToJSON(extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status);

#endif /* _extensions_v1beta1_deployment_status_H_ */


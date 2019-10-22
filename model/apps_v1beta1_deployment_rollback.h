/*
 * apps_v1beta1_deployment_rollback.h
 *
 * DEPRECATED. DeploymentRollback stores the information required to rollback a deployment.
 */

#ifndef _apps_v1beta1_deployment_rollback_H_
#define _apps_v1beta1_deployment_rollback_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "apps_v1beta1_rollback_config.h"



typedef struct apps_v1beta1_deployment_rollback_t {
    char *apiVersion; // string
    char *kind; // string
    char *name; // string
    apps_v1beta1_rollback_config_t *rollbackTo; //model
    list_t* updatedAnnotations; //map

} apps_v1beta1_deployment_rollback_t;

apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_create(
    char *apiVersion,
    char *kind,
    char *name,
    apps_v1beta1_rollback_config_t *rollbackTo,
    list_t* updatedAnnotations
);

void apps_v1beta1_deployment_rollback_free(apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback);

apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback_parseFromJSON(cJSON *apps_v1beta1_deployment_rollbackJSON);

cJSON *apps_v1beta1_deployment_rollback_convertToJSON(apps_v1beta1_deployment_rollback_t *apps_v1beta1_deployment_rollback);

#endif /* _apps_v1beta1_deployment_rollback_H_ */


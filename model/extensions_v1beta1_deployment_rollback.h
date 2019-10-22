/*
 * extensions_v1beta1_deployment_rollback.h
 *
 * DEPRECATED. DeploymentRollback stores the information required to rollback a deployment.
 */

#ifndef _extensions_v1beta1_deployment_rollback_H_
#define _extensions_v1beta1_deployment_rollback_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_rollback_config.h"



typedef struct extensions_v1beta1_deployment_rollback_t {
    char *apiVersion; // string
    char *kind; // string
    char *name; // string
    extensions_v1beta1_rollback_config_t *rollbackTo; //model
    list_t* updatedAnnotations; //map

} extensions_v1beta1_deployment_rollback_t;

extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_create(
    char *apiVersion,
    char *kind,
    char *name,
    extensions_v1beta1_rollback_config_t *rollbackTo,
    list_t* updatedAnnotations
);

void extensions_v1beta1_deployment_rollback_free(extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback);

extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_parseFromJSON(cJSON *extensions_v1beta1_deployment_rollbackJSON);

cJSON *extensions_v1beta1_deployment_rollback_convertToJSON(extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback);

#endif /* _extensions_v1beta1_deployment_rollback_H_ */


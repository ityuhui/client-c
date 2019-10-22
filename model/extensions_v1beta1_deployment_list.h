/*
 * extensions_v1beta1_deployment_list.h
 *
 * DeploymentList is a list of Deployments.
 */

#ifndef _extensions_v1beta1_deployment_list_H_
#define _extensions_v1beta1_deployment_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_deployment.h"
#include "v1_list_meta.h"



typedef struct extensions_v1beta1_deployment_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} extensions_v1beta1_deployment_list_t;

extensions_v1beta1_deployment_list_t *extensions_v1beta1_deployment_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void extensions_v1beta1_deployment_list_free(extensions_v1beta1_deployment_list_t *extensions_v1beta1_deployment_list);

extensions_v1beta1_deployment_list_t *extensions_v1beta1_deployment_list_parseFromJSON(cJSON *extensions_v1beta1_deployment_listJSON);

cJSON *extensions_v1beta1_deployment_list_convertToJSON(extensions_v1beta1_deployment_list_t *extensions_v1beta1_deployment_list);

#endif /* _extensions_v1beta1_deployment_list_H_ */


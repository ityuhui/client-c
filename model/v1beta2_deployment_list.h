/*
 * v1beta2_deployment_list.h
 *
 * DeploymentList is a list of Deployments.
 */

#ifndef _v1beta2_deployment_list_H_
#define _v1beta2_deployment_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_list_meta.h"
#include "v1beta2_deployment.h"



typedef struct v1beta2_deployment_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1beta2_deployment_list_t;

v1beta2_deployment_list_t *v1beta2_deployment_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta2_deployment_list_free(v1beta2_deployment_list_t *v1beta2_deployment_list);

v1beta2_deployment_list_t *v1beta2_deployment_list_parseFromJSON(cJSON *v1beta2_deployment_listJSON);

cJSON *v1beta2_deployment_list_convertToJSON(v1beta2_deployment_list_t *v1beta2_deployment_list);

#endif /* _v1beta2_deployment_list_H_ */


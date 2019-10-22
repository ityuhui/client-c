/*
 * v1_component_status.h
 *
 * ComponentStatus (and ComponentStatusList) holds the cluster validation info.
 */

#ifndef _v1_component_status_H_
#define _v1_component_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_component_condition.h"
#include "v1_object_meta.h"



typedef struct v1_component_status_t {
    char *apiVersion; // string
    list_t *conditions; //nonprimitive container
    char *kind; // string
    v1_object_meta_t *metadata; //model

} v1_component_status_t;

v1_component_status_t *v1_component_status_create(
    char *apiVersion,
    list_t *conditions,
    char *kind,
    v1_object_meta_t *metadata
);

void v1_component_status_free(v1_component_status_t *v1_component_status);

v1_component_status_t *v1_component_status_parseFromJSON(cJSON *v1_component_statusJSON);

cJSON *v1_component_status_convertToJSON(v1_component_status_t *v1_component_status);

#endif /* _v1_component_status_H_ */


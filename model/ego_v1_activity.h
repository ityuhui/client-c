/*
 * object.h
 */

#ifndef _EGO_V1_ACTIVITY_H_
#define _EGO_V1_ACTIVITY_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "ego_v1_activity_spec.h"
#include "ego_v1_activity_status.h"


typedef struct ego_v1_activity {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    ego_v1_activity_spec_t *spec; //model
    ego_v1_activity_status_t *status; //model
} ego_v1_activity_t;

ego_v1_activity_t *ego_v1_activity_create();

void ego_v1_activity_free(ego_v1_activity_t *object);

ego_v1_activity_t *ego_v1_activity_parseFromJSON(char *jsonString);

cJSON *ego_v1_activity_convertToJSON(ego_v1_activity_t *activity);

#endif /* _EGO_V1_ACTIVITY_H_ */

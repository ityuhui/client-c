/*
 * object.h
 */

#ifndef _object_H_
#define _object_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "ego_v1_activity_spec.h"
#include "ego_v1_activity_status.h"


typedef struct activity {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    ego_v1_activity_spec_t *spec; //model
    ego_v1_activity_status_t *status; //model
} activity_t;

activity_t *activity_create();

void activity_free(activity_t *object);

activity_t *activity_parseFromJSON(char *jsonString);

cJSON *activity_convertToJSON(activity_t *activity);

#endif /* _object_H_ */

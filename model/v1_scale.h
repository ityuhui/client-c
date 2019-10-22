/*
 * v1_scale.h
 *
 * Scale represents a scaling request for a resource.
 */

#ifndef _v1_scale_H_
#define _v1_scale_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_scale_spec.h"
#include "v1_scale_status.h"



typedef struct v1_scale_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_scale_spec_t *spec; //model
    v1_scale_status_t *status; //model

} v1_scale_t;

v1_scale_t *v1_scale_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_scale_spec_t *spec,
    v1_scale_status_t *status
);

void v1_scale_free(v1_scale_t *v1_scale);

v1_scale_t *v1_scale_parseFromJSON(cJSON *v1_scaleJSON);

cJSON *v1_scale_convertToJSON(v1_scale_t *v1_scale);

#endif /* _v1_scale_H_ */


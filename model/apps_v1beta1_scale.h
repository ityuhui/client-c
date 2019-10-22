/*
 * apps_v1beta1_scale.h
 *
 * Scale represents a scaling request for a resource.
 */

#ifndef _apps_v1beta1_scale_H_
#define _apps_v1beta1_scale_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "apps_v1beta1_scale_spec.h"
#include "apps_v1beta1_scale_status.h"
#include "v1_object_meta.h"



typedef struct apps_v1beta1_scale_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    apps_v1beta1_scale_spec_t *spec; //model
    apps_v1beta1_scale_status_t *status; //model

} apps_v1beta1_scale_t;

apps_v1beta1_scale_t *apps_v1beta1_scale_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    apps_v1beta1_scale_spec_t *spec,
    apps_v1beta1_scale_status_t *status
);

void apps_v1beta1_scale_free(apps_v1beta1_scale_t *apps_v1beta1_scale);

apps_v1beta1_scale_t *apps_v1beta1_scale_parseFromJSON(cJSON *apps_v1beta1_scaleJSON);

cJSON *apps_v1beta1_scale_convertToJSON(apps_v1beta1_scale_t *apps_v1beta1_scale);

#endif /* _apps_v1beta1_scale_H_ */


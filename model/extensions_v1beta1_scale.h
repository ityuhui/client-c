/*
 * extensions_v1beta1_scale.h
 *
 * represents a scaling request for a resource.
 */

#ifndef _extensions_v1beta1_scale_H_
#define _extensions_v1beta1_scale_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_scale_spec.h"
#include "extensions_v1beta1_scale_status.h"
#include "v1_object_meta.h"



typedef struct extensions_v1beta1_scale_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    extensions_v1beta1_scale_spec_t *spec; //model
    extensions_v1beta1_scale_status_t *status; //model

} extensions_v1beta1_scale_t;

extensions_v1beta1_scale_t *extensions_v1beta1_scale_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    extensions_v1beta1_scale_spec_t *spec,
    extensions_v1beta1_scale_status_t *status
);

void extensions_v1beta1_scale_free(extensions_v1beta1_scale_t *extensions_v1beta1_scale);

extensions_v1beta1_scale_t *extensions_v1beta1_scale_parseFromJSON(cJSON *extensions_v1beta1_scaleJSON);

cJSON *extensions_v1beta1_scale_convertToJSON(extensions_v1beta1_scale_t *extensions_v1beta1_scale);

#endif /* _extensions_v1beta1_scale_H_ */


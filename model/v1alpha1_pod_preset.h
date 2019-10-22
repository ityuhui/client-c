/*
 * v1alpha1_pod_preset.h
 *
 * PodPreset is a policy resource that defines additional runtime requirements for a Pod.
 */

#ifndef _v1alpha1_pod_preset_H_
#define _v1alpha1_pod_preset_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1alpha1_pod_preset_spec.h"



typedef struct v1alpha1_pod_preset_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1alpha1_pod_preset_spec_t *spec; //model

} v1alpha1_pod_preset_t;

v1alpha1_pod_preset_t *v1alpha1_pod_preset_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_pod_preset_spec_t *spec
);

void v1alpha1_pod_preset_free(v1alpha1_pod_preset_t *v1alpha1_pod_preset);

v1alpha1_pod_preset_t *v1alpha1_pod_preset_parseFromJSON(cJSON *v1alpha1_pod_presetJSON);

cJSON *v1alpha1_pod_preset_convertToJSON(v1alpha1_pod_preset_t *v1alpha1_pod_preset);

#endif /* _v1alpha1_pod_preset_H_ */


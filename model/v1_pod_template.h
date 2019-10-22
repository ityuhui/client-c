/*
 * v1_pod_template.h
 *
 * PodTemplate describes a template for creating copies of a predefined pod.
 */

#ifndef _v1_pod_template_H_
#define _v1_pod_template_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_pod_template_spec.h"



typedef struct v1_pod_template_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_pod_template_spec_t *template; //model

} v1_pod_template_t;

v1_pod_template_t *v1_pod_template_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_template_spec_t *template
);

void v1_pod_template_free(v1_pod_template_t *v1_pod_template);

v1_pod_template_t *v1_pod_template_parseFromJSON(cJSON *v1_pod_templateJSON);

cJSON *v1_pod_template_convertToJSON(v1_pod_template_t *v1_pod_template);

#endif /* _v1_pod_template_H_ */


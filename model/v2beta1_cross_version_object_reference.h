/*
 * v2beta1_cross_version_object_reference.h
 *
 * CrossVersionObjectReference contains enough information to let you identify the referred resource.
 */

#ifndef _v2beta1_cross_version_object_reference_H_
#define _v2beta1_cross_version_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v2beta1_cross_version_object_reference_t {
    char *apiVersion; // string
    char *kind; // string
    char *name; // string

} v2beta1_cross_version_object_reference_t;

v2beta1_cross_version_object_reference_t *v2beta1_cross_version_object_reference_create(
    char *apiVersion,
    char *kind,
    char *name
);

void v2beta1_cross_version_object_reference_free(v2beta1_cross_version_object_reference_t *v2beta1_cross_version_object_reference);

v2beta1_cross_version_object_reference_t *v2beta1_cross_version_object_reference_parseFromJSON(cJSON *v2beta1_cross_version_object_referenceJSON);

cJSON *v2beta1_cross_version_object_reference_convertToJSON(v2beta1_cross_version_object_reference_t *v2beta1_cross_version_object_reference);

#endif /* _v2beta1_cross_version_object_reference_H_ */


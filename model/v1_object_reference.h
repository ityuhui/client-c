/*
 * v1_object_reference.h
 *
 * ObjectReference contains enough information to let you inspect or modify the referred object.
 */

#ifndef _v1_object_reference_H_
#define _v1_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_object_reference_t {
    char *apiVersion; // string
    char *fieldPath; // string
    char *kind; // string
    char *name; // string
    char *namespace; // string
    char *resourceVersion; // string
    char *uid; // string

} v1_object_reference_t;

v1_object_reference_t *v1_object_reference_create(
    char *apiVersion,
    char *fieldPath,
    char *kind,
    char *name,
    char *namespace,
    char *resourceVersion,
    char *uid
);

void v1_object_reference_free(v1_object_reference_t *v1_object_reference);

v1_object_reference_t *v1_object_reference_parseFromJSON(cJSON *v1_object_referenceJSON);

cJSON *v1_object_reference_convertToJSON(v1_object_reference_t *v1_object_reference);

#endif /* _v1_object_reference_H_ */


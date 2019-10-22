/*
 * v1_priority_class.h
 *
 * PriorityClass defines mapping from a priority class name to the priority integer value. The value can be any valid integer.
 */

#ifndef _v1_priority_class_H_
#define _v1_priority_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"



typedef struct v1_priority_class_t {
    char *apiVersion; // string
    char *description; // string
    int globalDefault; //boolean
    char *kind; // string
    v1_object_meta_t *metadata; //model
    char *preemptionPolicy; // string
    int value; //numeric

} v1_priority_class_t;

v1_priority_class_t *v1_priority_class_create(
    char *apiVersion,
    char *description,
    int globalDefault,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemptionPolicy,
    int value
);

void v1_priority_class_free(v1_priority_class_t *v1_priority_class);

v1_priority_class_t *v1_priority_class_parseFromJSON(cJSON *v1_priority_classJSON);

cJSON *v1_priority_class_convertToJSON(v1_priority_class_t *v1_priority_class);

#endif /* _v1_priority_class_H_ */


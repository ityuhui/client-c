/*
 * v1beta1_priority_class.h
 *
 * DEPRECATED - This group version of PriorityClass is deprecated by scheduling.k8s.io/v1/PriorityClass. PriorityClass defines mapping from a priority class name to the priority integer value. The value can be any valid integer.
 */

#ifndef _v1beta1_priority_class_H_
#define _v1beta1_priority_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"



typedef struct v1beta1_priority_class_t {
    char *apiVersion; // string
    char *description; // string
    int globalDefault; //boolean
    char *kind; // string
    v1_object_meta_t *metadata; //model
    char *preemptionPolicy; // string
    int value; //numeric

} v1beta1_priority_class_t;

v1beta1_priority_class_t *v1beta1_priority_class_create(
    char *apiVersion,
    char *description,
    int globalDefault,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemptionPolicy,
    int value
);

void v1beta1_priority_class_free(v1beta1_priority_class_t *v1beta1_priority_class);

v1beta1_priority_class_t *v1beta1_priority_class_parseFromJSON(cJSON *v1beta1_priority_classJSON);

cJSON *v1beta1_priority_class_convertToJSON(v1beta1_priority_class_t *v1beta1_priority_class);

#endif /* _v1beta1_priority_class_H_ */


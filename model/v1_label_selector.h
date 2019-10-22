/*
 * v1_label_selector.h
 *
 * A label selector is a label query over a set of resources. The result of matchLabels and matchExpressions are ANDed. An empty label selector matches all objects. A null label selector matches no objects.
 */

#ifndef _v1_label_selector_H_
#define _v1_label_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector_requirement.h"



typedef struct v1_label_selector_t {
    list_t *matchExpressions; //nonprimitive container
    list_t* matchLabels; //map

} v1_label_selector_t;

v1_label_selector_t *v1_label_selector_create(
    list_t *matchExpressions,
    list_t* matchLabels
);

void v1_label_selector_free(v1_label_selector_t *v1_label_selector);

v1_label_selector_t *v1_label_selector_parseFromJSON(cJSON *v1_label_selectorJSON);

cJSON *v1_label_selector_convertToJSON(v1_label_selector_t *v1_label_selector);

#endif /* _v1_label_selector_H_ */


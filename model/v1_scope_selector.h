/*
 * v1_scope_selector.h
 *
 * A scope selector represents the AND of the selectors represented by the scoped-resource selector requirements.
 */

#ifndef _v1_scope_selector_H_
#define _v1_scope_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_scoped_resource_selector_requirement.h"



typedef struct v1_scope_selector_t {
    list_t *matchExpressions; //nonprimitive container

} v1_scope_selector_t;

v1_scope_selector_t *v1_scope_selector_create(
    list_t *matchExpressions
);

void v1_scope_selector_free(v1_scope_selector_t *v1_scope_selector);

v1_scope_selector_t *v1_scope_selector_parseFromJSON(cJSON *v1_scope_selectorJSON);

cJSON *v1_scope_selector_convertToJSON(v1_scope_selector_t *v1_scope_selector);

#endif /* _v1_scope_selector_H_ */


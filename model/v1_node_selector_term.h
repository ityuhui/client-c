/*
 * v1_node_selector_term.h
 *
 * A null or empty node selector term matches no objects. The requirements of them are ANDed. The TopologySelectorTerm type implements a subset of the NodeSelectorTerm.
 */

#ifndef _v1_node_selector_term_H_
#define _v1_node_selector_term_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_node_selector_requirement.h"



typedef struct v1_node_selector_term_t {
    list_t *matchExpressions; //nonprimitive container
    list_t *matchFields; //nonprimitive container

} v1_node_selector_term_t;

v1_node_selector_term_t *v1_node_selector_term_create(
    list_t *matchExpressions,
    list_t *matchFields
);

void v1_node_selector_term_free(v1_node_selector_term_t *v1_node_selector_term);

v1_node_selector_term_t *v1_node_selector_term_parseFromJSON(cJSON *v1_node_selector_termJSON);

cJSON *v1_node_selector_term_convertToJSON(v1_node_selector_term_t *v1_node_selector_term);

#endif /* _v1_node_selector_term_H_ */


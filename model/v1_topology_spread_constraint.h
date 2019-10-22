/*
 * v1_topology_spread_constraint.h
 *
 * TopologySpreadConstraint specifies how to spread matching pods among the given topology.
 */

#ifndef _v1_topology_spread_constraint_H_
#define _v1_topology_spread_constraint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"



typedef struct v1_topology_spread_constraint_t {
    v1_label_selector_t *labelSelector; //model
    int maxSkew; //numeric
    char *topologyKey; // string
    char *whenUnsatisfiable; // string

} v1_topology_spread_constraint_t;

v1_topology_spread_constraint_t *v1_topology_spread_constraint_create(
    v1_label_selector_t *labelSelector,
    int maxSkew,
    char *topologyKey,
    char *whenUnsatisfiable
);

void v1_topology_spread_constraint_free(v1_topology_spread_constraint_t *v1_topology_spread_constraint);

v1_topology_spread_constraint_t *v1_topology_spread_constraint_parseFromJSON(cJSON *v1_topology_spread_constraintJSON);

cJSON *v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_t *v1_topology_spread_constraint);

#endif /* _v1_topology_spread_constraint_H_ */


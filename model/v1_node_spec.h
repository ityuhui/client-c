/*
 * v1_node_spec.h
 *
 * NodeSpec describes the attributes that a node is created with.
 */

#ifndef _v1_node_spec_H_
#define _v1_node_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_node_config_source.h"
#include "v1_taint.h"



typedef struct v1_node_spec_t {
    v1_node_config_source_t *configSource; //model
    char *externalID; // string
    char *podCIDR; // string
    list_t *podCIDRs; //primitive container
    char *providerID; // string
    list_t *taints; //nonprimitive container
    int unschedulable; //boolean

} v1_node_spec_t;

v1_node_spec_t *v1_node_spec_create(
    v1_node_config_source_t *configSource,
    char *externalID,
    char *podCIDR,
    list_t *podCIDRs,
    char *providerID,
    list_t *taints,
    int unschedulable
);

void v1_node_spec_free(v1_node_spec_t *v1_node_spec);

v1_node_spec_t *v1_node_spec_parseFromJSON(cJSON *v1_node_specJSON);

cJSON *v1_node_spec_convertToJSON(v1_node_spec_t *v1_node_spec);

#endif /* _v1_node_spec_H_ */


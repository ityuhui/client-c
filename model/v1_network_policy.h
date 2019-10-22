/*
 * v1_network_policy.h
 *
 * NetworkPolicy describes what network traffic is allowed for a set of Pods
 */

#ifndef _v1_network_policy_H_
#define _v1_network_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_network_policy_spec.h"
#include "v1_object_meta.h"



typedef struct v1_network_policy_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_network_policy_spec_t *spec; //model

} v1_network_policy_t;

v1_network_policy_t *v1_network_policy_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_network_policy_spec_t *spec
);

void v1_network_policy_free(v1_network_policy_t *v1_network_policy);

v1_network_policy_t *v1_network_policy_parseFromJSON(cJSON *v1_network_policyJSON);

cJSON *v1_network_policy_convertToJSON(v1_network_policy_t *v1_network_policy);

#endif /* _v1_network_policy_H_ */


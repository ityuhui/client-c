/*
 * v1_affinity.h
 *
 * Affinity is a group of affinity scheduling rules.
 */

#ifndef _v1_affinity_H_
#define _v1_affinity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_node_affinity.h"
#include "v1_pod_affinity.h"
#include "v1_pod_anti_affinity.h"



typedef struct v1_affinity_t {
    v1_node_affinity_t *nodeAffinity; //model
    v1_pod_affinity_t *podAffinity; //model
    v1_pod_anti_affinity_t *podAntiAffinity; //model

} v1_affinity_t;

v1_affinity_t *v1_affinity_create(
    v1_node_affinity_t *nodeAffinity,
    v1_pod_affinity_t *podAffinity,
    v1_pod_anti_affinity_t *podAntiAffinity
);

void v1_affinity_free(v1_affinity_t *v1_affinity);

v1_affinity_t *v1_affinity_parseFromJSON(cJSON *v1_affinityJSON);

cJSON *v1_affinity_convertToJSON(v1_affinity_t *v1_affinity);

#endif /* _v1_affinity_H_ */


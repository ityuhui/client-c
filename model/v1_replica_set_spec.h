/*
 * v1_replica_set_spec.h
 *
 * ReplicaSetSpec is the specification of a ReplicaSet.
 */

#ifndef _v1_replica_set_spec_H_
#define _v1_replica_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct v1_replica_set_spec_t {
    int minReadySeconds; //numeric
    int replicas; //numeric
    v1_label_selector_t *selector; //model
    v1_pod_template_spec_t *template; //model

} v1_replica_set_spec_t;

v1_replica_set_spec_t *v1_replica_set_spec_create(
    int minReadySeconds,
    int replicas,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template
);

void v1_replica_set_spec_free(v1_replica_set_spec_t *v1_replica_set_spec);

v1_replica_set_spec_t *v1_replica_set_spec_parseFromJSON(cJSON *v1_replica_set_specJSON);

cJSON *v1_replica_set_spec_convertToJSON(v1_replica_set_spec_t *v1_replica_set_spec);

#endif /* _v1_replica_set_spec_H_ */


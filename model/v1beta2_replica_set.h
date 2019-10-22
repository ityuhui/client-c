/*
 * v1beta2_replica_set.h
 *
 * DEPRECATED - This group version of ReplicaSet is deprecated by apps/v1/ReplicaSet. See the release notes for more information. ReplicaSet ensures that a specified number of pod replicas are running at any given time.
 */

#ifndef _v1beta2_replica_set_H_
#define _v1beta2_replica_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta2_replica_set_spec.h"
#include "v1beta2_replica_set_status.h"



typedef struct v1beta2_replica_set_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1beta2_replica_set_spec_t *spec; //model
    v1beta2_replica_set_status_t *status; //model

} v1beta2_replica_set_t;

v1beta2_replica_set_t *v1beta2_replica_set_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_replica_set_spec_t *spec,
    v1beta2_replica_set_status_t *status
);

void v1beta2_replica_set_free(v1beta2_replica_set_t *v1beta2_replica_set);

v1beta2_replica_set_t *v1beta2_replica_set_parseFromJSON(cJSON *v1beta2_replica_setJSON);

cJSON *v1beta2_replica_set_convertToJSON(v1beta2_replica_set_t *v1beta2_replica_set);

#endif /* _v1beta2_replica_set_H_ */


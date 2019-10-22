/*
 * v1beta1_lease.h
 *
 * Lease defines a lease concept.
 */

#ifndef _v1beta1_lease_H_
#define _v1beta1_lease_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta1_lease_spec.h"



typedef struct v1beta1_lease_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1beta1_lease_spec_t *spec; //model

} v1beta1_lease_t;

v1beta1_lease_t *v1beta1_lease_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_lease_spec_t *spec
);

void v1beta1_lease_free(v1beta1_lease_t *v1beta1_lease);

v1beta1_lease_t *v1beta1_lease_parseFromJSON(cJSON *v1beta1_leaseJSON);

cJSON *v1beta1_lease_convertToJSON(v1beta1_lease_t *v1beta1_lease);

#endif /* _v1beta1_lease_H_ */


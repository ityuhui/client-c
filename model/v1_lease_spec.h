/*
 * v1_lease_spec.h
 *
 * LeaseSpec is a specification of a Lease.
 */

#ifndef _v1_lease_spec_H_
#define _v1_lease_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_lease_spec_t {
    char *acquireTime; //date time
    char *holderIdentity; // string
    int leaseDurationSeconds; //numeric
    int leaseTransitions; //numeric
    char *renewTime; //date time

} v1_lease_spec_t;

v1_lease_spec_t *v1_lease_spec_create(
    char *acquireTime,
    char *holderIdentity,
    int leaseDurationSeconds,
    int leaseTransitions,
    char *renewTime
);

void v1_lease_spec_free(v1_lease_spec_t *v1_lease_spec);

v1_lease_spec_t *v1_lease_spec_parseFromJSON(cJSON *v1_lease_specJSON);

cJSON *v1_lease_spec_convertToJSON(v1_lease_spec_t *v1_lease_spec);

#endif /* _v1_lease_spec_H_ */


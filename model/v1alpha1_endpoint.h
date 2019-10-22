/*
 * v1alpha1_endpoint.h
 *
 * Endpoint represents a single logical \&quot;backend\&quot; implementing a service.
 */

#ifndef _v1alpha1_endpoint_H_
#define _v1alpha1_endpoint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_reference.h"
#include "v1alpha1_endpoint_conditions.h"



typedef struct v1alpha1_endpoint_t {
    list_t *addresses; //primitive container
    v1alpha1_endpoint_conditions_t *conditions; //model
    char *hostname; // string
    v1_object_reference_t *targetRef; //model
    list_t* topology; //map

} v1alpha1_endpoint_t;

v1alpha1_endpoint_t *v1alpha1_endpoint_create(
    list_t *addresses,
    v1alpha1_endpoint_conditions_t *conditions,
    char *hostname,
    v1_object_reference_t *targetRef,
    list_t* topology
);

void v1alpha1_endpoint_free(v1alpha1_endpoint_t *v1alpha1_endpoint);

v1alpha1_endpoint_t *v1alpha1_endpoint_parseFromJSON(cJSON *v1alpha1_endpointJSON);

cJSON *v1alpha1_endpoint_convertToJSON(v1alpha1_endpoint_t *v1alpha1_endpoint);

#endif /* _v1alpha1_endpoint_H_ */


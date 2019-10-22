/*
 * v1alpha1_endpoint_slice.h
 *
 * EndpointSlice represents a subset of the endpoints that implement a service. For a given service there may be multiple EndpointSlice objects, selected by labels, which must be joined to produce the full set of endpoints.
 */

#ifndef _v1alpha1_endpoint_slice_H_
#define _v1alpha1_endpoint_slice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1alpha1_endpoint.h"
#include "v1alpha1_endpoint_port.h"



typedef struct v1alpha1_endpoint_slice_t {
    char *addressType; // string
    char *apiVersion; // string
    list_t *endpoints; //nonprimitive container
    char *kind; // string
    v1_object_meta_t *metadata; //model
    list_t *ports; //nonprimitive container

} v1alpha1_endpoint_slice_t;

v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice_create(
    char *addressType,
    char *apiVersion,
    list_t *endpoints,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *ports
);

void v1alpha1_endpoint_slice_free(v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice);

v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice_parseFromJSON(cJSON *v1alpha1_endpoint_sliceJSON);

cJSON *v1alpha1_endpoint_slice_convertToJSON(v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice);

#endif /* _v1alpha1_endpoint_slice_H_ */


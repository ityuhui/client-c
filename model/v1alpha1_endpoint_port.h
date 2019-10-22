/*
 * v1alpha1_endpoint_port.h
 *
 * EndpointPort represents a Port used by an EndpointSlice
 */

#ifndef _v1alpha1_endpoint_port_H_
#define _v1alpha1_endpoint_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1alpha1_endpoint_port_t {
    char *name; // string
    int port; //numeric
    char *protocol; // string

} v1alpha1_endpoint_port_t;

v1alpha1_endpoint_port_t *v1alpha1_endpoint_port_create(
    char *name,
    int port,
    char *protocol
);

void v1alpha1_endpoint_port_free(v1alpha1_endpoint_port_t *v1alpha1_endpoint_port);

v1alpha1_endpoint_port_t *v1alpha1_endpoint_port_parseFromJSON(cJSON *v1alpha1_endpoint_portJSON);

cJSON *v1alpha1_endpoint_port_convertToJSON(v1alpha1_endpoint_port_t *v1alpha1_endpoint_port);

#endif /* _v1alpha1_endpoint_port_H_ */


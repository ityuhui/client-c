/*
 * v1_service_port.h
 *
 * ServicePort contains information on service&#39;s port.
 */

#ifndef _v1_service_port_H_
#define _v1_service_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct v1_service_port_t {
    char *name; // string
    int nodePort; //numeric
    int port; //numeric
    char *protocol; // string
    object_t *targetPort; //object

} v1_service_port_t;

v1_service_port_t *v1_service_port_create(
    char *name,
    int nodePort,
    int port,
    char *protocol,
    object_t *targetPort
);

void v1_service_port_free(v1_service_port_t *v1_service_port);

v1_service_port_t *v1_service_port_parseFromJSON(cJSON *v1_service_portJSON);

cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port);

#endif /* _v1_service_port_H_ */


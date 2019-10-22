/*
 * networking_v1beta1_ingress_backend.h
 *
 * IngressBackend describes all endpoints for a given service and port.
 */

#ifndef _networking_v1beta1_ingress_backend_H_
#define _networking_v1beta1_ingress_backend_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct networking_v1beta1_ingress_backend_t {
    char *serviceName; // string
    object_t *servicePort; //object

} networking_v1beta1_ingress_backend_t;

networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_create(
    char *serviceName,
    object_t *servicePort
);

void networking_v1beta1_ingress_backend_free(networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend);

networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_parseFromJSON(cJSON *networking_v1beta1_ingress_backendJSON);

cJSON *networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend);

#endif /* _networking_v1beta1_ingress_backend_H_ */


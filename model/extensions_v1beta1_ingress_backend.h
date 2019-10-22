/*
 * extensions_v1beta1_ingress_backend.h
 *
 * IngressBackend describes all endpoints for a given service and port.
 */

#ifndef _extensions_v1beta1_ingress_backend_H_
#define _extensions_v1beta1_ingress_backend_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct extensions_v1beta1_ingress_backend_t {
    char *serviceName; // string
    object_t *servicePort; //object

} extensions_v1beta1_ingress_backend_t;

extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_create(
    char *serviceName,
    object_t *servicePort
);

void extensions_v1beta1_ingress_backend_free(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend);

extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_parseFromJSON(cJSON *extensions_v1beta1_ingress_backendJSON);

cJSON *extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend);

#endif /* _extensions_v1beta1_ingress_backend_H_ */


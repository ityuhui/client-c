/*
 * extensions_v1beta1_ingress_status.h
 *
 * IngressStatus describe the current state of the Ingress.
 */

#ifndef _extensions_v1beta1_ingress_status_H_
#define _extensions_v1beta1_ingress_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_load_balancer_status.h"



typedef struct extensions_v1beta1_ingress_status_t {
    v1_load_balancer_status_t *loadBalancer; //model

} extensions_v1beta1_ingress_status_t;

extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_create(
    v1_load_balancer_status_t *loadBalancer
);

void extensions_v1beta1_ingress_status_free(extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status);

extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_parseFromJSON(cJSON *extensions_v1beta1_ingress_statusJSON);

cJSON *extensions_v1beta1_ingress_status_convertToJSON(extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status);

#endif /* _extensions_v1beta1_ingress_status_H_ */


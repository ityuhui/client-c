/*
 * extensions_v1beta1_ingress_spec.h
 *
 * IngressSpec describes the Ingress the user wishes to exist.
 */

#ifndef _extensions_v1beta1_ingress_spec_H_
#define _extensions_v1beta1_ingress_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_ingress_backend.h"
#include "extensions_v1beta1_ingress_rule.h"
#include "extensions_v1beta1_ingress_tls.h"



typedef struct extensions_v1beta1_ingress_spec_t {
    extensions_v1beta1_ingress_backend_t *backend; //model
    list_t *rules; //nonprimitive container
    list_t *tls; //nonprimitive container

} extensions_v1beta1_ingress_spec_t;

extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec_create(
    extensions_v1beta1_ingress_backend_t *backend,
    list_t *rules,
    list_t *tls
);

void extensions_v1beta1_ingress_spec_free(extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec);

extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec_parseFromJSON(cJSON *extensions_v1beta1_ingress_specJSON);

cJSON *extensions_v1beta1_ingress_spec_convertToJSON(extensions_v1beta1_ingress_spec_t *extensions_v1beta1_ingress_spec);

#endif /* _extensions_v1beta1_ingress_spec_H_ */


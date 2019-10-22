/*
 * extensions_v1beta1_ingress_list.h
 *
 * IngressList is a collection of Ingress.
 */

#ifndef _extensions_v1beta1_ingress_list_H_
#define _extensions_v1beta1_ingress_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_ingress.h"
#include "v1_list_meta.h"



typedef struct extensions_v1beta1_ingress_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} extensions_v1beta1_ingress_list_t;

extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void extensions_v1beta1_ingress_list_free(extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list);

extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list_parseFromJSON(cJSON *extensions_v1beta1_ingress_listJSON);

cJSON *extensions_v1beta1_ingress_list_convertToJSON(extensions_v1beta1_ingress_list_t *extensions_v1beta1_ingress_list);

#endif /* _extensions_v1beta1_ingress_list_H_ */


/*
 * extensions_v1beta1_pod_security_policy.h
 *
 * PodSecurityPolicy governs the ability to make requests that affect the Security Context that will be applied to a pod and container. Deprecated: use PodSecurityPolicy from policy API Group instead.
 */

#ifndef _extensions_v1beta1_pod_security_policy_H_
#define _extensions_v1beta1_pod_security_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "extensions_v1beta1_pod_security_policy_spec.h"
#include "v1_object_meta.h"



typedef struct extensions_v1beta1_pod_security_policy_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    extensions_v1beta1_pod_security_policy_spec_t *spec; //model

} extensions_v1beta1_pod_security_policy_t;

extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    extensions_v1beta1_pod_security_policy_spec_t *spec
);

void extensions_v1beta1_pod_security_policy_free(extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy);

extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy_parseFromJSON(cJSON *extensions_v1beta1_pod_security_policyJSON);

cJSON *extensions_v1beta1_pod_security_policy_convertToJSON(extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy);

#endif /* _extensions_v1beta1_pod_security_policy_H_ */


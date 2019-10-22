/*
 * v1beta1_validating_webhook.h
 *
 * ValidatingWebhook describes an admission webhook and the resources and operations it applies to.
 */

#ifndef _v1beta1_validating_webhook_H_
#define _v1beta1_validating_webhook_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "admissionregistration_v1beta1_webhook_client_config.h"
#include "v1_label_selector.h"
#include "v1beta1_rule_with_operations.h"



typedef struct v1beta1_validating_webhook_t {
    list_t *admissionReviewVersions; //primitive container
    admissionregistration_v1beta1_webhook_client_config_t *clientConfig; //model
    char *failurePolicy; // string
    char *matchPolicy; // string
    char *name; // string
    v1_label_selector_t *namespaceSelector; //model
    v1_label_selector_t *objectSelector; //model
    list_t *rules; //nonprimitive container
    char *sideEffects; // string
    int timeoutSeconds; //numeric

} v1beta1_validating_webhook_t;

v1beta1_validating_webhook_t *v1beta1_validating_webhook_create(
    list_t *admissionReviewVersions,
    admissionregistration_v1beta1_webhook_client_config_t *clientConfig,
    char *failurePolicy,
    char *matchPolicy,
    char *name,
    v1_label_selector_t *namespaceSelector,
    v1_label_selector_t *objectSelector,
    list_t *rules,
    char *sideEffects,
    int timeoutSeconds
);

void v1beta1_validating_webhook_free(v1beta1_validating_webhook_t *v1beta1_validating_webhook);

v1beta1_validating_webhook_t *v1beta1_validating_webhook_parseFromJSON(cJSON *v1beta1_validating_webhookJSON);

cJSON *v1beta1_validating_webhook_convertToJSON(v1beta1_validating_webhook_t *v1beta1_validating_webhook);

#endif /* _v1beta1_validating_webhook_H_ */


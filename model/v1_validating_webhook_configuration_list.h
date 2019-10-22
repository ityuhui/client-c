/*
 * v1_validating_webhook_configuration_list.h
 *
 * ValidatingWebhookConfigurationList is a list of ValidatingWebhookConfiguration.
 */

#ifndef _v1_validating_webhook_configuration_list_H_
#define _v1_validating_webhook_configuration_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_list_meta.h"
#include "v1_validating_webhook_configuration.h"



typedef struct v1_validating_webhook_configuration_list_t {
    char *apiVersion; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    v1_list_meta_t *metadata; //model

} v1_validating_webhook_configuration_list_t;

v1_validating_webhook_configuration_list_t *v1_validating_webhook_configuration_list_create(
    char *apiVersion,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_validating_webhook_configuration_list_free(v1_validating_webhook_configuration_list_t *v1_validating_webhook_configuration_list);

v1_validating_webhook_configuration_list_t *v1_validating_webhook_configuration_list_parseFromJSON(cJSON *v1_validating_webhook_configuration_listJSON);

cJSON *v1_validating_webhook_configuration_list_convertToJSON(v1_validating_webhook_configuration_list_t *v1_validating_webhook_configuration_list);

#endif /* _v1_validating_webhook_configuration_list_H_ */


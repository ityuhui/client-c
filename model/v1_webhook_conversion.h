/*
 * v1_webhook_conversion.h
 *
 * WebhookConversion describes how to call a conversion webhook
 */

#ifndef _v1_webhook_conversion_H_
#define _v1_webhook_conversion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "apiextensions_v1_webhook_client_config.h"



typedef struct v1_webhook_conversion_t {
    apiextensions_v1_webhook_client_config_t *clientConfig; //model
    list_t *conversionReviewVersions; //primitive container

} v1_webhook_conversion_t;

v1_webhook_conversion_t *v1_webhook_conversion_create(
    apiextensions_v1_webhook_client_config_t *clientConfig,
    list_t *conversionReviewVersions
);

void v1_webhook_conversion_free(v1_webhook_conversion_t *v1_webhook_conversion);

v1_webhook_conversion_t *v1_webhook_conversion_parseFromJSON(cJSON *v1_webhook_conversionJSON);

cJSON *v1_webhook_conversion_convertToJSON(v1_webhook_conversion_t *v1_webhook_conversion);

#endif /* _v1_webhook_conversion_H_ */


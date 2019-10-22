/*
 * v1_client_ip_config.h
 *
 * ClientIPConfig represents the configurations of Client IP based session affinity.
 */

#ifndef _v1_client_ip_config_H_
#define _v1_client_ip_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_client_ip_config_t {
    int timeoutSeconds; //numeric

} v1_client_ip_config_t;

v1_client_ip_config_t *v1_client_ip_config_create(
    int timeoutSeconds
);

void v1_client_ip_config_free(v1_client_ip_config_t *v1_client_ip_config);

v1_client_ip_config_t *v1_client_ip_config_parseFromJSON(cJSON *v1_client_ip_configJSON);

cJSON *v1_client_ip_config_convertToJSON(v1_client_ip_config_t *v1_client_ip_config);

#endif /* _v1_client_ip_config_H_ */


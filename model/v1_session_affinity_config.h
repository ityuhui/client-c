/*
 * v1_session_affinity_config.h
 *
 * SessionAffinityConfig represents the configurations of session affinity.
 */

#ifndef _v1_session_affinity_config_H_
#define _v1_session_affinity_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_client_ip_config.h"



typedef struct v1_session_affinity_config_t {
    v1_client_ip_config_t *clientIP; //model

} v1_session_affinity_config_t;

v1_session_affinity_config_t *v1_session_affinity_config_create(
    v1_client_ip_config_t *clientIP
);

void v1_session_affinity_config_free(v1_session_affinity_config_t *v1_session_affinity_config);

v1_session_affinity_config_t *v1_session_affinity_config_parseFromJSON(cJSON *v1_session_affinity_configJSON);

cJSON *v1_session_affinity_config_convertToJSON(v1_session_affinity_config_t *v1_session_affinity_config);

#endif /* _v1_session_affinity_config_H_ */


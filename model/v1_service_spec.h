/*
 * v1_service_spec.h
 *
 * ServiceSpec describes the attributes that a user creates on a service.
 */

#ifndef _v1_service_spec_H_
#define _v1_service_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_service_port.h"
#include "v1_session_affinity_config.h"



typedef struct v1_service_spec_t {
    char *clusterIP; // string
    list_t *externalIPs; //primitive container
    char *externalName; // string
    char *externalTrafficPolicy; // string
    int healthCheckNodePort; //numeric
    char *ipFamily; // string
    char *loadBalancerIP; // string
    list_t *loadBalancerSourceRanges; //primitive container
    list_t *ports; //nonprimitive container
    int publishNotReadyAddresses; //boolean
    list_t* selector; //map
    char *sessionAffinity; // string
    v1_session_affinity_config_t *sessionAffinityConfig; //model
    char *type; // string

} v1_service_spec_t;

v1_service_spec_t *v1_service_spec_create(
    char *clusterIP,
    list_t *externalIPs,
    char *externalName,
    char *externalTrafficPolicy,
    int healthCheckNodePort,
    char *ipFamily,
    char *loadBalancerIP,
    list_t *loadBalancerSourceRanges,
    list_t *ports,
    int publishNotReadyAddresses,
    list_t* selector,
    char *sessionAffinity,
    v1_session_affinity_config_t *sessionAffinityConfig,
    char *type
);

void v1_service_spec_free(v1_service_spec_t *v1_service_spec);

v1_service_spec_t *v1_service_spec_parseFromJSON(cJSON *v1_service_specJSON);

cJSON *v1_service_spec_convertToJSON(v1_service_spec_t *v1_service_spec);

#endif /* _v1_service_spec_H_ */


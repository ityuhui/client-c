/*
 * v1_node_daemon_endpoints.h
 *
 * NodeDaemonEndpoints lists ports opened by daemons running on the Node.
 */

#ifndef _v1_node_daemon_endpoints_H_
#define _v1_node_daemon_endpoints_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_daemon_endpoint.h"



typedef struct v1_node_daemon_endpoints_t {
    v1_daemon_endpoint_t *kubeletEndpoint; //model

} v1_node_daemon_endpoints_t;

v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_create(
    v1_daemon_endpoint_t *kubeletEndpoint
);

void v1_node_daemon_endpoints_free(v1_node_daemon_endpoints_t *v1_node_daemon_endpoints);

v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_parseFromJSON(cJSON *v1_node_daemon_endpointsJSON);

cJSON *v1_node_daemon_endpoints_convertToJSON(v1_node_daemon_endpoints_t *v1_node_daemon_endpoints);

#endif /* _v1_node_daemon_endpoints_H_ */


/*
 * v1_probe.h
 *
 * Probe describes a health check to be performed against a container to determine whether it is alive or ready to receive traffic.
 */

#ifndef _v1_probe_H_
#define _v1_probe_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_exec_action.h"
#include "v1_http_get_action.h"
#include "v1_tcp_socket_action.h"



typedef struct v1_probe_t {
    v1_exec_action_t *exec; //model
    int failureThreshold; //numeric
    v1_http_get_action_t *httpGet; //model
    int initialDelaySeconds; //numeric
    int periodSeconds; //numeric
    int successThreshold; //numeric
    v1_tcp_socket_action_t *tcpSocket; //model
    int timeoutSeconds; //numeric

} v1_probe_t;

v1_probe_t *v1_probe_create(
    v1_exec_action_t *exec,
    int failureThreshold,
    v1_http_get_action_t *httpGet,
    int initialDelaySeconds,
    int periodSeconds,
    int successThreshold,
    v1_tcp_socket_action_t *tcpSocket,
    int timeoutSeconds
);

void v1_probe_free(v1_probe_t *v1_probe);

v1_probe_t *v1_probe_parseFromJSON(cJSON *v1_probeJSON);

cJSON *v1_probe_convertToJSON(v1_probe_t *v1_probe);

#endif /* _v1_probe_H_ */


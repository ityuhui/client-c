/*
 * v1_handler.h
 *
 * Handler defines a specific action that should be taken
 */

#ifndef _v1_handler_H_
#define _v1_handler_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_exec_action.h"
#include "v1_http_get_action.h"
#include "v1_tcp_socket_action.h"



typedef struct v1_handler_t {
    v1_exec_action_t *exec; //model
    v1_http_get_action_t *httpGet; //model
    v1_tcp_socket_action_t *tcpSocket; //model

} v1_handler_t;

v1_handler_t *v1_handler_create(
    v1_exec_action_t *exec,
    v1_http_get_action_t *httpGet,
    v1_tcp_socket_action_t *tcpSocket
);

void v1_handler_free(v1_handler_t *v1_handler);

v1_handler_t *v1_handler_parseFromJSON(cJSON *v1_handlerJSON);

cJSON *v1_handler_convertToJSON(v1_handler_t *v1_handler);

#endif /* _v1_handler_H_ */


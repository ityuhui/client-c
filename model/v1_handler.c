#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_handler.h"



v1_handler_t *v1_handler_create(
    v1_exec_action_t *exec,
    v1_http_get_action_t *httpGet,
    v1_tcp_socket_action_t *tcpSocket
    ) {
	v1_handler_t *v1_handler_local_var = malloc(sizeof(v1_handler_t));
    if (!v1_handler_local_var) {
        return NULL;
    }
	v1_handler_local_var->exec = exec;
	v1_handler_local_var->httpGet = httpGet;
	v1_handler_local_var->tcpSocket = tcpSocket;

	return v1_handler_local_var;
}


void v1_handler_free(v1_handler_t *v1_handler) {
    listEntry_t *listEntry;
    v1_exec_action_free(v1_handler->exec);
    v1_http_get_action_free(v1_handler->httpGet);
    v1_tcp_socket_action_free(v1_handler->tcpSocket);
	free(v1_handler);
}

cJSON *v1_handler_convertToJSON(v1_handler_t *v1_handler) {
	cJSON *item = cJSON_CreateObject();

	// v1_handler->exec
    if(v1_handler->exec) { 
    cJSON *exec_local_JSON = v1_exec_action_convertToJSON(v1_handler->exec);
    if(exec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exec", exec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_handler->httpGet
    if(v1_handler->httpGet) { 
    cJSON *httpGet_local_JSON = v1_http_get_action_convertToJSON(v1_handler->httpGet);
    if(httpGet_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "httpGet", httpGet_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_handler->tcpSocket
    if(v1_handler->tcpSocket) { 
    cJSON *tcpSocket_local_JSON = v1_tcp_socket_action_convertToJSON(v1_handler->tcpSocket);
    if(tcpSocket_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tcpSocket", tcpSocket_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_handler_t *v1_handler_parseFromJSON(cJSON *v1_handlerJSON){

    v1_handler_t *v1_handler_local_var = NULL;

    // v1_handler->exec
    cJSON *exec = cJSON_GetObjectItemCaseSensitive(v1_handlerJSON, "exec");
    v1_exec_action_t *exec_local_nonprim = NULL;
    if (exec) { 
    exec_local_nonprim = v1_exec_action_parseFromJSON(exec); //nonprimitive
    }

    // v1_handler->httpGet
    cJSON *httpGet = cJSON_GetObjectItemCaseSensitive(v1_handlerJSON, "httpGet");
    v1_http_get_action_t *httpGet_local_nonprim = NULL;
    if (httpGet) { 
    httpGet_local_nonprim = v1_http_get_action_parseFromJSON(httpGet); //nonprimitive
    }

    // v1_handler->tcpSocket
    cJSON *tcpSocket = cJSON_GetObjectItemCaseSensitive(v1_handlerJSON, "tcpSocket");
    v1_tcp_socket_action_t *tcpSocket_local_nonprim = NULL;
    if (tcpSocket) { 
    tcpSocket_local_nonprim = v1_tcp_socket_action_parseFromJSON(tcpSocket); //nonprimitive
    }


    v1_handler_local_var = v1_handler_create (
        exec ? exec_local_nonprim : NULL,
        httpGet ? httpGet_local_nonprim : NULL,
        tcpSocket ? tcpSocket_local_nonprim : NULL
        );

    return v1_handler_local_var;
end:
    return NULL;

}

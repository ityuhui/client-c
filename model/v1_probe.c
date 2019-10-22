#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_probe.h"



v1_probe_t *v1_probe_create(
    v1_exec_action_t *exec,
    int failureThreshold,
    v1_http_get_action_t *httpGet,
    int initialDelaySeconds,
    int periodSeconds,
    int successThreshold,
    v1_tcp_socket_action_t *tcpSocket,
    int timeoutSeconds
    ) {
	v1_probe_t *v1_probe_local_var = malloc(sizeof(v1_probe_t));
    if (!v1_probe_local_var) {
        return NULL;
    }
	v1_probe_local_var->exec = exec;
	v1_probe_local_var->failureThreshold = failureThreshold;
	v1_probe_local_var->httpGet = httpGet;
	v1_probe_local_var->initialDelaySeconds = initialDelaySeconds;
	v1_probe_local_var->periodSeconds = periodSeconds;
	v1_probe_local_var->successThreshold = successThreshold;
	v1_probe_local_var->tcpSocket = tcpSocket;
	v1_probe_local_var->timeoutSeconds = timeoutSeconds;

	return v1_probe_local_var;
}


void v1_probe_free(v1_probe_t *v1_probe) {
    listEntry_t *listEntry;
    v1_exec_action_free(v1_probe->exec);
    v1_http_get_action_free(v1_probe->httpGet);
    v1_tcp_socket_action_free(v1_probe->tcpSocket);
	free(v1_probe);
}

cJSON *v1_probe_convertToJSON(v1_probe_t *v1_probe) {
	cJSON *item = cJSON_CreateObject();

	// v1_probe->exec
    if(v1_probe->exec) { 
    cJSON *exec_local_JSON = v1_exec_action_convertToJSON(v1_probe->exec);
    if(exec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exec", exec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_probe->failureThreshold
    if(v1_probe->failureThreshold) { 
    if(cJSON_AddNumberToObject(item, "failureThreshold", v1_probe->failureThreshold) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_probe->httpGet
    if(v1_probe->httpGet) { 
    cJSON *httpGet_local_JSON = v1_http_get_action_convertToJSON(v1_probe->httpGet);
    if(httpGet_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "httpGet", httpGet_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_probe->initialDelaySeconds
    if(v1_probe->initialDelaySeconds) { 
    if(cJSON_AddNumberToObject(item, "initialDelaySeconds", v1_probe->initialDelaySeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_probe->periodSeconds
    if(v1_probe->periodSeconds) { 
    if(cJSON_AddNumberToObject(item, "periodSeconds", v1_probe->periodSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_probe->successThreshold
    if(v1_probe->successThreshold) { 
    if(cJSON_AddNumberToObject(item, "successThreshold", v1_probe->successThreshold) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_probe->tcpSocket
    if(v1_probe->tcpSocket) { 
    cJSON *tcpSocket_local_JSON = v1_tcp_socket_action_convertToJSON(v1_probe->tcpSocket);
    if(tcpSocket_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tcpSocket", tcpSocket_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_probe->timeoutSeconds
    if(v1_probe->timeoutSeconds) { 
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_probe->timeoutSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_probe_t *v1_probe_parseFromJSON(cJSON *v1_probeJSON){

    v1_probe_t *v1_probe_local_var = NULL;

    // v1_probe->exec
    cJSON *exec = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "exec");
    v1_exec_action_t *exec_local_nonprim = NULL;
    if (exec) { 
    exec_local_nonprim = v1_exec_action_parseFromJSON(exec); //nonprimitive
    }

    // v1_probe->failureThreshold
    cJSON *failureThreshold = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "failureThreshold");
    if (failureThreshold) { 
    if(!cJSON_IsNumber(failureThreshold))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->httpGet
    cJSON *httpGet = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "httpGet");
    v1_http_get_action_t *httpGet_local_nonprim = NULL;
    if (httpGet) { 
    httpGet_local_nonprim = v1_http_get_action_parseFromJSON(httpGet); //nonprimitive
    }

    // v1_probe->initialDelaySeconds
    cJSON *initialDelaySeconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "initialDelaySeconds");
    if (initialDelaySeconds) { 
    if(!cJSON_IsNumber(initialDelaySeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->periodSeconds
    cJSON *periodSeconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "periodSeconds");
    if (periodSeconds) { 
    if(!cJSON_IsNumber(periodSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->successThreshold
    cJSON *successThreshold = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "successThreshold");
    if (successThreshold) { 
    if(!cJSON_IsNumber(successThreshold))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->tcpSocket
    cJSON *tcpSocket = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "tcpSocket");
    v1_tcp_socket_action_t *tcpSocket_local_nonprim = NULL;
    if (tcpSocket) { 
    tcpSocket_local_nonprim = v1_tcp_socket_action_parseFromJSON(tcpSocket); //nonprimitive
    }

    // v1_probe->timeoutSeconds
    cJSON *timeoutSeconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "timeoutSeconds");
    if (timeoutSeconds) { 
    if(!cJSON_IsNumber(timeoutSeconds))
    {
    goto end; //Numeric
    }
    }


    v1_probe_local_var = v1_probe_create (
        exec ? exec_local_nonprim : NULL,
        failureThreshold ? failureThreshold->valuedouble : 0,
        httpGet ? httpGet_local_nonprim : NULL,
        initialDelaySeconds ? initialDelaySeconds->valuedouble : 0,
        periodSeconds ? periodSeconds->valuedouble : 0,
        successThreshold ? successThreshold->valuedouble : 0,
        tcpSocket ? tcpSocket_local_nonprim : NULL,
        timeoutSeconds ? timeoutSeconds->valuedouble : 0
        );

    return v1_probe_local_var;
end:
    return NULL;

}

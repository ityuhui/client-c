#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_endpoint.h"



v1_daemon_endpoint_t *v1_daemon_endpoint_create(
    int Port
    ) {
	v1_daemon_endpoint_t *v1_daemon_endpoint_local_var = malloc(sizeof(v1_daemon_endpoint_t));
    if (!v1_daemon_endpoint_local_var) {
        return NULL;
    }
	v1_daemon_endpoint_local_var->Port = Port;

	return v1_daemon_endpoint_local_var;
}


void v1_daemon_endpoint_free(v1_daemon_endpoint_t *v1_daemon_endpoint) {
    listEntry_t *listEntry;
	free(v1_daemon_endpoint);
}

cJSON *v1_daemon_endpoint_convertToJSON(v1_daemon_endpoint_t *v1_daemon_endpoint) {
	cJSON *item = cJSON_CreateObject();

	// v1_daemon_endpoint->Port
    if (!v1_daemon_endpoint->Port) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "Port", v1_daemon_endpoint->Port) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_daemon_endpoint_t *v1_daemon_endpoint_parseFromJSON(cJSON *v1_daemon_endpointJSON){

    v1_daemon_endpoint_t *v1_daemon_endpoint_local_var = NULL;

    // v1_daemon_endpoint->Port
    cJSON *Port = cJSON_GetObjectItemCaseSensitive(v1_daemon_endpointJSON, "Port");
    if (!Port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(Port))
    {
    goto end; //Numeric
    }


    v1_daemon_endpoint_local_var = v1_daemon_endpoint_create (
        Port->valuedouble
        );

    return v1_daemon_endpoint_local_var;
end:
    return NULL;

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_daemon_endpoints.h"



v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_create(
    v1_daemon_endpoint_t *kubeletEndpoint
    ) {
	v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_local_var = malloc(sizeof(v1_node_daemon_endpoints_t));
    if (!v1_node_daemon_endpoints_local_var) {
        return NULL;
    }
	v1_node_daemon_endpoints_local_var->kubeletEndpoint = kubeletEndpoint;

	return v1_node_daemon_endpoints_local_var;
}


void v1_node_daemon_endpoints_free(v1_node_daemon_endpoints_t *v1_node_daemon_endpoints) {
    listEntry_t *listEntry;
    v1_daemon_endpoint_free(v1_node_daemon_endpoints->kubeletEndpoint);
	free(v1_node_daemon_endpoints);
}

cJSON *v1_node_daemon_endpoints_convertToJSON(v1_node_daemon_endpoints_t *v1_node_daemon_endpoints) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_daemon_endpoints->kubeletEndpoint
    if(v1_node_daemon_endpoints->kubeletEndpoint) { 
    cJSON *kubeletEndpoint_local_JSON = v1_daemon_endpoint_convertToJSON(v1_node_daemon_endpoints->kubeletEndpoint);
    if(kubeletEndpoint_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "kubeletEndpoint", kubeletEndpoint_local_JSON);
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

v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_parseFromJSON(cJSON *v1_node_daemon_endpointsJSON){

    v1_node_daemon_endpoints_t *v1_node_daemon_endpoints_local_var = NULL;

    // v1_node_daemon_endpoints->kubeletEndpoint
    cJSON *kubeletEndpoint = cJSON_GetObjectItemCaseSensitive(v1_node_daemon_endpointsJSON, "kubeletEndpoint");
    v1_daemon_endpoint_t *kubeletEndpoint_local_nonprim = NULL;
    if (kubeletEndpoint) { 
    kubeletEndpoint_local_nonprim = v1_daemon_endpoint_parseFromJSON(kubeletEndpoint); //nonprimitive
    }


    v1_node_daemon_endpoints_local_var = v1_node_daemon_endpoints_create (
        kubeletEndpoint ? kubeletEndpoint_local_nonprim : NULL
        );

    return v1_node_daemon_endpoints_local_var;
end:
    return NULL;

}

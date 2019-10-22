#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_network_policy_port.h"



v1beta1_network_policy_port_t *v1beta1_network_policy_port_create(
    object_t *port,
    char *protocol
    ) {
	v1beta1_network_policy_port_t *v1beta1_network_policy_port_local_var = malloc(sizeof(v1beta1_network_policy_port_t));
    if (!v1beta1_network_policy_port_local_var) {
        return NULL;
    }
	v1beta1_network_policy_port_local_var->port = port;
	v1beta1_network_policy_port_local_var->protocol = protocol;

	return v1beta1_network_policy_port_local_var;
}


void v1beta1_network_policy_port_free(v1beta1_network_policy_port_t *v1beta1_network_policy_port) {
    listEntry_t *listEntry;
    object_free(v1beta1_network_policy_port->port);
    free(v1beta1_network_policy_port->protocol);
	free(v1beta1_network_policy_port);
}

cJSON *v1beta1_network_policy_port_convertToJSON(v1beta1_network_policy_port_t *v1beta1_network_policy_port) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_network_policy_port->port
    if(v1beta1_network_policy_port->port) { 
    cJSON *port_object = object_convertToJSON(v1beta1_network_policy_port->port);
    if(port_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "port", port_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_network_policy_port->protocol
    if(v1beta1_network_policy_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1beta1_network_policy_port->protocol) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_network_policy_port_t *v1beta1_network_policy_port_parseFromJSON(cJSON *v1beta1_network_policy_portJSON){

    v1beta1_network_policy_port_t *v1beta1_network_policy_port_local_var = NULL;

    // v1beta1_network_policy_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_portJSON, "port");
    object_t *port_local_object = NULL;
    if (port) { 
    port_local_object = object_parseFromJSON(port); //object
    }

    // v1beta1_network_policy_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }


    v1beta1_network_policy_port_local_var = v1beta1_network_policy_port_create (
        port ? port_local_object : NULL,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1beta1_network_policy_port_local_var;
end:
    return NULL;

}

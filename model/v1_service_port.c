#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_port.h"



v1_service_port_t *v1_service_port_create(
    char *name,
    int nodePort,
    int port,
    char *protocol,
    object_t *targetPort
    ) {
	v1_service_port_t *v1_service_port_local_var = malloc(sizeof(v1_service_port_t));
    if (!v1_service_port_local_var) {
        return NULL;
    }
	v1_service_port_local_var->name = name;
	v1_service_port_local_var->nodePort = nodePort;
	v1_service_port_local_var->port = port;
	v1_service_port_local_var->protocol = protocol;
	v1_service_port_local_var->targetPort = targetPort;

	return v1_service_port_local_var;
}


void v1_service_port_free(v1_service_port_t *v1_service_port) {
    listEntry_t *listEntry;
    free(v1_service_port->name);
    free(v1_service_port->protocol);
    object_free(v1_service_port->targetPort);
	free(v1_service_port);
}

cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port) {
	cJSON *item = cJSON_CreateObject();

	// v1_service_port->name
    if(v1_service_port->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_service_port->name) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_port->nodePort
    if(v1_service_port->nodePort) { 
    if(cJSON_AddNumberToObject(item, "nodePort", v1_service_port->nodePort) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_service_port->port
    if (!v1_service_port->port) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "port", v1_service_port->port) == NULL) {
    goto fail; //Numeric
    }


	// v1_service_port->protocol
    if(v1_service_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1_service_port->protocol) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_port->targetPort
    if(v1_service_port->targetPort) { 
    cJSON *targetPort_object = object_convertToJSON(v1_service_port->targetPort);
    if(targetPort_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetPort", targetPort_object);
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

v1_service_port_t *v1_service_port_parseFromJSON(cJSON *v1_service_portJSON){

    v1_service_port_t *v1_service_port_local_var = NULL;

    // v1_service_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_service_port->nodePort
    cJSON *nodePort = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "nodePort");
    if (nodePort) { 
    if(!cJSON_IsNumber(nodePort))
    {
    goto end; //Numeric
    }
    }

    // v1_service_port->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_service_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }

    // v1_service_port->targetPort
    cJSON *targetPort = cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "targetPort");
    object_t *targetPort_local_object = NULL;
    if (targetPort) { 
    targetPort_local_object = object_parseFromJSON(targetPort); //object
    }


    v1_service_port_local_var = v1_service_port_create (
        name ? strdup(name->valuestring) : NULL,
        nodePort ? nodePort->valuedouble : 0,
        port->valuedouble,
        protocol ? strdup(protocol->valuestring) : NULL,
        targetPort ? targetPort_local_object : NULL
        );

    return v1_service_port_local_var;
end:
    return NULL;

}

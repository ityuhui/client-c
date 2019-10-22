#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_port.h"



v1_container_port_t *v1_container_port_create(
    int containerPort,
    char *hostIP,
    int hostPort,
    char *name,
    char *protocol
    ) {
	v1_container_port_t *v1_container_port_local_var = malloc(sizeof(v1_container_port_t));
    if (!v1_container_port_local_var) {
        return NULL;
    }
	v1_container_port_local_var->containerPort = containerPort;
	v1_container_port_local_var->hostIP = hostIP;
	v1_container_port_local_var->hostPort = hostPort;
	v1_container_port_local_var->name = name;
	v1_container_port_local_var->protocol = protocol;

	return v1_container_port_local_var;
}


void v1_container_port_free(v1_container_port_t *v1_container_port) {
    listEntry_t *listEntry;
    free(v1_container_port->hostIP);
    free(v1_container_port->name);
    free(v1_container_port->protocol);
	free(v1_container_port);
}

cJSON *v1_container_port_convertToJSON(v1_container_port_t *v1_container_port) {
	cJSON *item = cJSON_CreateObject();

	// v1_container_port->containerPort
    if (!v1_container_port->containerPort) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "containerPort", v1_container_port->containerPort) == NULL) {
    goto fail; //Numeric
    }


	// v1_container_port->hostIP
    if(v1_container_port->hostIP) { 
    if(cJSON_AddStringToObject(item, "hostIP", v1_container_port->hostIP) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container_port->hostPort
    if(v1_container_port->hostPort) { 
    if(cJSON_AddNumberToObject(item, "hostPort", v1_container_port->hostPort) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_container_port->name
    if(v1_container_port->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_container_port->name) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container_port->protocol
    if(v1_container_port->protocol) { 
    if(cJSON_AddStringToObject(item, "protocol", v1_container_port->protocol) == NULL) {
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

v1_container_port_t *v1_container_port_parseFromJSON(cJSON *v1_container_portJSON){

    v1_container_port_t *v1_container_port_local_var = NULL;

    // v1_container_port->containerPort
    cJSON *containerPort = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "containerPort");
    if (!containerPort) {
        goto end;
    }

    
    if(!cJSON_IsNumber(containerPort))
    {
    goto end; //Numeric
    }

    // v1_container_port->hostIP
    cJSON *hostIP = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "hostIP");
    if (hostIP) { 
    if(!cJSON_IsString(hostIP))
    {
    goto end; //String
    }
    }

    // v1_container_port->hostPort
    cJSON *hostPort = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "hostPort");
    if (hostPort) { 
    if(!cJSON_IsNumber(hostPort))
    {
    goto end; //Numeric
    }
    }

    // v1_container_port->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_container_port->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(v1_container_portJSON, "protocol");
    if (protocol) { 
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }
    }


    v1_container_port_local_var = v1_container_port_create (
        containerPort->valuedouble,
        hostIP ? strdup(hostIP->valuestring) : NULL,
        hostPort ? hostPort->valuedouble : 0,
        name ? strdup(name->valuestring) : NULL,
        protocol ? strdup(protocol->valuestring) : NULL
        );

    return v1_container_port_local_var;
end:
    return NULL;

}

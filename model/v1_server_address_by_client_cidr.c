#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_server_address_by_client_cidr.h"



v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_create(
    char *clientCIDR,
    char *serverAddress
    ) {
	v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_local_var = malloc(sizeof(v1_server_address_by_client_cidr_t));
    if (!v1_server_address_by_client_cidr_local_var) {
        return NULL;
    }
	v1_server_address_by_client_cidr_local_var->clientCIDR = clientCIDR;
	v1_server_address_by_client_cidr_local_var->serverAddress = serverAddress;

	return v1_server_address_by_client_cidr_local_var;
}


void v1_server_address_by_client_cidr_free(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr) {
    listEntry_t *listEntry;
    free(v1_server_address_by_client_cidr->clientCIDR);
    free(v1_server_address_by_client_cidr->serverAddress);
	free(v1_server_address_by_client_cidr);
}

cJSON *v1_server_address_by_client_cidr_convertToJSON(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr) {
	cJSON *item = cJSON_CreateObject();

	// v1_server_address_by_client_cidr->clientCIDR
    if (!v1_server_address_by_client_cidr->clientCIDR) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "clientCIDR", v1_server_address_by_client_cidr->clientCIDR) == NULL) {
    goto fail; //String
    }


	// v1_server_address_by_client_cidr->serverAddress
    if (!v1_server_address_by_client_cidr->serverAddress) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serverAddress", v1_server_address_by_client_cidr->serverAddress) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_parseFromJSON(cJSON *v1_server_address_by_client_cidrJSON){

    v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_local_var = NULL;

    // v1_server_address_by_client_cidr->clientCIDR
    cJSON *clientCIDR = cJSON_GetObjectItemCaseSensitive(v1_server_address_by_client_cidrJSON, "clientCIDR");
    if (!clientCIDR) {
        goto end;
    }

    
    if(!cJSON_IsString(clientCIDR))
    {
    goto end; //String
    }

    // v1_server_address_by_client_cidr->serverAddress
    cJSON *serverAddress = cJSON_GetObjectItemCaseSensitive(v1_server_address_by_client_cidrJSON, "serverAddress");
    if (!serverAddress) {
        goto end;
    }

    
    if(!cJSON_IsString(serverAddress))
    {
    goto end; //String
    }


    v1_server_address_by_client_cidr_local_var = v1_server_address_by_client_cidr_create (
        strdup(clientCIDR->valuestring),
        strdup(serverAddress->valuestring)
        );

    return v1_server_address_by_client_cidr_local_var;
end:
    return NULL;

}

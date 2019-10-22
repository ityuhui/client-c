#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_address.h"



v1_endpoint_address_t *v1_endpoint_address_create(
    char *hostname,
    char *ip,
    char *nodeName,
    v1_object_reference_t *targetRef
    ) {
	v1_endpoint_address_t *v1_endpoint_address_local_var = malloc(sizeof(v1_endpoint_address_t));
    if (!v1_endpoint_address_local_var) {
        return NULL;
    }
	v1_endpoint_address_local_var->hostname = hostname;
	v1_endpoint_address_local_var->ip = ip;
	v1_endpoint_address_local_var->nodeName = nodeName;
	v1_endpoint_address_local_var->targetRef = targetRef;

	return v1_endpoint_address_local_var;
}


void v1_endpoint_address_free(v1_endpoint_address_t *v1_endpoint_address) {
    listEntry_t *listEntry;
    free(v1_endpoint_address->hostname);
    free(v1_endpoint_address->ip);
    free(v1_endpoint_address->nodeName);
    v1_object_reference_free(v1_endpoint_address->targetRef);
	free(v1_endpoint_address);
}

cJSON *v1_endpoint_address_convertToJSON(v1_endpoint_address_t *v1_endpoint_address) {
	cJSON *item = cJSON_CreateObject();

	// v1_endpoint_address->hostname
    if(v1_endpoint_address->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1_endpoint_address->hostname) == NULL) {
    goto fail; //String
    }
     } 


	// v1_endpoint_address->ip
    if (!v1_endpoint_address->ip) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "ip", v1_endpoint_address->ip) == NULL) {
    goto fail; //String
    }


	// v1_endpoint_address->nodeName
    if(v1_endpoint_address->nodeName) { 
    if(cJSON_AddStringToObject(item, "nodeName", v1_endpoint_address->nodeName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_endpoint_address->targetRef
    if(v1_endpoint_address->targetRef) { 
    cJSON *targetRef_local_JSON = v1_object_reference_convertToJSON(v1_endpoint_address->targetRef);
    if(targetRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetRef", targetRef_local_JSON);
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

v1_endpoint_address_t *v1_endpoint_address_parseFromJSON(cJSON *v1_endpoint_addressJSON){

    v1_endpoint_address_t *v1_endpoint_address_local_var = NULL;

    // v1_endpoint_address->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1_endpoint_address->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "ip");
    if (!ip) {
        goto end;
    }

    
    if(!cJSON_IsString(ip))
    {
    goto end; //String
    }

    // v1_endpoint_address->nodeName
    cJSON *nodeName = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "nodeName");
    if (nodeName) { 
    if(!cJSON_IsString(nodeName))
    {
    goto end; //String
    }
    }

    // v1_endpoint_address->targetRef
    cJSON *targetRef = cJSON_GetObjectItemCaseSensitive(v1_endpoint_addressJSON, "targetRef");
    v1_object_reference_t *targetRef_local_nonprim = NULL;
    if (targetRef) { 
    targetRef_local_nonprim = v1_object_reference_parseFromJSON(targetRef); //nonprimitive
    }


    v1_endpoint_address_local_var = v1_endpoint_address_create (
        hostname ? strdup(hostname->valuestring) : NULL,
        strdup(ip->valuestring),
        nodeName ? strdup(nodeName->valuestring) : NULL,
        targetRef ? targetRef_local_nonprim : NULL
        );

    return v1_endpoint_address_local_var;
end:
    return NULL;

}

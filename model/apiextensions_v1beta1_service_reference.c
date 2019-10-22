#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apiextensions_v1beta1_service_reference.h"



apiextensions_v1beta1_service_reference_t *apiextensions_v1beta1_service_reference_create(
    char *name,
    char *namespace,
    char *path,
    int port
    ) {
	apiextensions_v1beta1_service_reference_t *apiextensions_v1beta1_service_reference_local_var = malloc(sizeof(apiextensions_v1beta1_service_reference_t));
    if (!apiextensions_v1beta1_service_reference_local_var) {
        return NULL;
    }
	apiextensions_v1beta1_service_reference_local_var->name = name;
	apiextensions_v1beta1_service_reference_local_var->namespace = namespace;
	apiextensions_v1beta1_service_reference_local_var->path = path;
	apiextensions_v1beta1_service_reference_local_var->port = port;

	return apiextensions_v1beta1_service_reference_local_var;
}


void apiextensions_v1beta1_service_reference_free(apiextensions_v1beta1_service_reference_t *apiextensions_v1beta1_service_reference) {
    listEntry_t *listEntry;
    free(apiextensions_v1beta1_service_reference->name);
    free(apiextensions_v1beta1_service_reference->namespace);
    free(apiextensions_v1beta1_service_reference->path);
	free(apiextensions_v1beta1_service_reference);
}

cJSON *apiextensions_v1beta1_service_reference_convertToJSON(apiextensions_v1beta1_service_reference_t *apiextensions_v1beta1_service_reference) {
	cJSON *item = cJSON_CreateObject();

	// apiextensions_v1beta1_service_reference->name
    if (!apiextensions_v1beta1_service_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", apiextensions_v1beta1_service_reference->name) == NULL) {
    goto fail; //String
    }


	// apiextensions_v1beta1_service_reference->namespace
    if (!apiextensions_v1beta1_service_reference->namespace) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "namespace", apiextensions_v1beta1_service_reference->namespace) == NULL) {
    goto fail; //String
    }


	// apiextensions_v1beta1_service_reference->path
    if(apiextensions_v1beta1_service_reference->path) { 
    if(cJSON_AddStringToObject(item, "path", apiextensions_v1beta1_service_reference->path) == NULL) {
    goto fail; //String
    }
     } 


	// apiextensions_v1beta1_service_reference->port
    if(apiextensions_v1beta1_service_reference->port) { 
    if(cJSON_AddNumberToObject(item, "port", apiextensions_v1beta1_service_reference->port) == NULL) {
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

apiextensions_v1beta1_service_reference_t *apiextensions_v1beta1_service_reference_parseFromJSON(cJSON *apiextensions_v1beta1_service_referenceJSON){

    apiextensions_v1beta1_service_reference_t *apiextensions_v1beta1_service_reference_local_var = NULL;

    // apiextensions_v1beta1_service_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(apiextensions_v1beta1_service_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // apiextensions_v1beta1_service_reference->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(apiextensions_v1beta1_service_referenceJSON, "namespace");
    if (!namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }

    // apiextensions_v1beta1_service_reference->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(apiextensions_v1beta1_service_referenceJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // apiextensions_v1beta1_service_reference->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(apiextensions_v1beta1_service_referenceJSON, "port");
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    apiextensions_v1beta1_service_reference_local_var = apiextensions_v1beta1_service_reference_create (
        strdup(name->valuestring),
        strdup(namespace->valuestring),
        path ? strdup(path->valuestring) : NULL,
        port ? port->valuedouble : 0
        );

    return apiextensions_v1beta1_service_reference_local_var;
end:
    return NULL;

}

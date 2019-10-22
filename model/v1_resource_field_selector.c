#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_field_selector.h"



v1_resource_field_selector_t *v1_resource_field_selector_create(
    char *containerName,
    char *divisor,
    char *resource
    ) {
	v1_resource_field_selector_t *v1_resource_field_selector_local_var = malloc(sizeof(v1_resource_field_selector_t));
    if (!v1_resource_field_selector_local_var) {
        return NULL;
    }
	v1_resource_field_selector_local_var->containerName = containerName;
	v1_resource_field_selector_local_var->divisor = divisor;
	v1_resource_field_selector_local_var->resource = resource;

	return v1_resource_field_selector_local_var;
}


void v1_resource_field_selector_free(v1_resource_field_selector_t *v1_resource_field_selector) {
    listEntry_t *listEntry;
    free(v1_resource_field_selector->containerName);
    free(v1_resource_field_selector->divisor);
    free(v1_resource_field_selector->resource);
	free(v1_resource_field_selector);
}

cJSON *v1_resource_field_selector_convertToJSON(v1_resource_field_selector_t *v1_resource_field_selector) {
	cJSON *item = cJSON_CreateObject();

	// v1_resource_field_selector->containerName
    if(v1_resource_field_selector->containerName) { 
    if(cJSON_AddStringToObject(item, "containerName", v1_resource_field_selector->containerName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_resource_field_selector->divisor
    if(v1_resource_field_selector->divisor) { 
    if(cJSON_AddStringToObject(item, "divisor", v1_resource_field_selector->divisor) == NULL) {
    goto fail; //String
    }
     } 


	// v1_resource_field_selector->resource
    if (!v1_resource_field_selector->resource) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "resource", v1_resource_field_selector->resource) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_resource_field_selector_t *v1_resource_field_selector_parseFromJSON(cJSON *v1_resource_field_selectorJSON){

    v1_resource_field_selector_t *v1_resource_field_selector_local_var = NULL;

    // v1_resource_field_selector->containerName
    cJSON *containerName = cJSON_GetObjectItemCaseSensitive(v1_resource_field_selectorJSON, "containerName");
    if (containerName) { 
    if(!cJSON_IsString(containerName))
    {
    goto end; //String
    }
    }

    // v1_resource_field_selector->divisor
    cJSON *divisor = cJSON_GetObjectItemCaseSensitive(v1_resource_field_selectorJSON, "divisor");
    if (divisor) { 
    if(!cJSON_IsString(divisor))
    {
    goto end; //String
    }
    }

    // v1_resource_field_selector->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(v1_resource_field_selectorJSON, "resource");
    if (!resource) {
        goto end;
    }

    
    if(!cJSON_IsString(resource))
    {
    goto end; //String
    }


    v1_resource_field_selector_local_var = v1_resource_field_selector_create (
        containerName ? strdup(containerName->valuestring) : NULL,
        divisor ? strdup(divisor->valuestring) : NULL,
        strdup(resource->valuestring)
        );

    return v1_resource_field_selector_local_var;
end:
    return NULL;

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_subresource_scale.h"



v1beta1_custom_resource_subresource_scale_t *v1beta1_custom_resource_subresource_scale_create(
    char *labelSelectorPath,
    char *specReplicasPath,
    char *statusReplicasPath
    ) {
	v1beta1_custom_resource_subresource_scale_t *v1beta1_custom_resource_subresource_scale_local_var = malloc(sizeof(v1beta1_custom_resource_subresource_scale_t));
    if (!v1beta1_custom_resource_subresource_scale_local_var) {
        return NULL;
    }
	v1beta1_custom_resource_subresource_scale_local_var->labelSelectorPath = labelSelectorPath;
	v1beta1_custom_resource_subresource_scale_local_var->specReplicasPath = specReplicasPath;
	v1beta1_custom_resource_subresource_scale_local_var->statusReplicasPath = statusReplicasPath;

	return v1beta1_custom_resource_subresource_scale_local_var;
}


void v1beta1_custom_resource_subresource_scale_free(v1beta1_custom_resource_subresource_scale_t *v1beta1_custom_resource_subresource_scale) {
    listEntry_t *listEntry;
    free(v1beta1_custom_resource_subresource_scale->labelSelectorPath);
    free(v1beta1_custom_resource_subresource_scale->specReplicasPath);
    free(v1beta1_custom_resource_subresource_scale->statusReplicasPath);
	free(v1beta1_custom_resource_subresource_scale);
}

cJSON *v1beta1_custom_resource_subresource_scale_convertToJSON(v1beta1_custom_resource_subresource_scale_t *v1beta1_custom_resource_subresource_scale) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_custom_resource_subresource_scale->labelSelectorPath
    if(v1beta1_custom_resource_subresource_scale->labelSelectorPath) { 
    if(cJSON_AddStringToObject(item, "labelSelectorPath", v1beta1_custom_resource_subresource_scale->labelSelectorPath) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_custom_resource_subresource_scale->specReplicasPath
    if (!v1beta1_custom_resource_subresource_scale->specReplicasPath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "specReplicasPath", v1beta1_custom_resource_subresource_scale->specReplicasPath) == NULL) {
    goto fail; //String
    }


	// v1beta1_custom_resource_subresource_scale->statusReplicasPath
    if (!v1beta1_custom_resource_subresource_scale->statusReplicasPath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "statusReplicasPath", v1beta1_custom_resource_subresource_scale->statusReplicasPath) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_custom_resource_subresource_scale_t *v1beta1_custom_resource_subresource_scale_parseFromJSON(cJSON *v1beta1_custom_resource_subresource_scaleJSON){

    v1beta1_custom_resource_subresource_scale_t *v1beta1_custom_resource_subresource_scale_local_var = NULL;

    // v1beta1_custom_resource_subresource_scale->labelSelectorPath
    cJSON *labelSelectorPath = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_subresource_scaleJSON, "labelSelectorPath");
    if (labelSelectorPath) { 
    if(!cJSON_IsString(labelSelectorPath))
    {
    goto end; //String
    }
    }

    // v1beta1_custom_resource_subresource_scale->specReplicasPath
    cJSON *specReplicasPath = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_subresource_scaleJSON, "specReplicasPath");
    if (!specReplicasPath) {
        goto end;
    }

    
    if(!cJSON_IsString(specReplicasPath))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_subresource_scale->statusReplicasPath
    cJSON *statusReplicasPath = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_subresource_scaleJSON, "statusReplicasPath");
    if (!statusReplicasPath) {
        goto end;
    }

    
    if(!cJSON_IsString(statusReplicasPath))
    {
    goto end; //String
    }


    v1beta1_custom_resource_subresource_scale_local_var = v1beta1_custom_resource_subresource_scale_create (
        labelSelectorPath ? strdup(labelSelectorPath->valuestring) : NULL,
        strdup(specReplicasPath->valuestring),
        strdup(statusReplicasPath->valuestring)
        );

    return v1beta1_custom_resource_subresource_scale_local_var;
end:
    return NULL;

}

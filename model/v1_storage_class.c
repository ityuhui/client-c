#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_class.h"



v1_storage_class_t *v1_storage_class_create(
    int allowVolumeExpansion,
    list_t *allowedTopologies,
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *mountOptions,
    list_t* parameters,
    char *provisioner,
    char *reclaimPolicy,
    char *volumeBindingMode
    ) {
	v1_storage_class_t *v1_storage_class_local_var = malloc(sizeof(v1_storage_class_t));
    if (!v1_storage_class_local_var) {
        return NULL;
    }
	v1_storage_class_local_var->allowVolumeExpansion = allowVolumeExpansion;
	v1_storage_class_local_var->allowedTopologies = allowedTopologies;
	v1_storage_class_local_var->apiVersion = apiVersion;
	v1_storage_class_local_var->kind = kind;
	v1_storage_class_local_var->metadata = metadata;
	v1_storage_class_local_var->mountOptions = mountOptions;
	v1_storage_class_local_var->parameters = parameters;
	v1_storage_class_local_var->provisioner = provisioner;
	v1_storage_class_local_var->reclaimPolicy = reclaimPolicy;
	v1_storage_class_local_var->volumeBindingMode = volumeBindingMode;

	return v1_storage_class_local_var;
}


void v1_storage_class_free(v1_storage_class_t *v1_storage_class) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_storage_class->allowedTopologies) {
		v1_topology_selector_term_free(listEntry->data);
	}
	list_free(v1_storage_class->allowedTopologies);
    free(v1_storage_class->apiVersion);
    free(v1_storage_class->kind);
    v1_object_meta_free(v1_storage_class->metadata);
	list_ForEach(listEntry, v1_storage_class->mountOptions) {
		free(listEntry->data);
	}
	list_free(v1_storage_class->mountOptions);
	list_ForEach(listEntry, v1_storage_class->parameters) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_storage_class->parameters);
    free(v1_storage_class->provisioner);
    free(v1_storage_class->reclaimPolicy);
    free(v1_storage_class->volumeBindingMode);
	free(v1_storage_class);
}

cJSON *v1_storage_class_convertToJSON(v1_storage_class_t *v1_storage_class) {
	cJSON *item = cJSON_CreateObject();

	// v1_storage_class->allowVolumeExpansion
    if(v1_storage_class->allowVolumeExpansion) { 
    if(cJSON_AddBoolToObject(item, "allowVolumeExpansion", v1_storage_class->allowVolumeExpansion) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_storage_class->allowedTopologies
    if(v1_storage_class->allowedTopologies) { 
    cJSON *allowedTopologies = cJSON_AddArrayToObject(item, "allowedTopologies");
    if(allowedTopologies == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowedTopologiesListEntry;
    if (v1_storage_class->allowedTopologies) {
    list_ForEach(allowedTopologiesListEntry, v1_storage_class->allowedTopologies) {
    cJSON *itemLocal = v1_topology_selector_term_convertToJSON(allowedTopologiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowedTopologies, itemLocal);
    }
    }
     } 


	// v1_storage_class->apiVersion
    if(v1_storage_class->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_storage_class->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_storage_class->kind
    if(v1_storage_class->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_storage_class->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_storage_class->metadata
    if(v1_storage_class->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_storage_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_storage_class->mountOptions
    if(v1_storage_class->mountOptions) { 
	cJSON *mount_options = cJSON_AddArrayToObject(item, "mountOptions");
	if(mount_options == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *mount_optionsListEntry;
    list_ForEach(mount_optionsListEntry, v1_storage_class->mountOptions) {
    if(cJSON_AddStringToObject(mount_options, "", (char*)mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_storage_class->parameters
    if(v1_storage_class->parameters) { 
	cJSON *parameters = cJSON_AddObjectToObject(item, "parameters");
	if(parameters == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *parametersListEntry;
    if (v1_storage_class->parameters) {
    list_ForEach(parametersListEntry, v1_storage_class->parameters) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)parametersListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(parameters,"", localMapObject);
    }
    }
     } 


	// v1_storage_class->provisioner
    if (!v1_storage_class->provisioner) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "provisioner", v1_storage_class->provisioner) == NULL) {
    goto fail; //String
    }


	// v1_storage_class->reclaimPolicy
    if(v1_storage_class->reclaimPolicy) { 
    if(cJSON_AddStringToObject(item, "reclaimPolicy", v1_storage_class->reclaimPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_storage_class->volumeBindingMode
    if(v1_storage_class->volumeBindingMode) { 
    if(cJSON_AddStringToObject(item, "volumeBindingMode", v1_storage_class->volumeBindingMode) == NULL) {
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

v1_storage_class_t *v1_storage_class_parseFromJSON(cJSON *v1_storage_classJSON){

    v1_storage_class_t *v1_storage_class_local_var = NULL;

    // v1_storage_class->allowVolumeExpansion
    cJSON *allowVolumeExpansion = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "allowVolumeExpansion");
    if (allowVolumeExpansion) { 
    if(!cJSON_IsBool(allowVolumeExpansion))
    {
    goto end; //Bool
    }
    }

    // v1_storage_class->allowedTopologies
    cJSON *allowedTopologies = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "allowedTopologies");
    list_t *allowedTopologiesList;
    if (allowedTopologies) { 
    cJSON *allowedTopologies_local_nonprimitive;
    if(!cJSON_IsArray(allowedTopologies)){
        goto end; //nonprimitive container
    }

    allowedTopologiesList = list_create();

    cJSON_ArrayForEach(allowedTopologies_local_nonprimitive,allowedTopologies )
    {
        if(!cJSON_IsObject(allowedTopologies_local_nonprimitive)){
            goto end;
        }
        v1_topology_selector_term_t *allowedTopologiesItem = v1_topology_selector_term_parseFromJSON(allowedTopologies_local_nonprimitive);

        list_addElement(allowedTopologiesList, allowedTopologiesItem);
    }
    }

    // v1_storage_class->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_storage_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_storage_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_storage_class->mountOptions
    cJSON *mountOptions = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "mountOptions");
    list_t *mount_optionsList;
    if (mountOptions) { 
    cJSON *mount_options_local;
    if(!cJSON_IsArray(mountOptions)) {
        goto end;//primitive container
    }
    mount_optionsList = list_create();

    cJSON_ArrayForEach(mount_options_local, mountOptions)
    {
        if(!cJSON_IsString(mount_options_local))
        {
            goto end;
        }
        list_addElement(mount_optionsList , strdup(mount_options_local->valuestring));
    }
    }

    // v1_storage_class->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "parameters");
    list_t *List;
    if (parameters) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(parameters)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, parameters)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_storage_class->provisioner
    cJSON *provisioner = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "provisioner");
    if (!provisioner) {
        goto end;
    }

    
    if(!cJSON_IsString(provisioner))
    {
    goto end; //String
    }

    // v1_storage_class->reclaimPolicy
    cJSON *reclaimPolicy = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "reclaimPolicy");
    if (reclaimPolicy) { 
    if(!cJSON_IsString(reclaimPolicy))
    {
    goto end; //String
    }
    }

    // v1_storage_class->volumeBindingMode
    cJSON *volumeBindingMode = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "volumeBindingMode");
    if (volumeBindingMode) { 
    if(!cJSON_IsString(volumeBindingMode))
    {
    goto end; //String
    }
    }


    v1_storage_class_local_var = v1_storage_class_create (
        allowVolumeExpansion ? allowVolumeExpansion->valueint : 0,
        allowedTopologies ? allowedTopologiesList : NULL,
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        mountOptions ? mount_optionsList : NULL,
        parameters ? List : NULL,
        strdup(provisioner->valuestring),
        reclaimPolicy ? strdup(reclaimPolicy->valuestring) : NULL,
        volumeBindingMode ? strdup(volumeBindingMode->valuestring) : NULL
        );

    return v1_storage_class_local_var;
end:
    return NULL;

}

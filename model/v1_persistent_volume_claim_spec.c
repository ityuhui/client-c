#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_spec.h"



v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec_create(
    list_t *accessModes,
    v1_typed_local_object_reference_t *dataSource,
    v1_resource_requirements_t *resources,
    v1_label_selector_t *selector,
    char *storageClassName,
    char *volumeMode,
    char *volumeName
    ) {
	v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec_local_var = malloc(sizeof(v1_persistent_volume_claim_spec_t));
    if (!v1_persistent_volume_claim_spec_local_var) {
        return NULL;
    }
	v1_persistent_volume_claim_spec_local_var->accessModes = accessModes;
	v1_persistent_volume_claim_spec_local_var->dataSource = dataSource;
	v1_persistent_volume_claim_spec_local_var->resources = resources;
	v1_persistent_volume_claim_spec_local_var->selector = selector;
	v1_persistent_volume_claim_spec_local_var->storageClassName = storageClassName;
	v1_persistent_volume_claim_spec_local_var->volumeMode = volumeMode;
	v1_persistent_volume_claim_spec_local_var->volumeName = volumeName;

	return v1_persistent_volume_claim_spec_local_var;
}


void v1_persistent_volume_claim_spec_free(v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_persistent_volume_claim_spec->accessModes) {
		free(listEntry->data);
	}
	list_free(v1_persistent_volume_claim_spec->accessModes);
    v1_typed_local_object_reference_free(v1_persistent_volume_claim_spec->dataSource);
    v1_resource_requirements_free(v1_persistent_volume_claim_spec->resources);
    v1_label_selector_free(v1_persistent_volume_claim_spec->selector);
    free(v1_persistent_volume_claim_spec->storageClassName);
    free(v1_persistent_volume_claim_spec->volumeMode);
    free(v1_persistent_volume_claim_spec->volumeName);
	free(v1_persistent_volume_claim_spec);
}

cJSON *v1_persistent_volume_claim_spec_convertToJSON(v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_persistent_volume_claim_spec->accessModes
    if(v1_persistent_volume_claim_spec->accessModes) { 
	cJSON *access_modes = cJSON_AddArrayToObject(item, "accessModes");
	if(access_modes == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *access_modesListEntry;
    list_ForEach(access_modesListEntry, v1_persistent_volume_claim_spec->accessModes) {
    if(cJSON_AddStringToObject(access_modes, "", (char*)access_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_persistent_volume_claim_spec->dataSource
    if(v1_persistent_volume_claim_spec->dataSource) { 
    cJSON *dataSource_local_JSON = v1_typed_local_object_reference_convertToJSON(v1_persistent_volume_claim_spec->dataSource);
    if(dataSource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dataSource", dataSource_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_claim_spec->resources
    if(v1_persistent_volume_claim_spec->resources) { 
    cJSON *resources_local_JSON = v1_resource_requirements_convertToJSON(v1_persistent_volume_claim_spec->resources);
    if(resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resources", resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_claim_spec->selector
    if(v1_persistent_volume_claim_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_persistent_volume_claim_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_claim_spec->storageClassName
    if(v1_persistent_volume_claim_spec->storageClassName) { 
    if(cJSON_AddStringToObject(item, "storageClassName", v1_persistent_volume_claim_spec->storageClassName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_claim_spec->volumeMode
    if(v1_persistent_volume_claim_spec->volumeMode) { 
    if(cJSON_AddStringToObject(item, "volumeMode", v1_persistent_volume_claim_spec->volumeMode) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_claim_spec->volumeName
    if(v1_persistent_volume_claim_spec->volumeName) { 
    if(cJSON_AddStringToObject(item, "volumeName", v1_persistent_volume_claim_spec->volumeName) == NULL) {
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

v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec_parseFromJSON(cJSON *v1_persistent_volume_claim_specJSON){

    v1_persistent_volume_claim_spec_t *v1_persistent_volume_claim_spec_local_var = NULL;

    // v1_persistent_volume_claim_spec->accessModes
    cJSON *accessModes = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "accessModes");
    list_t *access_modesList;
    if (accessModes) { 
    cJSON *access_modes_local;
    if(!cJSON_IsArray(accessModes)) {
        goto end;//primitive container
    }
    access_modesList = list_create();

    cJSON_ArrayForEach(access_modes_local, accessModes)
    {
        if(!cJSON_IsString(access_modes_local))
        {
            goto end;
        }
        list_addElement(access_modesList , strdup(access_modes_local->valuestring));
    }
    }

    // v1_persistent_volume_claim_spec->dataSource
    cJSON *dataSource = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "dataSource");
    v1_typed_local_object_reference_t *dataSource_local_nonprim = NULL;
    if (dataSource) { 
    dataSource_local_nonprim = v1_typed_local_object_reference_parseFromJSON(dataSource); //nonprimitive
    }

    // v1_persistent_volume_claim_spec->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "resources");
    v1_resource_requirements_t *resources_local_nonprim = NULL;
    if (resources) { 
    resources_local_nonprim = v1_resource_requirements_parseFromJSON(resources); //nonprimitive
    }

    // v1_persistent_volume_claim_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1_persistent_volume_claim_spec->storageClassName
    cJSON *storageClassName = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "storageClassName");
    if (storageClassName) { 
    if(!cJSON_IsString(storageClassName))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_claim_spec->volumeMode
    cJSON *volumeMode = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "volumeMode");
    if (volumeMode) { 
    if(!cJSON_IsString(volumeMode))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_claim_spec->volumeName
    cJSON *volumeName = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_specJSON, "volumeName");
    if (volumeName) { 
    if(!cJSON_IsString(volumeName))
    {
    goto end; //String
    }
    }


    v1_persistent_volume_claim_spec_local_var = v1_persistent_volume_claim_spec_create (
        accessModes ? access_modesList : NULL,
        dataSource ? dataSource_local_nonprim : NULL,
        resources ? resources_local_nonprim : NULL,
        selector ? selector_local_nonprim : NULL,
        storageClassName ? strdup(storageClassName->valuestring) : NULL,
        volumeMode ? strdup(volumeMode->valuestring) : NULL,
        volumeName ? strdup(volumeName->valuestring) : NULL
        );

    return v1_persistent_volume_claim_spec_local_var;
end:
    return NULL;

}

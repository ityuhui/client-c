#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_volume_attachment_source.h"



v1alpha1_volume_attachment_source_t *v1alpha1_volume_attachment_source_create(
    v1_persistent_volume_spec_t *inlineVolumeSpec,
    char *persistentVolumeName
    ) {
	v1alpha1_volume_attachment_source_t *v1alpha1_volume_attachment_source_local_var = malloc(sizeof(v1alpha1_volume_attachment_source_t));
    if (!v1alpha1_volume_attachment_source_local_var) {
        return NULL;
    }
	v1alpha1_volume_attachment_source_local_var->inlineVolumeSpec = inlineVolumeSpec;
	v1alpha1_volume_attachment_source_local_var->persistentVolumeName = persistentVolumeName;

	return v1alpha1_volume_attachment_source_local_var;
}


void v1alpha1_volume_attachment_source_free(v1alpha1_volume_attachment_source_t *v1alpha1_volume_attachment_source) {
    listEntry_t *listEntry;
    v1_persistent_volume_spec_free(v1alpha1_volume_attachment_source->inlineVolumeSpec);
    free(v1alpha1_volume_attachment_source->persistentVolumeName);
	free(v1alpha1_volume_attachment_source);
}

cJSON *v1alpha1_volume_attachment_source_convertToJSON(v1alpha1_volume_attachment_source_t *v1alpha1_volume_attachment_source) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_volume_attachment_source->inlineVolumeSpec
    if(v1alpha1_volume_attachment_source->inlineVolumeSpec) { 
    cJSON *inlineVolumeSpec_local_JSON = v1_persistent_volume_spec_convertToJSON(v1alpha1_volume_attachment_source->inlineVolumeSpec);
    if(inlineVolumeSpec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "inlineVolumeSpec", inlineVolumeSpec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_volume_attachment_source->persistentVolumeName
    if(v1alpha1_volume_attachment_source->persistentVolumeName) { 
    if(cJSON_AddStringToObject(item, "persistentVolumeName", v1alpha1_volume_attachment_source->persistentVolumeName) == NULL) {
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

v1alpha1_volume_attachment_source_t *v1alpha1_volume_attachment_source_parseFromJSON(cJSON *v1alpha1_volume_attachment_sourceJSON){

    v1alpha1_volume_attachment_source_t *v1alpha1_volume_attachment_source_local_var = NULL;

    // v1alpha1_volume_attachment_source->inlineVolumeSpec
    cJSON *inlineVolumeSpec = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_sourceJSON, "inlineVolumeSpec");
    v1_persistent_volume_spec_t *inlineVolumeSpec_local_nonprim = NULL;
    if (inlineVolumeSpec) { 
    inlineVolumeSpec_local_nonprim = v1_persistent_volume_spec_parseFromJSON(inlineVolumeSpec); //nonprimitive
    }

    // v1alpha1_volume_attachment_source->persistentVolumeName
    cJSON *persistentVolumeName = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachment_sourceJSON, "persistentVolumeName");
    if (persistentVolumeName) { 
    if(!cJSON_IsString(persistentVolumeName))
    {
    goto end; //String
    }
    }


    v1alpha1_volume_attachment_source_local_var = v1alpha1_volume_attachment_source_create (
        inlineVolumeSpec ? inlineVolumeSpec_local_nonprim : NULL,
        persistentVolumeName ? strdup(persistentVolumeName->valuestring) : NULL
        );

    return v1alpha1_volume_attachment_source_local_var;
end:
    return NULL;

}

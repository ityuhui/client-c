#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_csi_driver_spec.h"



v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_create(
    int attachRequired,
    int podInfoOnMount,
    list_t *volumeLifecycleModes
    ) {
	v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_local_var = malloc(sizeof(v1beta1_csi_driver_spec_t));
    if (!v1beta1_csi_driver_spec_local_var) {
        return NULL;
    }
	v1beta1_csi_driver_spec_local_var->attachRequired = attachRequired;
	v1beta1_csi_driver_spec_local_var->podInfoOnMount = podInfoOnMount;
	v1beta1_csi_driver_spec_local_var->volumeLifecycleModes = volumeLifecycleModes;

	return v1beta1_csi_driver_spec_local_var;
}


void v1beta1_csi_driver_spec_free(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_csi_driver_spec->volumeLifecycleModes) {
		free(listEntry->data);
	}
	list_free(v1beta1_csi_driver_spec->volumeLifecycleModes);
	free(v1beta1_csi_driver_spec);
}

cJSON *v1beta1_csi_driver_spec_convertToJSON(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_csi_driver_spec->attachRequired
    if(v1beta1_csi_driver_spec->attachRequired) { 
    if(cJSON_AddBoolToObject(item, "attachRequired", v1beta1_csi_driver_spec->attachRequired) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1beta1_csi_driver_spec->podInfoOnMount
    if(v1beta1_csi_driver_spec->podInfoOnMount) { 
    if(cJSON_AddBoolToObject(item, "podInfoOnMount", v1beta1_csi_driver_spec->podInfoOnMount) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1beta1_csi_driver_spec->volumeLifecycleModes
    if(v1beta1_csi_driver_spec->volumeLifecycleModes) { 
	cJSON *volume_lifecycle_modes = cJSON_AddArrayToObject(item, "volumeLifecycleModes");
	if(volume_lifecycle_modes == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *volume_lifecycle_modesListEntry;
    list_ForEach(volume_lifecycle_modesListEntry, v1beta1_csi_driver_spec->volumeLifecycleModes) {
    if(cJSON_AddStringToObject(volume_lifecycle_modes, "", (char*)volume_lifecycle_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_parseFromJSON(cJSON *v1beta1_csi_driver_specJSON){

    v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_local_var = NULL;

    // v1beta1_csi_driver_spec->attachRequired
    cJSON *attachRequired = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_driver_specJSON, "attachRequired");
    if (attachRequired) { 
    if(!cJSON_IsBool(attachRequired))
    {
    goto end; //Bool
    }
    }

    // v1beta1_csi_driver_spec->podInfoOnMount
    cJSON *podInfoOnMount = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_driver_specJSON, "podInfoOnMount");
    if (podInfoOnMount) { 
    if(!cJSON_IsBool(podInfoOnMount))
    {
    goto end; //Bool
    }
    }

    // v1beta1_csi_driver_spec->volumeLifecycleModes
    cJSON *volumeLifecycleModes = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_driver_specJSON, "volumeLifecycleModes");
    list_t *volume_lifecycle_modesList;
    if (volumeLifecycleModes) { 
    cJSON *volume_lifecycle_modes_local;
    if(!cJSON_IsArray(volumeLifecycleModes)) {
        goto end;//primitive container
    }
    volume_lifecycle_modesList = list_create();

    cJSON_ArrayForEach(volume_lifecycle_modes_local, volumeLifecycleModes)
    {
        if(!cJSON_IsString(volume_lifecycle_modes_local))
        {
            goto end;
        }
        list_addElement(volume_lifecycle_modesList , strdup(volume_lifecycle_modes_local->valuestring));
    }
    }


    v1beta1_csi_driver_spec_local_var = v1beta1_csi_driver_spec_create (
        attachRequired ? attachRequired->valueint : 0,
        podInfoOnMount ? podInfoOnMount->valueint : 0,
        volumeLifecycleModes ? volume_lifecycle_modesList : NULL
        );

    return v1beta1_csi_driver_spec_local_var;
end:
    return NULL;

}

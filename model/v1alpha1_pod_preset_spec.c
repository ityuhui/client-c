#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_pod_preset_spec.h"



v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_create(
    list_t *env,
    list_t *envFrom,
    v1_label_selector_t *selector,
    list_t *volumeMounts,
    list_t *volumes
    ) {
	v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_local_var = malloc(sizeof(v1alpha1_pod_preset_spec_t));
    if (!v1alpha1_pod_preset_spec_local_var) {
        return NULL;
    }
	v1alpha1_pod_preset_spec_local_var->env = env;
	v1alpha1_pod_preset_spec_local_var->envFrom = envFrom;
	v1alpha1_pod_preset_spec_local_var->selector = selector;
	v1alpha1_pod_preset_spec_local_var->volumeMounts = volumeMounts;
	v1alpha1_pod_preset_spec_local_var->volumes = volumes;

	return v1alpha1_pod_preset_spec_local_var;
}


void v1alpha1_pod_preset_spec_free(v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1alpha1_pod_preset_spec->env) {
		v1_env_var_free(listEntry->data);
	}
	list_free(v1alpha1_pod_preset_spec->env);
	list_ForEach(listEntry, v1alpha1_pod_preset_spec->envFrom) {
		v1_env_from_source_free(listEntry->data);
	}
	list_free(v1alpha1_pod_preset_spec->envFrom);
    v1_label_selector_free(v1alpha1_pod_preset_spec->selector);
	list_ForEach(listEntry, v1alpha1_pod_preset_spec->volumeMounts) {
		v1_volume_mount_free(listEntry->data);
	}
	list_free(v1alpha1_pod_preset_spec->volumeMounts);
	list_ForEach(listEntry, v1alpha1_pod_preset_spec->volumes) {
		v1_volume_free(listEntry->data);
	}
	list_free(v1alpha1_pod_preset_spec->volumes);
	free(v1alpha1_pod_preset_spec);
}

cJSON *v1alpha1_pod_preset_spec_convertToJSON(v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_pod_preset_spec->env
    if(v1alpha1_pod_preset_spec->env) { 
    cJSON *env = cJSON_AddArrayToObject(item, "env");
    if(env == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *envListEntry;
    if (v1alpha1_pod_preset_spec->env) {
    list_ForEach(envListEntry, v1alpha1_pod_preset_spec->env) {
    cJSON *itemLocal = v1_env_var_convertToJSON(envListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(env, itemLocal);
    }
    }
     } 


	// v1alpha1_pod_preset_spec->envFrom
    if(v1alpha1_pod_preset_spec->envFrom) { 
    cJSON *envFrom = cJSON_AddArrayToObject(item, "envFrom");
    if(envFrom == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *envFromListEntry;
    if (v1alpha1_pod_preset_spec->envFrom) {
    list_ForEach(envFromListEntry, v1alpha1_pod_preset_spec->envFrom) {
    cJSON *itemLocal = v1_env_from_source_convertToJSON(envFromListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(envFrom, itemLocal);
    }
    }
     } 


	// v1alpha1_pod_preset_spec->selector
    if(v1alpha1_pod_preset_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1alpha1_pod_preset_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_pod_preset_spec->volumeMounts
    if(v1alpha1_pod_preset_spec->volumeMounts) { 
    cJSON *volumeMounts = cJSON_AddArrayToObject(item, "volumeMounts");
    if(volumeMounts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumeMountsListEntry;
    if (v1alpha1_pod_preset_spec->volumeMounts) {
    list_ForEach(volumeMountsListEntry, v1alpha1_pod_preset_spec->volumeMounts) {
    cJSON *itemLocal = v1_volume_mount_convertToJSON(volumeMountsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumeMounts, itemLocal);
    }
    }
     } 


	// v1alpha1_pod_preset_spec->volumes
    if(v1alpha1_pod_preset_spec->volumes) { 
    cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
    if(volumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumesListEntry;
    if (v1alpha1_pod_preset_spec->volumes) {
    list_ForEach(volumesListEntry, v1alpha1_pod_preset_spec->volumes) {
    cJSON *itemLocal = v1_volume_convertToJSON(volumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumes, itemLocal);
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

v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_parseFromJSON(cJSON *v1alpha1_pod_preset_specJSON){

    v1alpha1_pod_preset_spec_t *v1alpha1_pod_preset_spec_local_var = NULL;

    // v1alpha1_pod_preset_spec->env
    cJSON *env = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "env");
    list_t *envList;
    if (env) { 
    cJSON *env_local_nonprimitive;
    if(!cJSON_IsArray(env)){
        goto end; //nonprimitive container
    }

    envList = list_create();

    cJSON_ArrayForEach(env_local_nonprimitive,env )
    {
        if(!cJSON_IsObject(env_local_nonprimitive)){
            goto end;
        }
        v1_env_var_t *envItem = v1_env_var_parseFromJSON(env_local_nonprimitive);

        list_addElement(envList, envItem);
    }
    }

    // v1alpha1_pod_preset_spec->envFrom
    cJSON *envFrom = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "envFrom");
    list_t *envFromList;
    if (envFrom) { 
    cJSON *envFrom_local_nonprimitive;
    if(!cJSON_IsArray(envFrom)){
        goto end; //nonprimitive container
    }

    envFromList = list_create();

    cJSON_ArrayForEach(envFrom_local_nonprimitive,envFrom )
    {
        if(!cJSON_IsObject(envFrom_local_nonprimitive)){
            goto end;
        }
        v1_env_from_source_t *envFromItem = v1_env_from_source_parseFromJSON(envFrom_local_nonprimitive);

        list_addElement(envFromList, envFromItem);
    }
    }

    // v1alpha1_pod_preset_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1alpha1_pod_preset_spec->volumeMounts
    cJSON *volumeMounts = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "volumeMounts");
    list_t *volumeMountsList;
    if (volumeMounts) { 
    cJSON *volumeMounts_local_nonprimitive;
    if(!cJSON_IsArray(volumeMounts)){
        goto end; //nonprimitive container
    }

    volumeMountsList = list_create();

    cJSON_ArrayForEach(volumeMounts_local_nonprimitive,volumeMounts )
    {
        if(!cJSON_IsObject(volumeMounts_local_nonprimitive)){
            goto end;
        }
        v1_volume_mount_t *volumeMountsItem = v1_volume_mount_parseFromJSON(volumeMounts_local_nonprimitive);

        list_addElement(volumeMountsList, volumeMountsItem);
    }
    }

    // v1alpha1_pod_preset_spec->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_preset_specJSON, "volumes");
    list_t *volumesList;
    if (volumes) { 
    cJSON *volumes_local_nonprimitive;
    if(!cJSON_IsArray(volumes)){
        goto end; //nonprimitive container
    }

    volumesList = list_create();

    cJSON_ArrayForEach(volumes_local_nonprimitive,volumes )
    {
        if(!cJSON_IsObject(volumes_local_nonprimitive)){
            goto end;
        }
        v1_volume_t *volumesItem = v1_volume_parseFromJSON(volumes_local_nonprimitive);

        list_addElement(volumesList, volumesItem);
    }
    }


    v1alpha1_pod_preset_spec_local_var = v1alpha1_pod_preset_spec_create (
        env ? envList : NULL,
        envFrom ? envFromList : NULL,
        selector ? selector_local_nonprim : NULL,
        volumeMounts ? volumeMountsList : NULL,
        volumes ? volumesList : NULL
        );

    return v1alpha1_pod_preset_spec_local_var;
end:
    return NULL;

}

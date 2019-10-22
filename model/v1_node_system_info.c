#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_system_info.h"



v1_node_system_info_t *v1_node_system_info_create(
    char *architecture,
    char *bootID,
    char *containerRuntimeVersion,
    char *kernelVersion,
    char *kubeProxyVersion,
    char *kubeletVersion,
    char *machineID,
    char *operatingSystem,
    char *osImage,
    char *systemUUID
    ) {
	v1_node_system_info_t *v1_node_system_info_local_var = malloc(sizeof(v1_node_system_info_t));
    if (!v1_node_system_info_local_var) {
        return NULL;
    }
	v1_node_system_info_local_var->architecture = architecture;
	v1_node_system_info_local_var->bootID = bootID;
	v1_node_system_info_local_var->containerRuntimeVersion = containerRuntimeVersion;
	v1_node_system_info_local_var->kernelVersion = kernelVersion;
	v1_node_system_info_local_var->kubeProxyVersion = kubeProxyVersion;
	v1_node_system_info_local_var->kubeletVersion = kubeletVersion;
	v1_node_system_info_local_var->machineID = machineID;
	v1_node_system_info_local_var->operatingSystem = operatingSystem;
	v1_node_system_info_local_var->osImage = osImage;
	v1_node_system_info_local_var->systemUUID = systemUUID;

	return v1_node_system_info_local_var;
}


void v1_node_system_info_free(v1_node_system_info_t *v1_node_system_info) {
    listEntry_t *listEntry;
    free(v1_node_system_info->architecture);
    free(v1_node_system_info->bootID);
    free(v1_node_system_info->containerRuntimeVersion);
    free(v1_node_system_info->kernelVersion);
    free(v1_node_system_info->kubeProxyVersion);
    free(v1_node_system_info->kubeletVersion);
    free(v1_node_system_info->machineID);
    free(v1_node_system_info->operatingSystem);
    free(v1_node_system_info->osImage);
    free(v1_node_system_info->systemUUID);
	free(v1_node_system_info);
}

cJSON *v1_node_system_info_convertToJSON(v1_node_system_info_t *v1_node_system_info) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_system_info->architecture
    if (!v1_node_system_info->architecture) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "architecture", v1_node_system_info->architecture) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->bootID
    if (!v1_node_system_info->bootID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "bootID", v1_node_system_info->bootID) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->containerRuntimeVersion
    if (!v1_node_system_info->containerRuntimeVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "containerRuntimeVersion", v1_node_system_info->containerRuntimeVersion) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->kernelVersion
    if (!v1_node_system_info->kernelVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kernelVersion", v1_node_system_info->kernelVersion) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->kubeProxyVersion
    if (!v1_node_system_info->kubeProxyVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kubeProxyVersion", v1_node_system_info->kubeProxyVersion) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->kubeletVersion
    if (!v1_node_system_info->kubeletVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kubeletVersion", v1_node_system_info->kubeletVersion) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->machineID
    if (!v1_node_system_info->machineID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "machineID", v1_node_system_info->machineID) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->operatingSystem
    if (!v1_node_system_info->operatingSystem) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "operatingSystem", v1_node_system_info->operatingSystem) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->osImage
    if (!v1_node_system_info->osImage) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "osImage", v1_node_system_info->osImage) == NULL) {
    goto fail; //String
    }


	// v1_node_system_info->systemUUID
    if (!v1_node_system_info->systemUUID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "systemUUID", v1_node_system_info->systemUUID) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_node_system_info_t *v1_node_system_info_parseFromJSON(cJSON *v1_node_system_infoJSON){

    v1_node_system_info_t *v1_node_system_info_local_var = NULL;

    // v1_node_system_info->architecture
    cJSON *architecture = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "architecture");
    if (!architecture) {
        goto end;
    }

    
    if(!cJSON_IsString(architecture))
    {
    goto end; //String
    }

    // v1_node_system_info->bootID
    cJSON *bootID = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "bootID");
    if (!bootID) {
        goto end;
    }

    
    if(!cJSON_IsString(bootID))
    {
    goto end; //String
    }

    // v1_node_system_info->containerRuntimeVersion
    cJSON *containerRuntimeVersion = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "containerRuntimeVersion");
    if (!containerRuntimeVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(containerRuntimeVersion))
    {
    goto end; //String
    }

    // v1_node_system_info->kernelVersion
    cJSON *kernelVersion = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kernelVersion");
    if (!kernelVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(kernelVersion))
    {
    goto end; //String
    }

    // v1_node_system_info->kubeProxyVersion
    cJSON *kubeProxyVersion = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kubeProxyVersion");
    if (!kubeProxyVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(kubeProxyVersion))
    {
    goto end; //String
    }

    // v1_node_system_info->kubeletVersion
    cJSON *kubeletVersion = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kubeletVersion");
    if (!kubeletVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(kubeletVersion))
    {
    goto end; //String
    }

    // v1_node_system_info->machineID
    cJSON *machineID = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "machineID");
    if (!machineID) {
        goto end;
    }

    
    if(!cJSON_IsString(machineID))
    {
    goto end; //String
    }

    // v1_node_system_info->operatingSystem
    cJSON *operatingSystem = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "operatingSystem");
    if (!operatingSystem) {
        goto end;
    }

    
    if(!cJSON_IsString(operatingSystem))
    {
    goto end; //String
    }

    // v1_node_system_info->osImage
    cJSON *osImage = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "osImage");
    if (!osImage) {
        goto end;
    }

    
    if(!cJSON_IsString(osImage))
    {
    goto end; //String
    }

    // v1_node_system_info->systemUUID
    cJSON *systemUUID = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "systemUUID");
    if (!systemUUID) {
        goto end;
    }

    
    if(!cJSON_IsString(systemUUID))
    {
    goto end; //String
    }


    v1_node_system_info_local_var = v1_node_system_info_create (
        strdup(architecture->valuestring),
        strdup(bootID->valuestring),
        strdup(containerRuntimeVersion->valuestring),
        strdup(kernelVersion->valuestring),
        strdup(kubeProxyVersion->valuestring),
        strdup(kubeletVersion->valuestring),
        strdup(machineID->valuestring),
        strdup(operatingSystem->valuestring),
        strdup(osImage->valuestring),
        strdup(systemUUID->valuestring)
        );

    return v1_node_system_info_local_var;
end:
    return NULL;

}

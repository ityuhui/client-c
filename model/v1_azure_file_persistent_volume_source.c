#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_azure_file_persistent_volume_source.h"



v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_create(
    int readOnly,
    char *secretName,
    char *secretNamespace,
    char *shareName
    ) {
	v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_local_var = malloc(sizeof(v1_azure_file_persistent_volume_source_t));
    if (!v1_azure_file_persistent_volume_source_local_var) {
        return NULL;
    }
	v1_azure_file_persistent_volume_source_local_var->readOnly = readOnly;
	v1_azure_file_persistent_volume_source_local_var->secretName = secretName;
	v1_azure_file_persistent_volume_source_local_var->secretNamespace = secretNamespace;
	v1_azure_file_persistent_volume_source_local_var->shareName = shareName;

	return v1_azure_file_persistent_volume_source_local_var;
}


void v1_azure_file_persistent_volume_source_free(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source) {
    listEntry_t *listEntry;
    free(v1_azure_file_persistent_volume_source->secretName);
    free(v1_azure_file_persistent_volume_source->secretNamespace);
    free(v1_azure_file_persistent_volume_source->shareName);
	free(v1_azure_file_persistent_volume_source);
}

cJSON *v1_azure_file_persistent_volume_source_convertToJSON(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_azure_file_persistent_volume_source->readOnly
    if(v1_azure_file_persistent_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_azure_file_persistent_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_azure_file_persistent_volume_source->secretName
    if (!v1_azure_file_persistent_volume_source->secretName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "secretName", v1_azure_file_persistent_volume_source->secretName) == NULL) {
    goto fail; //String
    }


	// v1_azure_file_persistent_volume_source->secretNamespace
    if(v1_azure_file_persistent_volume_source->secretNamespace) { 
    if(cJSON_AddStringToObject(item, "secretNamespace", v1_azure_file_persistent_volume_source->secretNamespace) == NULL) {
    goto fail; //String
    }
     } 


	// v1_azure_file_persistent_volume_source->shareName
    if (!v1_azure_file_persistent_volume_source->shareName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "shareName", v1_azure_file_persistent_volume_source->shareName) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_parseFromJSON(cJSON *v1_azure_file_persistent_volume_sourceJSON){

    v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_local_var = NULL;

    // v1_azure_file_persistent_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_azure_file_persistent_volume_source->secretName
    cJSON *secretName = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "secretName");
    if (!secretName) {
        goto end;
    }

    
    if(!cJSON_IsString(secretName))
    {
    goto end; //String
    }

    // v1_azure_file_persistent_volume_source->secretNamespace
    cJSON *secretNamespace = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "secretNamespace");
    if (secretNamespace) { 
    if(!cJSON_IsString(secretNamespace))
    {
    goto end; //String
    }
    }

    // v1_azure_file_persistent_volume_source->shareName
    cJSON *shareName = cJSON_GetObjectItemCaseSensitive(v1_azure_file_persistent_volume_sourceJSON, "shareName");
    if (!shareName) {
        goto end;
    }

    
    if(!cJSON_IsString(shareName))
    {
    goto end; //String
    }


    v1_azure_file_persistent_volume_source_local_var = v1_azure_file_persistent_volume_source_create (
        readOnly ? readOnly->valueint : 0,
        strdup(secretName->valuestring),
        secretNamespace ? strdup(secretNamespace->valuestring) : NULL,
        strdup(shareName->valuestring)
        );

    return v1_azure_file_persistent_volume_source_local_var;
end:
    return NULL;

}

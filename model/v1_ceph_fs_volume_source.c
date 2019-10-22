#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ceph_fs_volume_source.h"



v1_ceph_fs_volume_source_t *v1_ceph_fs_volume_source_create(
    list_t *monitors,
    char *path,
    int readOnly,
    char *secretFile,
    v1_local_object_reference_t *secretRef,
    char *user
    ) {
	v1_ceph_fs_volume_source_t *v1_ceph_fs_volume_source_local_var = malloc(sizeof(v1_ceph_fs_volume_source_t));
    if (!v1_ceph_fs_volume_source_local_var) {
        return NULL;
    }
	v1_ceph_fs_volume_source_local_var->monitors = monitors;
	v1_ceph_fs_volume_source_local_var->path = path;
	v1_ceph_fs_volume_source_local_var->readOnly = readOnly;
	v1_ceph_fs_volume_source_local_var->secretFile = secretFile;
	v1_ceph_fs_volume_source_local_var->secretRef = secretRef;
	v1_ceph_fs_volume_source_local_var->user = user;

	return v1_ceph_fs_volume_source_local_var;
}


void v1_ceph_fs_volume_source_free(v1_ceph_fs_volume_source_t *v1_ceph_fs_volume_source) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_ceph_fs_volume_source->monitors) {
		free(listEntry->data);
	}
	list_free(v1_ceph_fs_volume_source->monitors);
    free(v1_ceph_fs_volume_source->path);
    free(v1_ceph_fs_volume_source->secretFile);
    v1_local_object_reference_free(v1_ceph_fs_volume_source->secretRef);
    free(v1_ceph_fs_volume_source->user);
	free(v1_ceph_fs_volume_source);
}

cJSON *v1_ceph_fs_volume_source_convertToJSON(v1_ceph_fs_volume_source_t *v1_ceph_fs_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_ceph_fs_volume_source->monitors
    if (!v1_ceph_fs_volume_source->monitors) {
        goto fail;
    }
    
	cJSON *monitors = cJSON_AddArrayToObject(item, "monitors");
	if(monitors == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *monitorsListEntry;
    list_ForEach(monitorsListEntry, v1_ceph_fs_volume_source->monitors) {
    if(cJSON_AddStringToObject(monitors, "", (char*)monitorsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// v1_ceph_fs_volume_source->path
    if(v1_ceph_fs_volume_source->path) { 
    if(cJSON_AddStringToObject(item, "path", v1_ceph_fs_volume_source->path) == NULL) {
    goto fail; //String
    }
     } 


	// v1_ceph_fs_volume_source->readOnly
    if(v1_ceph_fs_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_ceph_fs_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_ceph_fs_volume_source->secretFile
    if(v1_ceph_fs_volume_source->secretFile) { 
    if(cJSON_AddStringToObject(item, "secretFile", v1_ceph_fs_volume_source->secretFile) == NULL) {
    goto fail; //String
    }
     } 


	// v1_ceph_fs_volume_source->secretRef
    if(v1_ceph_fs_volume_source->secretRef) { 
    cJSON *secretRef_local_JSON = v1_local_object_reference_convertToJSON(v1_ceph_fs_volume_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_ceph_fs_volume_source->user
    if(v1_ceph_fs_volume_source->user) { 
    if(cJSON_AddStringToObject(item, "user", v1_ceph_fs_volume_source->user) == NULL) {
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

v1_ceph_fs_volume_source_t *v1_ceph_fs_volume_source_parseFromJSON(cJSON *v1_ceph_fs_volume_sourceJSON){

    v1_ceph_fs_volume_source_t *v1_ceph_fs_volume_source_local_var = NULL;

    // v1_ceph_fs_volume_source->monitors
    cJSON *monitors = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_volume_sourceJSON, "monitors");
    if (!monitors) {
        goto end;
    }

    list_t *monitorsList;
    
    cJSON *monitors_local;
    if(!cJSON_IsArray(monitors)) {
        goto end;//primitive container
    }
    monitorsList = list_create();

    cJSON_ArrayForEach(monitors_local, monitors)
    {
        if(!cJSON_IsString(monitors_local))
        {
            goto end;
        }
        list_addElement(monitorsList , strdup(monitors_local->valuestring));
    }

    // v1_ceph_fs_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_volume_sourceJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // v1_ceph_fs_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_ceph_fs_volume_source->secretFile
    cJSON *secretFile = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_volume_sourceJSON, "secretFile");
    if (secretFile) { 
    if(!cJSON_IsString(secretFile))
    {
    goto end; //String
    }
    }

    // v1_ceph_fs_volume_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_volume_sourceJSON, "secretRef");
    v1_local_object_reference_t *secretRef_local_nonprim = NULL;
    if (secretRef) { 
    secretRef_local_nonprim = v1_local_object_reference_parseFromJSON(secretRef); //nonprimitive
    }

    // v1_ceph_fs_volume_source->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_volume_sourceJSON, "user");
    if (user) { 
    if(!cJSON_IsString(user))
    {
    goto end; //String
    }
    }


    v1_ceph_fs_volume_source_local_var = v1_ceph_fs_volume_source_create (
        monitorsList,
        path ? strdup(path->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0,
        secretFile ? strdup(secretFile->valuestring) : NULL,
        secretRef ? secretRef_local_nonprim : NULL,
        user ? strdup(user->valuestring) : NULL
        );

    return v1_ceph_fs_volume_source_local_var;
end:
    return NULL;

}

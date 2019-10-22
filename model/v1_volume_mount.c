#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_mount.h"



v1_volume_mount_t *v1_volume_mount_create(
    char *mountPath,
    char *mountPropagation,
    char *name,
    int readOnly,
    char *subPath,
    char *subPathExpr
    ) {
	v1_volume_mount_t *v1_volume_mount_local_var = malloc(sizeof(v1_volume_mount_t));
    if (!v1_volume_mount_local_var) {
        return NULL;
    }
	v1_volume_mount_local_var->mountPath = mountPath;
	v1_volume_mount_local_var->mountPropagation = mountPropagation;
	v1_volume_mount_local_var->name = name;
	v1_volume_mount_local_var->readOnly = readOnly;
	v1_volume_mount_local_var->subPath = subPath;
	v1_volume_mount_local_var->subPathExpr = subPathExpr;

	return v1_volume_mount_local_var;
}


void v1_volume_mount_free(v1_volume_mount_t *v1_volume_mount) {
    listEntry_t *listEntry;
    free(v1_volume_mount->mountPath);
    free(v1_volume_mount->mountPropagation);
    free(v1_volume_mount->name);
    free(v1_volume_mount->subPath);
    free(v1_volume_mount->subPathExpr);
	free(v1_volume_mount);
}

cJSON *v1_volume_mount_convertToJSON(v1_volume_mount_t *v1_volume_mount) {
	cJSON *item = cJSON_CreateObject();

	// v1_volume_mount->mountPath
    if (!v1_volume_mount->mountPath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "mountPath", v1_volume_mount->mountPath) == NULL) {
    goto fail; //String
    }


	// v1_volume_mount->mountPropagation
    if(v1_volume_mount->mountPropagation) { 
    if(cJSON_AddStringToObject(item, "mountPropagation", v1_volume_mount->mountPropagation) == NULL) {
    goto fail; //String
    }
     } 


	// v1_volume_mount->name
    if (!v1_volume_mount->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_volume_mount->name) == NULL) {
    goto fail; //String
    }


	// v1_volume_mount->readOnly
    if(v1_volume_mount->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_volume_mount->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_volume_mount->subPath
    if(v1_volume_mount->subPath) { 
    if(cJSON_AddStringToObject(item, "subPath", v1_volume_mount->subPath) == NULL) {
    goto fail; //String
    }
     } 


	// v1_volume_mount->subPathExpr
    if(v1_volume_mount->subPathExpr) { 
    if(cJSON_AddStringToObject(item, "subPathExpr", v1_volume_mount->subPathExpr) == NULL) {
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

v1_volume_mount_t *v1_volume_mount_parseFromJSON(cJSON *v1_volume_mountJSON){

    v1_volume_mount_t *v1_volume_mount_local_var = NULL;

    // v1_volume_mount->mountPath
    cJSON *mountPath = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "mountPath");
    if (!mountPath) {
        goto end;
    }

    
    if(!cJSON_IsString(mountPath))
    {
    goto end; //String
    }

    // v1_volume_mount->mountPropagation
    cJSON *mountPropagation = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "mountPropagation");
    if (mountPropagation) { 
    if(!cJSON_IsString(mountPropagation))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_volume_mount->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_volume_mount->subPath
    cJSON *subPath = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "subPath");
    if (subPath) { 
    if(!cJSON_IsString(subPath))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->subPathExpr
    cJSON *subPathExpr = cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "subPathExpr");
    if (subPathExpr) { 
    if(!cJSON_IsString(subPathExpr))
    {
    goto end; //String
    }
    }


    v1_volume_mount_local_var = v1_volume_mount_create (
        strdup(mountPath->valuestring),
        mountPropagation ? strdup(mountPropagation->valuestring) : NULL,
        strdup(name->valuestring),
        readOnly ? readOnly->valueint : 0,
        subPath ? strdup(subPath->valuestring) : NULL,
        subPathExpr ? strdup(subPathExpr->valuestring) : NULL
        );

    return v1_volume_mount_local_var;
end:
    return NULL;

}

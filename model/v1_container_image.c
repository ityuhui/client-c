#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_image.h"



v1_container_image_t *v1_container_image_create(
    list_t *names,
    long sizeBytes
    ) {
	v1_container_image_t *v1_container_image_local_var = malloc(sizeof(v1_container_image_t));
    if (!v1_container_image_local_var) {
        return NULL;
    }
	v1_container_image_local_var->names = names;
	v1_container_image_local_var->sizeBytes = sizeBytes;

	return v1_container_image_local_var;
}


void v1_container_image_free(v1_container_image_t *v1_container_image) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_container_image->names) {
		free(listEntry->data);
	}
	list_free(v1_container_image->names);
	free(v1_container_image);
}

cJSON *v1_container_image_convertToJSON(v1_container_image_t *v1_container_image) {
	cJSON *item = cJSON_CreateObject();

	// v1_container_image->names
    if (!v1_container_image->names) {
        goto fail;
    }
    
	cJSON *names = cJSON_AddArrayToObject(item, "names");
	if(names == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *namesListEntry;
    list_ForEach(namesListEntry, v1_container_image->names) {
    if(cJSON_AddStringToObject(names, "", (char*)namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// v1_container_image->sizeBytes
    if(v1_container_image->sizeBytes) { 
    if(cJSON_AddNumberToObject(item, "sizeBytes", v1_container_image->sizeBytes) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_container_image_t *v1_container_image_parseFromJSON(cJSON *v1_container_imageJSON){

    v1_container_image_t *v1_container_image_local_var = NULL;

    // v1_container_image->names
    cJSON *names = cJSON_GetObjectItemCaseSensitive(v1_container_imageJSON, "names");
    if (!names) {
        goto end;
    }

    list_t *namesList;
    
    cJSON *names_local;
    if(!cJSON_IsArray(names)) {
        goto end;//primitive container
    }
    namesList = list_create();

    cJSON_ArrayForEach(names_local, names)
    {
        if(!cJSON_IsString(names_local))
        {
            goto end;
        }
        list_addElement(namesList , strdup(names_local->valuestring));
    }

    // v1_container_image->sizeBytes
    cJSON *sizeBytes = cJSON_GetObjectItemCaseSensitive(v1_container_imageJSON, "sizeBytes");
    if (sizeBytes) { 
    if(!cJSON_IsNumber(sizeBytes))
    {
    goto end; //Numeric
    }
    }


    v1_container_image_local_var = v1_container_image_create (
        namesList,
        sizeBytes ? sizeBytes->valuedouble : 0
        );

    return v1_container_image_local_var;
end:
    return NULL;

}

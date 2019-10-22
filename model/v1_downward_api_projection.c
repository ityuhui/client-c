#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_downward_api_projection.h"



v1_downward_api_projection_t *v1_downward_api_projection_create(
    list_t *items
    ) {
	v1_downward_api_projection_t *v1_downward_api_projection_local_var = malloc(sizeof(v1_downward_api_projection_t));
    if (!v1_downward_api_projection_local_var) {
        return NULL;
    }
	v1_downward_api_projection_local_var->items = items;

	return v1_downward_api_projection_local_var;
}


void v1_downward_api_projection_free(v1_downward_api_projection_t *v1_downward_api_projection) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_downward_api_projection->items) {
		v1_downward_api_volume_file_free(listEntry->data);
	}
	list_free(v1_downward_api_projection->items);
	free(v1_downward_api_projection);
}

cJSON *v1_downward_api_projection_convertToJSON(v1_downward_api_projection_t *v1_downward_api_projection) {
	cJSON *item = cJSON_CreateObject();

	// v1_downward_api_projection->items
    if(v1_downward_api_projection->items) { 
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_downward_api_projection->items) {
    list_ForEach(itemsListEntry, v1_downward_api_projection->items) {
    cJSON *itemLocal = v1_downward_api_volume_file_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
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

v1_downward_api_projection_t *v1_downward_api_projection_parseFromJSON(cJSON *v1_downward_api_projectionJSON){

    v1_downward_api_projection_t *v1_downward_api_projection_local_var = NULL;

    // v1_downward_api_projection->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_downward_api_projectionJSON, "items");
    list_t *itemsList;
    if (items) { 
    cJSON *items_local_nonprimitive;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_create();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v1_downward_api_volume_file_t *itemsItem = v1_downward_api_volume_file_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }


    v1_downward_api_projection_local_var = v1_downward_api_projection_create (
        items ? itemsList : NULL
        );

    return v1_downward_api_projection_local_var;
end:
    return NULL;

}

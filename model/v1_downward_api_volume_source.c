#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_downward_api_volume_source.h"



v1_downward_api_volume_source_t *v1_downward_api_volume_source_create(
    int defaultMode,
    list_t *items
    ) {
	v1_downward_api_volume_source_t *v1_downward_api_volume_source_local_var = malloc(sizeof(v1_downward_api_volume_source_t));
    if (!v1_downward_api_volume_source_local_var) {
        return NULL;
    }
	v1_downward_api_volume_source_local_var->defaultMode = defaultMode;
	v1_downward_api_volume_source_local_var->items = items;

	return v1_downward_api_volume_source_local_var;
}


void v1_downward_api_volume_source_free(v1_downward_api_volume_source_t *v1_downward_api_volume_source) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_downward_api_volume_source->items) {
		v1_downward_api_volume_file_free(listEntry->data);
	}
	list_free(v1_downward_api_volume_source->items);
	free(v1_downward_api_volume_source);
}

cJSON *v1_downward_api_volume_source_convertToJSON(v1_downward_api_volume_source_t *v1_downward_api_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_downward_api_volume_source->defaultMode
    if(v1_downward_api_volume_source->defaultMode) { 
    if(cJSON_AddNumberToObject(item, "defaultMode", v1_downward_api_volume_source->defaultMode) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_downward_api_volume_source->items
    if(v1_downward_api_volume_source->items) { 
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_downward_api_volume_source->items) {
    list_ForEach(itemsListEntry, v1_downward_api_volume_source->items) {
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

v1_downward_api_volume_source_t *v1_downward_api_volume_source_parseFromJSON(cJSON *v1_downward_api_volume_sourceJSON){

    v1_downward_api_volume_source_t *v1_downward_api_volume_source_local_var = NULL;

    // v1_downward_api_volume_source->defaultMode
    cJSON *defaultMode = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_sourceJSON, "defaultMode");
    if (defaultMode) { 
    if(!cJSON_IsNumber(defaultMode))
    {
    goto end; //Numeric
    }
    }

    // v1_downward_api_volume_source->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_sourceJSON, "items");
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


    v1_downward_api_volume_source_local_var = v1_downward_api_volume_source_create (
        defaultMode ? defaultMode->valuedouble : 0,
        items ? itemsList : NULL
        );

    return v1_downward_api_volume_source_local_var;
end:
    return NULL;

}

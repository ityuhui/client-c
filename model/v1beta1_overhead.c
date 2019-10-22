#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_overhead.h"



v1beta1_overhead_t *v1beta1_overhead_create(
    list_t* podFixed
    ) {
	v1beta1_overhead_t *v1beta1_overhead_local_var = malloc(sizeof(v1beta1_overhead_t));
    if (!v1beta1_overhead_local_var) {
        return NULL;
    }
	v1beta1_overhead_local_var->podFixed = podFixed;

	return v1beta1_overhead_local_var;
}


void v1beta1_overhead_free(v1beta1_overhead_t *v1beta1_overhead) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_overhead->podFixed) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1beta1_overhead->podFixed);
	free(v1beta1_overhead);
}

cJSON *v1beta1_overhead_convertToJSON(v1beta1_overhead_t *v1beta1_overhead) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_overhead->podFixed
    if(v1beta1_overhead->podFixed) { 
	cJSON *podFixed = cJSON_AddObjectToObject(item, "podFixed");
	if(podFixed == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *podFixedListEntry;
    if (v1beta1_overhead->podFixed) {
    list_ForEach(podFixedListEntry, v1beta1_overhead->podFixed) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)podFixedListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(podFixed,"", localMapObject);
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

v1beta1_overhead_t *v1beta1_overhead_parseFromJSON(cJSON *v1beta1_overheadJSON){

    v1beta1_overhead_t *v1beta1_overhead_local_var = NULL;

    // v1beta1_overhead->podFixed
    cJSON *podFixed = cJSON_GetObjectItemCaseSensitive(v1beta1_overheadJSON, "podFixed");
    list_t *List;
    if (podFixed) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(podFixed)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, podFixed)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }


    v1beta1_overhead_local_var = v1beta1_overhead_create (
        podFixed ? List : NULL
        );

    return v1beta1_overhead_local_var;
end:
    return NULL;

}

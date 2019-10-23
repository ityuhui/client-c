#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_scheduling.h"



v1beta1_scheduling_t *v1beta1_scheduling_create(
    list_t* nodeSelector,
    list_t *tolerations
    ) {
	v1beta1_scheduling_t *v1beta1_scheduling_local_var = malloc(sizeof(v1beta1_scheduling_t));
    if (!v1beta1_scheduling_local_var) {
        return NULL;
    }
	v1beta1_scheduling_local_var->nodeSelector = nodeSelector;
	v1beta1_scheduling_local_var->tolerations = tolerations;

	return v1beta1_scheduling_local_var;
}


void v1beta1_scheduling_free(v1beta1_scheduling_t *v1beta1_scheduling) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_scheduling->nodeSelector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1beta1_scheduling->nodeSelector);
	list_ForEach(listEntry, v1beta1_scheduling->tolerations) {
		v1_toleration_free(listEntry->data);
	}
	list_free(v1beta1_scheduling->tolerations);
	free(v1beta1_scheduling);
}

cJSON *v1beta1_scheduling_convertToJSON(v1beta1_scheduling_t *v1beta1_scheduling) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_scheduling->nodeSelector
    if(v1beta1_scheduling->nodeSelector) { 
	cJSON *nodeSelector = cJSON_AddObjectToObject(item, "nodeSelector");
	if(nodeSelector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *nodeSelectorListEntry;
    if (v1beta1_scheduling->nodeSelector) {
    list_ForEach(nodeSelectorListEntry, v1beta1_scheduling->nodeSelector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)nodeSelectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(nodeSelector,"", localMapObject);
    }
    }
     } 


	// v1beta1_scheduling->tolerations
    if(v1beta1_scheduling->tolerations) { 
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1beta1_scheduling->tolerations) {
    list_ForEach(tolerationsListEntry, v1beta1_scheduling->tolerations) {
    cJSON *itemLocal = v1_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
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

v1beta1_scheduling_t *v1beta1_scheduling_parseFromJSON(cJSON *v1beta1_schedulingJSON){

    v1beta1_scheduling_t *v1beta1_scheduling_local_var = NULL;

    // v1beta1_scheduling->nodeSelector
    cJSON *nodeSelector = cJSON_GetObjectItemCaseSensitive(v1beta1_schedulingJSON, "nodeSelector");
    list_t *List;
    if (nodeSelector) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(nodeSelector)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, nodeSelector)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1beta1_scheduling->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1beta1_schedulingJSON, "tolerations");
    list_t *tolerationsList;
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_create();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1_toleration_t *tolerationsItem = v1_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    v1beta1_scheduling_local_var = v1beta1_scheduling_create (
        nodeSelector ? List : NULL,
        tolerations ? tolerationsList : NULL
        );

    return v1beta1_scheduling_local_var;
end:
    return NULL;

}

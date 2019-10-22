#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_label_selector.h"



v1_label_selector_t *v1_label_selector_create(
    list_t *matchExpressions,
    list_t* matchLabels
    ) {
	v1_label_selector_t *v1_label_selector_local_var = malloc(sizeof(v1_label_selector_t));
    if (!v1_label_selector_local_var) {
        return NULL;
    }
	v1_label_selector_local_var->matchExpressions = matchExpressions;
	v1_label_selector_local_var->matchLabels = matchLabels;

	return v1_label_selector_local_var;
}


void v1_label_selector_free(v1_label_selector_t *v1_label_selector) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_label_selector->matchExpressions) {
		v1_label_selector_requirement_free(listEntry->data);
	}
	list_free(v1_label_selector->matchExpressions);
	list_ForEach(listEntry, v1_label_selector->matchLabels) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_label_selector->matchLabels);
	free(v1_label_selector);
}

cJSON *v1_label_selector_convertToJSON(v1_label_selector_t *v1_label_selector) {
	cJSON *item = cJSON_CreateObject();

	// v1_label_selector->matchExpressions
    if(v1_label_selector->matchExpressions) { 
    cJSON *matchExpressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(matchExpressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *matchExpressionsListEntry;
    if (v1_label_selector->matchExpressions) {
    list_ForEach(matchExpressionsListEntry, v1_label_selector->matchExpressions) {
    cJSON *itemLocal = v1_label_selector_requirement_convertToJSON(matchExpressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(matchExpressions, itemLocal);
    }
    }
     } 


	// v1_label_selector->matchLabels
    if(v1_label_selector->matchLabels) { 
	cJSON *matchLabels = cJSON_AddObjectToObject(item, "matchLabels");
	if(matchLabels == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *matchLabelsListEntry;
    if (v1_label_selector->matchLabels) {
    list_ForEach(matchLabelsListEntry, v1_label_selector->matchLabels) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)matchLabelsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(matchLabels,"", localMapObject);
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

v1_label_selector_t *v1_label_selector_parseFromJSON(cJSON *v1_label_selectorJSON){

    v1_label_selector_t *v1_label_selector_local_var = NULL;

    // v1_label_selector->matchExpressions
    cJSON *matchExpressions = cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchExpressions");
    list_t *matchExpressionsList;
    if (matchExpressions) { 
    cJSON *matchExpressions_local_nonprimitive;
    if(!cJSON_IsArray(matchExpressions)){
        goto end; //nonprimitive container
    }

    matchExpressionsList = list_create();

    cJSON_ArrayForEach(matchExpressions_local_nonprimitive,matchExpressions )
    {
        if(!cJSON_IsObject(matchExpressions_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_requirement_t *matchExpressionsItem = v1_label_selector_requirement_parseFromJSON(matchExpressions_local_nonprimitive);

        list_addElement(matchExpressionsList, matchExpressionsItem);
    }
    }

    // v1_label_selector->matchLabels
    cJSON *matchLabels = cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchLabels");
    list_t *List;
    if (matchLabels) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(matchLabels)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, matchLabels)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }


    v1_label_selector_local_var = v1_label_selector_create (
        matchExpressions ? matchExpressionsList : NULL,
        matchLabels ? List : NULL
        );

    return v1_label_selector_local_var;
end:
    return NULL;

}

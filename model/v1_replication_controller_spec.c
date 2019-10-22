#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replication_controller_spec.h"



v1_replication_controller_spec_t *v1_replication_controller_spec_create(
    int minReadySeconds,
    int replicas,
    list_t* selector,
    v1_pod_template_spec_t *template
    ) {
	v1_replication_controller_spec_t *v1_replication_controller_spec_local_var = malloc(sizeof(v1_replication_controller_spec_t));
    if (!v1_replication_controller_spec_local_var) {
        return NULL;
    }
	v1_replication_controller_spec_local_var->minReadySeconds = minReadySeconds;
	v1_replication_controller_spec_local_var->replicas = replicas;
	v1_replication_controller_spec_local_var->selector = selector;
	v1_replication_controller_spec_local_var->template = template;

	return v1_replication_controller_spec_local_var;
}


void v1_replication_controller_spec_free(v1_replication_controller_spec_t *v1_replication_controller_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_replication_controller_spec->selector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_replication_controller_spec->selector);
    v1_pod_template_spec_free(v1_replication_controller_spec->template);
	free(v1_replication_controller_spec);
}

cJSON *v1_replication_controller_spec_convertToJSON(v1_replication_controller_spec_t *v1_replication_controller_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_replication_controller_spec->minReadySeconds
    if(v1_replication_controller_spec->minReadySeconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_replication_controller_spec->minReadySeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replication_controller_spec->replicas
    if(v1_replication_controller_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1_replication_controller_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replication_controller_spec->selector
    if(v1_replication_controller_spec->selector) { 
	cJSON *selector = cJSON_AddObjectToObject(item, "selector");
	if(selector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *selectorListEntry;
    if (v1_replication_controller_spec->selector) {
    list_ForEach(selectorListEntry, v1_replication_controller_spec->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(selector,"", localMapObject);
    }
    }
     } 


	// v1_replication_controller_spec->template
    if(v1_replication_controller_spec->template) { 
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1_replication_controller_spec->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_replication_controller_spec_t *v1_replication_controller_spec_parseFromJSON(cJSON *v1_replication_controller_specJSON){

    v1_replication_controller_spec_t *v1_replication_controller_spec_local_var = NULL;

    // v1_replication_controller_spec->minReadySeconds
    cJSON *minReadySeconds = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "minReadySeconds");
    if (minReadySeconds) { 
    if(!cJSON_IsNumber(minReadySeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replication_controller_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "selector");
    list_t *List;
    if (selector) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, selector)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_replication_controller_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1_replication_controller_specJSON, "template");
    v1_pod_template_spec_t *template_local_nonprim = NULL;
    if (template) { 
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive
    }


    v1_replication_controller_spec_local_var = v1_replication_controller_spec_create (
        minReadySeconds ? minReadySeconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        selector ? List : NULL,
        template ? template_local_nonprim : NULL
        );

    return v1_replication_controller_spec_local_var;
end:
    return NULL;

}

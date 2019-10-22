#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_affinity_term.h"



v1_pod_affinity_term_t *v1_pod_affinity_term_create(
    v1_label_selector_t *labelSelector,
    list_t *namespaces,
    char *topologyKey
    ) {
	v1_pod_affinity_term_t *v1_pod_affinity_term_local_var = malloc(sizeof(v1_pod_affinity_term_t));
    if (!v1_pod_affinity_term_local_var) {
        return NULL;
    }
	v1_pod_affinity_term_local_var->labelSelector = labelSelector;
	v1_pod_affinity_term_local_var->namespaces = namespaces;
	v1_pod_affinity_term_local_var->topologyKey = topologyKey;

	return v1_pod_affinity_term_local_var;
}


void v1_pod_affinity_term_free(v1_pod_affinity_term_t *v1_pod_affinity_term) {
    listEntry_t *listEntry;
    v1_label_selector_free(v1_pod_affinity_term->labelSelector);
	list_ForEach(listEntry, v1_pod_affinity_term->namespaces) {
		free(listEntry->data);
	}
	list_free(v1_pod_affinity_term->namespaces);
    free(v1_pod_affinity_term->topologyKey);
	free(v1_pod_affinity_term);
}

cJSON *v1_pod_affinity_term_convertToJSON(v1_pod_affinity_term_t *v1_pod_affinity_term) {
	cJSON *item = cJSON_CreateObject();

	// v1_pod_affinity_term->labelSelector
    if(v1_pod_affinity_term->labelSelector) { 
    cJSON *labelSelector_local_JSON = v1_label_selector_convertToJSON(v1_pod_affinity_term->labelSelector);
    if(labelSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", labelSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_pod_affinity_term->namespaces
    if(v1_pod_affinity_term->namespaces) { 
	cJSON *namespaces = cJSON_AddArrayToObject(item, "namespaces");
	if(namespaces == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *namespacesListEntry;
    list_ForEach(namespacesListEntry, v1_pod_affinity_term->namespaces) {
    if(cJSON_AddStringToObject(namespaces, "", (char*)namespacesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_pod_affinity_term->topologyKey
    if (!v1_pod_affinity_term->topologyKey) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "topologyKey", v1_pod_affinity_term->topologyKey) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_pod_affinity_term_t *v1_pod_affinity_term_parseFromJSON(cJSON *v1_pod_affinity_termJSON){

    v1_pod_affinity_term_t *v1_pod_affinity_term_local_var = NULL;

    // v1_pod_affinity_term->labelSelector
    cJSON *labelSelector = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "labelSelector");
    v1_label_selector_t *labelSelector_local_nonprim = NULL;
    if (labelSelector) { 
    labelSelector_local_nonprim = v1_label_selector_parseFromJSON(labelSelector); //nonprimitive
    }

    // v1_pod_affinity_term->namespaces
    cJSON *namespaces = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "namespaces");
    list_t *namespacesList;
    if (namespaces) { 
    cJSON *namespaces_local;
    if(!cJSON_IsArray(namespaces)) {
        goto end;//primitive container
    }
    namespacesList = list_create();

    cJSON_ArrayForEach(namespaces_local, namespaces)
    {
        if(!cJSON_IsString(namespaces_local))
        {
            goto end;
        }
        list_addElement(namespacesList , strdup(namespaces_local->valuestring));
    }
    }

    // v1_pod_affinity_term->topologyKey
    cJSON *topologyKey = cJSON_GetObjectItemCaseSensitive(v1_pod_affinity_termJSON, "topologyKey");
    if (!topologyKey) {
        goto end;
    }

    
    if(!cJSON_IsString(topologyKey))
    {
    goto end; //String
    }


    v1_pod_affinity_term_local_var = v1_pod_affinity_term_create (
        labelSelector ? labelSelector_local_nonprim : NULL,
        namespaces ? namespacesList : NULL,
        strdup(topologyKey->valuestring)
        );

    return v1_pod_affinity_term_local_var;
end:
    return NULL;

}

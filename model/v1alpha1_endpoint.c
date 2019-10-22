#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_endpoint.h"



v1alpha1_endpoint_t *v1alpha1_endpoint_create(
    list_t *addresses,
    v1alpha1_endpoint_conditions_t *conditions,
    char *hostname,
    v1_object_reference_t *targetRef,
    list_t* topology
    ) {
	v1alpha1_endpoint_t *v1alpha1_endpoint_local_var = malloc(sizeof(v1alpha1_endpoint_t));
    if (!v1alpha1_endpoint_local_var) {
        return NULL;
    }
	v1alpha1_endpoint_local_var->addresses = addresses;
	v1alpha1_endpoint_local_var->conditions = conditions;
	v1alpha1_endpoint_local_var->hostname = hostname;
	v1alpha1_endpoint_local_var->targetRef = targetRef;
	v1alpha1_endpoint_local_var->topology = topology;

	return v1alpha1_endpoint_local_var;
}


void v1alpha1_endpoint_free(v1alpha1_endpoint_t *v1alpha1_endpoint) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1alpha1_endpoint->addresses) {
		free(listEntry->data);
	}
	list_free(v1alpha1_endpoint->addresses);
    v1alpha1_endpoint_conditions_free(v1alpha1_endpoint->conditions);
    free(v1alpha1_endpoint->hostname);
    v1_object_reference_free(v1alpha1_endpoint->targetRef);
	list_ForEach(listEntry, v1alpha1_endpoint->topology) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1alpha1_endpoint->topology);
	free(v1alpha1_endpoint);
}

cJSON *v1alpha1_endpoint_convertToJSON(v1alpha1_endpoint_t *v1alpha1_endpoint) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_endpoint->addresses
    if (!v1alpha1_endpoint->addresses) {
        goto fail;
    }
    
	cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
	if(addresses == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, v1alpha1_endpoint->addresses) {
    if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// v1alpha1_endpoint->conditions
    if(v1alpha1_endpoint->conditions) { 
    cJSON *conditions_local_JSON = v1alpha1_endpoint_conditions_convertToJSON(v1alpha1_endpoint->conditions);
    if(conditions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conditions", conditions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_endpoint->hostname
    if(v1alpha1_endpoint->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1alpha1_endpoint->hostname) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_endpoint->targetRef
    if(v1alpha1_endpoint->targetRef) { 
    cJSON *targetRef_local_JSON = v1_object_reference_convertToJSON(v1alpha1_endpoint->targetRef);
    if(targetRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetRef", targetRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_endpoint->topology
    if(v1alpha1_endpoint->topology) { 
	cJSON *topology = cJSON_AddObjectToObject(item, "topology");
	if(topology == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *topologyListEntry;
    if (v1alpha1_endpoint->topology) {
    list_ForEach(topologyListEntry, v1alpha1_endpoint->topology) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)topologyListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(topology,"", localMapObject);
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

v1alpha1_endpoint_t *v1alpha1_endpoint_parseFromJSON(cJSON *v1alpha1_endpointJSON){

    v1alpha1_endpoint_t *v1alpha1_endpoint_local_var = NULL;

    // v1alpha1_endpoint->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpointJSON, "addresses");
    if (!addresses) {
        goto end;
    }

    list_t *addressesList;
    
    cJSON *addresses_local;
    if(!cJSON_IsArray(addresses)) {
        goto end;//primitive container
    }
    addressesList = list_create();

    cJSON_ArrayForEach(addresses_local, addresses)
    {
        if(!cJSON_IsString(addresses_local))
        {
            goto end;
        }
        list_addElement(addressesList , strdup(addresses_local->valuestring));
    }

    // v1alpha1_endpoint->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpointJSON, "conditions");
    v1alpha1_endpoint_conditions_t *conditions_local_nonprim = NULL;
    if (conditions) { 
    conditions_local_nonprim = v1alpha1_endpoint_conditions_parseFromJSON(conditions); //nonprimitive
    }

    // v1alpha1_endpoint->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpointJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1alpha1_endpoint->targetRef
    cJSON *targetRef = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpointJSON, "targetRef");
    v1_object_reference_t *targetRef_local_nonprim = NULL;
    if (targetRef) { 
    targetRef_local_nonprim = v1_object_reference_parseFromJSON(targetRef); //nonprimitive
    }

    // v1alpha1_endpoint->topology
    cJSON *topology = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpointJSON, "topology");
    list_t *List;
    if (topology) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(topology)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, topology)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }


    v1alpha1_endpoint_local_var = v1alpha1_endpoint_create (
        addressesList,
        conditions ? conditions_local_nonprim : NULL,
        hostname ? strdup(hostname->valuestring) : NULL,
        targetRef ? targetRef_local_nonprim : NULL,
        topology ? List : NULL
        );

    return v1alpha1_endpoint_local_var;
end:
    return NULL;

}

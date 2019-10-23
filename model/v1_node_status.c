#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_status.h"



v1_node_status_t *v1_node_status_create(
    list_t *addresses,
    list_t* allocatable,
    list_t* capacity,
    list_t *conditions,
    v1_node_config_status_t *config,
    v1_node_daemon_endpoints_t *daemonEndpoints,
    list_t *images,
    v1_node_system_info_t *nodeInfo,
    char *phase,
    list_t *volumesAttached,
    list_t *volumesInUse
    ) {
	v1_node_status_t *v1_node_status_local_var = malloc(sizeof(v1_node_status_t));
    if (!v1_node_status_local_var) {
        return NULL;
    }
	v1_node_status_local_var->addresses = addresses;
	v1_node_status_local_var->allocatable = allocatable;
	v1_node_status_local_var->capacity = capacity;
	v1_node_status_local_var->conditions = conditions;
	v1_node_status_local_var->config = config;
	v1_node_status_local_var->daemonEndpoints = daemonEndpoints;
	v1_node_status_local_var->images = images;
	v1_node_status_local_var->nodeInfo = nodeInfo;
	v1_node_status_local_var->phase = phase;
	v1_node_status_local_var->volumesAttached = volumesAttached;
	v1_node_status_local_var->volumesInUse = volumesInUse;

	return v1_node_status_local_var;
}


void v1_node_status_free(v1_node_status_t *v1_node_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_node_status->addresses) {
		v1_node_address_free(listEntry->data);
	}
	list_free(v1_node_status->addresses);
	list_ForEach(listEntry, v1_node_status->allocatable) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_node_status->allocatable);
	list_ForEach(listEntry, v1_node_status->capacity) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_node_status->capacity);
	list_ForEach(listEntry, v1_node_status->conditions) {
		v1_node_condition_free(listEntry->data);
	}
	list_free(v1_node_status->conditions);
    v1_node_config_status_free(v1_node_status->config);
    v1_node_daemon_endpoints_free(v1_node_status->daemonEndpoints);
	list_ForEach(listEntry, v1_node_status->images) {
		v1_container_image_free(listEntry->data);
	}
	list_free(v1_node_status->images);
    v1_node_system_info_free(v1_node_status->nodeInfo);
    free(v1_node_status->phase);
	list_ForEach(listEntry, v1_node_status->volumesAttached) {
		v1_attached_volume_free(listEntry->data);
	}
	list_free(v1_node_status->volumesAttached);
	list_ForEach(listEntry, v1_node_status->volumesInUse) {
		free(listEntry->data);
	}
	list_free(v1_node_status->volumesInUse);
	free(v1_node_status);
}

cJSON *v1_node_status_convertToJSON(v1_node_status_t *v1_node_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_status->addresses
    if(v1_node_status->addresses) { 
    cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
    if(addresses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *addressesListEntry;
    if (v1_node_status->addresses) {
    list_ForEach(addressesListEntry, v1_node_status->addresses) {
    cJSON *itemLocal = v1_node_address_convertToJSON(addressesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(addresses, itemLocal);
    }
    }
     } 


	// v1_node_status->allocatable
    if(v1_node_status->allocatable) { 
	cJSON *allocatable = cJSON_AddObjectToObject(item, "allocatable");
	if(allocatable == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *allocatableListEntry;
    if (v1_node_status->allocatable) {
    list_ForEach(allocatableListEntry, v1_node_status->allocatable) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)allocatableListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(allocatable,"", localMapObject);
    }
    }
     } 


	// v1_node_status->capacity
    if(v1_node_status->capacity) { 
	cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
	if(capacity == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *capacityListEntry;
    if (v1_node_status->capacity) {
    list_ForEach(capacityListEntry, v1_node_status->capacity) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(capacity,"", localMapObject);
    }
    }
     } 


	// v1_node_status->conditions
    if(v1_node_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_node_status->conditions) {
    list_ForEach(conditionsListEntry, v1_node_status->conditions) {
    cJSON *itemLocal = v1_node_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1_node_status->config
    if(v1_node_status->config) { 
    cJSON *config_local_JSON = v1_node_config_status_convertToJSON(v1_node_status->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_node_status->daemonEndpoints
    if(v1_node_status->daemonEndpoints) { 
    cJSON *daemonEndpoints_local_JSON = v1_node_daemon_endpoints_convertToJSON(v1_node_status->daemonEndpoints);
    if(daemonEndpoints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "daemonEndpoints", daemonEndpoints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_node_status->images
    if(v1_node_status->images) { 
    cJSON *images = cJSON_AddArrayToObject(item, "images");
    if(images == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *imagesListEntry;
    if (v1_node_status->images) {
    list_ForEach(imagesListEntry, v1_node_status->images) {
    cJSON *itemLocal = v1_container_image_convertToJSON(imagesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(images, itemLocal);
    }
    }
     } 


	// v1_node_status->nodeInfo
    if(v1_node_status->nodeInfo) { 
    cJSON *nodeInfo_local_JSON = v1_node_system_info_convertToJSON(v1_node_status->nodeInfo);
    if(nodeInfo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeInfo", nodeInfo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_node_status->phase
    if(v1_node_status->phase) { 
    if(cJSON_AddStringToObject(item, "phase", v1_node_status->phase) == NULL) {
    goto fail; //String
    }
     } 


	// v1_node_status->volumesAttached
    if(v1_node_status->volumesAttached) { 
    cJSON *volumesAttached = cJSON_AddArrayToObject(item, "volumesAttached");
    if(volumesAttached == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumesAttachedListEntry;
    if (v1_node_status->volumesAttached) {
    list_ForEach(volumesAttachedListEntry, v1_node_status->volumesAttached) {
    cJSON *itemLocal = v1_attached_volume_convertToJSON(volumesAttachedListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumesAttached, itemLocal);
    }
    }
     } 


	// v1_node_status->volumesInUse
    if(v1_node_status->volumesInUse) { 
	cJSON *volumes_in_use = cJSON_AddArrayToObject(item, "volumesInUse");
	if(volumes_in_use == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *volumes_in_useListEntry;
    list_ForEach(volumes_in_useListEntry, v1_node_status->volumesInUse) {
    if(cJSON_AddStringToObject(volumes_in_use, "", (char*)volumes_in_useListEntry->data) == NULL)
    {
        goto fail;
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

v1_node_status_t *v1_node_status_parseFromJSON(cJSON *v1_node_statusJSON){

    v1_node_status_t *v1_node_status_local_var = NULL;

    // v1_node_status->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "addresses");
    list_t *addressesList;
    if (addresses) { 
    cJSON *addresses_local_nonprimitive;
    if(!cJSON_IsArray(addresses)){
        goto end; //nonprimitive container
    }

    addressesList = list_create();

    cJSON_ArrayForEach(addresses_local_nonprimitive,addresses )
    {
        if(!cJSON_IsObject(addresses_local_nonprimitive)){
            goto end;
        }
        v1_node_address_t *addressesItem = v1_node_address_parseFromJSON(addresses_local_nonprimitive);

        list_addElement(addressesList, addressesItem);
    }
    }

    // v1_node_status->allocatable
    cJSON *allocatable = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "allocatable");
    list_t *List;
    if (allocatable) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(allocatable)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, allocatable)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_node_status->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "capacity");
    list_t *Listcapacity;
    if (capacity) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(capacity)) {
        goto end;//primitive map container
    }
    Listcapacity = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, capacity)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(Listcapacity, localMapKeyPair);
    }
    }

    // v1_node_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_node_condition_t *conditionsItem = v1_node_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_node_status->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "config");
    v1_node_config_status_t *config_local_nonprim = NULL;
    if (config) { 
    config_local_nonprim = v1_node_config_status_parseFromJSON(config); //nonprimitive
    }

    // v1_node_status->daemonEndpoints
    cJSON *daemonEndpoints = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "daemonEndpoints");
    v1_node_daemon_endpoints_t *daemonEndpoints_local_nonprim = NULL;
    if (daemonEndpoints) { 
    daemonEndpoints_local_nonprim = v1_node_daemon_endpoints_parseFromJSON(daemonEndpoints); //nonprimitive
    }

    // v1_node_status->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "images");
    list_t *imagesList;
    if (images) { 
    cJSON *images_local_nonprimitive;
    if(!cJSON_IsArray(images)){
        goto end; //nonprimitive container
    }

    imagesList = list_create();

    cJSON_ArrayForEach(images_local_nonprimitive,images )
    {
        if(!cJSON_IsObject(images_local_nonprimitive)){
            goto end;
        }
        v1_container_image_t *imagesItem = v1_container_image_parseFromJSON(images_local_nonprimitive);

        list_addElement(imagesList, imagesItem);
    }
    }

    // v1_node_status->nodeInfo
    cJSON *nodeInfo = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "nodeInfo");
    v1_node_system_info_t *nodeInfo_local_nonprim = NULL;
    if (nodeInfo) { 
    nodeInfo_local_nonprim = v1_node_system_info_parseFromJSON(nodeInfo); //nonprimitive
    }

    // v1_node_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "phase");
    if (phase) { 
    if(!cJSON_IsString(phase))
    {
    goto end; //String
    }
    }

    // v1_node_status->volumesAttached
    cJSON *volumesAttached = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "volumesAttached");
    list_t *volumesAttachedList;
    if (volumesAttached) { 
    cJSON *volumesAttached_local_nonprimitive;
    if(!cJSON_IsArray(volumesAttached)){
        goto end; //nonprimitive container
    }

    volumesAttachedList = list_create();

    cJSON_ArrayForEach(volumesAttached_local_nonprimitive,volumesAttached )
    {
        if(!cJSON_IsObject(volumesAttached_local_nonprimitive)){
            goto end;
        }
        v1_attached_volume_t *volumesAttachedItem = v1_attached_volume_parseFromJSON(volumesAttached_local_nonprimitive);

        list_addElement(volumesAttachedList, volumesAttachedItem);
    }
    }

    // v1_node_status->volumesInUse
    cJSON *volumesInUse = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "volumesInUse");
    list_t *volumes_in_useList;
    if (volumesInUse) { 
    cJSON *volumes_in_use_local;
    if(!cJSON_IsArray(volumesInUse)) {
        goto end;//primitive container
    }
    volumes_in_useList = list_create();

    cJSON_ArrayForEach(volumes_in_use_local, volumesInUse)
    {
        if(!cJSON_IsString(volumes_in_use_local))
        {
            goto end;
        }
        list_addElement(volumes_in_useList , strdup(volumes_in_use_local->valuestring));
    }
    }


    v1_node_status_local_var = v1_node_status_create (
        addresses ? addressesList : NULL,
        allocatable ? List : NULL,
        capacity ? Listcapacity : NULL,
        conditions ? conditionsList : NULL,
        config ? config_local_nonprim : NULL,
        daemonEndpoints ? daemonEndpoints_local_nonprim : NULL,
        images ? imagesList : NULL,
        nodeInfo ? nodeInfo_local_nonprim : NULL,
        phase ? strdup(phase->valuestring) : NULL,
        volumesAttached ? volumesAttachedList : NULL,
        volumesInUse ? volumes_in_useList : NULL
        );

    return v1_node_status_local_var;
end:
    return NULL;

}

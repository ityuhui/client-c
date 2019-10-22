#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_csi_node_driver.h"



v1beta1_csi_node_driver_t *v1beta1_csi_node_driver_create(
    v1beta1_volume_node_resources_t *allocatable,
    char *name,
    char *nodeID,
    list_t *topologyKeys
    ) {
	v1beta1_csi_node_driver_t *v1beta1_csi_node_driver_local_var = malloc(sizeof(v1beta1_csi_node_driver_t));
    if (!v1beta1_csi_node_driver_local_var) {
        return NULL;
    }
	v1beta1_csi_node_driver_local_var->allocatable = allocatable;
	v1beta1_csi_node_driver_local_var->name = name;
	v1beta1_csi_node_driver_local_var->nodeID = nodeID;
	v1beta1_csi_node_driver_local_var->topologyKeys = topologyKeys;

	return v1beta1_csi_node_driver_local_var;
}


void v1beta1_csi_node_driver_free(v1beta1_csi_node_driver_t *v1beta1_csi_node_driver) {
    listEntry_t *listEntry;
    v1beta1_volume_node_resources_free(v1beta1_csi_node_driver->allocatable);
    free(v1beta1_csi_node_driver->name);
    free(v1beta1_csi_node_driver->nodeID);
	list_ForEach(listEntry, v1beta1_csi_node_driver->topologyKeys) {
		free(listEntry->data);
	}
	list_free(v1beta1_csi_node_driver->topologyKeys);
	free(v1beta1_csi_node_driver);
}

cJSON *v1beta1_csi_node_driver_convertToJSON(v1beta1_csi_node_driver_t *v1beta1_csi_node_driver) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_csi_node_driver->allocatable
    if(v1beta1_csi_node_driver->allocatable) { 
    cJSON *allocatable_local_JSON = v1beta1_volume_node_resources_convertToJSON(v1beta1_csi_node_driver->allocatable);
    if(allocatable_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "allocatable", allocatable_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_csi_node_driver->name
    if (!v1beta1_csi_node_driver->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1beta1_csi_node_driver->name) == NULL) {
    goto fail; //String
    }


	// v1beta1_csi_node_driver->nodeID
    if (!v1beta1_csi_node_driver->nodeID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "nodeID", v1beta1_csi_node_driver->nodeID) == NULL) {
    goto fail; //String
    }


	// v1beta1_csi_node_driver->topologyKeys
    if(v1beta1_csi_node_driver->topologyKeys) { 
	cJSON *topology_keys = cJSON_AddArrayToObject(item, "topologyKeys");
	if(topology_keys == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *topology_keysListEntry;
    list_ForEach(topology_keysListEntry, v1beta1_csi_node_driver->topologyKeys) {
    if(cJSON_AddStringToObject(topology_keys, "", (char*)topology_keysListEntry->data) == NULL)
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

v1beta1_csi_node_driver_t *v1beta1_csi_node_driver_parseFromJSON(cJSON *v1beta1_csi_node_driverJSON){

    v1beta1_csi_node_driver_t *v1beta1_csi_node_driver_local_var = NULL;

    // v1beta1_csi_node_driver->allocatable
    cJSON *allocatable = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_node_driverJSON, "allocatable");
    v1beta1_volume_node_resources_t *allocatable_local_nonprim = NULL;
    if (allocatable) { 
    allocatable_local_nonprim = v1beta1_volume_node_resources_parseFromJSON(allocatable); //nonprimitive
    }

    // v1beta1_csi_node_driver->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_node_driverJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1beta1_csi_node_driver->nodeID
    cJSON *nodeID = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_node_driverJSON, "nodeID");
    if (!nodeID) {
        goto end;
    }

    
    if(!cJSON_IsString(nodeID))
    {
    goto end; //String
    }

    // v1beta1_csi_node_driver->topologyKeys
    cJSON *topologyKeys = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_node_driverJSON, "topologyKeys");
    list_t *topology_keysList;
    if (topologyKeys) { 
    cJSON *topology_keys_local;
    if(!cJSON_IsArray(topologyKeys)) {
        goto end;//primitive container
    }
    topology_keysList = list_create();

    cJSON_ArrayForEach(topology_keys_local, topologyKeys)
    {
        if(!cJSON_IsString(topology_keys_local))
        {
            goto end;
        }
        list_addElement(topology_keysList , strdup(topology_keys_local->valuestring));
    }
    }


    v1beta1_csi_node_driver_local_var = v1beta1_csi_node_driver_create (
        allocatable ? allocatable_local_nonprim : NULL,
        strdup(name->valuestring),
        strdup(nodeID->valuestring),
        topologyKeys ? topology_keysList : NULL
        );

    return v1beta1_csi_node_driver_local_var;
end:
    return NULL;

}

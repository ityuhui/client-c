#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_endpoint_slice.h"



v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice_create(
    char *addressType,
    char *apiVersion,
    list_t *endpoints,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *ports
    ) {
	v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice_local_var = malloc(sizeof(v1alpha1_endpoint_slice_t));
    if (!v1alpha1_endpoint_slice_local_var) {
        return NULL;
    }
	v1alpha1_endpoint_slice_local_var->addressType = addressType;
	v1alpha1_endpoint_slice_local_var->apiVersion = apiVersion;
	v1alpha1_endpoint_slice_local_var->endpoints = endpoints;
	v1alpha1_endpoint_slice_local_var->kind = kind;
	v1alpha1_endpoint_slice_local_var->metadata = metadata;
	v1alpha1_endpoint_slice_local_var->ports = ports;

	return v1alpha1_endpoint_slice_local_var;
}


void v1alpha1_endpoint_slice_free(v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice) {
    listEntry_t *listEntry;
    free(v1alpha1_endpoint_slice->addressType);
    free(v1alpha1_endpoint_slice->apiVersion);
	list_ForEach(listEntry, v1alpha1_endpoint_slice->endpoints) {
		v1alpha1_endpoint_free(listEntry->data);
	}
	list_free(v1alpha1_endpoint_slice->endpoints);
    free(v1alpha1_endpoint_slice->kind);
    v1_object_meta_free(v1alpha1_endpoint_slice->metadata);
	list_ForEach(listEntry, v1alpha1_endpoint_slice->ports) {
		v1alpha1_endpoint_port_free(listEntry->data);
	}
	list_free(v1alpha1_endpoint_slice->ports);
	free(v1alpha1_endpoint_slice);
}

cJSON *v1alpha1_endpoint_slice_convertToJSON(v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_endpoint_slice->addressType
    if(v1alpha1_endpoint_slice->addressType) { 
    if(cJSON_AddStringToObject(item, "addressType", v1alpha1_endpoint_slice->addressType) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_endpoint_slice->apiVersion
    if(v1alpha1_endpoint_slice->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_endpoint_slice->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_endpoint_slice->endpoints
    if (!v1alpha1_endpoint_slice->endpoints) {
        goto fail;
    }
    
    cJSON *endpoints = cJSON_AddArrayToObject(item, "endpoints");
    if(endpoints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *endpointsListEntry;
    if (v1alpha1_endpoint_slice->endpoints) {
    list_ForEach(endpointsListEntry, v1alpha1_endpoint_slice->endpoints) {
    cJSON *itemLocal = v1alpha1_endpoint_convertToJSON(endpointsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(endpoints, itemLocal);
    }
    }


	// v1alpha1_endpoint_slice->kind
    if(v1alpha1_endpoint_slice->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_endpoint_slice->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_endpoint_slice->metadata
    if(v1alpha1_endpoint_slice->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_endpoint_slice->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_endpoint_slice->ports
    if(v1alpha1_endpoint_slice->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1alpha1_endpoint_slice->ports) {
    list_ForEach(portsListEntry, v1alpha1_endpoint_slice->ports) {
    cJSON *itemLocal = v1alpha1_endpoint_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
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

v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice_parseFromJSON(cJSON *v1alpha1_endpoint_sliceJSON){

    v1alpha1_endpoint_slice_t *v1alpha1_endpoint_slice_local_var = NULL;

    // v1alpha1_endpoint_slice->addressType
    cJSON *addressType = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_sliceJSON, "addressType");
    if (addressType) { 
    if(!cJSON_IsString(addressType))
    {
    goto end; //String
    }
    }

    // v1alpha1_endpoint_slice->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_sliceJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_endpoint_slice->endpoints
    cJSON *endpoints = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_sliceJSON, "endpoints");
    if (!endpoints) {
        goto end;
    }

    list_t *endpointsList;
    
    cJSON *endpoints_local_nonprimitive;
    if(!cJSON_IsArray(endpoints)){
        goto end; //nonprimitive container
    }

    endpointsList = list_create();

    cJSON_ArrayForEach(endpoints_local_nonprimitive,endpoints )
    {
        if(!cJSON_IsObject(endpoints_local_nonprimitive)){
            goto end;
        }
        v1alpha1_endpoint_t *endpointsItem = v1alpha1_endpoint_parseFromJSON(endpoints_local_nonprimitive);

        list_addElement(endpointsList, endpointsItem);
    }

    // v1alpha1_endpoint_slice->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_sliceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_endpoint_slice->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_sliceJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_endpoint_slice->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_sliceJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1alpha1_endpoint_port_t *portsItem = v1alpha1_endpoint_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }


    v1alpha1_endpoint_slice_local_var = v1alpha1_endpoint_slice_create (
        addressType ? strdup(addressType->valuestring) : NULL,
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        endpointsList,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        ports ? portsList : NULL
        );

    return v1alpha1_endpoint_slice_local_var;
end:
    return NULL;

}

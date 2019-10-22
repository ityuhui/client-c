#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_group.h"



v1_api_group_t *v1_api_group_create(
    char *apiVersion,
    char *kind,
    char *name,
    v1_group_version_for_discovery_t *preferredVersion,
    list_t *serverAddressByClientCIDRs,
    list_t *versions
    ) {
	v1_api_group_t *v1_api_group_local_var = malloc(sizeof(v1_api_group_t));
    if (!v1_api_group_local_var) {
        return NULL;
    }
	v1_api_group_local_var->apiVersion = apiVersion;
	v1_api_group_local_var->kind = kind;
	v1_api_group_local_var->name = name;
	v1_api_group_local_var->preferredVersion = preferredVersion;
	v1_api_group_local_var->serverAddressByClientCIDRs = serverAddressByClientCIDRs;
	v1_api_group_local_var->versions = versions;

	return v1_api_group_local_var;
}


void v1_api_group_free(v1_api_group_t *v1_api_group) {
    listEntry_t *listEntry;
    free(v1_api_group->apiVersion);
    free(v1_api_group->kind);
    free(v1_api_group->name);
    v1_group_version_for_discovery_free(v1_api_group->preferredVersion);
	list_ForEach(listEntry, v1_api_group->serverAddressByClientCIDRs) {
		v1_server_address_by_client_cidr_free(listEntry->data);
	}
	list_free(v1_api_group->serverAddressByClientCIDRs);
	list_ForEach(listEntry, v1_api_group->versions) {
		v1_group_version_for_discovery_free(listEntry->data);
	}
	list_free(v1_api_group->versions);
	free(v1_api_group);
}

cJSON *v1_api_group_convertToJSON(v1_api_group_t *v1_api_group) {
	cJSON *item = cJSON_CreateObject();

	// v1_api_group->apiVersion
    if(v1_api_group->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_group->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_group->kind
    if(v1_api_group->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_api_group->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_group->name
    if (!v1_api_group->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_api_group->name) == NULL) {
    goto fail; //String
    }


	// v1_api_group->preferredVersion
    if(v1_api_group->preferredVersion) { 
    cJSON *preferredVersion_local_JSON = v1_group_version_for_discovery_convertToJSON(v1_api_group->preferredVersion);
    if(preferredVersion_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preferredVersion", preferredVersion_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_api_group->serverAddressByClientCIDRs
    if(v1_api_group->serverAddressByClientCIDRs) { 
    cJSON *serverAddressByClientCIDRs = cJSON_AddArrayToObject(item, "serverAddressByClientCIDRs");
    if(serverAddressByClientCIDRs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *serverAddressByClientCIDRsListEntry;
    if (v1_api_group->serverAddressByClientCIDRs) {
    list_ForEach(serverAddressByClientCIDRsListEntry, v1_api_group->serverAddressByClientCIDRs) {
    cJSON *itemLocal = v1_server_address_by_client_cidr_convertToJSON(serverAddressByClientCIDRsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(serverAddressByClientCIDRs, itemLocal);
    }
    }
     } 


	// v1_api_group->versions
    if (!v1_api_group->versions) {
        goto fail;
    }
    
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (v1_api_group->versions) {
    list_ForEach(versionsListEntry, v1_api_group->versions) {
    cJSON *itemLocal = v1_group_version_for_discovery_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
    }
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_api_group_t *v1_api_group_parseFromJSON(cJSON *v1_api_groupJSON){

    v1_api_group_t *v1_api_group_local_var = NULL;

    // v1_api_group->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_api_group->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_api_group->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_api_group->preferredVersion
    cJSON *preferredVersion = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "preferredVersion");
    v1_group_version_for_discovery_t *preferredVersion_local_nonprim = NULL;
    if (preferredVersion) { 
    preferredVersion_local_nonprim = v1_group_version_for_discovery_parseFromJSON(preferredVersion); //nonprimitive
    }

    // v1_api_group->serverAddressByClientCIDRs
    cJSON *serverAddressByClientCIDRs = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "serverAddressByClientCIDRs");
    list_t *serverAddressByClientCIDRsList;
    if (serverAddressByClientCIDRs) { 
    cJSON *serverAddressByClientCIDRs_local_nonprimitive;
    if(!cJSON_IsArray(serverAddressByClientCIDRs)){
        goto end; //nonprimitive container
    }

    serverAddressByClientCIDRsList = list_create();

    cJSON_ArrayForEach(serverAddressByClientCIDRs_local_nonprimitive,serverAddressByClientCIDRs )
    {
        if(!cJSON_IsObject(serverAddressByClientCIDRs_local_nonprimitive)){
            goto end;
        }
        v1_server_address_by_client_cidr_t *serverAddressByClientCIDRsItem = v1_server_address_by_client_cidr_parseFromJSON(serverAddressByClientCIDRs_local_nonprimitive);

        list_addElement(serverAddressByClientCIDRsList, serverAddressByClientCIDRsItem);
    }
    }

    // v1_api_group->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "versions");
    if (!versions) {
        goto end;
    }

    list_t *versionsList;
    
    cJSON *versions_local_nonprimitive;
    if(!cJSON_IsArray(versions)){
        goto end; //nonprimitive container
    }

    versionsList = list_create();

    cJSON_ArrayForEach(versions_local_nonprimitive,versions )
    {
        if(!cJSON_IsObject(versions_local_nonprimitive)){
            goto end;
        }
        v1_group_version_for_discovery_t *versionsItem = v1_group_version_for_discovery_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }


    v1_api_group_local_var = v1_api_group_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        strdup(name->valuestring),
        preferredVersion ? preferredVersion_local_nonprim : NULL,
        serverAddressByClientCIDRs ? serverAddressByClientCIDRsList : NULL,
        versionsList
        );

    return v1_api_group_local_var;
end:
    return NULL;

}

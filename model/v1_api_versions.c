#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_versions.h"



v1_api_versions_t *v1_api_versions_create(
    char *apiVersion,
    char *kind,
    list_t *serverAddressByClientCIDRs,
    list_t *versions
    ) {
	v1_api_versions_t *v1_api_versions_local_var = malloc(sizeof(v1_api_versions_t));
    if (!v1_api_versions_local_var) {
        return NULL;
    }
	v1_api_versions_local_var->apiVersion = apiVersion;
	v1_api_versions_local_var->kind = kind;
	v1_api_versions_local_var->serverAddressByClientCIDRs = serverAddressByClientCIDRs;
	v1_api_versions_local_var->versions = versions;

	return v1_api_versions_local_var;
}


void v1_api_versions_free(v1_api_versions_t *v1_api_versions) {
    listEntry_t *listEntry;
    free(v1_api_versions->apiVersion);
    free(v1_api_versions->kind);
	list_ForEach(listEntry, v1_api_versions->serverAddressByClientCIDRs) {
		v1_server_address_by_client_cidr_free(listEntry->data);
	}
	list_free(v1_api_versions->serverAddressByClientCIDRs);
	list_ForEach(listEntry, v1_api_versions->versions) {
		free(listEntry->data);
	}
	list_free(v1_api_versions->versions);
	free(v1_api_versions);
}

cJSON *v1_api_versions_convertToJSON(v1_api_versions_t *v1_api_versions) {
	cJSON *item = cJSON_CreateObject();

	// v1_api_versions->apiVersion
    if(v1_api_versions->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_versions->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_versions->kind
    if(v1_api_versions->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_api_versions->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_versions->serverAddressByClientCIDRs
    if (!v1_api_versions->serverAddressByClientCIDRs) {
        goto fail;
    }
    
    cJSON *serverAddressByClientCIDRs = cJSON_AddArrayToObject(item, "serverAddressByClientCIDRs");
    if(serverAddressByClientCIDRs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *serverAddressByClientCIDRsListEntry;
    if (v1_api_versions->serverAddressByClientCIDRs) {
    list_ForEach(serverAddressByClientCIDRsListEntry, v1_api_versions->serverAddressByClientCIDRs) {
    cJSON *itemLocal = v1_server_address_by_client_cidr_convertToJSON(serverAddressByClientCIDRsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(serverAddressByClientCIDRs, itemLocal);
    }
    }


	// v1_api_versions->versions
    if (!v1_api_versions->versions) {
        goto fail;
    }
    
	cJSON *versions = cJSON_AddArrayToObject(item, "versions");
	if(versions == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *versionsListEntry;
    list_ForEach(versionsListEntry, v1_api_versions->versions) {
    if(cJSON_AddStringToObject(versions, "", (char*)versionsListEntry->data) == NULL)
    {
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

v1_api_versions_t *v1_api_versions_parseFromJSON(cJSON *v1_api_versionsJSON){

    v1_api_versions_t *v1_api_versions_local_var = NULL;

    // v1_api_versions->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_api_versions->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_api_versions->serverAddressByClientCIDRs
    cJSON *serverAddressByClientCIDRs = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "serverAddressByClientCIDRs");
    if (!serverAddressByClientCIDRs) {
        goto end;
    }

    list_t *serverAddressByClientCIDRsList;
    
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

    // v1_api_versions->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1_api_versionsJSON, "versions");
    if (!versions) {
        goto end;
    }

    list_t *versionsList;
    
    cJSON *versions_local;
    if(!cJSON_IsArray(versions)) {
        goto end;//primitive container
    }
    versionsList = list_create();

    cJSON_ArrayForEach(versions_local, versions)
    {
        if(!cJSON_IsString(versions_local))
        {
            goto end;
        }
        list_addElement(versionsList , strdup(versions_local->valuestring));
    }


    v1_api_versions_local_var = v1_api_versions_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        serverAddressByClientCIDRsList,
        versionsList
        );

    return v1_api_versions_local_var;
end:
    return NULL;

}

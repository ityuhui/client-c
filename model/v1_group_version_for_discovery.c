#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_group_version_for_discovery.h"



v1_group_version_for_discovery_t *v1_group_version_for_discovery_create(
    char *groupVersion,
    char *version
    ) {
	v1_group_version_for_discovery_t *v1_group_version_for_discovery_local_var = malloc(sizeof(v1_group_version_for_discovery_t));
    if (!v1_group_version_for_discovery_local_var) {
        return NULL;
    }
	v1_group_version_for_discovery_local_var->groupVersion = groupVersion;
	v1_group_version_for_discovery_local_var->version = version;

	return v1_group_version_for_discovery_local_var;
}


void v1_group_version_for_discovery_free(v1_group_version_for_discovery_t *v1_group_version_for_discovery) {
    listEntry_t *listEntry;
    free(v1_group_version_for_discovery->groupVersion);
    free(v1_group_version_for_discovery->version);
	free(v1_group_version_for_discovery);
}

cJSON *v1_group_version_for_discovery_convertToJSON(v1_group_version_for_discovery_t *v1_group_version_for_discovery) {
	cJSON *item = cJSON_CreateObject();

	// v1_group_version_for_discovery->groupVersion
    if (!v1_group_version_for_discovery->groupVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "groupVersion", v1_group_version_for_discovery->groupVersion) == NULL) {
    goto fail; //String
    }


	// v1_group_version_for_discovery->version
    if (!v1_group_version_for_discovery->version) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "version", v1_group_version_for_discovery->version) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_group_version_for_discovery_t *v1_group_version_for_discovery_parseFromJSON(cJSON *v1_group_version_for_discoveryJSON){

    v1_group_version_for_discovery_t *v1_group_version_for_discovery_local_var = NULL;

    // v1_group_version_for_discovery->groupVersion
    cJSON *groupVersion = cJSON_GetObjectItemCaseSensitive(v1_group_version_for_discoveryJSON, "groupVersion");
    if (!groupVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(groupVersion))
    {
    goto end; //String
    }

    // v1_group_version_for_discovery->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_group_version_for_discoveryJSON, "version");
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }


    v1_group_version_for_discovery_local_var = v1_group_version_for_discovery_create (
        strdup(groupVersion->valuestring),
        strdup(version->valuestring)
        );

    return v1_group_version_for_discovery_local_var;
end:
    return NULL;

}

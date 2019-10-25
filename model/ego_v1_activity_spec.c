#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ego_v1_activity_spec.h"



ego_v1_activity_spec_t *ego_v1_activity_spec_create(
    char *host, // string
    char *command// string
    ) {
    ego_v1_activity_spec_t *ego_v1_activity_spec_local_var = malloc(sizeof(ego_v1_activity_spec_t));
    if (!ego_v1_activity_spec_local_var) {
        return NULL;
    }
    ego_v1_activity_spec_local_var->host = strdup(host);
    ego_v1_activity_spec_local_var->command = strdup(command);


	return ego_v1_activity_spec_local_var;
}


void ego_v1_activity_spec_free(ego_v1_activity_spec_t *ego_v1_activity_spec) {
    FREEUP(ego_v1_activity_spec->host);
    FREEUP(ego_v1_activity_spec->command);
    FREEUP(ego_v1_activity_spec);
}

cJSON *ego_v1_activity_spec_convertToJSON(ego_v1_activity_spec_t *ego_v1_activity_spec) {
	cJSON *item = cJSON_CreateObject();

    // ego_v1_activity_spec->host
    if (ego_v1_activity_spec->host) {
        if (cJSON_AddStringToObject(item, "host", ego_v1_activity_spec->host) == NULL) {
            goto fail; //String
        }
    }

	// ego_v1_activity_spec->command
    if(ego_v1_activity_spec->command) {
        if(cJSON_AddStringToObject(item, "command", ego_v1_activity_spec->command) == NULL) {
            goto fail; //String
        }
    } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

ego_v1_activity_spec_t *ego_v1_activity_spec_parseFromJSON(cJSON *ego_v1_activity_specJSON){

    ego_v1_activity_spec_t *ego_v1_activity_spec_local_var = NULL;

    // ego_v1_activity_spec->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "host");
    if (host) {
        if(!cJSON_IsString(host)){
            goto end; //String
        }
    }

    // v1_job_spec->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "command");
    if (command) {
        if(!cJSON_IsString(command)){
            goto end; //String
        }
    }

    ego_v1_activity_spec_local_var = v1_job_spec_create (
        host ? strdup(host->valuestring) : NULL,
        command ? strdup(command->valuestring) : NULL
        );

    return ego_v1_activity_spec_local_var;
end:
    return NULL;

}

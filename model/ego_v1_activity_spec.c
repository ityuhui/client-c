#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ego_v1_activity_spec.h"



ego_v1_activity_spec_t *ego_v1_activity_spec_create(
    char *host, // string
    char *command,// string
    char *execuser,
    char *execcwd,
    list_t *envs
    ) {
    ego_v1_activity_spec_t *ego_v1_activity_spec_local_var = malloc(sizeof(ego_v1_activity_spec_t));
    if (!ego_v1_activity_spec_local_var) {
        return NULL;
    }
    ego_v1_activity_spec_local_var->host = host;
    ego_v1_activity_spec_local_var->command = command;
    ego_v1_activity_spec_local_var->execuser = execuser;
    ego_v1_activity_spec_local_var->execcwd = execcwd;
    ego_v1_activity_spec_local_var->envs = envs;

	return ego_v1_activity_spec_local_var;
}


void ego_v1_activity_spec_free(ego_v1_activity_spec_t *ego_v1_activity_spec) {
    listEntry_t *listEntry;

    FREEUP(ego_v1_activity_spec->host);
    FREEUP(ego_v1_activity_spec->command);
    FREEUP(ego_v1_activity_spec->execuser);
    FREEUP(ego_v1_activity_spec->execcwd);

    if (ego_v1_activity_spec->envs) {
        list_ForEach(listEntry, ego_v1_activity_spec->envs) {
            FREEUP(listEntry->data);
        }
        list_free(ego_v1_activity_spec->envs);
    }

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

    // ego_v1_activity_spec->execuser
    if (ego_v1_activity_spec->execuser) {
        if (cJSON_AddStringToObject(item, "execuser", ego_v1_activity_spec->execuser) == NULL) {
            goto fail; //String
        }
    }

    // ego_v1_activity_spec->execcwd
    if (ego_v1_activity_spec->execcwd) {
        if (cJSON_AddStringToObject(item, "execcwd", ego_v1_activity_spec->execcwd) == NULL) {
            goto fail; //String
        }
    }

    // ego_v1_activity_spec->envs
    if (ego_v1_activity_spec->envs) {
        cJSON *envs = cJSON_AddArrayToObject(item, "envs");
        if (envs == NULL) {
            goto fail; //primitive container
        }

        listEntry_t *envsListEntry;
        list_ForEach(envsListEntry, ego_v1_activity_spec->envs) {
            if (cJSON_AddStringToObject(envs, "", (char*)envsListEntry->data) == NULL) {
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

ego_v1_activity_spec_t *ego_v1_activity_spec_parseFromJSON(cJSON *ego_v1_activity_specJSON){

    ego_v1_activity_spec_t *ego_v1_activity_spec_local_var = NULL;

    // ego_v1_activity_spec->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "host");
    if (host) {
        if(!cJSON_IsString(host)){
            goto end; //String
        }
    }

    // ego_v1_activity_spec->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "command");
    if (command) {
        if(!cJSON_IsString(command)){
            goto end; //String
        }
    }

    // ego_v1_activity_spec->execuser
    cJSON *execuser = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "execuser");
    if (execuser) {
        if (!cJSON_IsString(execuser)) {
            goto end; //String
        }
    }

    // ego_v1_activity_spec->execcwd
    cJSON *execcwd = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "execcwd");
    if (execcwd) {
        if (!cJSON_IsString(execcwd)) {
            goto end; //String
        }
    }

    // ego_v1_activity_spec->envs
    cJSON *envs = cJSON_GetObjectItemCaseSensitive(ego_v1_activity_specJSON, "envs");
    list_t *envList;
    if (envs) {
        cJSON *env_local;
        if (!cJSON_IsArray(envs)) {
            goto end;//primitive container
        }
        envList = list_create();

        cJSON_ArrayForEach(env_local, envs)
        {
            if (!cJSON_IsString(env_local)) {
                goto end;
            }
            list_addElement(envList, strdup(env_local->valuestring));
        }
    }


    ego_v1_activity_spec_local_var = ego_v1_activity_spec_create(
        host ? strdup(host->valuestring) : NULL,
        command ? strdup(command->valuestring) : NULL,
        execuser ? strdup(execuser->valuestring) : NULL,
        execcwd ? strdup(execcwd->valuestring) : NULL,
        envs ? envList : NULL
        );

    return ego_v1_activity_spec_local_var;
end:
    return NULL;

}

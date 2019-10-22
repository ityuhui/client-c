#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "version_info.h"



version_info_t *version_info_create(
    char *buildDate,
    char *compiler,
    char *gitCommit,
    char *gitTreeState,
    char *gitVersion,
    char *goVersion,
    char *major,
    char *minor,
    char *platform
    ) {
	version_info_t *version_info_local_var = malloc(sizeof(version_info_t));
    if (!version_info_local_var) {
        return NULL;
    }
	version_info_local_var->buildDate = buildDate;
	version_info_local_var->compiler = compiler;
	version_info_local_var->gitCommit = gitCommit;
	version_info_local_var->gitTreeState = gitTreeState;
	version_info_local_var->gitVersion = gitVersion;
	version_info_local_var->goVersion = goVersion;
	version_info_local_var->major = major;
	version_info_local_var->minor = minor;
	version_info_local_var->platform = platform;

	return version_info_local_var;
}


void version_info_free(version_info_t *version_info) {
    listEntry_t *listEntry;
    free(version_info->buildDate);
    free(version_info->compiler);
    free(version_info->gitCommit);
    free(version_info->gitTreeState);
    free(version_info->gitVersion);
    free(version_info->goVersion);
    free(version_info->major);
    free(version_info->minor);
    free(version_info->platform);
	free(version_info);
}

cJSON *version_info_convertToJSON(version_info_t *version_info) {
	cJSON *item = cJSON_CreateObject();

	// version_info->buildDate
    if (!version_info->buildDate) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "buildDate", version_info->buildDate) == NULL) {
    goto fail; //String
    }


	// version_info->compiler
    if (!version_info->compiler) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "compiler", version_info->compiler) == NULL) {
    goto fail; //String
    }


	// version_info->gitCommit
    if (!version_info->gitCommit) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gitCommit", version_info->gitCommit) == NULL) {
    goto fail; //String
    }


	// version_info->gitTreeState
    if (!version_info->gitTreeState) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gitTreeState", version_info->gitTreeState) == NULL) {
    goto fail; //String
    }


	// version_info->gitVersion
    if (!version_info->gitVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gitVersion", version_info->gitVersion) == NULL) {
    goto fail; //String
    }


	// version_info->goVersion
    if (!version_info->goVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "goVersion", version_info->goVersion) == NULL) {
    goto fail; //String
    }


	// version_info->major
    if (!version_info->major) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "major", version_info->major) == NULL) {
    goto fail; //String
    }


	// version_info->minor
    if (!version_info->minor) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "minor", version_info->minor) == NULL) {
    goto fail; //String
    }


	// version_info->platform
    if (!version_info->platform) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "platform", version_info->platform) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

version_info_t *version_info_parseFromJSON(cJSON *version_infoJSON){

    version_info_t *version_info_local_var = NULL;

    // version_info->buildDate
    cJSON *buildDate = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "buildDate");
    if (!buildDate) {
        goto end;
    }

    
    if(!cJSON_IsString(buildDate))
    {
    goto end; //String
    }

    // version_info->compiler
    cJSON *compiler = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "compiler");
    if (!compiler) {
        goto end;
    }

    
    if(!cJSON_IsString(compiler))
    {
    goto end; //String
    }

    // version_info->gitCommit
    cJSON *gitCommit = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitCommit");
    if (!gitCommit) {
        goto end;
    }

    
    if(!cJSON_IsString(gitCommit))
    {
    goto end; //String
    }

    // version_info->gitTreeState
    cJSON *gitTreeState = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitTreeState");
    if (!gitTreeState) {
        goto end;
    }

    
    if(!cJSON_IsString(gitTreeState))
    {
    goto end; //String
    }

    // version_info->gitVersion
    cJSON *gitVersion = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitVersion");
    if (!gitVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(gitVersion))
    {
    goto end; //String
    }

    // version_info->goVersion
    cJSON *goVersion = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "goVersion");
    if (!goVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(goVersion))
    {
    goto end; //String
    }

    // version_info->major
    cJSON *major = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "major");
    if (!major) {
        goto end;
    }

    
    if(!cJSON_IsString(major))
    {
    goto end; //String
    }

    // version_info->minor
    cJSON *minor = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "minor");
    if (!minor) {
        goto end;
    }

    
    if(!cJSON_IsString(minor))
    {
    goto end; //String
    }

    // version_info->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "platform");
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }


    version_info_local_var = version_info_create (
        strdup(buildDate->valuestring),
        strdup(compiler->valuestring),
        strdup(gitCommit->valuestring),
        strdup(gitTreeState->valuestring),
        strdup(gitVersion->valuestring),
        strdup(goVersion->valuestring),
        strdup(major->valuestring),
        strdup(minor->valuestring),
        strdup(platform->valuestring)
        );

    return version_info_local_var;
end:
    return NULL;

}

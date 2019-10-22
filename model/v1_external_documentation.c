#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_external_documentation.h"



v1_external_documentation_t *v1_external_documentation_create(
    char *description,
    char *url
    ) {
	v1_external_documentation_t *v1_external_documentation_local_var = malloc(sizeof(v1_external_documentation_t));
    if (!v1_external_documentation_local_var) {
        return NULL;
    }
	v1_external_documentation_local_var->description = description;
	v1_external_documentation_local_var->url = url;

	return v1_external_documentation_local_var;
}


void v1_external_documentation_free(v1_external_documentation_t *v1_external_documentation) {
    listEntry_t *listEntry;
    free(v1_external_documentation->description);
    free(v1_external_documentation->url);
	free(v1_external_documentation);
}

cJSON *v1_external_documentation_convertToJSON(v1_external_documentation_t *v1_external_documentation) {
	cJSON *item = cJSON_CreateObject();

	// v1_external_documentation->description
    if(v1_external_documentation->description) { 
    if(cJSON_AddStringToObject(item, "description", v1_external_documentation->description) == NULL) {
    goto fail; //String
    }
     } 


	// v1_external_documentation->url
    if(v1_external_documentation->url) { 
    if(cJSON_AddStringToObject(item, "url", v1_external_documentation->url) == NULL) {
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

v1_external_documentation_t *v1_external_documentation_parseFromJSON(cJSON *v1_external_documentationJSON){

    v1_external_documentation_t *v1_external_documentation_local_var = NULL;

    // v1_external_documentation->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1_external_documentationJSON, "description");
    if (description) { 
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }
    }

    // v1_external_documentation->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(v1_external_documentationJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }
    }


    v1_external_documentation_local_var = v1_external_documentation_create (
        description ? strdup(description->valuestring) : NULL,
        url ? strdup(url->valuestring) : NULL
        );

    return v1_external_documentation_local_var;
end:
    return NULL;

}

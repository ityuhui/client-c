#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_attachment_spec.h"



v1_volume_attachment_spec_t *v1_volume_attachment_spec_create(
    char *attacher,
    char *nodeName,
    v1_volume_attachment_source_t *source
    ) {
	v1_volume_attachment_spec_t *v1_volume_attachment_spec_local_var = malloc(sizeof(v1_volume_attachment_spec_t));
    if (!v1_volume_attachment_spec_local_var) {
        return NULL;
    }
	v1_volume_attachment_spec_local_var->attacher = attacher;
	v1_volume_attachment_spec_local_var->nodeName = nodeName;
	v1_volume_attachment_spec_local_var->source = source;

	return v1_volume_attachment_spec_local_var;
}


void v1_volume_attachment_spec_free(v1_volume_attachment_spec_t *v1_volume_attachment_spec) {
    listEntry_t *listEntry;
    free(v1_volume_attachment_spec->attacher);
    free(v1_volume_attachment_spec->nodeName);
    v1_volume_attachment_source_free(v1_volume_attachment_spec->source);
	free(v1_volume_attachment_spec);
}

cJSON *v1_volume_attachment_spec_convertToJSON(v1_volume_attachment_spec_t *v1_volume_attachment_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_volume_attachment_spec->attacher
    if (!v1_volume_attachment_spec->attacher) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "attacher", v1_volume_attachment_spec->attacher) == NULL) {
    goto fail; //String
    }


	// v1_volume_attachment_spec->nodeName
    if (!v1_volume_attachment_spec->nodeName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "nodeName", v1_volume_attachment_spec->nodeName) == NULL) {
    goto fail; //String
    }


	// v1_volume_attachment_spec->source
    if (!v1_volume_attachment_spec->source) {
        goto fail;
    }
    
    cJSON *source_local_JSON = v1_volume_attachment_source_convertToJSON(v1_volume_attachment_spec->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_volume_attachment_spec_t *v1_volume_attachment_spec_parseFromJSON(cJSON *v1_volume_attachment_specJSON){

    v1_volume_attachment_spec_t *v1_volume_attachment_spec_local_var = NULL;

    // v1_volume_attachment_spec->attacher
    cJSON *attacher = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_specJSON, "attacher");
    if (!attacher) {
        goto end;
    }

    
    if(!cJSON_IsString(attacher))
    {
    goto end; //String
    }

    // v1_volume_attachment_spec->nodeName
    cJSON *nodeName = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_specJSON, "nodeName");
    if (!nodeName) {
        goto end;
    }

    
    if(!cJSON_IsString(nodeName))
    {
    goto end; //String
    }

    // v1_volume_attachment_spec->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_specJSON, "source");
    if (!source) {
        goto end;
    }

    v1_volume_attachment_source_t *source_local_nonprim = NULL;
    
    source_local_nonprim = v1_volume_attachment_source_parseFromJSON(source); //nonprimitive


    v1_volume_attachment_spec_local_var = v1_volume_attachment_spec_create (
        strdup(attacher->valuestring),
        strdup(nodeName->valuestring),
        source_local_nonprim
        );

    return v1_volume_attachment_spec_local_var;
end:
    return NULL;

}

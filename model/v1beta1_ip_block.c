#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_ip_block.h"



v1beta1_ip_block_t *v1beta1_ip_block_create(
    char *cidr,
    list_t *except
    ) {
	v1beta1_ip_block_t *v1beta1_ip_block_local_var = malloc(sizeof(v1beta1_ip_block_t));
    if (!v1beta1_ip_block_local_var) {
        return NULL;
    }
	v1beta1_ip_block_local_var->cidr = cidr;
	v1beta1_ip_block_local_var->except = except;

	return v1beta1_ip_block_local_var;
}


void v1beta1_ip_block_free(v1beta1_ip_block_t *v1beta1_ip_block) {
    listEntry_t *listEntry;
    free(v1beta1_ip_block->cidr);
	list_ForEach(listEntry, v1beta1_ip_block->except) {
		free(listEntry->data);
	}
	list_free(v1beta1_ip_block->except);
	free(v1beta1_ip_block);
}

cJSON *v1beta1_ip_block_convertToJSON(v1beta1_ip_block_t *v1beta1_ip_block) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_ip_block->cidr
    if (!v1beta1_ip_block->cidr) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "cidr", v1beta1_ip_block->cidr) == NULL) {
    goto fail; //String
    }


	// v1beta1_ip_block->except
    if(v1beta1_ip_block->except) { 
	cJSON *except = cJSON_AddArrayToObject(item, "except");
	if(except == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *exceptListEntry;
    list_ForEach(exceptListEntry, v1beta1_ip_block->except) {
    if(cJSON_AddStringToObject(except, "", (char*)exceptListEntry->data) == NULL)
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

v1beta1_ip_block_t *v1beta1_ip_block_parseFromJSON(cJSON *v1beta1_ip_blockJSON){

    v1beta1_ip_block_t *v1beta1_ip_block_local_var = NULL;

    // v1beta1_ip_block->cidr
    cJSON *cidr = cJSON_GetObjectItemCaseSensitive(v1beta1_ip_blockJSON, "cidr");
    if (!cidr) {
        goto end;
    }

    
    if(!cJSON_IsString(cidr))
    {
    goto end; //String
    }

    // v1beta1_ip_block->except
    cJSON *except = cJSON_GetObjectItemCaseSensitive(v1beta1_ip_blockJSON, "except");
    list_t *exceptList;
    if (except) { 
    cJSON *except_local;
    if(!cJSON_IsArray(except)) {
        goto end;//primitive container
    }
    exceptList = list_create();

    cJSON_ArrayForEach(except_local, except)
    {
        if(!cJSON_IsString(except_local))
        {
            goto end;
        }
        list_addElement(exceptList , strdup(except_local->valuestring));
    }
    }


    v1beta1_ip_block_local_var = v1beta1_ip_block_create (
        strdup(cidr->valuestring),
        except ? exceptList : NULL
        );

    return v1beta1_ip_block_local_var;
end:
    return NULL;

}

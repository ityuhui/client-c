#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_account.h"



v1_service_account_t *v1_service_account_create(
    char *apiVersion,
    int automountServiceAccountToken,
    list_t *imagePullSecrets,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *secrets
    ) {
	v1_service_account_t *v1_service_account_local_var = malloc(sizeof(v1_service_account_t));
    if (!v1_service_account_local_var) {
        return NULL;
    }
	v1_service_account_local_var->apiVersion = apiVersion;
	v1_service_account_local_var->automountServiceAccountToken = automountServiceAccountToken;
	v1_service_account_local_var->imagePullSecrets = imagePullSecrets;
	v1_service_account_local_var->kind = kind;
	v1_service_account_local_var->metadata = metadata;
	v1_service_account_local_var->secrets = secrets;

	return v1_service_account_local_var;
}


void v1_service_account_free(v1_service_account_t *v1_service_account) {
    listEntry_t *listEntry;
    free(v1_service_account->apiVersion);
	list_ForEach(listEntry, v1_service_account->imagePullSecrets) {
		v1_local_object_reference_free(listEntry->data);
	}
	list_free(v1_service_account->imagePullSecrets);
    free(v1_service_account->kind);
    v1_object_meta_free(v1_service_account->metadata);
	list_ForEach(listEntry, v1_service_account->secrets) {
		v1_object_reference_free(listEntry->data);
	}
	list_free(v1_service_account->secrets);
	free(v1_service_account);
}

cJSON *v1_service_account_convertToJSON(v1_service_account_t *v1_service_account) {
	cJSON *item = cJSON_CreateObject();

	// v1_service_account->apiVersion
    if(v1_service_account->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_service_account->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_account->automountServiceAccountToken
    if(v1_service_account->automountServiceAccountToken) { 
    if(cJSON_AddBoolToObject(item, "automountServiceAccountToken", v1_service_account->automountServiceAccountToken) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_service_account->imagePullSecrets
    if(v1_service_account->imagePullSecrets) { 
    cJSON *imagePullSecrets = cJSON_AddArrayToObject(item, "imagePullSecrets");
    if(imagePullSecrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *imagePullSecretsListEntry;
    if (v1_service_account->imagePullSecrets) {
    list_ForEach(imagePullSecretsListEntry, v1_service_account->imagePullSecrets) {
    cJSON *itemLocal = v1_local_object_reference_convertToJSON(imagePullSecretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(imagePullSecrets, itemLocal);
    }
    }
     } 


	// v1_service_account->kind
    if(v1_service_account->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_service_account->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_account->metadata
    if(v1_service_account->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_service_account->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_service_account->secrets
    if(v1_service_account->secrets) { 
    cJSON *secrets = cJSON_AddArrayToObject(item, "secrets");
    if(secrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *secretsListEntry;
    if (v1_service_account->secrets) {
    list_ForEach(secretsListEntry, v1_service_account->secrets) {
    cJSON *itemLocal = v1_object_reference_convertToJSON(secretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(secrets, itemLocal);
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

v1_service_account_t *v1_service_account_parseFromJSON(cJSON *v1_service_accountJSON){

    v1_service_account_t *v1_service_account_local_var = NULL;

    // v1_service_account->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_service_account->automountServiceAccountToken
    cJSON *automountServiceAccountToken = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "automountServiceAccountToken");
    if (automountServiceAccountToken) { 
    if(!cJSON_IsBool(automountServiceAccountToken))
    {
    goto end; //Bool
    }
    }

    // v1_service_account->imagePullSecrets
    cJSON *imagePullSecrets = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "imagePullSecrets");
    list_t *imagePullSecretsList;
    if (imagePullSecrets) { 
    cJSON *imagePullSecrets_local_nonprimitive;
    if(!cJSON_IsArray(imagePullSecrets)){
        goto end; //nonprimitive container
    }

    imagePullSecretsList = list_create();

    cJSON_ArrayForEach(imagePullSecrets_local_nonprimitive,imagePullSecrets )
    {
        if(!cJSON_IsObject(imagePullSecrets_local_nonprimitive)){
            goto end;
        }
        v1_local_object_reference_t *imagePullSecretsItem = v1_local_object_reference_parseFromJSON(imagePullSecrets_local_nonprimitive);

        list_addElement(imagePullSecretsList, imagePullSecretsItem);
    }
    }

    // v1_service_account->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_service_account->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_service_account->secrets
    cJSON *secrets = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "secrets");
    list_t *secretsList;
    if (secrets) { 
    cJSON *secrets_local_nonprimitive;
    if(!cJSON_IsArray(secrets)){
        goto end; //nonprimitive container
    }

    secretsList = list_create();

    cJSON_ArrayForEach(secrets_local_nonprimitive,secrets )
    {
        if(!cJSON_IsObject(secrets_local_nonprimitive)){
            goto end;
        }
        v1_object_reference_t *secretsItem = v1_object_reference_parseFromJSON(secrets_local_nonprimitive);

        list_addElement(secretsList, secretsItem);
    }
    }


    v1_service_account_local_var = v1_service_account_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        automountServiceAccountToken ? automountServiceAccountToken->valueint : 0,
        imagePullSecrets ? imagePullSecretsList : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        secrets ? secretsList : NULL
        );

    return v1_service_account_local_var;
end:
    return NULL;

}

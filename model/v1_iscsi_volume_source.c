#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_iscsi_volume_source.h"



v1_iscsi_volume_source_t *v1_iscsi_volume_source_create(
    int chapAuthDiscovery,
    int chapAuthSession,
    char *fsType,
    char *initiatorName,
    char *iqn,
    char *iscsiInterface,
    int lun,
    list_t *portals,
    int readOnly,
    v1_local_object_reference_t *secretRef,
    char *targetPortal
    ) {
	v1_iscsi_volume_source_t *v1_iscsi_volume_source_local_var = malloc(sizeof(v1_iscsi_volume_source_t));
    if (!v1_iscsi_volume_source_local_var) {
        return NULL;
    }
	v1_iscsi_volume_source_local_var->chapAuthDiscovery = chapAuthDiscovery;
	v1_iscsi_volume_source_local_var->chapAuthSession = chapAuthSession;
	v1_iscsi_volume_source_local_var->fsType = fsType;
	v1_iscsi_volume_source_local_var->initiatorName = initiatorName;
	v1_iscsi_volume_source_local_var->iqn = iqn;
	v1_iscsi_volume_source_local_var->iscsiInterface = iscsiInterface;
	v1_iscsi_volume_source_local_var->lun = lun;
	v1_iscsi_volume_source_local_var->portals = portals;
	v1_iscsi_volume_source_local_var->readOnly = readOnly;
	v1_iscsi_volume_source_local_var->secretRef = secretRef;
	v1_iscsi_volume_source_local_var->targetPortal = targetPortal;

	return v1_iscsi_volume_source_local_var;
}


void v1_iscsi_volume_source_free(v1_iscsi_volume_source_t *v1_iscsi_volume_source) {
    listEntry_t *listEntry;
    free(v1_iscsi_volume_source->fsType);
    free(v1_iscsi_volume_source->initiatorName);
    free(v1_iscsi_volume_source->iqn);
    free(v1_iscsi_volume_source->iscsiInterface);
	list_ForEach(listEntry, v1_iscsi_volume_source->portals) {
		free(listEntry->data);
	}
	list_free(v1_iscsi_volume_source->portals);
    v1_local_object_reference_free(v1_iscsi_volume_source->secretRef);
    free(v1_iscsi_volume_source->targetPortal);
	free(v1_iscsi_volume_source);
}

cJSON *v1_iscsi_volume_source_convertToJSON(v1_iscsi_volume_source_t *v1_iscsi_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_iscsi_volume_source->chapAuthDiscovery
    if(v1_iscsi_volume_source->chapAuthDiscovery) { 
    if(cJSON_AddBoolToObject(item, "chapAuthDiscovery", v1_iscsi_volume_source->chapAuthDiscovery) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_iscsi_volume_source->chapAuthSession
    if(v1_iscsi_volume_source->chapAuthSession) { 
    if(cJSON_AddBoolToObject(item, "chapAuthSession", v1_iscsi_volume_source->chapAuthSession) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_iscsi_volume_source->fsType
    if(v1_iscsi_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_iscsi_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_iscsi_volume_source->initiatorName
    if(v1_iscsi_volume_source->initiatorName) { 
    if(cJSON_AddStringToObject(item, "initiatorName", v1_iscsi_volume_source->initiatorName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_iscsi_volume_source->iqn
    if (!v1_iscsi_volume_source->iqn) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "iqn", v1_iscsi_volume_source->iqn) == NULL) {
    goto fail; //String
    }


	// v1_iscsi_volume_source->iscsiInterface
    if(v1_iscsi_volume_source->iscsiInterface) { 
    if(cJSON_AddStringToObject(item, "iscsiInterface", v1_iscsi_volume_source->iscsiInterface) == NULL) {
    goto fail; //String
    }
     } 


	// v1_iscsi_volume_source->lun
    if (!v1_iscsi_volume_source->lun) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "lun", v1_iscsi_volume_source->lun) == NULL) {
    goto fail; //Numeric
    }


	// v1_iscsi_volume_source->portals
    if(v1_iscsi_volume_source->portals) { 
	cJSON *portals = cJSON_AddArrayToObject(item, "portals");
	if(portals == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *portalsListEntry;
    list_ForEach(portalsListEntry, v1_iscsi_volume_source->portals) {
    if(cJSON_AddStringToObject(portals, "", (char*)portalsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_iscsi_volume_source->readOnly
    if(v1_iscsi_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_iscsi_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_iscsi_volume_source->secretRef
    if(v1_iscsi_volume_source->secretRef) { 
    cJSON *secretRef_local_JSON = v1_local_object_reference_convertToJSON(v1_iscsi_volume_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_iscsi_volume_source->targetPortal
    if (!v1_iscsi_volume_source->targetPortal) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "targetPortal", v1_iscsi_volume_source->targetPortal) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_iscsi_volume_source_t *v1_iscsi_volume_source_parseFromJSON(cJSON *v1_iscsi_volume_sourceJSON){

    v1_iscsi_volume_source_t *v1_iscsi_volume_source_local_var = NULL;

    // v1_iscsi_volume_source->chapAuthDiscovery
    cJSON *chapAuthDiscovery = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "chapAuthDiscovery");
    if (chapAuthDiscovery) { 
    if(!cJSON_IsBool(chapAuthDiscovery))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_volume_source->chapAuthSession
    cJSON *chapAuthSession = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "chapAuthSession");
    if (chapAuthSession) { 
    if(!cJSON_IsBool(chapAuthSession))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_iscsi_volume_source->initiatorName
    cJSON *initiatorName = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "initiatorName");
    if (initiatorName) { 
    if(!cJSON_IsString(initiatorName))
    {
    goto end; //String
    }
    }

    // v1_iscsi_volume_source->iqn
    cJSON *iqn = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "iqn");
    if (!iqn) {
        goto end;
    }

    
    if(!cJSON_IsString(iqn))
    {
    goto end; //String
    }

    // v1_iscsi_volume_source->iscsiInterface
    cJSON *iscsiInterface = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "iscsiInterface");
    if (iscsiInterface) { 
    if(!cJSON_IsString(iscsiInterface))
    {
    goto end; //String
    }
    }

    // v1_iscsi_volume_source->lun
    cJSON *lun = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "lun");
    if (!lun) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lun))
    {
    goto end; //Numeric
    }

    // v1_iscsi_volume_source->portals
    cJSON *portals = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "portals");
    list_t *portalsList;
    if (portals) { 
    cJSON *portals_local;
    if(!cJSON_IsArray(portals)) {
        goto end;//primitive container
    }
    portalsList = list_create();

    cJSON_ArrayForEach(portals_local, portals)
    {
        if(!cJSON_IsString(portals_local))
        {
            goto end;
        }
        list_addElement(portalsList , strdup(portals_local->valuestring));
    }
    }

    // v1_iscsi_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_volume_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "secretRef");
    v1_local_object_reference_t *secretRef_local_nonprim = NULL;
    if (secretRef) { 
    secretRef_local_nonprim = v1_local_object_reference_parseFromJSON(secretRef); //nonprimitive
    }

    // v1_iscsi_volume_source->targetPortal
    cJSON *targetPortal = cJSON_GetObjectItemCaseSensitive(v1_iscsi_volume_sourceJSON, "targetPortal");
    if (!targetPortal) {
        goto end;
    }

    
    if(!cJSON_IsString(targetPortal))
    {
    goto end; //String
    }


    v1_iscsi_volume_source_local_var = v1_iscsi_volume_source_create (
        chapAuthDiscovery ? chapAuthDiscovery->valueint : 0,
        chapAuthSession ? chapAuthSession->valueint : 0,
        fsType ? strdup(fsType->valuestring) : NULL,
        initiatorName ? strdup(initiatorName->valuestring) : NULL,
        strdup(iqn->valuestring),
        iscsiInterface ? strdup(iscsiInterface->valuestring) : NULL,
        lun->valuedouble,
        portals ? portalsList : NULL,
        readOnly ? readOnly->valueint : 0,
        secretRef ? secretRef_local_nonprim : NULL,
        strdup(targetPortal->valuestring)
        );

    return v1_iscsi_volume_source_local_var;
end:
    return NULL;

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_meta.h"



v1_object_meta_t *v1_object_meta_create(
    list_t* annotations,
    char *clusterName,
    char *creationTimestamp,
    long deletionGracePeriodSeconds,
    char *deletionTimestamp,
    list_t *finalizers,
    char *generateName,
    long generation,
    list_t* labels,
    list_t *managedFields,
    char *name,
    char *namespace,
    list_t *ownerReferences,
    char *resourceVersion,
    char *selfLink,
    char *uid
    ) {
	v1_object_meta_t *v1_object_meta_local_var = malloc(sizeof(v1_object_meta_t));
    if (!v1_object_meta_local_var) {
        return NULL;
    }
	v1_object_meta_local_var->annotations = annotations;
	v1_object_meta_local_var->clusterName = clusterName;
	v1_object_meta_local_var->creationTimestamp = creationTimestamp;
	v1_object_meta_local_var->deletionGracePeriodSeconds = deletionGracePeriodSeconds;
	v1_object_meta_local_var->deletionTimestamp = deletionTimestamp;
	v1_object_meta_local_var->finalizers = finalizers;
	v1_object_meta_local_var->generateName = generateName;
	v1_object_meta_local_var->generation = generation;
	v1_object_meta_local_var->labels = labels;
	v1_object_meta_local_var->managedFields = managedFields;
	v1_object_meta_local_var->name = name;
	v1_object_meta_local_var->namespace = namespace;
	v1_object_meta_local_var->ownerReferences = ownerReferences;
	v1_object_meta_local_var->resourceVersion = resourceVersion;
	v1_object_meta_local_var->selfLink = selfLink;
	v1_object_meta_local_var->uid = uid;

	return v1_object_meta_local_var;
}


void v1_object_meta_free(v1_object_meta_t *v1_object_meta) {
    listEntry_t *listEntry;
    if (v1_object_meta->annotations) {
        list_ForEach(listEntry, v1_object_meta->annotations) {
            keyValuePair_t *localMapKeyPair = (keyValuePair_t*)listEntry->data;
            FREEUP(localMapKeyPair->key);
            FREEUP(localMapKeyPair->value);
        }
        list_free(v1_object_meta->annotations);
    }
    FREEUP(v1_object_meta->clusterName);
    FREEUP(v1_object_meta->creationTimestamp);
    FREEUP(v1_object_meta->deletionTimestamp);

    if (v1_object_meta->finalizers) {
        list_ForEach(listEntry, v1_object_meta->finalizers) {
            FREEUP(listEntry->data);
        }
        list_free(v1_object_meta->finalizers);
    }

    FREEUP(v1_object_meta->generateName);

    if (v1_object_meta->labels) {
        list_ForEach(listEntry, v1_object_meta->labels) {
            keyValuePair_t *localMapKeyPair = (keyValuePair_t*)listEntry->data;
            FREEUP(localMapKeyPair->key);
            FREEUP(localMapKeyPair->value);
        }
        list_free(v1_object_meta->labels);
    }

    if (v1_object_meta->managedFields) {
        list_ForEach(listEntry, v1_object_meta->managedFields) {
            v1_managed_fields_entry_free(listEntry->data);
        }
        list_free(v1_object_meta->managedFields);
    }

    FREEUP(v1_object_meta->name);
    FREEUP(v1_object_meta->namespace);

    if (v1_object_meta->ownerReferences) {
        list_ForEach(listEntry, v1_object_meta->ownerReferences) {
            v1_owner_reference_free(listEntry->data);
        }
        list_free(v1_object_meta->ownerReferences);
    }

    FREEUP(v1_object_meta->resourceVersion);
    FREEUP(v1_object_meta->selfLink);
    FREEUP(v1_object_meta->uid);
    FREEUP(v1_object_meta);
}

cJSON *v1_object_meta_convertToJSON(v1_object_meta_t *v1_object_meta) {
	cJSON *item = cJSON_CreateObject();

	// v1_object_meta->annotations
    if(v1_object_meta->annotations) { 
	cJSON *annotations = cJSON_AddObjectToObject(item, "annotations");
	if(annotations == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *annotationsListEntry;
    if (v1_object_meta->annotations) {
    list_ForEach(annotationsListEntry, v1_object_meta->annotations) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)annotationsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(annotations,"", localMapObject);
    }
    }
     } 


	// v1_object_meta->clusterName
    if(v1_object_meta->clusterName) { 
    if(cJSON_AddStringToObject(item, "clusterName", v1_object_meta->clusterName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_meta->creationTimestamp
    if(v1_object_meta->creationTimestamp) { 
    if(cJSON_AddStringToObject(item, "creationTimestamp", v1_object_meta->creationTimestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_object_meta->deletionGracePeriodSeconds
    if(v1_object_meta->deletionGracePeriodSeconds) { 
    if(cJSON_AddNumberToObject(item, "deletionGracePeriodSeconds", v1_object_meta->deletionGracePeriodSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_object_meta->deletionTimestamp
    if(v1_object_meta->deletionTimestamp) { 
    if(cJSON_AddStringToObject(item, "deletionTimestamp", v1_object_meta->deletionTimestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_object_meta->finalizers
    if(v1_object_meta->finalizers) { 
	cJSON *finalizers = cJSON_AddArrayToObject(item, "finalizers");
	if(finalizers == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *finalizersListEntry;
    list_ForEach(finalizersListEntry, v1_object_meta->finalizers) {
    if(cJSON_AddStringToObject(finalizers, "", (char*)finalizersListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_object_meta->generateName
    if(v1_object_meta->generateName) { 
    if(cJSON_AddStringToObject(item, "generateName", v1_object_meta->generateName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_meta->generation
    if(v1_object_meta->generation) { 
    if(cJSON_AddNumberToObject(item, "generation", v1_object_meta->generation) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_object_meta->labels
    if(v1_object_meta->labels) { 
	cJSON *labels = cJSON_AddObjectToObject(item, "labels");
	if(labels == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *labelsListEntry;
    if (v1_object_meta->labels) {
    list_ForEach(labelsListEntry, v1_object_meta->labels) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)labelsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(labels,"", localMapObject);
    }
    }
     } 


	// v1_object_meta->managedFields
    if(v1_object_meta->managedFields) { 
    cJSON *managedFields = cJSON_AddArrayToObject(item, "managedFields");
    if(managedFields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *managedFieldsListEntry;
    if (v1_object_meta->managedFields) {
    list_ForEach(managedFieldsListEntry, v1_object_meta->managedFields) {
    cJSON *itemLocal = v1_managed_fields_entry_convertToJSON(managedFieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(managedFields, itemLocal);
    }
    }
     } 


	// v1_object_meta->name
    if(v1_object_meta->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_object_meta->name) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_meta->namespace
    if(v1_object_meta->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_object_meta->namespace) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_meta->ownerReferences
    if(v1_object_meta->ownerReferences) { 
    cJSON *ownerReferences = cJSON_AddArrayToObject(item, "ownerReferences");
    if(ownerReferences == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ownerReferencesListEntry;
    if (v1_object_meta->ownerReferences) {
    list_ForEach(ownerReferencesListEntry, v1_object_meta->ownerReferences) {
    cJSON *itemLocal = v1_owner_reference_convertToJSON(ownerReferencesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ownerReferences, itemLocal);
    }
    }
     } 


	// v1_object_meta->resourceVersion
    if(v1_object_meta->resourceVersion) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_object_meta->resourceVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_meta->selfLink
    if(v1_object_meta->selfLink) { 
    if(cJSON_AddStringToObject(item, "selfLink", v1_object_meta->selfLink) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_meta->uid
    if(v1_object_meta->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_object_meta->uid) == NULL) {
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

v1_object_meta_t *v1_object_meta_parseFromJSON(cJSON *v1_object_metaJSON){

    v1_object_meta_t *v1_object_meta_local_var = NULL;

    // v1_object_meta->annotations
    cJSON *annotations = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "annotations");
    list_t *List;
    if (annotations) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(annotations)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, annotations)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_object_meta->clusterName
    cJSON *clusterName = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "clusterName");
    if (clusterName) { 
    if(!cJSON_IsString(clusterName))
    {
    goto end; //String
    }
    }

    // v1_object_meta->creationTimestamp
    cJSON *creationTimestamp = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "creationTimestamp");
    if (creationTimestamp) { 
    if(!cJSON_IsString(creationTimestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_object_meta->deletionGracePeriodSeconds
    cJSON *deletionGracePeriodSeconds = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "deletionGracePeriodSeconds");
    if (deletionGracePeriodSeconds) { 
    if(!cJSON_IsNumber(deletionGracePeriodSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_object_meta->deletionTimestamp
    cJSON *deletionTimestamp = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "deletionTimestamp");
    if (deletionTimestamp) { 
    if(!cJSON_IsString(deletionTimestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_object_meta->finalizers
    cJSON *finalizers = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "finalizers");
    list_t *finalizersList;
    if (finalizers) { 
    cJSON *finalizers_local;
    if(!cJSON_IsArray(finalizers)) {
        goto end;//primitive container
    }
    finalizersList = list_create();

    cJSON_ArrayForEach(finalizers_local, finalizers)
    {
        if(!cJSON_IsString(finalizers_local))
        {
            goto end;
        }
        list_addElement(finalizersList , strdup(finalizers_local->valuestring));
    }
    }

    // v1_object_meta->generateName
    cJSON *generateName = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "generateName");
    if (generateName) { 
    if(!cJSON_IsString(generateName))
    {
    goto end; //String
    }
    }

    // v1_object_meta->generation
    cJSON *generation = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "generation");
    if (generation) { 
    if(!cJSON_IsNumber(generation))
    {
    goto end; //Numeric
    }
    }

    // v1_object_meta->labels
    cJSON *labels = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "labels");
    list_t *Listlabels;
    if (labels) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(labels)) {
        goto end;//primitive map container
    }
    Listlabels = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, labels)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(Listlabels, localMapKeyPair);
    }
    }

    // v1_object_meta->managedFields
    cJSON *managedFields = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "managedFields");
    list_t *managedFieldsList;
    if (managedFields) { 
    cJSON *managedFields_local_nonprimitive;
    if(!cJSON_IsArray(managedFields)){
        goto end; //nonprimitive container
    }

    managedFieldsList = list_create();

    cJSON_ArrayForEach(managedFields_local_nonprimitive,managedFields )
    {
        if(!cJSON_IsObject(managedFields_local_nonprimitive)){
            goto end;
        }
        v1_managed_fields_entry_t *managedFieldsItem = v1_managed_fields_entry_parseFromJSON(managedFields_local_nonprimitive);

        list_addElement(managedFieldsList, managedFieldsItem);
    }
    }

    // v1_object_meta->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_object_meta->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }

    // v1_object_meta->ownerReferences
    cJSON *ownerReferences = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "ownerReferences");
    list_t *ownerReferencesList;
    if (ownerReferences) { 
    cJSON *ownerReferences_local_nonprimitive;
    if(!cJSON_IsArray(ownerReferences)){
        goto end; //nonprimitive container
    }

    ownerReferencesList = list_create();

    cJSON_ArrayForEach(ownerReferences_local_nonprimitive,ownerReferences )
    {
        if(!cJSON_IsObject(ownerReferences_local_nonprimitive)){
            goto end;
        }
        v1_owner_reference_t *ownerReferencesItem = v1_owner_reference_parseFromJSON(ownerReferences_local_nonprimitive);

        list_addElement(ownerReferencesList, ownerReferencesItem);
    }
    }

    // v1_object_meta->resourceVersion
    cJSON *resourceVersion = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "resourceVersion");
    if (resourceVersion) { 
    if(!cJSON_IsString(resourceVersion))
    {
    goto end; //String
    }
    }

    // v1_object_meta->selfLink
    cJSON *selfLink = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "selfLink");
    if (selfLink) { 
    if(!cJSON_IsString(selfLink))
    {
    goto end; //String
    }
    }

    // v1_object_meta->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_object_meta_local_var = v1_object_meta_create (
        annotations ? List : NULL,
        clusterName ? strdup(clusterName->valuestring) : NULL,
        creationTimestamp ? strdup(creationTimestamp->valuestring) : NULL,
        deletionGracePeriodSeconds ? deletionGracePeriodSeconds->valuedouble : 0,
        deletionTimestamp ? strdup(deletionTimestamp->valuestring) : NULL,
        finalizers ? finalizersList : NULL,
        generateName ? strdup(generateName->valuestring) : NULL,
        generation ? generation->valuedouble : 0,
        labels ? Listlabels : NULL,
        managedFields ? managedFieldsList : NULL,
        name ? strdup(name->valuestring) : NULL,
        namespace ? strdup(namespace->valuestring) : NULL,
        ownerReferences ? ownerReferencesList : NULL,
        resourceVersion ? strdup(resourceVersion->valuestring) : NULL,
        selfLink ? strdup(selfLink->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_object_meta_local_var;
end:
    return NULL;

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_event.h"



v1beta1_event_t *v1beta1_event_create(
    char *action,
    char *apiVersion,
    int deprecatedCount,
    char *deprecatedFirstTimestamp,
    char *deprecatedLastTimestamp,
    v1_event_source_t *deprecatedSource,
    char *eventTime,
    char *kind,
    v1_object_meta_t *metadata,
    char *note,
    char *reason,
    v1_object_reference_t *regarding,
    v1_object_reference_t *related,
    char *reportingController,
    char *reportingInstance,
    v1beta1_event_series_t *series,
    char *type
    ) {
	v1beta1_event_t *v1beta1_event_local_var = malloc(sizeof(v1beta1_event_t));
    if (!v1beta1_event_local_var) {
        return NULL;
    }
	v1beta1_event_local_var->action = action;
	v1beta1_event_local_var->apiVersion = apiVersion;
	v1beta1_event_local_var->deprecatedCount = deprecatedCount;
	v1beta1_event_local_var->deprecatedFirstTimestamp = deprecatedFirstTimestamp;
	v1beta1_event_local_var->deprecatedLastTimestamp = deprecatedLastTimestamp;
	v1beta1_event_local_var->deprecatedSource = deprecatedSource;
	v1beta1_event_local_var->eventTime = eventTime;
	v1beta1_event_local_var->kind = kind;
	v1beta1_event_local_var->metadata = metadata;
	v1beta1_event_local_var->note = note;
	v1beta1_event_local_var->reason = reason;
	v1beta1_event_local_var->regarding = regarding;
	v1beta1_event_local_var->related = related;
	v1beta1_event_local_var->reportingController = reportingController;
	v1beta1_event_local_var->reportingInstance = reportingInstance;
	v1beta1_event_local_var->series = series;
	v1beta1_event_local_var->type = type;

	return v1beta1_event_local_var;
}


void v1beta1_event_free(v1beta1_event_t *v1beta1_event) {
    listEntry_t *listEntry;
    free(v1beta1_event->action);
    free(v1beta1_event->apiVersion);
    free(v1beta1_event->deprecatedFirstTimestamp);
    free(v1beta1_event->deprecatedLastTimestamp);
    v1_event_source_free(v1beta1_event->deprecatedSource);
    free(v1beta1_event->eventTime);
    free(v1beta1_event->kind);
    v1_object_meta_free(v1beta1_event->metadata);
    free(v1beta1_event->note);
    free(v1beta1_event->reason);
    v1_object_reference_free(v1beta1_event->regarding);
    v1_object_reference_free(v1beta1_event->related);
    free(v1beta1_event->reportingController);
    free(v1beta1_event->reportingInstance);
    v1beta1_event_series_free(v1beta1_event->series);
    free(v1beta1_event->type);
	free(v1beta1_event);
}

cJSON *v1beta1_event_convertToJSON(v1beta1_event_t *v1beta1_event) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_event->action
    if(v1beta1_event->action) { 
    if(cJSON_AddStringToObject(item, "action", v1beta1_event->action) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->apiVersion
    if(v1beta1_event->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_event->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->deprecatedCount
    if(v1beta1_event->deprecatedCount) { 
    if(cJSON_AddNumberToObject(item, "deprecatedCount", v1beta1_event->deprecatedCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta1_event->deprecatedFirstTimestamp
    if(v1beta1_event->deprecatedFirstTimestamp) { 
    if(cJSON_AddStringToObject(item, "deprecatedFirstTimestamp", v1beta1_event->deprecatedFirstTimestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1beta1_event->deprecatedLastTimestamp
    if(v1beta1_event->deprecatedLastTimestamp) { 
    if(cJSON_AddStringToObject(item, "deprecatedLastTimestamp", v1beta1_event->deprecatedLastTimestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1beta1_event->deprecatedSource
    if(v1beta1_event->deprecatedSource) { 
    cJSON *deprecatedSource_local_JSON = v1_event_source_convertToJSON(v1beta1_event->deprecatedSource);
    if(deprecatedSource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deprecatedSource", deprecatedSource_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_event->eventTime
    if (!v1beta1_event->eventTime) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "eventTime", v1beta1_event->eventTime) == NULL) {
    goto fail; //Date-Time
    }


	// v1beta1_event->kind
    if(v1beta1_event->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_event->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->metadata
    if(v1beta1_event->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_event->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_event->note
    if(v1beta1_event->note) { 
    if(cJSON_AddStringToObject(item, "note", v1beta1_event->note) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->reason
    if(v1beta1_event->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1beta1_event->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->regarding
    if(v1beta1_event->regarding) { 
    cJSON *regarding_local_JSON = v1_object_reference_convertToJSON(v1beta1_event->regarding);
    if(regarding_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "regarding", regarding_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_event->related
    if(v1beta1_event->related) { 
    cJSON *related_local_JSON = v1_object_reference_convertToJSON(v1beta1_event->related);
    if(related_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "related", related_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_event->reportingController
    if(v1beta1_event->reportingController) { 
    if(cJSON_AddStringToObject(item, "reportingController", v1beta1_event->reportingController) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->reportingInstance
    if(v1beta1_event->reportingInstance) { 
    if(cJSON_AddStringToObject(item, "reportingInstance", v1beta1_event->reportingInstance) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_event->series
    if(v1beta1_event->series) { 
    cJSON *series_local_JSON = v1beta1_event_series_convertToJSON(v1beta1_event->series);
    if(series_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "series", series_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_event->type
    if(v1beta1_event->type) { 
    if(cJSON_AddStringToObject(item, "type", v1beta1_event->type) == NULL) {
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

v1beta1_event_t *v1beta1_event_parseFromJSON(cJSON *v1beta1_eventJSON){

    v1beta1_event_t *v1beta1_event_local_var = NULL;

    // v1beta1_event->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "action");
    if (action) { 
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }
    }

    // v1beta1_event->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_event->deprecatedCount
    cJSON *deprecatedCount = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedCount");
    if (deprecatedCount) { 
    if(!cJSON_IsNumber(deprecatedCount))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_event->deprecatedFirstTimestamp
    cJSON *deprecatedFirstTimestamp = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedFirstTimestamp");
    if (deprecatedFirstTimestamp) { 
    if(!cJSON_IsString(deprecatedFirstTimestamp))
    {
    goto end; //DateTime
    }
    }

    // v1beta1_event->deprecatedLastTimestamp
    cJSON *deprecatedLastTimestamp = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedLastTimestamp");
    if (deprecatedLastTimestamp) { 
    if(!cJSON_IsString(deprecatedLastTimestamp))
    {
    goto end; //DateTime
    }
    }

    // v1beta1_event->deprecatedSource
    cJSON *deprecatedSource = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "deprecatedSource");
    v1_event_source_t *deprecatedSource_local_nonprim = NULL;
    if (deprecatedSource) { 
    deprecatedSource_local_nonprim = v1_event_source_parseFromJSON(deprecatedSource); //nonprimitive
    }

    // v1beta1_event->eventTime
    cJSON *eventTime = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "eventTime");
    if (!eventTime) {
        goto end;
    }

    
    if(!cJSON_IsString(eventTime))
    {
    goto end; //DateTime
    }

    // v1beta1_event->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_event->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_event->note
    cJSON *note = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "note");
    if (note) { 
    if(!cJSON_IsString(note))
    {
    goto end; //String
    }
    }

    // v1beta1_event->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1beta1_event->regarding
    cJSON *regarding = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "regarding");
    v1_object_reference_t *regarding_local_nonprim = NULL;
    if (regarding) { 
    regarding_local_nonprim = v1_object_reference_parseFromJSON(regarding); //nonprimitive
    }

    // v1beta1_event->related
    cJSON *related = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "related");
    v1_object_reference_t *related_local_nonprim = NULL;
    if (related) { 
    related_local_nonprim = v1_object_reference_parseFromJSON(related); //nonprimitive
    }

    // v1beta1_event->reportingController
    cJSON *reportingController = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "reportingController");
    if (reportingController) { 
    if(!cJSON_IsString(reportingController))
    {
    goto end; //String
    }
    }

    // v1beta1_event->reportingInstance
    cJSON *reportingInstance = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "reportingInstance");
    if (reportingInstance) { 
    if(!cJSON_IsString(reportingInstance))
    {
    goto end; //String
    }
    }

    // v1beta1_event->series
    cJSON *series = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "series");
    v1beta1_event_series_t *series_local_nonprim = NULL;
    if (series) { 
    series_local_nonprim = v1beta1_event_series_parseFromJSON(series); //nonprimitive
    }

    // v1beta1_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta1_eventJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1beta1_event_local_var = v1beta1_event_create (
        action ? strdup(action->valuestring) : NULL,
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        deprecatedCount ? deprecatedCount->valuedouble : 0,
        deprecatedFirstTimestamp ? strdup(deprecatedFirstTimestamp->valuestring) : NULL,
        deprecatedLastTimestamp ? strdup(deprecatedLastTimestamp->valuestring) : NULL,
        deprecatedSource ? deprecatedSource_local_nonprim : NULL,
        strdup(eventTime->valuestring),
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        note ? strdup(note->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        regarding ? regarding_local_nonprim : NULL,
        related ? related_local_nonprim : NULL,
        reportingController ? strdup(reportingController->valuestring) : NULL,
        reportingInstance ? strdup(reportingInstance->valuestring) : NULL,
        series ? series_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1beta1_event_local_var;
end:
    return NULL;

}

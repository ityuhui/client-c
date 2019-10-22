#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_event.h"



v1_event_t *v1_event_create(
    char *action,
    char *apiVersion,
    int count,
    char *eventTime,
    char *firstTimestamp,
    v1_object_reference_t *involvedObject,
    char *kind,
    char *lastTimestamp,
    char *message,
    v1_object_meta_t *metadata,
    char *reason,
    v1_object_reference_t *related,
    char *reportingComponent,
    char *reportingInstance,
    v1_event_series_t *series,
    v1_event_source_t *source,
    char *type
    ) {
	v1_event_t *v1_event_local_var = malloc(sizeof(v1_event_t));
    if (!v1_event_local_var) {
        return NULL;
    }
	v1_event_local_var->action = action;
	v1_event_local_var->apiVersion = apiVersion;
	v1_event_local_var->count = count;
	v1_event_local_var->eventTime = eventTime;
	v1_event_local_var->firstTimestamp = firstTimestamp;
	v1_event_local_var->involvedObject = involvedObject;
	v1_event_local_var->kind = kind;
	v1_event_local_var->lastTimestamp = lastTimestamp;
	v1_event_local_var->message = message;
	v1_event_local_var->metadata = metadata;
	v1_event_local_var->reason = reason;
	v1_event_local_var->related = related;
	v1_event_local_var->reportingComponent = reportingComponent;
	v1_event_local_var->reportingInstance = reportingInstance;
	v1_event_local_var->series = series;
	v1_event_local_var->source = source;
	v1_event_local_var->type = type;

	return v1_event_local_var;
}


void v1_event_free(v1_event_t *v1_event) {
    listEntry_t *listEntry;
    free(v1_event->action);
    free(v1_event->apiVersion);
    free(v1_event->eventTime);
    free(v1_event->firstTimestamp);
    v1_object_reference_free(v1_event->involvedObject);
    free(v1_event->kind);
    free(v1_event->lastTimestamp);
    free(v1_event->message);
    v1_object_meta_free(v1_event->metadata);
    free(v1_event->reason);
    v1_object_reference_free(v1_event->related);
    free(v1_event->reportingComponent);
    free(v1_event->reportingInstance);
    v1_event_series_free(v1_event->series);
    v1_event_source_free(v1_event->source);
    free(v1_event->type);
	free(v1_event);
}

cJSON *v1_event_convertToJSON(v1_event_t *v1_event) {
	cJSON *item = cJSON_CreateObject();

	// v1_event->action
    if(v1_event->action) { 
    if(cJSON_AddStringToObject(item, "action", v1_event->action) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->apiVersion
    if(v1_event->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_event->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->count
    if(v1_event->count) { 
    if(cJSON_AddNumberToObject(item, "count", v1_event->count) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_event->eventTime
    if(v1_event->eventTime) { 
    if(cJSON_AddStringToObject(item, "eventTime", v1_event->eventTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_event->firstTimestamp
    if(v1_event->firstTimestamp) { 
    if(cJSON_AddStringToObject(item, "firstTimestamp", v1_event->firstTimestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_event->involvedObject
    if (!v1_event->involvedObject) {
        goto fail;
    }
    
    cJSON *involvedObject_local_JSON = v1_object_reference_convertToJSON(v1_event->involvedObject);
    if(involvedObject_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "involvedObject", involvedObject_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_event->kind
    if(v1_event->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_event->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->lastTimestamp
    if(v1_event->lastTimestamp) { 
    if(cJSON_AddStringToObject(item, "lastTimestamp", v1_event->lastTimestamp) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_event->message
    if(v1_event->message) { 
    if(cJSON_AddStringToObject(item, "message", v1_event->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->metadata
    if (!v1_event->metadata) {
        goto fail;
    }
    
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_event->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_event->reason
    if(v1_event->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_event->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->related
    if(v1_event->related) { 
    cJSON *related_local_JSON = v1_object_reference_convertToJSON(v1_event->related);
    if(related_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "related", related_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_event->reportingComponent
    if(v1_event->reportingComponent) { 
    if(cJSON_AddStringToObject(item, "reportingComponent", v1_event->reportingComponent) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->reportingInstance
    if(v1_event->reportingInstance) { 
    if(cJSON_AddStringToObject(item, "reportingInstance", v1_event->reportingInstance) == NULL) {
    goto fail; //String
    }
     } 


	// v1_event->series
    if(v1_event->series) { 
    cJSON *series_local_JSON = v1_event_series_convertToJSON(v1_event->series);
    if(series_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "series", series_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_event->source
    if(v1_event->source) { 
    cJSON *source_local_JSON = v1_event_source_convertToJSON(v1_event->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_event->type
    if(v1_event->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_event->type) == NULL) {
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

v1_event_t *v1_event_parseFromJSON(cJSON *v1_eventJSON){

    v1_event_t *v1_event_local_var = NULL;

    // v1_event->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "action");
    if (action) { 
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }
    }

    // v1_event->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_event->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // v1_event->eventTime
    cJSON *eventTime = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "eventTime");
    if (eventTime) { 
    if(!cJSON_IsString(eventTime))
    {
    goto end; //DateTime
    }
    }

    // v1_event->firstTimestamp
    cJSON *firstTimestamp = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "firstTimestamp");
    if (firstTimestamp) { 
    if(!cJSON_IsString(firstTimestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_event->involvedObject
    cJSON *involvedObject = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "involvedObject");
    if (!involvedObject) {
        goto end;
    }

    v1_object_reference_t *involvedObject_local_nonprim = NULL;
    
    involvedObject_local_nonprim = v1_object_reference_parseFromJSON(involvedObject); //nonprimitive

    // v1_event->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_event->lastTimestamp
    cJSON *lastTimestamp = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "lastTimestamp");
    if (lastTimestamp) { 
    if(!cJSON_IsString(lastTimestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_event->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_event->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "metadata");
    if (!metadata) {
        goto end;
    }

    v1_object_meta_t *metadata_local_nonprim = NULL;
    
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive

    // v1_event->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_event->related
    cJSON *related = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "related");
    v1_object_reference_t *related_local_nonprim = NULL;
    if (related) { 
    related_local_nonprim = v1_object_reference_parseFromJSON(related); //nonprimitive
    }

    // v1_event->reportingComponent
    cJSON *reportingComponent = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "reportingComponent");
    if (reportingComponent) { 
    if(!cJSON_IsString(reportingComponent))
    {
    goto end; //String
    }
    }

    // v1_event->reportingInstance
    cJSON *reportingInstance = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "reportingInstance");
    if (reportingInstance) { 
    if(!cJSON_IsString(reportingInstance))
    {
    goto end; //String
    }
    }

    // v1_event->series
    cJSON *series = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "series");
    v1_event_series_t *series_local_nonprim = NULL;
    if (series) { 
    series_local_nonprim = v1_event_series_parseFromJSON(series); //nonprimitive
    }

    // v1_event->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "source");
    v1_event_source_t *source_local_nonprim = NULL;
    if (source) { 
    source_local_nonprim = v1_event_source_parseFromJSON(source); //nonprimitive
    }

    // v1_event->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_eventJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_event_local_var = v1_event_create (
        action ? strdup(action->valuestring) : NULL,
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        count ? count->valuedouble : 0,
        eventTime ? strdup(eventTime->valuestring) : NULL,
        firstTimestamp ? strdup(firstTimestamp->valuestring) : NULL,
        involvedObject_local_nonprim,
        kind ? strdup(kind->valuestring) : NULL,
        lastTimestamp ? strdup(lastTimestamp->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        metadata_local_nonprim,
        reason ? strdup(reason->valuestring) : NULL,
        related ? related_local_nonprim : NULL,
        reportingComponent ? strdup(reportingComponent->valuestring) : NULL,
        reportingInstance ? strdup(reportingInstance->valuestring) : NULL,
        series ? series_local_nonprim : NULL,
        source ? source_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_event_local_var;
end:
    return NULL;

}

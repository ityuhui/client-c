#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_event_series.h"



v1_event_series_t *v1_event_series_create(
    int count,
    char *lastObservedTime,
    char *state
    ) {
	v1_event_series_t *v1_event_series_local_var = malloc(sizeof(v1_event_series_t));
    if (!v1_event_series_local_var) {
        return NULL;
    }
	v1_event_series_local_var->count = count;
	v1_event_series_local_var->lastObservedTime = lastObservedTime;
	v1_event_series_local_var->state = state;

	return v1_event_series_local_var;
}


void v1_event_series_free(v1_event_series_t *v1_event_series) {
    listEntry_t *listEntry;
    free(v1_event_series->lastObservedTime);
    free(v1_event_series->state);
	free(v1_event_series);
}

cJSON *v1_event_series_convertToJSON(v1_event_series_t *v1_event_series) {
	cJSON *item = cJSON_CreateObject();

	// v1_event_series->count
    if(v1_event_series->count) { 
    if(cJSON_AddNumberToObject(item, "count", v1_event_series->count) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_event_series->lastObservedTime
    if(v1_event_series->lastObservedTime) { 
    if(cJSON_AddStringToObject(item, "lastObservedTime", v1_event_series->lastObservedTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_event_series->state
    if(v1_event_series->state) { 
    if(cJSON_AddStringToObject(item, "state", v1_event_series->state) == NULL) {
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

v1_event_series_t *v1_event_series_parseFromJSON(cJSON *v1_event_seriesJSON){

    v1_event_series_t *v1_event_series_local_var = NULL;

    // v1_event_series->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(v1_event_seriesJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // v1_event_series->lastObservedTime
    cJSON *lastObservedTime = cJSON_GetObjectItemCaseSensitive(v1_event_seriesJSON, "lastObservedTime");
    if (lastObservedTime) { 
    if(!cJSON_IsString(lastObservedTime))
    {
    goto end; //DateTime
    }
    }

    // v1_event_series->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(v1_event_seriesJSON, "state");
    if (state) { 
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }
    }


    v1_event_series_local_var = v1_event_series_create (
        count ? count->valuedouble : 0,
        lastObservedTime ? strdup(lastObservedTime->valuestring) : NULL,
        state ? strdup(state->valuestring) : NULL
        );

    return v1_event_series_local_var;
end:
    return NULL;

}

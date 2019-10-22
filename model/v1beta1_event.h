/*
 * v1beta1_event.h
 *
 * Event is a report of an event somewhere in the cluster. It generally denotes some state change in the system.
 */

#ifndef _v1beta1_event_H_
#define _v1beta1_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_event_source.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"
#include "v1beta1_event_series.h"



typedef struct v1beta1_event_t {
    char *action; // string
    char *apiVersion; // string
    int deprecatedCount; //numeric
    char *deprecatedFirstTimestamp; //date time
    char *deprecatedLastTimestamp; //date time
    v1_event_source_t *deprecatedSource; //model
    char *eventTime; //date time
    char *kind; // string
    v1_object_meta_t *metadata; //model
    char *note; // string
    char *reason; // string
    v1_object_reference_t *regarding; //model
    v1_object_reference_t *related; //model
    char *reportingController; // string
    char *reportingInstance; // string
    v1beta1_event_series_t *series; //model
    char *type; // string

} v1beta1_event_t;

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
);

void v1beta1_event_free(v1beta1_event_t *v1beta1_event);

v1beta1_event_t *v1beta1_event_parseFromJSON(cJSON *v1beta1_eventJSON);

cJSON *v1beta1_event_convertToJSON(v1beta1_event_t *v1beta1_event);

#endif /* _v1beta1_event_H_ */


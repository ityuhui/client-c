/*
 * v1_event.h
 *
 * Event is a report of an event somewhere in the cluster.
 */

#ifndef _v1_event_H_
#define _v1_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_event_series.h"
#include "v1_event_source.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"



typedef struct v1_event_t {
    char *action; // string
    char *apiVersion; // string
    int count; //numeric
    char *eventTime; //date time
    char *firstTimestamp; //date time
    v1_object_reference_t *involvedObject; //model
    char *kind; // string
    char *lastTimestamp; //date time
    char *message; // string
    v1_object_meta_t *metadata; //model
    char *reason; // string
    v1_object_reference_t *related; //model
    char *reportingComponent; // string
    char *reportingInstance; // string
    v1_event_series_t *series; //model
    v1_event_source_t *source; //model
    char *type; // string

} v1_event_t;

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
);

void v1_event_free(v1_event_t *v1_event);

v1_event_t *v1_event_parseFromJSON(cJSON *v1_eventJSON);

cJSON *v1_event_convertToJSON(v1_event_t *v1_event);

#endif /* _v1_event_H_ */


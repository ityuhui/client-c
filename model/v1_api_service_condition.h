/*
 * v1_api_service_condition.h
 *
 * APIServiceCondition describes the state of an APIService at a particular point
 */

#ifndef _v1_api_service_condition_H_
#define _v1_api_service_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_api_service_condition_t {
    char *lastTransitionTime; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_api_service_condition_t;

v1_api_service_condition_t *v1_api_service_condition_create(
    char *lastTransitionTime,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_api_service_condition_free(v1_api_service_condition_t *v1_api_service_condition);

v1_api_service_condition_t *v1_api_service_condition_parseFromJSON(cJSON *v1_api_service_conditionJSON);

cJSON *v1_api_service_condition_convertToJSON(v1_api_service_condition_t *v1_api_service_condition);

#endif /* _v1_api_service_condition_H_ */


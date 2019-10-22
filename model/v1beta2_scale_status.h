/*
 * v1beta2_scale_status.h
 *
 * ScaleStatus represents the current status of a scale subresource.
 */

#ifndef _v1beta2_scale_status_H_
#define _v1beta2_scale_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta2_scale_status_t {
    int replicas; //numeric
    list_t* selector; //map
    char *targetSelector; // string

} v1beta2_scale_status_t;

v1beta2_scale_status_t *v1beta2_scale_status_create(
    int replicas,
    list_t* selector,
    char *targetSelector
);

void v1beta2_scale_status_free(v1beta2_scale_status_t *v1beta2_scale_status);

v1beta2_scale_status_t *v1beta2_scale_status_parseFromJSON(cJSON *v1beta2_scale_statusJSON);

cJSON *v1beta2_scale_status_convertToJSON(v1beta2_scale_status_t *v1beta2_scale_status);

#endif /* _v1beta2_scale_status_H_ */


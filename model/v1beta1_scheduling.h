/*
 * v1beta1_scheduling.h
 *
 * Scheduling specifies the scheduling constraints for nodes supporting a RuntimeClass.
 */

#ifndef _v1beta1_scheduling_H_
#define _v1beta1_scheduling_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_toleration.h"



typedef struct v1beta1_scheduling_t {
    list_t* nodeSelector; //map
    list_t *tolerations; //nonprimitive container

} v1beta1_scheduling_t;

v1beta1_scheduling_t *v1beta1_scheduling_create(
    list_t* nodeSelector,
    list_t *tolerations
);

void v1beta1_scheduling_free(v1beta1_scheduling_t *v1beta1_scheduling);

v1beta1_scheduling_t *v1beta1_scheduling_parseFromJSON(cJSON *v1beta1_schedulingJSON);

cJSON *v1beta1_scheduling_convertToJSON(v1beta1_scheduling_t *v1beta1_scheduling);

#endif /* _v1beta1_scheduling_H_ */


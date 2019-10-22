/*
 * v1alpha1_endpoint_conditions.h
 *
 * EndpointConditions represents the current condition of an endpoint.
 */

#ifndef _v1alpha1_endpoint_conditions_H_
#define _v1alpha1_endpoint_conditions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1alpha1_endpoint_conditions_t {
    int ready; //boolean

} v1alpha1_endpoint_conditions_t;

v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions_create(
    int ready
);

void v1alpha1_endpoint_conditions_free(v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions);

v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions_parseFromJSON(cJSON *v1alpha1_endpoint_conditionsJSON);

cJSON *v1alpha1_endpoint_conditions_convertToJSON(v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions);

#endif /* _v1alpha1_endpoint_conditions_H_ */


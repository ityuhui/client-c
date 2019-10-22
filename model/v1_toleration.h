/*
 * v1_toleration.h
 *
 * The pod this Toleration is attached to tolerates any taint that matches the triple &lt;key,value,effect&gt; using the matching operator &lt;operator&gt;.
 */

#ifndef _v1_toleration_H_
#define _v1_toleration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_toleration_t {
    char *effect; // string
    char *key; // string
    char *operator; // string
    long tolerationSeconds; //numeric
    char *value; // string

} v1_toleration_t;

v1_toleration_t *v1_toleration_create(
    char *effect,
    char *key,
    char *operator,
    long tolerationSeconds,
    char *value
);

void v1_toleration_free(v1_toleration_t *v1_toleration);

v1_toleration_t *v1_toleration_parseFromJSON(cJSON *v1_tolerationJSON);

cJSON *v1_toleration_convertToJSON(v1_toleration_t *v1_toleration);

#endif /* _v1_toleration_H_ */


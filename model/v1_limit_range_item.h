/*
 * v1_limit_range_item.h
 *
 * LimitRangeItem defines a min/max usage limit for any resource that matches on kind.
 */

#ifndef _v1_limit_range_item_H_
#define _v1_limit_range_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_limit_range_item_t {
    list_t* default_; //map
    list_t* defaultRequest; //map
    list_t* max; //map
    list_t* maxLimitRequestRatio; //map
    list_t* min; //map
    char *type; // string

} v1_limit_range_item_t;

v1_limit_range_item_t *v1_limit_range_item_create(
    list_t* default_,
    list_t* defaultRequest,
    list_t* max,
    list_t* maxLimitRequestRatio,
    list_t* min,
    char *type
);

void v1_limit_range_item_free(v1_limit_range_item_t *v1_limit_range_item);

v1_limit_range_item_t *v1_limit_range_item_parseFromJSON(cJSON *v1_limit_range_itemJSON);

cJSON *v1_limit_range_item_convertToJSON(v1_limit_range_item_t *v1_limit_range_item);

#endif /* _v1_limit_range_item_H_ */


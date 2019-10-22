/*
 * v1_list_meta.h
 *
 * ListMeta describes metadata that synthetic resources must have, including lists and various status objects. A resource may have only one of {ObjectMeta, ListMeta}.
 */

#ifndef _v1_list_meta_H_
#define _v1_list_meta_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_list_meta_t {
    char *continue_; // string
    long remainingItemCount; //numeric
    char *resourceVersion; // string
    char *selfLink; // string

} v1_list_meta_t;

v1_list_meta_t *v1_list_meta_create(
    char *continue_,
    long remainingItemCount,
    char *resourceVersion,
    char *selfLink
);

void v1_list_meta_free(v1_list_meta_t *v1_list_meta);

v1_list_meta_t *v1_list_meta_parseFromJSON(cJSON *v1_list_metaJSON);

cJSON *v1_list_meta_convertToJSON(v1_list_meta_t *v1_list_meta);

#endif /* _v1_list_meta_H_ */


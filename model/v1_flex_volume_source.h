/*
 * v1_flex_volume_source.h
 *
 * FlexVolume represents a generic volume resource that is provisioned/attached using an exec based plugin.
 */

#ifndef _v1_flex_volume_source_H_
#define _v1_flex_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_local_object_reference.h"



typedef struct v1_flex_volume_source_t {
    char *driver; // string
    char *fsType; // string
    list_t* options; //map
    int readOnly; //boolean
    v1_local_object_reference_t *secretRef; //model

} v1_flex_volume_source_t;

v1_flex_volume_source_t *v1_flex_volume_source_create(
    char *driver,
    char *fsType,
    list_t* options,
    int readOnly,
    v1_local_object_reference_t *secretRef
);

void v1_flex_volume_source_free(v1_flex_volume_source_t *v1_flex_volume_source);

v1_flex_volume_source_t *v1_flex_volume_source_parseFromJSON(cJSON *v1_flex_volume_sourceJSON);

cJSON *v1_flex_volume_source_convertToJSON(v1_flex_volume_source_t *v1_flex_volume_source);

#endif /* _v1_flex_volume_source_H_ */


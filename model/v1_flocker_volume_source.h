/*
 * v1_flocker_volume_source.h
 *
 * Represents a Flocker volume mounted by the Flocker agent. One and only one of datasetName and datasetUUID should be set. Flocker volumes do not_ support ownership management or SELinux relabeling.
 */

#ifndef _v1_flocker_volume_source_H_
#define _v1_flocker_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_flocker_volume_source_t {
    char *datasetName; // string
    char *datasetUUID; // string

} v1_flocker_volume_source_t;

v1_flocker_volume_source_t *v1_flocker_volume_source_create(
    char *datasetName,
    char *datasetUUID
);

void v1_flocker_volume_source_free(v1_flocker_volume_source_t *v1_flocker_volume_source);

v1_flocker_volume_source_t *v1_flocker_volume_source_parseFromJSON(cJSON *v1_flocker_volume_sourceJSON);

cJSON *v1_flocker_volume_source_convertToJSON(v1_flocker_volume_source_t *v1_flocker_volume_source);

#endif /* _v1_flocker_volume_source_H_ */


/*
 * v1_projected_volume_source.h
 *
 * Represents a projected volume source
 */

#ifndef _v1_projected_volume_source_H_
#define _v1_projected_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_volume_projection.h"



typedef struct v1_projected_volume_source_t {
    int defaultMode; //numeric
    list_t *sources; //nonprimitive container

} v1_projected_volume_source_t;

v1_projected_volume_source_t *v1_projected_volume_source_create(
    int defaultMode,
    list_t *sources
);

void v1_projected_volume_source_free(v1_projected_volume_source_t *v1_projected_volume_source);

v1_projected_volume_source_t *v1_projected_volume_source_parseFromJSON(cJSON *v1_projected_volume_sourceJSON);

cJSON *v1_projected_volume_source_convertToJSON(v1_projected_volume_source_t *v1_projected_volume_source);

#endif /* _v1_projected_volume_source_H_ */


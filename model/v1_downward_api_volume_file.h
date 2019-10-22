/*
 * v1_downward_api_volume_file.h
 *
 * DownwardAPIVolumeFile represents information to create the file containing the pod field
 */

#ifndef _v1_downward_api_volume_file_H_
#define _v1_downward_api_volume_file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_field_selector.h"
#include "v1_resource_field_selector.h"



typedef struct v1_downward_api_volume_file_t {
    v1_object_field_selector_t *fieldRef; //model
    int mode; //numeric
    char *path; // string
    v1_resource_field_selector_t *resourceFieldRef; //model

} v1_downward_api_volume_file_t;

v1_downward_api_volume_file_t *v1_downward_api_volume_file_create(
    v1_object_field_selector_t *fieldRef,
    int mode,
    char *path,
    v1_resource_field_selector_t *resourceFieldRef
);

void v1_downward_api_volume_file_free(v1_downward_api_volume_file_t *v1_downward_api_volume_file);

v1_downward_api_volume_file_t *v1_downward_api_volume_file_parseFromJSON(cJSON *v1_downward_api_volume_fileJSON);

cJSON *v1_downward_api_volume_file_convertToJSON(v1_downward_api_volume_file_t *v1_downward_api_volume_file);

#endif /* _v1_downward_api_volume_file_H_ */


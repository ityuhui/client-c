/*
 * v1_custom_resource_subresource_scale.h
 *
 * CustomResourceSubresourceScale defines how to serve the scale subresource for CustomResources.
 */

#ifndef _v1_custom_resource_subresource_scale_H_
#define _v1_custom_resource_subresource_scale_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_custom_resource_subresource_scale_t {
    char *labelSelectorPath; // string
    char *specReplicasPath; // string
    char *statusReplicasPath; // string

} v1_custom_resource_subresource_scale_t;

v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_create(
    char *labelSelectorPath,
    char *specReplicasPath,
    char *statusReplicasPath
);

void v1_custom_resource_subresource_scale_free(v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale);

v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale_parseFromJSON(cJSON *v1_custom_resource_subresource_scaleJSON);

cJSON *v1_custom_resource_subresource_scale_convertToJSON(v1_custom_resource_subresource_scale_t *v1_custom_resource_subresource_scale);

#endif /* _v1_custom_resource_subresource_scale_H_ */


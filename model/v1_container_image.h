/*
 * v1_container_image.h
 *
 * Describe a container image
 */

#ifndef _v1_container_image_H_
#define _v1_container_image_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_container_image_t {
    list_t *names; //primitive container
    long sizeBytes; //numeric

} v1_container_image_t;

v1_container_image_t *v1_container_image_create(
    list_t *names,
    long sizeBytes
);

void v1_container_image_free(v1_container_image_t *v1_container_image);

v1_container_image_t *v1_container_image_parseFromJSON(cJSON *v1_container_imageJSON);

cJSON *v1_container_image_convertToJSON(v1_container_image_t *v1_container_image);

#endif /* _v1_container_image_H_ */


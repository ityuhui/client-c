/*
 * v1beta1_volume_attachment_status.h
 *
 * VolumeAttachmentStatus is the status of a VolumeAttachment request.
 */

#ifndef _v1beta1_volume_attachment_status_H_
#define _v1beta1_volume_attachment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_volume_error.h"



typedef struct v1beta1_volume_attachment_status_t {
    v1beta1_volume_error_t *attachError; //model
    int attached; //boolean
    list_t* attachmentMetadata; //map
    v1beta1_volume_error_t *detachError; //model

} v1beta1_volume_attachment_status_t;

v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status_create(
    v1beta1_volume_error_t *attachError,
    int attached,
    list_t* attachmentMetadata,
    v1beta1_volume_error_t *detachError
);

void v1beta1_volume_attachment_status_free(v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status);

v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status_parseFromJSON(cJSON *v1beta1_volume_attachment_statusJSON);

cJSON *v1beta1_volume_attachment_status_convertToJSON(v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status);

#endif /* _v1beta1_volume_attachment_status_H_ */


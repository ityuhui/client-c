/*
 * v1alpha1_volume_attachment_status.h
 *
 * VolumeAttachmentStatus is the status of a VolumeAttachment request.
 */

#ifndef _v1alpha1_volume_attachment_status_H_
#define _v1alpha1_volume_attachment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1alpha1_volume_error.h"



typedef struct v1alpha1_volume_attachment_status_t {
    v1alpha1_volume_error_t *attachError; //model
    int attached; //boolean
    list_t* attachmentMetadata; //map
    v1alpha1_volume_error_t *detachError; //model

} v1alpha1_volume_attachment_status_t;

v1alpha1_volume_attachment_status_t *v1alpha1_volume_attachment_status_create(
    v1alpha1_volume_error_t *attachError,
    int attached,
    list_t* attachmentMetadata,
    v1alpha1_volume_error_t *detachError
);

void v1alpha1_volume_attachment_status_free(v1alpha1_volume_attachment_status_t *v1alpha1_volume_attachment_status);

v1alpha1_volume_attachment_status_t *v1alpha1_volume_attachment_status_parseFromJSON(cJSON *v1alpha1_volume_attachment_statusJSON);

cJSON *v1alpha1_volume_attachment_status_convertToJSON(v1alpha1_volume_attachment_status_t *v1alpha1_volume_attachment_status);

#endif /* _v1alpha1_volume_attachment_status_H_ */


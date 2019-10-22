/*
 * v1beta1_volume_attachment_spec.h
 *
 * VolumeAttachmentSpec is the specification of a VolumeAttachment request.
 */

#ifndef _v1beta1_volume_attachment_spec_H_
#define _v1beta1_volume_attachment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_volume_attachment_source.h"



typedef struct v1beta1_volume_attachment_spec_t {
    char *attacher; // string
    char *nodeName; // string
    v1beta1_volume_attachment_source_t *source; //model

} v1beta1_volume_attachment_spec_t;

v1beta1_volume_attachment_spec_t *v1beta1_volume_attachment_spec_create(
    char *attacher,
    char *nodeName,
    v1beta1_volume_attachment_source_t *source
);

void v1beta1_volume_attachment_spec_free(v1beta1_volume_attachment_spec_t *v1beta1_volume_attachment_spec);

v1beta1_volume_attachment_spec_t *v1beta1_volume_attachment_spec_parseFromJSON(cJSON *v1beta1_volume_attachment_specJSON);

cJSON *v1beta1_volume_attachment_spec_convertToJSON(v1beta1_volume_attachment_spec_t *v1beta1_volume_attachment_spec);

#endif /* _v1beta1_volume_attachment_spec_H_ */


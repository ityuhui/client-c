/*
 * v1_volume_attachment_spec.h
 *
 * VolumeAttachmentSpec is the specification of a VolumeAttachment request.
 */

#ifndef _v1_volume_attachment_spec_H_
#define _v1_volume_attachment_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_volume_attachment_source.h"



typedef struct v1_volume_attachment_spec_t {
    char *attacher; // string
    char *nodeName; // string
    v1_volume_attachment_source_t *source; //model

} v1_volume_attachment_spec_t;

v1_volume_attachment_spec_t *v1_volume_attachment_spec_create(
    char *attacher,
    char *nodeName,
    v1_volume_attachment_source_t *source
);

void v1_volume_attachment_spec_free(v1_volume_attachment_spec_t *v1_volume_attachment_spec);

v1_volume_attachment_spec_t *v1_volume_attachment_spec_parseFromJSON(cJSON *v1_volume_attachment_specJSON);

cJSON *v1_volume_attachment_spec_convertToJSON(v1_volume_attachment_spec_t *v1_volume_attachment_spec);

#endif /* _v1_volume_attachment_spec_H_ */


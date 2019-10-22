/*
 * v1beta1_volume_attachment_source.h
 *
 * VolumeAttachmentSource represents a volume that should be attached. Right now only PersistenVolumes can be attached via external attacher, in future we may allow also inline volumes in pods. Exactly one member can be set.
 */

#ifndef _v1beta1_volume_attachment_source_H_
#define _v1beta1_volume_attachment_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_persistent_volume_spec.h"



typedef struct v1beta1_volume_attachment_source_t {
    v1_persistent_volume_spec_t *inlineVolumeSpec; //model
    char *persistentVolumeName; // string

} v1beta1_volume_attachment_source_t;

v1beta1_volume_attachment_source_t *v1beta1_volume_attachment_source_create(
    v1_persistent_volume_spec_t *inlineVolumeSpec,
    char *persistentVolumeName
);

void v1beta1_volume_attachment_source_free(v1beta1_volume_attachment_source_t *v1beta1_volume_attachment_source);

v1beta1_volume_attachment_source_t *v1beta1_volume_attachment_source_parseFromJSON(cJSON *v1beta1_volume_attachment_sourceJSON);

cJSON *v1beta1_volume_attachment_source_convertToJSON(v1beta1_volume_attachment_source_t *v1beta1_volume_attachment_source);

#endif /* _v1beta1_volume_attachment_source_H_ */


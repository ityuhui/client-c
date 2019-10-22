/*
 * v1_aws_elastic_block_store_volume_source.h
 *
 * Represents a Persistent Disk resource in AWS.  An AWS EBS disk must exist before mounting to a container. The disk must also be in the same AWS zone as the kubelet. An AWS EBS disk can only be mounted as read/write once. AWS EBS volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_aws_elastic_block_store_volume_source_H_
#define _v1_aws_elastic_block_store_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_aws_elastic_block_store_volume_source_t {
    char *fsType; // string
    int partition; //numeric
    int readOnly; //boolean
    char *volumeID; // string

} v1_aws_elastic_block_store_volume_source_t;

v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_create(
    char *fsType,
    int partition,
    int readOnly,
    char *volumeID
);

void v1_aws_elastic_block_store_volume_source_free(v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source);

v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_parseFromJSON(cJSON *v1_aws_elastic_block_store_volume_sourceJSON);

cJSON *v1_aws_elastic_block_store_volume_source_convertToJSON(v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source);

#endif /* _v1_aws_elastic_block_store_volume_source_H_ */


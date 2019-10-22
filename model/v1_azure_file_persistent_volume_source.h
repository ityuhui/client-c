/*
 * v1_azure_file_persistent_volume_source.h
 *
 * AzureFile represents an Azure File Service mount on the host and bind mount to the pod.
 */

#ifndef _v1_azure_file_persistent_volume_source_H_
#define _v1_azure_file_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_azure_file_persistent_volume_source_t {
    int readOnly; //boolean
    char *secretName; // string
    char *secretNamespace; // string
    char *shareName; // string

} v1_azure_file_persistent_volume_source_t;

v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_create(
    int readOnly,
    char *secretName,
    char *secretNamespace,
    char *shareName
);

void v1_azure_file_persistent_volume_source_free(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source);

v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_parseFromJSON(cJSON *v1_azure_file_persistent_volume_sourceJSON);

cJSON *v1_azure_file_persistent_volume_source_convertToJSON(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source);

#endif /* _v1_azure_file_persistent_volume_source_H_ */


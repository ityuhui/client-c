/*
 * v1_volume.h
 *
 * Volume represents a named volume in a pod that may be accessed by any container in the pod.
 */

#ifndef _v1_volume_H_
#define _v1_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_aws_elastic_block_store_volume_source.h"
#include "v1_azure_disk_volume_source.h"
#include "v1_azure_file_volume_source.h"
#include "v1_ceph_fs_volume_source.h"
#include "v1_cinder_volume_source.h"
#include "v1_config_map_volume_source.h"
#include "v1_csi_volume_source.h"
#include "v1_downward_api_volume_source.h"
#include "v1_empty_dir_volume_source.h"
#include "v1_fc_volume_source.h"
#include "v1_flex_volume_source.h"
#include "v1_flocker_volume_source.h"
#include "v1_gce_persistent_disk_volume_source.h"
#include "v1_git_repo_volume_source.h"
#include "v1_glusterfs_volume_source.h"
#include "v1_host_path_volume_source.h"
#include "v1_iscsi_volume_source.h"
#include "v1_nfs_volume_source.h"
#include "v1_persistent_volume_claim_volume_source.h"
#include "v1_photon_persistent_disk_volume_source.h"
#include "v1_portworx_volume_source.h"
#include "v1_projected_volume_source.h"
#include "v1_quobyte_volume_source.h"
#include "v1_rbd_volume_source.h"
#include "v1_scale_io_volume_source.h"
#include "v1_secret_volume_source.h"
#include "v1_storage_os_volume_source.h"
#include "v1_vsphere_virtual_disk_volume_source.h"



typedef struct v1_volume_t {
    v1_aws_elastic_block_store_volume_source_t *awsElasticBlockStore; //model
    v1_azure_disk_volume_source_t *azureDisk; //model
    v1_azure_file_volume_source_t *azureFile; //model
    v1_ceph_fs_volume_source_t *cephfs; //model
    v1_cinder_volume_source_t *cinder; //model
    v1_config_map_volume_source_t *configMap; //model
    v1_csi_volume_source_t *csi; //model
    v1_downward_api_volume_source_t *downwardAPI; //model
    v1_empty_dir_volume_source_t *emptyDir; //model
    v1_fc_volume_source_t *fc; //model
    v1_flex_volume_source_t *flexVolume; //model
    v1_flocker_volume_source_t *flocker; //model
    v1_gce_persistent_disk_volume_source_t *gcePersistentDisk; //model
    v1_git_repo_volume_source_t *gitRepo; //model
    v1_glusterfs_volume_source_t *glusterfs; //model
    v1_host_path_volume_source_t *hostPath; //model
    v1_iscsi_volume_source_t *iscsi; //model
    char *name; // string
    v1_nfs_volume_source_t *nfs; //model
    v1_persistent_volume_claim_volume_source_t *persistentVolumeClaim; //model
    v1_photon_persistent_disk_volume_source_t *photonPersistentDisk; //model
    v1_portworx_volume_source_t *portworxVolume; //model
    v1_projected_volume_source_t *projected; //model
    v1_quobyte_volume_source_t *quobyte; //model
    v1_rbd_volume_source_t *rbd; //model
    v1_scale_io_volume_source_t *scaleIO; //model
    v1_secret_volume_source_t *secret; //model
    v1_storage_os_volume_source_t *storageos; //model
    v1_vsphere_virtual_disk_volume_source_t *vsphereVolume; //model

} v1_volume_t;

v1_volume_t *v1_volume_create(
    v1_aws_elastic_block_store_volume_source_t *awsElasticBlockStore,
    v1_azure_disk_volume_source_t *azureDisk,
    v1_azure_file_volume_source_t *azureFile,
    v1_ceph_fs_volume_source_t *cephfs,
    v1_cinder_volume_source_t *cinder,
    v1_config_map_volume_source_t *configMap,
    v1_csi_volume_source_t *csi,
    v1_downward_api_volume_source_t *downwardAPI,
    v1_empty_dir_volume_source_t *emptyDir,
    v1_fc_volume_source_t *fc,
    v1_flex_volume_source_t *flexVolume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gcePersistentDisk,
    v1_git_repo_volume_source_t *gitRepo,
    v1_glusterfs_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *hostPath,
    v1_iscsi_volume_source_t *iscsi,
    char *name,
    v1_nfs_volume_source_t *nfs,
    v1_persistent_volume_claim_volume_source_t *persistentVolumeClaim,
    v1_photon_persistent_disk_volume_source_t *photonPersistentDisk,
    v1_portworx_volume_source_t *portworxVolume,
    v1_projected_volume_source_t *projected,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_volume_source_t *rbd,
    v1_scale_io_volume_source_t *scaleIO,
    v1_secret_volume_source_t *secret,
    v1_storage_os_volume_source_t *storageos,
    v1_vsphere_virtual_disk_volume_source_t *vsphereVolume
);

void v1_volume_free(v1_volume_t *v1_volume);

v1_volume_t *v1_volume_parseFromJSON(cJSON *v1_volumeJSON);

cJSON *v1_volume_convertToJSON(v1_volume_t *v1_volume);

#endif /* _v1_volume_H_ */


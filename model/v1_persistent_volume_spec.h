/*
 * v1_persistent_volume_spec.h
 *
 * PersistentVolumeSpec is the specification of a persistent volume.
 */

#ifndef _v1_persistent_volume_spec_H_
#define _v1_persistent_volume_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_aws_elastic_block_store_volume_source.h"
#include "v1_azure_disk_volume_source.h"
#include "v1_azure_file_persistent_volume_source.h"
#include "v1_ceph_fs_persistent_volume_source.h"
#include "v1_cinder_persistent_volume_source.h"
#include "v1_csi_persistent_volume_source.h"
#include "v1_fc_volume_source.h"
#include "v1_flex_persistent_volume_source.h"
#include "v1_flocker_volume_source.h"
#include "v1_gce_persistent_disk_volume_source.h"
#include "v1_glusterfs_persistent_volume_source.h"
#include "v1_host_path_volume_source.h"
#include "v1_iscsi_persistent_volume_source.h"
#include "v1_local_volume_source.h"
#include "v1_nfs_volume_source.h"
#include "v1_object_reference.h"
#include "v1_photon_persistent_disk_volume_source.h"
#include "v1_portworx_volume_source.h"
#include "v1_quobyte_volume_source.h"
#include "v1_rbd_persistent_volume_source.h"
#include "v1_scale_io_persistent_volume_source.h"
#include "v1_storage_os_persistent_volume_source.h"
#include "v1_volume_node_affinity.h"
#include "v1_vsphere_virtual_disk_volume_source.h"



typedef struct v1_persistent_volume_spec_t {
    list_t *accessModes; //primitive container
    v1_aws_elastic_block_store_volume_source_t *awsElasticBlockStore; //model
    v1_azure_disk_volume_source_t *azureDisk; //model
    v1_azure_file_persistent_volume_source_t *azureFile; //model
    list_t* capacity; //map
    v1_ceph_fs_persistent_volume_source_t *cephfs; //model
    v1_cinder_persistent_volume_source_t *cinder; //model
    v1_object_reference_t *claimRef; //model
    v1_csi_persistent_volume_source_t *csi; //model
    v1_fc_volume_source_t *fc; //model
    v1_flex_persistent_volume_source_t *flexVolume; //model
    v1_flocker_volume_source_t *flocker; //model
    v1_gce_persistent_disk_volume_source_t *gcePersistentDisk; //model
    v1_glusterfs_persistent_volume_source_t *glusterfs; //model
    v1_host_path_volume_source_t *hostPath; //model
    v1_iscsi_persistent_volume_source_t *iscsi; //model
    v1_local_volume_source_t *local; //model
    list_t *mountOptions; //primitive container
    v1_nfs_volume_source_t *nfs; //model
    v1_volume_node_affinity_t *nodeAffinity; //model
    char *persistentVolumeReclaimPolicy; // string
    v1_photon_persistent_disk_volume_source_t *photonPersistentDisk; //model
    v1_portworx_volume_source_t *portworxVolume; //model
    v1_quobyte_volume_source_t *quobyte; //model
    v1_rbd_persistent_volume_source_t *rbd; //model
    v1_scale_io_persistent_volume_source_t *scaleIO; //model
    char *storageClassName; // string
    v1_storage_os_persistent_volume_source_t *storageos; //model
    char *volumeMode; // string
    v1_vsphere_virtual_disk_volume_source_t *vsphereVolume; //model

} v1_persistent_volume_spec_t;

v1_persistent_volume_spec_t *v1_persistent_volume_spec_create(
    list_t *accessModes,
    v1_aws_elastic_block_store_volume_source_t *awsElasticBlockStore,
    v1_azure_disk_volume_source_t *azureDisk,
    v1_azure_file_persistent_volume_source_t *azureFile,
    list_t* capacity,
    v1_ceph_fs_persistent_volume_source_t *cephfs,
    v1_cinder_persistent_volume_source_t *cinder,
    v1_object_reference_t *claimRef,
    v1_csi_persistent_volume_source_t *csi,
    v1_fc_volume_source_t *fc,
    v1_flex_persistent_volume_source_t *flexVolume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gcePersistentDisk,
    v1_glusterfs_persistent_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *hostPath,
    v1_iscsi_persistent_volume_source_t *iscsi,
    v1_local_volume_source_t *local,
    list_t *mountOptions,
    v1_nfs_volume_source_t *nfs,
    v1_volume_node_affinity_t *nodeAffinity,
    char *persistentVolumeReclaimPolicy,
    v1_photon_persistent_disk_volume_source_t *photonPersistentDisk,
    v1_portworx_volume_source_t *portworxVolume,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_persistent_volume_source_t *rbd,
    v1_scale_io_persistent_volume_source_t *scaleIO,
    char *storageClassName,
    v1_storage_os_persistent_volume_source_t *storageos,
    char *volumeMode,
    v1_vsphere_virtual_disk_volume_source_t *vsphereVolume
);

void v1_persistent_volume_spec_free(v1_persistent_volume_spec_t *v1_persistent_volume_spec);

v1_persistent_volume_spec_t *v1_persistent_volume_spec_parseFromJSON(cJSON *v1_persistent_volume_specJSON);

cJSON *v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_t *v1_persistent_volume_spec);

#endif /* _v1_persistent_volume_spec_H_ */


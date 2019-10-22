#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume.h"



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
    ) {
	v1_volume_t *v1_volume_local_var = malloc(sizeof(v1_volume_t));
    if (!v1_volume_local_var) {
        return NULL;
    }
	v1_volume_local_var->awsElasticBlockStore = awsElasticBlockStore;
	v1_volume_local_var->azureDisk = azureDisk;
	v1_volume_local_var->azureFile = azureFile;
	v1_volume_local_var->cephfs = cephfs;
	v1_volume_local_var->cinder = cinder;
	v1_volume_local_var->configMap = configMap;
	v1_volume_local_var->csi = csi;
	v1_volume_local_var->downwardAPI = downwardAPI;
	v1_volume_local_var->emptyDir = emptyDir;
	v1_volume_local_var->fc = fc;
	v1_volume_local_var->flexVolume = flexVolume;
	v1_volume_local_var->flocker = flocker;
	v1_volume_local_var->gcePersistentDisk = gcePersistentDisk;
	v1_volume_local_var->gitRepo = gitRepo;
	v1_volume_local_var->glusterfs = glusterfs;
	v1_volume_local_var->hostPath = hostPath;
	v1_volume_local_var->iscsi = iscsi;
	v1_volume_local_var->name = name;
	v1_volume_local_var->nfs = nfs;
	v1_volume_local_var->persistentVolumeClaim = persistentVolumeClaim;
	v1_volume_local_var->photonPersistentDisk = photonPersistentDisk;
	v1_volume_local_var->portworxVolume = portworxVolume;
	v1_volume_local_var->projected = projected;
	v1_volume_local_var->quobyte = quobyte;
	v1_volume_local_var->rbd = rbd;
	v1_volume_local_var->scaleIO = scaleIO;
	v1_volume_local_var->secret = secret;
	v1_volume_local_var->storageos = storageos;
	v1_volume_local_var->vsphereVolume = vsphereVolume;

	return v1_volume_local_var;
}


void v1_volume_free(v1_volume_t *v1_volume) {
    listEntry_t *listEntry;
    v1_aws_elastic_block_store_volume_source_free(v1_volume->awsElasticBlockStore);
    v1_azure_disk_volume_source_free(v1_volume->azureDisk);
    v1_azure_file_volume_source_free(v1_volume->azureFile);
    v1_ceph_fs_volume_source_free(v1_volume->cephfs);
    v1_cinder_volume_source_free(v1_volume->cinder);
    v1_config_map_volume_source_free(v1_volume->configMap);
    v1_csi_volume_source_free(v1_volume->csi);
    v1_downward_api_volume_source_free(v1_volume->downwardAPI);
    v1_empty_dir_volume_source_free(v1_volume->emptyDir);
    v1_fc_volume_source_free(v1_volume->fc);
    v1_flex_volume_source_free(v1_volume->flexVolume);
    v1_flocker_volume_source_free(v1_volume->flocker);
    v1_gce_persistent_disk_volume_source_free(v1_volume->gcePersistentDisk);
    v1_git_repo_volume_source_free(v1_volume->gitRepo);
    v1_glusterfs_volume_source_free(v1_volume->glusterfs);
    v1_host_path_volume_source_free(v1_volume->hostPath);
    v1_iscsi_volume_source_free(v1_volume->iscsi);
    free(v1_volume->name);
    v1_nfs_volume_source_free(v1_volume->nfs);
    v1_persistent_volume_claim_volume_source_free(v1_volume->persistentVolumeClaim);
    v1_photon_persistent_disk_volume_source_free(v1_volume->photonPersistentDisk);
    v1_portworx_volume_source_free(v1_volume->portworxVolume);
    v1_projected_volume_source_free(v1_volume->projected);
    v1_quobyte_volume_source_free(v1_volume->quobyte);
    v1_rbd_volume_source_free(v1_volume->rbd);
    v1_scale_io_volume_source_free(v1_volume->scaleIO);
    v1_secret_volume_source_free(v1_volume->secret);
    v1_storage_os_volume_source_free(v1_volume->storageos);
    v1_vsphere_virtual_disk_volume_source_free(v1_volume->vsphereVolume);
	free(v1_volume);
}

cJSON *v1_volume_convertToJSON(v1_volume_t *v1_volume) {
	cJSON *item = cJSON_CreateObject();

	// v1_volume->awsElasticBlockStore
    if(v1_volume->awsElasticBlockStore) { 
    cJSON *awsElasticBlockStore_local_JSON = v1_aws_elastic_block_store_volume_source_convertToJSON(v1_volume->awsElasticBlockStore);
    if(awsElasticBlockStore_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "awsElasticBlockStore", awsElasticBlockStore_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->azureDisk
    if(v1_volume->azureDisk) { 
    cJSON *azureDisk_local_JSON = v1_azure_disk_volume_source_convertToJSON(v1_volume->azureDisk);
    if(azureDisk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureDisk", azureDisk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->azureFile
    if(v1_volume->azureFile) { 
    cJSON *azureFile_local_JSON = v1_azure_file_volume_source_convertToJSON(v1_volume->azureFile);
    if(azureFile_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureFile", azureFile_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->cephfs
    if(v1_volume->cephfs) { 
    cJSON *cephfs_local_JSON = v1_ceph_fs_volume_source_convertToJSON(v1_volume->cephfs);
    if(cephfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cephfs", cephfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->cinder
    if(v1_volume->cinder) { 
    cJSON *cinder_local_JSON = v1_cinder_volume_source_convertToJSON(v1_volume->cinder);
    if(cinder_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cinder", cinder_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->configMap
    if(v1_volume->configMap) { 
    cJSON *configMap_local_JSON = v1_config_map_volume_source_convertToJSON(v1_volume->configMap);
    if(configMap_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMap", configMap_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->csi
    if(v1_volume->csi) { 
    cJSON *csi_local_JSON = v1_csi_volume_source_convertToJSON(v1_volume->csi);
    if(csi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "csi", csi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->downwardAPI
    if(v1_volume->downwardAPI) { 
    cJSON *downwardAPI_local_JSON = v1_downward_api_volume_source_convertToJSON(v1_volume->downwardAPI);
    if(downwardAPI_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "downwardAPI", downwardAPI_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->emptyDir
    if(v1_volume->emptyDir) { 
    cJSON *emptyDir_local_JSON = v1_empty_dir_volume_source_convertToJSON(v1_volume->emptyDir);
    if(emptyDir_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "emptyDir", emptyDir_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->fc
    if(v1_volume->fc) { 
    cJSON *fc_local_JSON = v1_fc_volume_source_convertToJSON(v1_volume->fc);
    if(fc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fc", fc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->flexVolume
    if(v1_volume->flexVolume) { 
    cJSON *flexVolume_local_JSON = v1_flex_volume_source_convertToJSON(v1_volume->flexVolume);
    if(flexVolume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flexVolume", flexVolume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->flocker
    if(v1_volume->flocker) { 
    cJSON *flocker_local_JSON = v1_flocker_volume_source_convertToJSON(v1_volume->flocker);
    if(flocker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flocker", flocker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->gcePersistentDisk
    if(v1_volume->gcePersistentDisk) { 
    cJSON *gcePersistentDisk_local_JSON = v1_gce_persistent_disk_volume_source_convertToJSON(v1_volume->gcePersistentDisk);
    if(gcePersistentDisk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gcePersistentDisk", gcePersistentDisk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->gitRepo
    if(v1_volume->gitRepo) { 
    cJSON *gitRepo_local_JSON = v1_git_repo_volume_source_convertToJSON(v1_volume->gitRepo);
    if(gitRepo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gitRepo", gitRepo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->glusterfs
    if(v1_volume->glusterfs) { 
    cJSON *glusterfs_local_JSON = v1_glusterfs_volume_source_convertToJSON(v1_volume->glusterfs);
    if(glusterfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "glusterfs", glusterfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->hostPath
    if(v1_volume->hostPath) { 
    cJSON *hostPath_local_JSON = v1_host_path_volume_source_convertToJSON(v1_volume->hostPath);
    if(hostPath_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hostPath", hostPath_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->iscsi
    if(v1_volume->iscsi) { 
    cJSON *iscsi_local_JSON = v1_iscsi_volume_source_convertToJSON(v1_volume->iscsi);
    if(iscsi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "iscsi", iscsi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->name
    if (!v1_volume->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_volume->name) == NULL) {
    goto fail; //String
    }


	// v1_volume->nfs
    if(v1_volume->nfs) { 
    cJSON *nfs_local_JSON = v1_nfs_volume_source_convertToJSON(v1_volume->nfs);
    if(nfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nfs", nfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->persistentVolumeClaim
    if(v1_volume->persistentVolumeClaim) { 
    cJSON *persistentVolumeClaim_local_JSON = v1_persistent_volume_claim_volume_source_convertToJSON(v1_volume->persistentVolumeClaim);
    if(persistentVolumeClaim_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "persistentVolumeClaim", persistentVolumeClaim_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->photonPersistentDisk
    if(v1_volume->photonPersistentDisk) { 
    cJSON *photonPersistentDisk_local_JSON = v1_photon_persistent_disk_volume_source_convertToJSON(v1_volume->photonPersistentDisk);
    if(photonPersistentDisk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "photonPersistentDisk", photonPersistentDisk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->portworxVolume
    if(v1_volume->portworxVolume) { 
    cJSON *portworxVolume_local_JSON = v1_portworx_volume_source_convertToJSON(v1_volume->portworxVolume);
    if(portworxVolume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "portworxVolume", portworxVolume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->projected
    if(v1_volume->projected) { 
    cJSON *projected_local_JSON = v1_projected_volume_source_convertToJSON(v1_volume->projected);
    if(projected_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "projected", projected_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->quobyte
    if(v1_volume->quobyte) { 
    cJSON *quobyte_local_JSON = v1_quobyte_volume_source_convertToJSON(v1_volume->quobyte);
    if(quobyte_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quobyte", quobyte_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->rbd
    if(v1_volume->rbd) { 
    cJSON *rbd_local_JSON = v1_rbd_volume_source_convertToJSON(v1_volume->rbd);
    if(rbd_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rbd", rbd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->scaleIO
    if(v1_volume->scaleIO) { 
    cJSON *scaleIO_local_JSON = v1_scale_io_volume_source_convertToJSON(v1_volume->scaleIO);
    if(scaleIO_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleIO", scaleIO_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->secret
    if(v1_volume->secret) { 
    cJSON *secret_local_JSON = v1_secret_volume_source_convertToJSON(v1_volume->secret);
    if(secret_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secret", secret_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->storageos
    if(v1_volume->storageos) { 
    cJSON *storageos_local_JSON = v1_storage_os_volume_source_convertToJSON(v1_volume->storageos);
    if(storageos_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "storageos", storageos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume->vsphereVolume
    if(v1_volume->vsphereVolume) { 
    cJSON *vsphereVolume_local_JSON = v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_volume->vsphereVolume);
    if(vsphereVolume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vsphereVolume", vsphereVolume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_volume_t *v1_volume_parseFromJSON(cJSON *v1_volumeJSON){

    v1_volume_t *v1_volume_local_var = NULL;

    // v1_volume->awsElasticBlockStore
    cJSON *awsElasticBlockStore = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "awsElasticBlockStore");
    v1_aws_elastic_block_store_volume_source_t *awsElasticBlockStore_local_nonprim = NULL;
    if (awsElasticBlockStore) { 
    awsElasticBlockStore_local_nonprim = v1_aws_elastic_block_store_volume_source_parseFromJSON(awsElasticBlockStore); //nonprimitive
    }

    // v1_volume->azureDisk
    cJSON *azureDisk = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "azureDisk");
    v1_azure_disk_volume_source_t *azureDisk_local_nonprim = NULL;
    if (azureDisk) { 
    azureDisk_local_nonprim = v1_azure_disk_volume_source_parseFromJSON(azureDisk); //nonprimitive
    }

    // v1_volume->azureFile
    cJSON *azureFile = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "azureFile");
    v1_azure_file_volume_source_t *azureFile_local_nonprim = NULL;
    if (azureFile) { 
    azureFile_local_nonprim = v1_azure_file_volume_source_parseFromJSON(azureFile); //nonprimitive
    }

    // v1_volume->cephfs
    cJSON *cephfs = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "cephfs");
    v1_ceph_fs_volume_source_t *cephfs_local_nonprim = NULL;
    if (cephfs) { 
    cephfs_local_nonprim = v1_ceph_fs_volume_source_parseFromJSON(cephfs); //nonprimitive
    }

    // v1_volume->cinder
    cJSON *cinder = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "cinder");
    v1_cinder_volume_source_t *cinder_local_nonprim = NULL;
    if (cinder) { 
    cinder_local_nonprim = v1_cinder_volume_source_parseFromJSON(cinder); //nonprimitive
    }

    // v1_volume->configMap
    cJSON *configMap = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "configMap");
    v1_config_map_volume_source_t *configMap_local_nonprim = NULL;
    if (configMap) { 
    configMap_local_nonprim = v1_config_map_volume_source_parseFromJSON(configMap); //nonprimitive
    }

    // v1_volume->csi
    cJSON *csi = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "csi");
    v1_csi_volume_source_t *csi_local_nonprim = NULL;
    if (csi) { 
    csi_local_nonprim = v1_csi_volume_source_parseFromJSON(csi); //nonprimitive
    }

    // v1_volume->downwardAPI
    cJSON *downwardAPI = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "downwardAPI");
    v1_downward_api_volume_source_t *downwardAPI_local_nonprim = NULL;
    if (downwardAPI) { 
    downwardAPI_local_nonprim = v1_downward_api_volume_source_parseFromJSON(downwardAPI); //nonprimitive
    }

    // v1_volume->emptyDir
    cJSON *emptyDir = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "emptyDir");
    v1_empty_dir_volume_source_t *emptyDir_local_nonprim = NULL;
    if (emptyDir) { 
    emptyDir_local_nonprim = v1_empty_dir_volume_source_parseFromJSON(emptyDir); //nonprimitive
    }

    // v1_volume->fc
    cJSON *fc = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "fc");
    v1_fc_volume_source_t *fc_local_nonprim = NULL;
    if (fc) { 
    fc_local_nonprim = v1_fc_volume_source_parseFromJSON(fc); //nonprimitive
    }

    // v1_volume->flexVolume
    cJSON *flexVolume = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "flexVolume");
    v1_flex_volume_source_t *flexVolume_local_nonprim = NULL;
    if (flexVolume) { 
    flexVolume_local_nonprim = v1_flex_volume_source_parseFromJSON(flexVolume); //nonprimitive
    }

    // v1_volume->flocker
    cJSON *flocker = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "flocker");
    v1_flocker_volume_source_t *flocker_local_nonprim = NULL;
    if (flocker) { 
    flocker_local_nonprim = v1_flocker_volume_source_parseFromJSON(flocker); //nonprimitive
    }

    // v1_volume->gcePersistentDisk
    cJSON *gcePersistentDisk = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "gcePersistentDisk");
    v1_gce_persistent_disk_volume_source_t *gcePersistentDisk_local_nonprim = NULL;
    if (gcePersistentDisk) { 
    gcePersistentDisk_local_nonprim = v1_gce_persistent_disk_volume_source_parseFromJSON(gcePersistentDisk); //nonprimitive
    }

    // v1_volume->gitRepo
    cJSON *gitRepo = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "gitRepo");
    v1_git_repo_volume_source_t *gitRepo_local_nonprim = NULL;
    if (gitRepo) { 
    gitRepo_local_nonprim = v1_git_repo_volume_source_parseFromJSON(gitRepo); //nonprimitive
    }

    // v1_volume->glusterfs
    cJSON *glusterfs = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "glusterfs");
    v1_glusterfs_volume_source_t *glusterfs_local_nonprim = NULL;
    if (glusterfs) { 
    glusterfs_local_nonprim = v1_glusterfs_volume_source_parseFromJSON(glusterfs); //nonprimitive
    }

    // v1_volume->hostPath
    cJSON *hostPath = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "hostPath");
    v1_host_path_volume_source_t *hostPath_local_nonprim = NULL;
    if (hostPath) { 
    hostPath_local_nonprim = v1_host_path_volume_source_parseFromJSON(hostPath); //nonprimitive
    }

    // v1_volume->iscsi
    cJSON *iscsi = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "iscsi");
    v1_iscsi_volume_source_t *iscsi_local_nonprim = NULL;
    if (iscsi) { 
    iscsi_local_nonprim = v1_iscsi_volume_source_parseFromJSON(iscsi); //nonprimitive
    }

    // v1_volume->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_volume->nfs
    cJSON *nfs = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "nfs");
    v1_nfs_volume_source_t *nfs_local_nonprim = NULL;
    if (nfs) { 
    nfs_local_nonprim = v1_nfs_volume_source_parseFromJSON(nfs); //nonprimitive
    }

    // v1_volume->persistentVolumeClaim
    cJSON *persistentVolumeClaim = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "persistentVolumeClaim");
    v1_persistent_volume_claim_volume_source_t *persistentVolumeClaim_local_nonprim = NULL;
    if (persistentVolumeClaim) { 
    persistentVolumeClaim_local_nonprim = v1_persistent_volume_claim_volume_source_parseFromJSON(persistentVolumeClaim); //nonprimitive
    }

    // v1_volume->photonPersistentDisk
    cJSON *photonPersistentDisk = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "photonPersistentDisk");
    v1_photon_persistent_disk_volume_source_t *photonPersistentDisk_local_nonprim = NULL;
    if (photonPersistentDisk) { 
    photonPersistentDisk_local_nonprim = v1_photon_persistent_disk_volume_source_parseFromJSON(photonPersistentDisk); //nonprimitive
    }

    // v1_volume->portworxVolume
    cJSON *portworxVolume = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "portworxVolume");
    v1_portworx_volume_source_t *portworxVolume_local_nonprim = NULL;
    if (portworxVolume) { 
    portworxVolume_local_nonprim = v1_portworx_volume_source_parseFromJSON(portworxVolume); //nonprimitive
    }

    // v1_volume->projected
    cJSON *projected = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "projected");
    v1_projected_volume_source_t *projected_local_nonprim = NULL;
    if (projected) { 
    projected_local_nonprim = v1_projected_volume_source_parseFromJSON(projected); //nonprimitive
    }

    // v1_volume->quobyte
    cJSON *quobyte = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "quobyte");
    v1_quobyte_volume_source_t *quobyte_local_nonprim = NULL;
    if (quobyte) { 
    quobyte_local_nonprim = v1_quobyte_volume_source_parseFromJSON(quobyte); //nonprimitive
    }

    // v1_volume->rbd
    cJSON *rbd = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "rbd");
    v1_rbd_volume_source_t *rbd_local_nonprim = NULL;
    if (rbd) { 
    rbd_local_nonprim = v1_rbd_volume_source_parseFromJSON(rbd); //nonprimitive
    }

    // v1_volume->scaleIO
    cJSON *scaleIO = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "scaleIO");
    v1_scale_io_volume_source_t *scaleIO_local_nonprim = NULL;
    if (scaleIO) { 
    scaleIO_local_nonprim = v1_scale_io_volume_source_parseFromJSON(scaleIO); //nonprimitive
    }

    // v1_volume->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "secret");
    v1_secret_volume_source_t *secret_local_nonprim = NULL;
    if (secret) { 
    secret_local_nonprim = v1_secret_volume_source_parseFromJSON(secret); //nonprimitive
    }

    // v1_volume->storageos
    cJSON *storageos = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "storageos");
    v1_storage_os_volume_source_t *storageos_local_nonprim = NULL;
    if (storageos) { 
    storageos_local_nonprim = v1_storage_os_volume_source_parseFromJSON(storageos); //nonprimitive
    }

    // v1_volume->vsphereVolume
    cJSON *vsphereVolume = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "vsphereVolume");
    v1_vsphere_virtual_disk_volume_source_t *vsphereVolume_local_nonprim = NULL;
    if (vsphereVolume) { 
    vsphereVolume_local_nonprim = v1_vsphere_virtual_disk_volume_source_parseFromJSON(vsphereVolume); //nonprimitive
    }


    v1_volume_local_var = v1_volume_create (
        awsElasticBlockStore ? awsElasticBlockStore_local_nonprim : NULL,
        azureDisk ? azureDisk_local_nonprim : NULL,
        azureFile ? azureFile_local_nonprim : NULL,
        cephfs ? cephfs_local_nonprim : NULL,
        cinder ? cinder_local_nonprim : NULL,
        configMap ? configMap_local_nonprim : NULL,
        csi ? csi_local_nonprim : NULL,
        downwardAPI ? downwardAPI_local_nonprim : NULL,
        emptyDir ? emptyDir_local_nonprim : NULL,
        fc ? fc_local_nonprim : NULL,
        flexVolume ? flexVolume_local_nonprim : NULL,
        flocker ? flocker_local_nonprim : NULL,
        gcePersistentDisk ? gcePersistentDisk_local_nonprim : NULL,
        gitRepo ? gitRepo_local_nonprim : NULL,
        glusterfs ? glusterfs_local_nonprim : NULL,
        hostPath ? hostPath_local_nonprim : NULL,
        iscsi ? iscsi_local_nonprim : NULL,
        strdup(name->valuestring),
        nfs ? nfs_local_nonprim : NULL,
        persistentVolumeClaim ? persistentVolumeClaim_local_nonprim : NULL,
        photonPersistentDisk ? photonPersistentDisk_local_nonprim : NULL,
        portworxVolume ? portworxVolume_local_nonprim : NULL,
        projected ? projected_local_nonprim : NULL,
        quobyte ? quobyte_local_nonprim : NULL,
        rbd ? rbd_local_nonprim : NULL,
        scaleIO ? scaleIO_local_nonprim : NULL,
        secret ? secret_local_nonprim : NULL,
        storageos ? storageos_local_nonprim : NULL,
        vsphereVolume ? vsphereVolume_local_nonprim : NULL
        );

    return v1_volume_local_var;
end:
    return NULL;

}

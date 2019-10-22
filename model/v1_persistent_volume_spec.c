#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_spec.h"



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
    ) {
	v1_persistent_volume_spec_t *v1_persistent_volume_spec_local_var = malloc(sizeof(v1_persistent_volume_spec_t));
    if (!v1_persistent_volume_spec_local_var) {
        return NULL;
    }
	v1_persistent_volume_spec_local_var->accessModes = accessModes;
	v1_persistent_volume_spec_local_var->awsElasticBlockStore = awsElasticBlockStore;
	v1_persistent_volume_spec_local_var->azureDisk = azureDisk;
	v1_persistent_volume_spec_local_var->azureFile = azureFile;
	v1_persistent_volume_spec_local_var->capacity = capacity;
	v1_persistent_volume_spec_local_var->cephfs = cephfs;
	v1_persistent_volume_spec_local_var->cinder = cinder;
	v1_persistent_volume_spec_local_var->claimRef = claimRef;
	v1_persistent_volume_spec_local_var->csi = csi;
	v1_persistent_volume_spec_local_var->fc = fc;
	v1_persistent_volume_spec_local_var->flexVolume = flexVolume;
	v1_persistent_volume_spec_local_var->flocker = flocker;
	v1_persistent_volume_spec_local_var->gcePersistentDisk = gcePersistentDisk;
	v1_persistent_volume_spec_local_var->glusterfs = glusterfs;
	v1_persistent_volume_spec_local_var->hostPath = hostPath;
	v1_persistent_volume_spec_local_var->iscsi = iscsi;
	v1_persistent_volume_spec_local_var->local = local;
	v1_persistent_volume_spec_local_var->mountOptions = mountOptions;
	v1_persistent_volume_spec_local_var->nfs = nfs;
	v1_persistent_volume_spec_local_var->nodeAffinity = nodeAffinity;
	v1_persistent_volume_spec_local_var->persistentVolumeReclaimPolicy = persistentVolumeReclaimPolicy;
	v1_persistent_volume_spec_local_var->photonPersistentDisk = photonPersistentDisk;
	v1_persistent_volume_spec_local_var->portworxVolume = portworxVolume;
	v1_persistent_volume_spec_local_var->quobyte = quobyte;
	v1_persistent_volume_spec_local_var->rbd = rbd;
	v1_persistent_volume_spec_local_var->scaleIO = scaleIO;
	v1_persistent_volume_spec_local_var->storageClassName = storageClassName;
	v1_persistent_volume_spec_local_var->storageos = storageos;
	v1_persistent_volume_spec_local_var->volumeMode = volumeMode;
	v1_persistent_volume_spec_local_var->vsphereVolume = vsphereVolume;

	return v1_persistent_volume_spec_local_var;
}


void v1_persistent_volume_spec_free(v1_persistent_volume_spec_t *v1_persistent_volume_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_persistent_volume_spec->accessModes) {
		free(listEntry->data);
	}
	list_free(v1_persistent_volume_spec->accessModes);
    v1_aws_elastic_block_store_volume_source_free(v1_persistent_volume_spec->awsElasticBlockStore);
    v1_azure_disk_volume_source_free(v1_persistent_volume_spec->azureDisk);
    v1_azure_file_persistent_volume_source_free(v1_persistent_volume_spec->azureFile);
	list_ForEach(listEntry, v1_persistent_volume_spec->capacity) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_persistent_volume_spec->capacity);
    v1_ceph_fs_persistent_volume_source_free(v1_persistent_volume_spec->cephfs);
    v1_cinder_persistent_volume_source_free(v1_persistent_volume_spec->cinder);
    v1_object_reference_free(v1_persistent_volume_spec->claimRef);
    v1_csi_persistent_volume_source_free(v1_persistent_volume_spec->csi);
    v1_fc_volume_source_free(v1_persistent_volume_spec->fc);
    v1_flex_persistent_volume_source_free(v1_persistent_volume_spec->flexVolume);
    v1_flocker_volume_source_free(v1_persistent_volume_spec->flocker);
    v1_gce_persistent_disk_volume_source_free(v1_persistent_volume_spec->gcePersistentDisk);
    v1_glusterfs_persistent_volume_source_free(v1_persistent_volume_spec->glusterfs);
    v1_host_path_volume_source_free(v1_persistent_volume_spec->hostPath);
    v1_iscsi_persistent_volume_source_free(v1_persistent_volume_spec->iscsi);
    v1_local_volume_source_free(v1_persistent_volume_spec->local);
	list_ForEach(listEntry, v1_persistent_volume_spec->mountOptions) {
		free(listEntry->data);
	}
	list_free(v1_persistent_volume_spec->mountOptions);
    v1_nfs_volume_source_free(v1_persistent_volume_spec->nfs);
    v1_volume_node_affinity_free(v1_persistent_volume_spec->nodeAffinity);
    free(v1_persistent_volume_spec->persistentVolumeReclaimPolicy);
    v1_photon_persistent_disk_volume_source_free(v1_persistent_volume_spec->photonPersistentDisk);
    v1_portworx_volume_source_free(v1_persistent_volume_spec->portworxVolume);
    v1_quobyte_volume_source_free(v1_persistent_volume_spec->quobyte);
    v1_rbd_persistent_volume_source_free(v1_persistent_volume_spec->rbd);
    v1_scale_io_persistent_volume_source_free(v1_persistent_volume_spec->scaleIO);
    free(v1_persistent_volume_spec->storageClassName);
    v1_storage_os_persistent_volume_source_free(v1_persistent_volume_spec->storageos);
    free(v1_persistent_volume_spec->volumeMode);
    v1_vsphere_virtual_disk_volume_source_free(v1_persistent_volume_spec->vsphereVolume);
	free(v1_persistent_volume_spec);
}

cJSON *v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_t *v1_persistent_volume_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_persistent_volume_spec->accessModes
    if(v1_persistent_volume_spec->accessModes) { 
	cJSON *access_modes = cJSON_AddArrayToObject(item, "accessModes");
	if(access_modes == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *access_modesListEntry;
    list_ForEach(access_modesListEntry, v1_persistent_volume_spec->accessModes) {
    if(cJSON_AddStringToObject(access_modes, "", (char*)access_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_persistent_volume_spec->awsElasticBlockStore
    if(v1_persistent_volume_spec->awsElasticBlockStore) { 
    cJSON *awsElasticBlockStore_local_JSON = v1_aws_elastic_block_store_volume_source_convertToJSON(v1_persistent_volume_spec->awsElasticBlockStore);
    if(awsElasticBlockStore_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "awsElasticBlockStore", awsElasticBlockStore_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->azureDisk
    if(v1_persistent_volume_spec->azureDisk) { 
    cJSON *azureDisk_local_JSON = v1_azure_disk_volume_source_convertToJSON(v1_persistent_volume_spec->azureDisk);
    if(azureDisk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureDisk", azureDisk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->azureFile
    if(v1_persistent_volume_spec->azureFile) { 
    cJSON *azureFile_local_JSON = v1_azure_file_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->azureFile);
    if(azureFile_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureFile", azureFile_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->capacity
    if(v1_persistent_volume_spec->capacity) { 
	cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
	if(capacity == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *capacityListEntry;
    if (v1_persistent_volume_spec->capacity) {
    list_ForEach(capacityListEntry, v1_persistent_volume_spec->capacity) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(capacity,"", localMapObject);
    }
    }
     } 


	// v1_persistent_volume_spec->cephfs
    if(v1_persistent_volume_spec->cephfs) { 
    cJSON *cephfs_local_JSON = v1_ceph_fs_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->cephfs);
    if(cephfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cephfs", cephfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->cinder
    if(v1_persistent_volume_spec->cinder) { 
    cJSON *cinder_local_JSON = v1_cinder_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->cinder);
    if(cinder_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cinder", cinder_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->claimRef
    if(v1_persistent_volume_spec->claimRef) { 
    cJSON *claimRef_local_JSON = v1_object_reference_convertToJSON(v1_persistent_volume_spec->claimRef);
    if(claimRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "claimRef", claimRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->csi
    if(v1_persistent_volume_spec->csi) { 
    cJSON *csi_local_JSON = v1_csi_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->csi);
    if(csi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "csi", csi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->fc
    if(v1_persistent_volume_spec->fc) { 
    cJSON *fc_local_JSON = v1_fc_volume_source_convertToJSON(v1_persistent_volume_spec->fc);
    if(fc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fc", fc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->flexVolume
    if(v1_persistent_volume_spec->flexVolume) { 
    cJSON *flexVolume_local_JSON = v1_flex_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->flexVolume);
    if(flexVolume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flexVolume", flexVolume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->flocker
    if(v1_persistent_volume_spec->flocker) { 
    cJSON *flocker_local_JSON = v1_flocker_volume_source_convertToJSON(v1_persistent_volume_spec->flocker);
    if(flocker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flocker", flocker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->gcePersistentDisk
    if(v1_persistent_volume_spec->gcePersistentDisk) { 
    cJSON *gcePersistentDisk_local_JSON = v1_gce_persistent_disk_volume_source_convertToJSON(v1_persistent_volume_spec->gcePersistentDisk);
    if(gcePersistentDisk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gcePersistentDisk", gcePersistentDisk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->glusterfs
    if(v1_persistent_volume_spec->glusterfs) { 
    cJSON *glusterfs_local_JSON = v1_glusterfs_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->glusterfs);
    if(glusterfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "glusterfs", glusterfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->hostPath
    if(v1_persistent_volume_spec->hostPath) { 
    cJSON *hostPath_local_JSON = v1_host_path_volume_source_convertToJSON(v1_persistent_volume_spec->hostPath);
    if(hostPath_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hostPath", hostPath_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->iscsi
    if(v1_persistent_volume_spec->iscsi) { 
    cJSON *iscsi_local_JSON = v1_iscsi_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->iscsi);
    if(iscsi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "iscsi", iscsi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->local
    if(v1_persistent_volume_spec->local) { 
    cJSON *local_local_JSON = v1_local_volume_source_convertToJSON(v1_persistent_volume_spec->local);
    if(local_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "local", local_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->mountOptions
    if(v1_persistent_volume_spec->mountOptions) { 
	cJSON *mount_options = cJSON_AddArrayToObject(item, "mountOptions");
	if(mount_options == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *mount_optionsListEntry;
    list_ForEach(mount_optionsListEntry, v1_persistent_volume_spec->mountOptions) {
    if(cJSON_AddStringToObject(mount_options, "", (char*)mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_persistent_volume_spec->nfs
    if(v1_persistent_volume_spec->nfs) { 
    cJSON *nfs_local_JSON = v1_nfs_volume_source_convertToJSON(v1_persistent_volume_spec->nfs);
    if(nfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nfs", nfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->nodeAffinity
    if(v1_persistent_volume_spec->nodeAffinity) { 
    cJSON *nodeAffinity_local_JSON = v1_volume_node_affinity_convertToJSON(v1_persistent_volume_spec->nodeAffinity);
    if(nodeAffinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeAffinity", nodeAffinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->persistentVolumeReclaimPolicy
    if(v1_persistent_volume_spec->persistentVolumeReclaimPolicy) { 
    if(cJSON_AddStringToObject(item, "persistentVolumeReclaimPolicy", v1_persistent_volume_spec->persistentVolumeReclaimPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_spec->photonPersistentDisk
    if(v1_persistent_volume_spec->photonPersistentDisk) { 
    cJSON *photonPersistentDisk_local_JSON = v1_photon_persistent_disk_volume_source_convertToJSON(v1_persistent_volume_spec->photonPersistentDisk);
    if(photonPersistentDisk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "photonPersistentDisk", photonPersistentDisk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->portworxVolume
    if(v1_persistent_volume_spec->portworxVolume) { 
    cJSON *portworxVolume_local_JSON = v1_portworx_volume_source_convertToJSON(v1_persistent_volume_spec->portworxVolume);
    if(portworxVolume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "portworxVolume", portworxVolume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->quobyte
    if(v1_persistent_volume_spec->quobyte) { 
    cJSON *quobyte_local_JSON = v1_quobyte_volume_source_convertToJSON(v1_persistent_volume_spec->quobyte);
    if(quobyte_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quobyte", quobyte_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->rbd
    if(v1_persistent_volume_spec->rbd) { 
    cJSON *rbd_local_JSON = v1_rbd_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->rbd);
    if(rbd_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rbd", rbd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->scaleIO
    if(v1_persistent_volume_spec->scaleIO) { 
    cJSON *scaleIO_local_JSON = v1_scale_io_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->scaleIO);
    if(scaleIO_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleIO", scaleIO_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->storageClassName
    if(v1_persistent_volume_spec->storageClassName) { 
    if(cJSON_AddStringToObject(item, "storageClassName", v1_persistent_volume_spec->storageClassName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_spec->storageos
    if(v1_persistent_volume_spec->storageos) { 
    cJSON *storageos_local_JSON = v1_storage_os_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->storageos);
    if(storageos_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "storageos", storageos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_spec->volumeMode
    if(v1_persistent_volume_spec->volumeMode) { 
    if(cJSON_AddStringToObject(item, "volumeMode", v1_persistent_volume_spec->volumeMode) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_spec->vsphereVolume
    if(v1_persistent_volume_spec->vsphereVolume) { 
    cJSON *vsphereVolume_local_JSON = v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_persistent_volume_spec->vsphereVolume);
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

v1_persistent_volume_spec_t *v1_persistent_volume_spec_parseFromJSON(cJSON *v1_persistent_volume_specJSON){

    v1_persistent_volume_spec_t *v1_persistent_volume_spec_local_var = NULL;

    // v1_persistent_volume_spec->accessModes
    cJSON *accessModes = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "accessModes");
    list_t *access_modesList;
    if (accessModes) { 
    cJSON *access_modes_local;
    if(!cJSON_IsArray(accessModes)) {
        goto end;//primitive container
    }
    access_modesList = list_create();

    cJSON_ArrayForEach(access_modes_local, accessModes)
    {
        if(!cJSON_IsString(access_modes_local))
        {
            goto end;
        }
        list_addElement(access_modesList , strdup(access_modes_local->valuestring));
    }
    }

    // v1_persistent_volume_spec->awsElasticBlockStore
    cJSON *awsElasticBlockStore = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "awsElasticBlockStore");
    v1_aws_elastic_block_store_volume_source_t *awsElasticBlockStore_local_nonprim = NULL;
    if (awsElasticBlockStore) { 
    awsElasticBlockStore_local_nonprim = v1_aws_elastic_block_store_volume_source_parseFromJSON(awsElasticBlockStore); //nonprimitive
    }

    // v1_persistent_volume_spec->azureDisk
    cJSON *azureDisk = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "azureDisk");
    v1_azure_disk_volume_source_t *azureDisk_local_nonprim = NULL;
    if (azureDisk) { 
    azureDisk_local_nonprim = v1_azure_disk_volume_source_parseFromJSON(azureDisk); //nonprimitive
    }

    // v1_persistent_volume_spec->azureFile
    cJSON *azureFile = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "azureFile");
    v1_azure_file_persistent_volume_source_t *azureFile_local_nonprim = NULL;
    if (azureFile) { 
    azureFile_local_nonprim = v1_azure_file_persistent_volume_source_parseFromJSON(azureFile); //nonprimitive
    }

    // v1_persistent_volume_spec->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "capacity");
    list_t *List;
    if (capacity) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(capacity)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, capacity)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_persistent_volume_spec->cephfs
    cJSON *cephfs = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "cephfs");
    v1_ceph_fs_persistent_volume_source_t *cephfs_local_nonprim = NULL;
    if (cephfs) { 
    cephfs_local_nonprim = v1_ceph_fs_persistent_volume_source_parseFromJSON(cephfs); //nonprimitive
    }

    // v1_persistent_volume_spec->cinder
    cJSON *cinder = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "cinder");
    v1_cinder_persistent_volume_source_t *cinder_local_nonprim = NULL;
    if (cinder) { 
    cinder_local_nonprim = v1_cinder_persistent_volume_source_parseFromJSON(cinder); //nonprimitive
    }

    // v1_persistent_volume_spec->claimRef
    cJSON *claimRef = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "claimRef");
    v1_object_reference_t *claimRef_local_nonprim = NULL;
    if (claimRef) { 
    claimRef_local_nonprim = v1_object_reference_parseFromJSON(claimRef); //nonprimitive
    }

    // v1_persistent_volume_spec->csi
    cJSON *csi = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "csi");
    v1_csi_persistent_volume_source_t *csi_local_nonprim = NULL;
    if (csi) { 
    csi_local_nonprim = v1_csi_persistent_volume_source_parseFromJSON(csi); //nonprimitive
    }

    // v1_persistent_volume_spec->fc
    cJSON *fc = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "fc");
    v1_fc_volume_source_t *fc_local_nonprim = NULL;
    if (fc) { 
    fc_local_nonprim = v1_fc_volume_source_parseFromJSON(fc); //nonprimitive
    }

    // v1_persistent_volume_spec->flexVolume
    cJSON *flexVolume = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "flexVolume");
    v1_flex_persistent_volume_source_t *flexVolume_local_nonprim = NULL;
    if (flexVolume) { 
    flexVolume_local_nonprim = v1_flex_persistent_volume_source_parseFromJSON(flexVolume); //nonprimitive
    }

    // v1_persistent_volume_spec->flocker
    cJSON *flocker = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "flocker");
    v1_flocker_volume_source_t *flocker_local_nonprim = NULL;
    if (flocker) { 
    flocker_local_nonprim = v1_flocker_volume_source_parseFromJSON(flocker); //nonprimitive
    }

    // v1_persistent_volume_spec->gcePersistentDisk
    cJSON *gcePersistentDisk = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "gcePersistentDisk");
    v1_gce_persistent_disk_volume_source_t *gcePersistentDisk_local_nonprim = NULL;
    if (gcePersistentDisk) { 
    gcePersistentDisk_local_nonprim = v1_gce_persistent_disk_volume_source_parseFromJSON(gcePersistentDisk); //nonprimitive
    }

    // v1_persistent_volume_spec->glusterfs
    cJSON *glusterfs = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "glusterfs");
    v1_glusterfs_persistent_volume_source_t *glusterfs_local_nonprim = NULL;
    if (glusterfs) { 
    glusterfs_local_nonprim = v1_glusterfs_persistent_volume_source_parseFromJSON(glusterfs); //nonprimitive
    }

    // v1_persistent_volume_spec->hostPath
    cJSON *hostPath = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "hostPath");
    v1_host_path_volume_source_t *hostPath_local_nonprim = NULL;
    if (hostPath) { 
    hostPath_local_nonprim = v1_host_path_volume_source_parseFromJSON(hostPath); //nonprimitive
    }

    // v1_persistent_volume_spec->iscsi
    cJSON *iscsi = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "iscsi");
    v1_iscsi_persistent_volume_source_t *iscsi_local_nonprim = NULL;
    if (iscsi) { 
    iscsi_local_nonprim = v1_iscsi_persistent_volume_source_parseFromJSON(iscsi); //nonprimitive
    }

    // v1_persistent_volume_spec->local
    cJSON *local = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "local");
    v1_local_volume_source_t *local_local_nonprim = NULL;
    if (local) { 
    local_local_nonprim = v1_local_volume_source_parseFromJSON(local); //nonprimitive
    }

    // v1_persistent_volume_spec->mountOptions
    cJSON *mountOptions = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "mountOptions");
    list_t *mount_optionsList;
    if (mountOptions) { 
    cJSON *mount_options_local;
    if(!cJSON_IsArray(mountOptions)) {
        goto end;//primitive container
    }
    mount_optionsList = list_create();

    cJSON_ArrayForEach(mount_options_local, mountOptions)
    {
        if(!cJSON_IsString(mount_options_local))
        {
            goto end;
        }
        list_addElement(mount_optionsList , strdup(mount_options_local->valuestring));
    }
    }

    // v1_persistent_volume_spec->nfs
    cJSON *nfs = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "nfs");
    v1_nfs_volume_source_t *nfs_local_nonprim = NULL;
    if (nfs) { 
    nfs_local_nonprim = v1_nfs_volume_source_parseFromJSON(nfs); //nonprimitive
    }

    // v1_persistent_volume_spec->nodeAffinity
    cJSON *nodeAffinity = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "nodeAffinity");
    v1_volume_node_affinity_t *nodeAffinity_local_nonprim = NULL;
    if (nodeAffinity) { 
    nodeAffinity_local_nonprim = v1_volume_node_affinity_parseFromJSON(nodeAffinity); //nonprimitive
    }

    // v1_persistent_volume_spec->persistentVolumeReclaimPolicy
    cJSON *persistentVolumeReclaimPolicy = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "persistentVolumeReclaimPolicy");
    if (persistentVolumeReclaimPolicy) { 
    if(!cJSON_IsString(persistentVolumeReclaimPolicy))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->photonPersistentDisk
    cJSON *photonPersistentDisk = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "photonPersistentDisk");
    v1_photon_persistent_disk_volume_source_t *photonPersistentDisk_local_nonprim = NULL;
    if (photonPersistentDisk) { 
    photonPersistentDisk_local_nonprim = v1_photon_persistent_disk_volume_source_parseFromJSON(photonPersistentDisk); //nonprimitive
    }

    // v1_persistent_volume_spec->portworxVolume
    cJSON *portworxVolume = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "portworxVolume");
    v1_portworx_volume_source_t *portworxVolume_local_nonprim = NULL;
    if (portworxVolume) { 
    portworxVolume_local_nonprim = v1_portworx_volume_source_parseFromJSON(portworxVolume); //nonprimitive
    }

    // v1_persistent_volume_spec->quobyte
    cJSON *quobyte = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "quobyte");
    v1_quobyte_volume_source_t *quobyte_local_nonprim = NULL;
    if (quobyte) { 
    quobyte_local_nonprim = v1_quobyte_volume_source_parseFromJSON(quobyte); //nonprimitive
    }

    // v1_persistent_volume_spec->rbd
    cJSON *rbd = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "rbd");
    v1_rbd_persistent_volume_source_t *rbd_local_nonprim = NULL;
    if (rbd) { 
    rbd_local_nonprim = v1_rbd_persistent_volume_source_parseFromJSON(rbd); //nonprimitive
    }

    // v1_persistent_volume_spec->scaleIO
    cJSON *scaleIO = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "scaleIO");
    v1_scale_io_persistent_volume_source_t *scaleIO_local_nonprim = NULL;
    if (scaleIO) { 
    scaleIO_local_nonprim = v1_scale_io_persistent_volume_source_parseFromJSON(scaleIO); //nonprimitive
    }

    // v1_persistent_volume_spec->storageClassName
    cJSON *storageClassName = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "storageClassName");
    if (storageClassName) { 
    if(!cJSON_IsString(storageClassName))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->storageos
    cJSON *storageos = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "storageos");
    v1_storage_os_persistent_volume_source_t *storageos_local_nonprim = NULL;
    if (storageos) { 
    storageos_local_nonprim = v1_storage_os_persistent_volume_source_parseFromJSON(storageos); //nonprimitive
    }

    // v1_persistent_volume_spec->volumeMode
    cJSON *volumeMode = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "volumeMode");
    if (volumeMode) { 
    if(!cJSON_IsString(volumeMode))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->vsphereVolume
    cJSON *vsphereVolume = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "vsphereVolume");
    v1_vsphere_virtual_disk_volume_source_t *vsphereVolume_local_nonprim = NULL;
    if (vsphereVolume) { 
    vsphereVolume_local_nonprim = v1_vsphere_virtual_disk_volume_source_parseFromJSON(vsphereVolume); //nonprimitive
    }


    v1_persistent_volume_spec_local_var = v1_persistent_volume_spec_create (
        accessModes ? access_modesList : NULL,
        awsElasticBlockStore ? awsElasticBlockStore_local_nonprim : NULL,
        azureDisk ? azureDisk_local_nonprim : NULL,
        azureFile ? azureFile_local_nonprim : NULL,
        capacity ? List : NULL,
        cephfs ? cephfs_local_nonprim : NULL,
        cinder ? cinder_local_nonprim : NULL,
        claimRef ? claimRef_local_nonprim : NULL,
        csi ? csi_local_nonprim : NULL,
        fc ? fc_local_nonprim : NULL,
        flexVolume ? flexVolume_local_nonprim : NULL,
        flocker ? flocker_local_nonprim : NULL,
        gcePersistentDisk ? gcePersistentDisk_local_nonprim : NULL,
        glusterfs ? glusterfs_local_nonprim : NULL,
        hostPath ? hostPath_local_nonprim : NULL,
        iscsi ? iscsi_local_nonprim : NULL,
        local ? local_local_nonprim : NULL,
        mountOptions ? mount_optionsList : NULL,
        nfs ? nfs_local_nonprim : NULL,
        nodeAffinity ? nodeAffinity_local_nonprim : NULL,
        persistentVolumeReclaimPolicy ? strdup(persistentVolumeReclaimPolicy->valuestring) : NULL,
        photonPersistentDisk ? photonPersistentDisk_local_nonprim : NULL,
        portworxVolume ? portworxVolume_local_nonprim : NULL,
        quobyte ? quobyte_local_nonprim : NULL,
        rbd ? rbd_local_nonprim : NULL,
        scaleIO ? scaleIO_local_nonprim : NULL,
        storageClassName ? strdup(storageClassName->valuestring) : NULL,
        storageos ? storageos_local_nonprim : NULL,
        volumeMode ? strdup(volumeMode->valuestring) : NULL,
        vsphereVolume ? vsphereVolume_local_nonprim : NULL
        );

    return v1_persistent_volume_spec_local_var;
end:
    return NULL;

}

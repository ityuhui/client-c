#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_pod_security_policy_spec.h"



policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec_create(
    int allowPrivilegeEscalation,
    list_t *allowedCSIDrivers,
    list_t *allowedCapabilities,
    list_t *allowedFlexVolumes,
    list_t *allowedHostPaths,
    list_t *allowedProcMountTypes,
    list_t *allowedUnsafeSysctls,
    list_t *defaultAddCapabilities,
    int defaultAllowPrivilegeEscalation,
    list_t *forbiddenSysctls,
    policy_v1beta1_fs_group_strategy_options_t *fsGroup,
    int hostIPC,
    int hostNetwork,
    int hostPID,
    list_t *hostPorts,
    int privileged,
    int readOnlyRootFilesystem,
    list_t *requiredDropCapabilities,
    policy_v1beta1_run_as_group_strategy_options_t *runAsGroup,
    policy_v1beta1_run_as_user_strategy_options_t *runAsUser,
    policy_v1beta1_runtime_class_strategy_options_t *runtimeClass,
    policy_v1beta1_se_linux_strategy_options_t *seLinux,
    policy_v1beta1_supplemental_groups_strategy_options_t *supplementalGroups,
    list_t *volumes
    ) {
	policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec_local_var = malloc(sizeof(policy_v1beta1_pod_security_policy_spec_t));
    if (!policy_v1beta1_pod_security_policy_spec_local_var) {
        return NULL;
    }
	policy_v1beta1_pod_security_policy_spec_local_var->allowPrivilegeEscalation = allowPrivilegeEscalation;
	policy_v1beta1_pod_security_policy_spec_local_var->allowedCSIDrivers = allowedCSIDrivers;
	policy_v1beta1_pod_security_policy_spec_local_var->allowedCapabilities = allowedCapabilities;
	policy_v1beta1_pod_security_policy_spec_local_var->allowedFlexVolumes = allowedFlexVolumes;
	policy_v1beta1_pod_security_policy_spec_local_var->allowedHostPaths = allowedHostPaths;
	policy_v1beta1_pod_security_policy_spec_local_var->allowedProcMountTypes = allowedProcMountTypes;
	policy_v1beta1_pod_security_policy_spec_local_var->allowedUnsafeSysctls = allowedUnsafeSysctls;
	policy_v1beta1_pod_security_policy_spec_local_var->defaultAddCapabilities = defaultAddCapabilities;
	policy_v1beta1_pod_security_policy_spec_local_var->defaultAllowPrivilegeEscalation = defaultAllowPrivilegeEscalation;
	policy_v1beta1_pod_security_policy_spec_local_var->forbiddenSysctls = forbiddenSysctls;
	policy_v1beta1_pod_security_policy_spec_local_var->fsGroup = fsGroup;
	policy_v1beta1_pod_security_policy_spec_local_var->hostIPC = hostIPC;
	policy_v1beta1_pod_security_policy_spec_local_var->hostNetwork = hostNetwork;
	policy_v1beta1_pod_security_policy_spec_local_var->hostPID = hostPID;
	policy_v1beta1_pod_security_policy_spec_local_var->hostPorts = hostPorts;
	policy_v1beta1_pod_security_policy_spec_local_var->privileged = privileged;
	policy_v1beta1_pod_security_policy_spec_local_var->readOnlyRootFilesystem = readOnlyRootFilesystem;
	policy_v1beta1_pod_security_policy_spec_local_var->requiredDropCapabilities = requiredDropCapabilities;
	policy_v1beta1_pod_security_policy_spec_local_var->runAsGroup = runAsGroup;
	policy_v1beta1_pod_security_policy_spec_local_var->runAsUser = runAsUser;
	policy_v1beta1_pod_security_policy_spec_local_var->runtimeClass = runtimeClass;
	policy_v1beta1_pod_security_policy_spec_local_var->seLinux = seLinux;
	policy_v1beta1_pod_security_policy_spec_local_var->supplementalGroups = supplementalGroups;
	policy_v1beta1_pod_security_policy_spec_local_var->volumes = volumes;

	return policy_v1beta1_pod_security_policy_spec_local_var;
}


void policy_v1beta1_pod_security_policy_spec_free(policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers) {
		policy_v1beta1_allowed_csi_driver_free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->allowedCapabilities) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->allowedCapabilities);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes) {
		policy_v1beta1_allowed_flex_volume_free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->allowedHostPaths) {
		policy_v1beta1_allowed_host_path_free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->allowedHostPaths);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->allowedProcMountTypes) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->allowedProcMountTypes);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->allowedUnsafeSysctls) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->allowedUnsafeSysctls);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->defaultAddCapabilities) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->defaultAddCapabilities);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->forbiddenSysctls) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->forbiddenSysctls);
    policy_v1beta1_fs_group_strategy_options_free(policy_v1beta1_pod_security_policy_spec->fsGroup);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->hostPorts) {
		policy_v1beta1_host_port_range_free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->hostPorts);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->requiredDropCapabilities) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->requiredDropCapabilities);
    policy_v1beta1_run_as_group_strategy_options_free(policy_v1beta1_pod_security_policy_spec->runAsGroup);
    policy_v1beta1_run_as_user_strategy_options_free(policy_v1beta1_pod_security_policy_spec->runAsUser);
    policy_v1beta1_runtime_class_strategy_options_free(policy_v1beta1_pod_security_policy_spec->runtimeClass);
    policy_v1beta1_se_linux_strategy_options_free(policy_v1beta1_pod_security_policy_spec->seLinux);
    policy_v1beta1_supplemental_groups_strategy_options_free(policy_v1beta1_pod_security_policy_spec->supplementalGroups);
	list_ForEach(listEntry, policy_v1beta1_pod_security_policy_spec->volumes) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_pod_security_policy_spec->volumes);
	free(policy_v1beta1_pod_security_policy_spec);
}

cJSON *policy_v1beta1_pod_security_policy_spec_convertToJSON(policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec) {
	cJSON *item = cJSON_CreateObject();

	// policy_v1beta1_pod_security_policy_spec->allowPrivilegeEscalation
    if(policy_v1beta1_pod_security_policy_spec->allowPrivilegeEscalation) { 
    if(cJSON_AddBoolToObject(item, "allowPrivilegeEscalation", policy_v1beta1_pod_security_policy_spec->allowPrivilegeEscalation) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers
    if(policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers) { 
    cJSON *allowedCSIDrivers = cJSON_AddArrayToObject(item, "allowedCSIDrivers");
    if(allowedCSIDrivers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowedCSIDriversListEntry;
    if (policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers) {
    list_ForEach(allowedCSIDriversListEntry, policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers) {
    cJSON *itemLocal = policy_v1beta1_allowed_csi_driver_convertToJSON(allowedCSIDriversListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowedCSIDrivers, itemLocal);
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->allowedCapabilities
    if(policy_v1beta1_pod_security_policy_spec->allowedCapabilities) { 
	cJSON *allowed_capabilities = cJSON_AddArrayToObject(item, "allowedCapabilities");
	if(allowed_capabilities == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *allowed_capabilitiesListEntry;
    list_ForEach(allowed_capabilitiesListEntry, policy_v1beta1_pod_security_policy_spec->allowedCapabilities) {
    if(cJSON_AddStringToObject(allowed_capabilities, "", (char*)allowed_capabilitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes
    if(policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes) { 
    cJSON *allowedFlexVolumes = cJSON_AddArrayToObject(item, "allowedFlexVolumes");
    if(allowedFlexVolumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowedFlexVolumesListEntry;
    if (policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes) {
    list_ForEach(allowedFlexVolumesListEntry, policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes) {
    cJSON *itemLocal = policy_v1beta1_allowed_flex_volume_convertToJSON(allowedFlexVolumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowedFlexVolumes, itemLocal);
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->allowedHostPaths
    if(policy_v1beta1_pod_security_policy_spec->allowedHostPaths) { 
    cJSON *allowedHostPaths = cJSON_AddArrayToObject(item, "allowedHostPaths");
    if(allowedHostPaths == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowedHostPathsListEntry;
    if (policy_v1beta1_pod_security_policy_spec->allowedHostPaths) {
    list_ForEach(allowedHostPathsListEntry, policy_v1beta1_pod_security_policy_spec->allowedHostPaths) {
    cJSON *itemLocal = policy_v1beta1_allowed_host_path_convertToJSON(allowedHostPathsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowedHostPaths, itemLocal);
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->allowedProcMountTypes
    if(policy_v1beta1_pod_security_policy_spec->allowedProcMountTypes) { 
	cJSON *allowed_proc_mount_types = cJSON_AddArrayToObject(item, "allowedProcMountTypes");
	if(allowed_proc_mount_types == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *allowed_proc_mount_typesListEntry;
    list_ForEach(allowed_proc_mount_typesListEntry, policy_v1beta1_pod_security_policy_spec->allowedProcMountTypes) {
    if(cJSON_AddStringToObject(allowed_proc_mount_types, "", (char*)allowed_proc_mount_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->allowedUnsafeSysctls
    if(policy_v1beta1_pod_security_policy_spec->allowedUnsafeSysctls) { 
	cJSON *allowed_unsafe_sysctls = cJSON_AddArrayToObject(item, "allowedUnsafeSysctls");
	if(allowed_unsafe_sysctls == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *allowed_unsafe_sysctlsListEntry;
    list_ForEach(allowed_unsafe_sysctlsListEntry, policy_v1beta1_pod_security_policy_spec->allowedUnsafeSysctls) {
    if(cJSON_AddStringToObject(allowed_unsafe_sysctls, "", (char*)allowed_unsafe_sysctlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->defaultAddCapabilities
    if(policy_v1beta1_pod_security_policy_spec->defaultAddCapabilities) { 
	cJSON *default_add_capabilities = cJSON_AddArrayToObject(item, "defaultAddCapabilities");
	if(default_add_capabilities == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *default_add_capabilitiesListEntry;
    list_ForEach(default_add_capabilitiesListEntry, policy_v1beta1_pod_security_policy_spec->defaultAddCapabilities) {
    if(cJSON_AddStringToObject(default_add_capabilities, "", (char*)default_add_capabilitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->defaultAllowPrivilegeEscalation
    if(policy_v1beta1_pod_security_policy_spec->defaultAllowPrivilegeEscalation) { 
    if(cJSON_AddBoolToObject(item, "defaultAllowPrivilegeEscalation", policy_v1beta1_pod_security_policy_spec->defaultAllowPrivilegeEscalation) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->forbiddenSysctls
    if(policy_v1beta1_pod_security_policy_spec->forbiddenSysctls) { 
	cJSON *forbidden_sysctls = cJSON_AddArrayToObject(item, "forbiddenSysctls");
	if(forbidden_sysctls == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *forbidden_sysctlsListEntry;
    list_ForEach(forbidden_sysctlsListEntry, policy_v1beta1_pod_security_policy_spec->forbiddenSysctls) {
    if(cJSON_AddStringToObject(forbidden_sysctls, "", (char*)forbidden_sysctlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->fsGroup
    if (!policy_v1beta1_pod_security_policy_spec->fsGroup) {
        goto fail;
    }
    
    cJSON *fsGroup_local_JSON = policy_v1beta1_fs_group_strategy_options_convertToJSON(policy_v1beta1_pod_security_policy_spec->fsGroup);
    if(fsGroup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fsGroup", fsGroup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// policy_v1beta1_pod_security_policy_spec->hostIPC
    if(policy_v1beta1_pod_security_policy_spec->hostIPC) { 
    if(cJSON_AddBoolToObject(item, "hostIPC", policy_v1beta1_pod_security_policy_spec->hostIPC) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->hostNetwork
    if(policy_v1beta1_pod_security_policy_spec->hostNetwork) { 
    if(cJSON_AddBoolToObject(item, "hostNetwork", policy_v1beta1_pod_security_policy_spec->hostNetwork) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->hostPID
    if(policy_v1beta1_pod_security_policy_spec->hostPID) { 
    if(cJSON_AddBoolToObject(item, "hostPID", policy_v1beta1_pod_security_policy_spec->hostPID) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->hostPorts
    if(policy_v1beta1_pod_security_policy_spec->hostPorts) { 
    cJSON *hostPorts = cJSON_AddArrayToObject(item, "hostPorts");
    if(hostPorts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *hostPortsListEntry;
    if (policy_v1beta1_pod_security_policy_spec->hostPorts) {
    list_ForEach(hostPortsListEntry, policy_v1beta1_pod_security_policy_spec->hostPorts) {
    cJSON *itemLocal = policy_v1beta1_host_port_range_convertToJSON(hostPortsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(hostPorts, itemLocal);
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->privileged
    if(policy_v1beta1_pod_security_policy_spec->privileged) { 
    if(cJSON_AddBoolToObject(item, "privileged", policy_v1beta1_pod_security_policy_spec->privileged) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->readOnlyRootFilesystem
    if(policy_v1beta1_pod_security_policy_spec->readOnlyRootFilesystem) { 
    if(cJSON_AddBoolToObject(item, "readOnlyRootFilesystem", policy_v1beta1_pod_security_policy_spec->readOnlyRootFilesystem) == NULL) {
    goto fail; //Bool
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->requiredDropCapabilities
    if(policy_v1beta1_pod_security_policy_spec->requiredDropCapabilities) { 
	cJSON *required_drop_capabilities = cJSON_AddArrayToObject(item, "requiredDropCapabilities");
	if(required_drop_capabilities == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *required_drop_capabilitiesListEntry;
    list_ForEach(required_drop_capabilitiesListEntry, policy_v1beta1_pod_security_policy_spec->requiredDropCapabilities) {
    if(cJSON_AddStringToObject(required_drop_capabilities, "", (char*)required_drop_capabilitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->runAsGroup
    if(policy_v1beta1_pod_security_policy_spec->runAsGroup) { 
    cJSON *runAsGroup_local_JSON = policy_v1beta1_run_as_group_strategy_options_convertToJSON(policy_v1beta1_pod_security_policy_spec->runAsGroup);
    if(runAsGroup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "runAsGroup", runAsGroup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->runAsUser
    if (!policy_v1beta1_pod_security_policy_spec->runAsUser) {
        goto fail;
    }
    
    cJSON *runAsUser_local_JSON = policy_v1beta1_run_as_user_strategy_options_convertToJSON(policy_v1beta1_pod_security_policy_spec->runAsUser);
    if(runAsUser_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "runAsUser", runAsUser_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// policy_v1beta1_pod_security_policy_spec->runtimeClass
    if(policy_v1beta1_pod_security_policy_spec->runtimeClass) { 
    cJSON *runtimeClass_local_JSON = policy_v1beta1_runtime_class_strategy_options_convertToJSON(policy_v1beta1_pod_security_policy_spec->runtimeClass);
    if(runtimeClass_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "runtimeClass", runtimeClass_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// policy_v1beta1_pod_security_policy_spec->seLinux
    if (!policy_v1beta1_pod_security_policy_spec->seLinux) {
        goto fail;
    }
    
    cJSON *seLinux_local_JSON = policy_v1beta1_se_linux_strategy_options_convertToJSON(policy_v1beta1_pod_security_policy_spec->seLinux);
    if(seLinux_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinux", seLinux_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// policy_v1beta1_pod_security_policy_spec->supplementalGroups
    if (!policy_v1beta1_pod_security_policy_spec->supplementalGroups) {
        goto fail;
    }
    
    cJSON *supplementalGroups_local_JSON = policy_v1beta1_supplemental_groups_strategy_options_convertToJSON(policy_v1beta1_pod_security_policy_spec->supplementalGroups);
    if(supplementalGroups_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "supplementalGroups", supplementalGroups_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// policy_v1beta1_pod_security_policy_spec->volumes
    if(policy_v1beta1_pod_security_policy_spec->volumes) { 
	cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
	if(volumes == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *volumesListEntry;
    list_ForEach(volumesListEntry, policy_v1beta1_pod_security_policy_spec->volumes) {
    if(cJSON_AddStringToObject(volumes, "", (char*)volumesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec_parseFromJSON(cJSON *policy_v1beta1_pod_security_policy_specJSON){

    policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec_local_var = NULL;

    // policy_v1beta1_pod_security_policy_spec->allowPrivilegeEscalation
    cJSON *allowPrivilegeEscalation = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowPrivilegeEscalation");
    if (allowPrivilegeEscalation) { 
    if(!cJSON_IsBool(allowPrivilegeEscalation))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->allowedCSIDrivers
    cJSON *allowedCSIDrivers = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowedCSIDrivers");
    list_t *allowedCSIDriversList;
    if (allowedCSIDrivers) { 
    cJSON *allowedCSIDrivers_local_nonprimitive;
    if(!cJSON_IsArray(allowedCSIDrivers)){
        goto end; //nonprimitive container
    }

    allowedCSIDriversList = list_create();

    cJSON_ArrayForEach(allowedCSIDrivers_local_nonprimitive,allowedCSIDrivers )
    {
        if(!cJSON_IsObject(allowedCSIDrivers_local_nonprimitive)){
            goto end;
        }
        policy_v1beta1_allowed_csi_driver_t *allowedCSIDriversItem = policy_v1beta1_allowed_csi_driver_parseFromJSON(allowedCSIDrivers_local_nonprimitive);

        list_addElement(allowedCSIDriversList, allowedCSIDriversItem);
    }
    }

    // policy_v1beta1_pod_security_policy_spec->allowedCapabilities
    cJSON *allowedCapabilities = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowedCapabilities");
    list_t *allowed_capabilitiesList;
    if (allowedCapabilities) { 
    cJSON *allowed_capabilities_local;
    if(!cJSON_IsArray(allowedCapabilities)) {
        goto end;//primitive container
    }
    allowed_capabilitiesList = list_create();

    cJSON_ArrayForEach(allowed_capabilities_local, allowedCapabilities)
    {
        if(!cJSON_IsString(allowed_capabilities_local))
        {
            goto end;
        }
        list_addElement(allowed_capabilitiesList , strdup(allowed_capabilities_local->valuestring));
    }
    }

    // policy_v1beta1_pod_security_policy_spec->allowedFlexVolumes
    cJSON *allowedFlexVolumes = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowedFlexVolumes");
    list_t *allowedFlexVolumesList;
    if (allowedFlexVolumes) { 
    cJSON *allowedFlexVolumes_local_nonprimitive;
    if(!cJSON_IsArray(allowedFlexVolumes)){
        goto end; //nonprimitive container
    }

    allowedFlexVolumesList = list_create();

    cJSON_ArrayForEach(allowedFlexVolumes_local_nonprimitive,allowedFlexVolumes )
    {
        if(!cJSON_IsObject(allowedFlexVolumes_local_nonprimitive)){
            goto end;
        }
        policy_v1beta1_allowed_flex_volume_t *allowedFlexVolumesItem = policy_v1beta1_allowed_flex_volume_parseFromJSON(allowedFlexVolumes_local_nonprimitive);

        list_addElement(allowedFlexVolumesList, allowedFlexVolumesItem);
    }
    }

    // policy_v1beta1_pod_security_policy_spec->allowedHostPaths
    cJSON *allowedHostPaths = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowedHostPaths");
    list_t *allowedHostPathsList;
    if (allowedHostPaths) { 
    cJSON *allowedHostPaths_local_nonprimitive;
    if(!cJSON_IsArray(allowedHostPaths)){
        goto end; //nonprimitive container
    }

    allowedHostPathsList = list_create();

    cJSON_ArrayForEach(allowedHostPaths_local_nonprimitive,allowedHostPaths )
    {
        if(!cJSON_IsObject(allowedHostPaths_local_nonprimitive)){
            goto end;
        }
        policy_v1beta1_allowed_host_path_t *allowedHostPathsItem = policy_v1beta1_allowed_host_path_parseFromJSON(allowedHostPaths_local_nonprimitive);

        list_addElement(allowedHostPathsList, allowedHostPathsItem);
    }
    }

    // policy_v1beta1_pod_security_policy_spec->allowedProcMountTypes
    cJSON *allowedProcMountTypes = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowedProcMountTypes");
    list_t *allowed_proc_mount_typesList;
    if (allowedProcMountTypes) { 
    cJSON *allowed_proc_mount_types_local;
    if(!cJSON_IsArray(allowedProcMountTypes)) {
        goto end;//primitive container
    }
    allowed_proc_mount_typesList = list_create();

    cJSON_ArrayForEach(allowed_proc_mount_types_local, allowedProcMountTypes)
    {
        if(!cJSON_IsString(allowed_proc_mount_types_local))
        {
            goto end;
        }
        list_addElement(allowed_proc_mount_typesList , strdup(allowed_proc_mount_types_local->valuestring));
    }
    }

    // policy_v1beta1_pod_security_policy_spec->allowedUnsafeSysctls
    cJSON *allowedUnsafeSysctls = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "allowedUnsafeSysctls");
    list_t *allowed_unsafe_sysctlsList;
    if (allowedUnsafeSysctls) { 
    cJSON *allowed_unsafe_sysctls_local;
    if(!cJSON_IsArray(allowedUnsafeSysctls)) {
        goto end;//primitive container
    }
    allowed_unsafe_sysctlsList = list_create();

    cJSON_ArrayForEach(allowed_unsafe_sysctls_local, allowedUnsafeSysctls)
    {
        if(!cJSON_IsString(allowed_unsafe_sysctls_local))
        {
            goto end;
        }
        list_addElement(allowed_unsafe_sysctlsList , strdup(allowed_unsafe_sysctls_local->valuestring));
    }
    }

    // policy_v1beta1_pod_security_policy_spec->defaultAddCapabilities
    cJSON *defaultAddCapabilities = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "defaultAddCapabilities");
    list_t *default_add_capabilitiesList;
    if (defaultAddCapabilities) { 
    cJSON *default_add_capabilities_local;
    if(!cJSON_IsArray(defaultAddCapabilities)) {
        goto end;//primitive container
    }
    default_add_capabilitiesList = list_create();

    cJSON_ArrayForEach(default_add_capabilities_local, defaultAddCapabilities)
    {
        if(!cJSON_IsString(default_add_capabilities_local))
        {
            goto end;
        }
        list_addElement(default_add_capabilitiesList , strdup(default_add_capabilities_local->valuestring));
    }
    }

    // policy_v1beta1_pod_security_policy_spec->defaultAllowPrivilegeEscalation
    cJSON *defaultAllowPrivilegeEscalation = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "defaultAllowPrivilegeEscalation");
    if (defaultAllowPrivilegeEscalation) { 
    if(!cJSON_IsBool(defaultAllowPrivilegeEscalation))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->forbiddenSysctls
    cJSON *forbiddenSysctls = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "forbiddenSysctls");
    list_t *forbidden_sysctlsList;
    if (forbiddenSysctls) { 
    cJSON *forbidden_sysctls_local;
    if(!cJSON_IsArray(forbiddenSysctls)) {
        goto end;//primitive container
    }
    forbidden_sysctlsList = list_create();

    cJSON_ArrayForEach(forbidden_sysctls_local, forbiddenSysctls)
    {
        if(!cJSON_IsString(forbidden_sysctls_local))
        {
            goto end;
        }
        list_addElement(forbidden_sysctlsList , strdup(forbidden_sysctls_local->valuestring));
    }
    }

    // policy_v1beta1_pod_security_policy_spec->fsGroup
    cJSON *fsGroup = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "fsGroup");
    if (!fsGroup) {
        goto end;
    }

    policy_v1beta1_fs_group_strategy_options_t *fsGroup_local_nonprim = NULL;
    
    fsGroup_local_nonprim = policy_v1beta1_fs_group_strategy_options_parseFromJSON(fsGroup); //nonprimitive

    // policy_v1beta1_pod_security_policy_spec->hostIPC
    cJSON *hostIPC = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "hostIPC");
    if (hostIPC) { 
    if(!cJSON_IsBool(hostIPC))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->hostNetwork
    cJSON *hostNetwork = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "hostNetwork");
    if (hostNetwork) { 
    if(!cJSON_IsBool(hostNetwork))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->hostPID
    cJSON *hostPID = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "hostPID");
    if (hostPID) { 
    if(!cJSON_IsBool(hostPID))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->hostPorts
    cJSON *hostPorts = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "hostPorts");
    list_t *hostPortsList;
    if (hostPorts) { 
    cJSON *hostPorts_local_nonprimitive;
    if(!cJSON_IsArray(hostPorts)){
        goto end; //nonprimitive container
    }

    hostPortsList = list_create();

    cJSON_ArrayForEach(hostPorts_local_nonprimitive,hostPorts )
    {
        if(!cJSON_IsObject(hostPorts_local_nonprimitive)){
            goto end;
        }
        policy_v1beta1_host_port_range_t *hostPortsItem = policy_v1beta1_host_port_range_parseFromJSON(hostPorts_local_nonprimitive);

        list_addElement(hostPortsList, hostPortsItem);
    }
    }

    // policy_v1beta1_pod_security_policy_spec->privileged
    cJSON *privileged = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "privileged");
    if (privileged) { 
    if(!cJSON_IsBool(privileged))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->readOnlyRootFilesystem
    cJSON *readOnlyRootFilesystem = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "readOnlyRootFilesystem");
    if (readOnlyRootFilesystem) { 
    if(!cJSON_IsBool(readOnlyRootFilesystem))
    {
    goto end; //Bool
    }
    }

    // policy_v1beta1_pod_security_policy_spec->requiredDropCapabilities
    cJSON *requiredDropCapabilities = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "requiredDropCapabilities");
    list_t *required_drop_capabilitiesList;
    if (requiredDropCapabilities) { 
    cJSON *required_drop_capabilities_local;
    if(!cJSON_IsArray(requiredDropCapabilities)) {
        goto end;//primitive container
    }
    required_drop_capabilitiesList = list_create();

    cJSON_ArrayForEach(required_drop_capabilities_local, requiredDropCapabilities)
    {
        if(!cJSON_IsString(required_drop_capabilities_local))
        {
            goto end;
        }
        list_addElement(required_drop_capabilitiesList , strdup(required_drop_capabilities_local->valuestring));
    }
    }

    // policy_v1beta1_pod_security_policy_spec->runAsGroup
    cJSON *runAsGroup = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "runAsGroup");
    policy_v1beta1_run_as_group_strategy_options_t *runAsGroup_local_nonprim = NULL;
    if (runAsGroup) { 
    runAsGroup_local_nonprim = policy_v1beta1_run_as_group_strategy_options_parseFromJSON(runAsGroup); //nonprimitive
    }

    // policy_v1beta1_pod_security_policy_spec->runAsUser
    cJSON *runAsUser = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "runAsUser");
    if (!runAsUser) {
        goto end;
    }

    policy_v1beta1_run_as_user_strategy_options_t *runAsUser_local_nonprim = NULL;
    
    runAsUser_local_nonprim = policy_v1beta1_run_as_user_strategy_options_parseFromJSON(runAsUser); //nonprimitive

    // policy_v1beta1_pod_security_policy_spec->runtimeClass
    cJSON *runtimeClass = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "runtimeClass");
    policy_v1beta1_runtime_class_strategy_options_t *runtimeClass_local_nonprim = NULL;
    if (runtimeClass) { 
    runtimeClass_local_nonprim = policy_v1beta1_runtime_class_strategy_options_parseFromJSON(runtimeClass); //nonprimitive
    }

    // policy_v1beta1_pod_security_policy_spec->seLinux
    cJSON *seLinux = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "seLinux");
    if (!seLinux) {
        goto end;
    }

    policy_v1beta1_se_linux_strategy_options_t *seLinux_local_nonprim = NULL;
    
    seLinux_local_nonprim = policy_v1beta1_se_linux_strategy_options_parseFromJSON(seLinux); //nonprimitive

    // policy_v1beta1_pod_security_policy_spec->supplementalGroups
    cJSON *supplementalGroups = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "supplementalGroups");
    if (!supplementalGroups) {
        goto end;
    }

    policy_v1beta1_supplemental_groups_strategy_options_t *supplementalGroups_local_nonprim = NULL;
    
    supplementalGroups_local_nonprim = policy_v1beta1_supplemental_groups_strategy_options_parseFromJSON(supplementalGroups); //nonprimitive

    // policy_v1beta1_pod_security_policy_spec->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policy_specJSON, "volumes");
    list_t *volumesList;
    if (volumes) { 
    cJSON *volumes_local;
    if(!cJSON_IsArray(volumes)) {
        goto end;//primitive container
    }
    volumesList = list_create();

    cJSON_ArrayForEach(volumes_local, volumes)
    {
        if(!cJSON_IsString(volumes_local))
        {
            goto end;
        }
        list_addElement(volumesList , strdup(volumes_local->valuestring));
    }
    }


    policy_v1beta1_pod_security_policy_spec_local_var = policy_v1beta1_pod_security_policy_spec_create (
        allowPrivilegeEscalation ? allowPrivilegeEscalation->valueint : 0,
        allowedCSIDrivers ? allowedCSIDriversList : NULL,
        allowedCapabilities ? allowed_capabilitiesList : NULL,
        allowedFlexVolumes ? allowedFlexVolumesList : NULL,
        allowedHostPaths ? allowedHostPathsList : NULL,
        allowedProcMountTypes ? allowed_proc_mount_typesList : NULL,
        allowedUnsafeSysctls ? allowed_unsafe_sysctlsList : NULL,
        defaultAddCapabilities ? default_add_capabilitiesList : NULL,
        defaultAllowPrivilegeEscalation ? defaultAllowPrivilegeEscalation->valueint : 0,
        forbiddenSysctls ? forbidden_sysctlsList : NULL,
        fsGroup_local_nonprim,
        hostIPC ? hostIPC->valueint : 0,
        hostNetwork ? hostNetwork->valueint : 0,
        hostPID ? hostPID->valueint : 0,
        hostPorts ? hostPortsList : NULL,
        privileged ? privileged->valueint : 0,
        readOnlyRootFilesystem ? readOnlyRootFilesystem->valueint : 0,
        requiredDropCapabilities ? required_drop_capabilitiesList : NULL,
        runAsGroup ? runAsGroup_local_nonprim : NULL,
        runAsUser_local_nonprim,
        runtimeClass ? runtimeClass_local_nonprim : NULL,
        seLinux_local_nonprim,
        supplementalGroups_local_nonprim,
        volumes ? volumesList : NULL
        );

    return policy_v1beta1_pod_security_policy_spec_local_var;
end:
    return NULL;

}

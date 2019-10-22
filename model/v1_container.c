#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container.h"



v1_container_t *v1_container_create(
    list_t *args,
    list_t *command,
    list_t *env,
    list_t *envFrom,
    char *image,
    char *imagePullPolicy,
    v1_lifecycle_t *lifecycle,
    v1_probe_t *livenessProbe,
    char *name,
    list_t *ports,
    v1_probe_t *readinessProbe,
    v1_resource_requirements_t *resources,
    v1_security_context_t *securityContext,
    v1_probe_t *startupProbe,
    int stdin,
    int stdinOnce,
    char *terminationMessagePath,
    char *terminationMessagePolicy,
    int tty,
    list_t *volumeDevices,
    list_t *volumeMounts,
    char *workingDir
    ) {
	v1_container_t *v1_container_local_var = malloc(sizeof(v1_container_t));
    if (!v1_container_local_var) {
        return NULL;
    }
	v1_container_local_var->args = args;
	v1_container_local_var->command = command;
	v1_container_local_var->env = env;
	v1_container_local_var->envFrom = envFrom;
	v1_container_local_var->image = image;
	v1_container_local_var->imagePullPolicy = imagePullPolicy;
	v1_container_local_var->lifecycle = lifecycle;
	v1_container_local_var->livenessProbe = livenessProbe;
	v1_container_local_var->name = name;
	v1_container_local_var->ports = ports;
	v1_container_local_var->readinessProbe = readinessProbe;
	v1_container_local_var->resources = resources;
	v1_container_local_var->securityContext = securityContext;
	v1_container_local_var->startupProbe = startupProbe;
	v1_container_local_var->stdin = stdin;
	v1_container_local_var->stdinOnce = stdinOnce;
	v1_container_local_var->terminationMessagePath = terminationMessagePath;
	v1_container_local_var->terminationMessagePolicy = terminationMessagePolicy;
	v1_container_local_var->tty = tty;
	v1_container_local_var->volumeDevices = volumeDevices;
	v1_container_local_var->volumeMounts = volumeMounts;
	v1_container_local_var->workingDir = workingDir;

	return v1_container_local_var;
}


void v1_container_free(v1_container_t *v1_container) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_container->args) {
		free(listEntry->data);
	}
	list_free(v1_container->args);
	list_ForEach(listEntry, v1_container->command) {
		free(listEntry->data);
	}
	list_free(v1_container->command);
	list_ForEach(listEntry, v1_container->env) {
		v1_env_var_free(listEntry->data);
	}
	list_free(v1_container->env);
	list_ForEach(listEntry, v1_container->envFrom) {
		v1_env_from_source_free(listEntry->data);
	}
	list_free(v1_container->envFrom);
    free(v1_container->image);
    free(v1_container->imagePullPolicy);
    v1_lifecycle_free(v1_container->lifecycle);
    v1_probe_free(v1_container->livenessProbe);
    free(v1_container->name);
	list_ForEach(listEntry, v1_container->ports) {
		v1_container_port_free(listEntry->data);
	}
	list_free(v1_container->ports);
    v1_probe_free(v1_container->readinessProbe);
    v1_resource_requirements_free(v1_container->resources);
    v1_security_context_free(v1_container->securityContext);
    v1_probe_free(v1_container->startupProbe);
    free(v1_container->terminationMessagePath);
    free(v1_container->terminationMessagePolicy);
	list_ForEach(listEntry, v1_container->volumeDevices) {
		v1_volume_device_free(listEntry->data);
	}
	list_free(v1_container->volumeDevices);
	list_ForEach(listEntry, v1_container->volumeMounts) {
		v1_volume_mount_free(listEntry->data);
	}
	list_free(v1_container->volumeMounts);
    free(v1_container->workingDir);
	free(v1_container);
}

cJSON *v1_container_convertToJSON(v1_container_t *v1_container) {
	cJSON *item = cJSON_CreateObject();

	// v1_container->args
    if(v1_container->args) { 
	cJSON *args = cJSON_AddArrayToObject(item, "args");
	if(args == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *argsListEntry;
    list_ForEach(argsListEntry, v1_container->args) {
    if(cJSON_AddStringToObject(args, "", (char*)argsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_container->command
    if(v1_container->command) { 
	cJSON *command = cJSON_AddArrayToObject(item, "command");
	if(command == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *commandListEntry;
    list_ForEach(commandListEntry, v1_container->command) {
    if(cJSON_AddStringToObject(command, "", (char*)commandListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_container->env
    if(v1_container->env) { 
    cJSON *env = cJSON_AddArrayToObject(item, "env");
    if(env == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *envListEntry;
    if (v1_container->env) {
    list_ForEach(envListEntry, v1_container->env) {
    cJSON *itemLocal = v1_env_var_convertToJSON(envListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(env, itemLocal);
    }
    }
     } 


	// v1_container->envFrom
    if(v1_container->envFrom) { 
    cJSON *envFrom = cJSON_AddArrayToObject(item, "envFrom");
    if(envFrom == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *envFromListEntry;
    if (v1_container->envFrom) {
    list_ForEach(envFromListEntry, v1_container->envFrom) {
    cJSON *itemLocal = v1_env_from_source_convertToJSON(envFromListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(envFrom, itemLocal);
    }
    }
     } 


	// v1_container->image
    if(v1_container->image) { 
    if(cJSON_AddStringToObject(item, "image", v1_container->image) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container->imagePullPolicy
    if(v1_container->imagePullPolicy) { 
    if(cJSON_AddStringToObject(item, "imagePullPolicy", v1_container->imagePullPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container->lifecycle
    if(v1_container->lifecycle) { 
    cJSON *lifecycle_local_JSON = v1_lifecycle_convertToJSON(v1_container->lifecycle);
    if(lifecycle_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lifecycle", lifecycle_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container->livenessProbe
    if(v1_container->livenessProbe) { 
    cJSON *livenessProbe_local_JSON = v1_probe_convertToJSON(v1_container->livenessProbe);
    if(livenessProbe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "livenessProbe", livenessProbe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container->name
    if (!v1_container->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_container->name) == NULL) {
    goto fail; //String
    }


	// v1_container->ports
    if(v1_container->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_container->ports) {
    list_ForEach(portsListEntry, v1_container->ports) {
    cJSON *itemLocal = v1_container_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
    }
    }
     } 


	// v1_container->readinessProbe
    if(v1_container->readinessProbe) { 
    cJSON *readinessProbe_local_JSON = v1_probe_convertToJSON(v1_container->readinessProbe);
    if(readinessProbe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "readinessProbe", readinessProbe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container->resources
    if(v1_container->resources) { 
    cJSON *resources_local_JSON = v1_resource_requirements_convertToJSON(v1_container->resources);
    if(resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resources", resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container->securityContext
    if(v1_container->securityContext) { 
    cJSON *securityContext_local_JSON = v1_security_context_convertToJSON(v1_container->securityContext);
    if(securityContext_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "securityContext", securityContext_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container->startupProbe
    if(v1_container->startupProbe) { 
    cJSON *startupProbe_local_JSON = v1_probe_convertToJSON(v1_container->startupProbe);
    if(startupProbe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "startupProbe", startupProbe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_container->stdin
    if(v1_container->stdin) { 
    if(cJSON_AddBoolToObject(item, "stdin", v1_container->stdin) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_container->stdinOnce
    if(v1_container->stdinOnce) { 
    if(cJSON_AddBoolToObject(item, "stdinOnce", v1_container->stdinOnce) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_container->terminationMessagePath
    if(v1_container->terminationMessagePath) { 
    if(cJSON_AddStringToObject(item, "terminationMessagePath", v1_container->terminationMessagePath) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container->terminationMessagePolicy
    if(v1_container->terminationMessagePolicy) { 
    if(cJSON_AddStringToObject(item, "terminationMessagePolicy", v1_container->terminationMessagePolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container->tty
    if(v1_container->tty) { 
    if(cJSON_AddBoolToObject(item, "tty", v1_container->tty) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_container->volumeDevices
    if(v1_container->volumeDevices) { 
    cJSON *volumeDevices = cJSON_AddArrayToObject(item, "volumeDevices");
    if(volumeDevices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumeDevicesListEntry;
    if (v1_container->volumeDevices) {
    list_ForEach(volumeDevicesListEntry, v1_container->volumeDevices) {
    cJSON *itemLocal = v1_volume_device_convertToJSON(volumeDevicesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumeDevices, itemLocal);
    }
    }
     } 


	// v1_container->volumeMounts
    if(v1_container->volumeMounts) { 
    cJSON *volumeMounts = cJSON_AddArrayToObject(item, "volumeMounts");
    if(volumeMounts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumeMountsListEntry;
    if (v1_container->volumeMounts) {
    list_ForEach(volumeMountsListEntry, v1_container->volumeMounts) {
    cJSON *itemLocal = v1_volume_mount_convertToJSON(volumeMountsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumeMounts, itemLocal);
    }
    }
     } 


	// v1_container->workingDir
    if(v1_container->workingDir) { 
    if(cJSON_AddStringToObject(item, "workingDir", v1_container->workingDir) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_container_t *v1_container_parseFromJSON(cJSON *v1_containerJSON){

    v1_container_t *v1_container_local_var = NULL;

    // v1_container->args
    cJSON *args = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "args");
    list_t *argsList;
    if (args) { 
    cJSON *args_local;
    if(!cJSON_IsArray(args)) {
        goto end;//primitive container
    }
    argsList = list_create();

    cJSON_ArrayForEach(args_local, args)
    {
        if(!cJSON_IsString(args_local))
        {
            goto end;
        }
        list_addElement(argsList , strdup(args_local->valuestring));
    }
    }

    // v1_container->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "command");
    list_t *commandList;
    if (command) { 
    cJSON *command_local;
    if(!cJSON_IsArray(command)) {
        goto end;//primitive container
    }
    commandList = list_create();

    cJSON_ArrayForEach(command_local, command)
    {
        if(!cJSON_IsString(command_local))
        {
            goto end;
        }
        list_addElement(commandList , strdup(command_local->valuestring));
    }
    }

    // v1_container->env
    cJSON *env = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "env");
    list_t *envList;
    if (env) { 
    cJSON *env_local_nonprimitive;
    if(!cJSON_IsArray(env)){
        goto end; //nonprimitive container
    }

    envList = list_create();

    cJSON_ArrayForEach(env_local_nonprimitive,env )
    {
        if(!cJSON_IsObject(env_local_nonprimitive)){
            goto end;
        }
        v1_env_var_t *envItem = v1_env_var_parseFromJSON(env_local_nonprimitive);

        list_addElement(envList, envItem);
    }
    }

    // v1_container->envFrom
    cJSON *envFrom = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "envFrom");
    list_t *envFromList;
    if (envFrom) { 
    cJSON *envFrom_local_nonprimitive;
    if(!cJSON_IsArray(envFrom)){
        goto end; //nonprimitive container
    }

    envFromList = list_create();

    cJSON_ArrayForEach(envFrom_local_nonprimitive,envFrom )
    {
        if(!cJSON_IsObject(envFrom_local_nonprimitive)){
            goto end;
        }
        v1_env_from_source_t *envFromItem = v1_env_from_source_parseFromJSON(envFrom_local_nonprimitive);

        list_addElement(envFromList, envFromItem);
    }
    }

    // v1_container->image
    cJSON *image = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "image");
    if (image) { 
    if(!cJSON_IsString(image))
    {
    goto end; //String
    }
    }

    // v1_container->imagePullPolicy
    cJSON *imagePullPolicy = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "imagePullPolicy");
    if (imagePullPolicy) { 
    if(!cJSON_IsString(imagePullPolicy))
    {
    goto end; //String
    }
    }

    // v1_container->lifecycle
    cJSON *lifecycle = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "lifecycle");
    v1_lifecycle_t *lifecycle_local_nonprim = NULL;
    if (lifecycle) { 
    lifecycle_local_nonprim = v1_lifecycle_parseFromJSON(lifecycle); //nonprimitive
    }

    // v1_container->livenessProbe
    cJSON *livenessProbe = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "livenessProbe");
    v1_probe_t *livenessProbe_local_nonprim = NULL;
    if (livenessProbe) { 
    livenessProbe_local_nonprim = v1_probe_parseFromJSON(livenessProbe); //nonprimitive
    }

    // v1_container->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_container->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1_container_port_t *portsItem = v1_container_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }

    // v1_container->readinessProbe
    cJSON *readinessProbe = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "readinessProbe");
    v1_probe_t *readinessProbe_local_nonprim = NULL;
    if (readinessProbe) { 
    readinessProbe_local_nonprim = v1_probe_parseFromJSON(readinessProbe); //nonprimitive
    }

    // v1_container->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "resources");
    v1_resource_requirements_t *resources_local_nonprim = NULL;
    if (resources) { 
    resources_local_nonprim = v1_resource_requirements_parseFromJSON(resources); //nonprimitive
    }

    // v1_container->securityContext
    cJSON *securityContext = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "securityContext");
    v1_security_context_t *securityContext_local_nonprim = NULL;
    if (securityContext) { 
    securityContext_local_nonprim = v1_security_context_parseFromJSON(securityContext); //nonprimitive
    }

    // v1_container->startupProbe
    cJSON *startupProbe = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "startupProbe");
    v1_probe_t *startupProbe_local_nonprim = NULL;
    if (startupProbe) { 
    startupProbe_local_nonprim = v1_probe_parseFromJSON(startupProbe); //nonprimitive
    }

    // v1_container->stdin
    cJSON *stdin = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "stdin");
    if (stdin) { 
    if(!cJSON_IsBool(stdin))
    {
    goto end; //Bool
    }
    }

    // v1_container->stdinOnce
    cJSON *stdinOnce = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "stdinOnce");
    if (stdinOnce) { 
    if(!cJSON_IsBool(stdinOnce))
    {
    goto end; //Bool
    }
    }

    // v1_container->terminationMessagePath
    cJSON *terminationMessagePath = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "terminationMessagePath");
    if (terminationMessagePath) { 
    if(!cJSON_IsString(terminationMessagePath))
    {
    goto end; //String
    }
    }

    // v1_container->terminationMessagePolicy
    cJSON *terminationMessagePolicy = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "terminationMessagePolicy");
    if (terminationMessagePolicy) { 
    if(!cJSON_IsString(terminationMessagePolicy))
    {
    goto end; //String
    }
    }

    // v1_container->tty
    cJSON *tty = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "tty");
    if (tty) { 
    if(!cJSON_IsBool(tty))
    {
    goto end; //Bool
    }
    }

    // v1_container->volumeDevices
    cJSON *volumeDevices = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "volumeDevices");
    list_t *volumeDevicesList;
    if (volumeDevices) { 
    cJSON *volumeDevices_local_nonprimitive;
    if(!cJSON_IsArray(volumeDevices)){
        goto end; //nonprimitive container
    }

    volumeDevicesList = list_create();

    cJSON_ArrayForEach(volumeDevices_local_nonprimitive,volumeDevices )
    {
        if(!cJSON_IsObject(volumeDevices_local_nonprimitive)){
            goto end;
        }
        v1_volume_device_t *volumeDevicesItem = v1_volume_device_parseFromJSON(volumeDevices_local_nonprimitive);

        list_addElement(volumeDevicesList, volumeDevicesItem);
    }
    }

    // v1_container->volumeMounts
    cJSON *volumeMounts = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "volumeMounts");
    list_t *volumeMountsList;
    if (volumeMounts) { 
    cJSON *volumeMounts_local_nonprimitive;
    if(!cJSON_IsArray(volumeMounts)){
        goto end; //nonprimitive container
    }

    volumeMountsList = list_create();

    cJSON_ArrayForEach(volumeMounts_local_nonprimitive,volumeMounts )
    {
        if(!cJSON_IsObject(volumeMounts_local_nonprimitive)){
            goto end;
        }
        v1_volume_mount_t *volumeMountsItem = v1_volume_mount_parseFromJSON(volumeMounts_local_nonprimitive);

        list_addElement(volumeMountsList, volumeMountsItem);
    }
    }

    // v1_container->workingDir
    cJSON *workingDir = cJSON_GetObjectItemCaseSensitive(v1_containerJSON, "workingDir");
    if (workingDir) { 
    if(!cJSON_IsString(workingDir))
    {
    goto end; //String
    }
    }


    v1_container_local_var = v1_container_create (
        args ? argsList : NULL,
        command ? commandList : NULL,
        env ? envList : NULL,
        envFrom ? envFromList : NULL,
        image ? strdup(image->valuestring) : NULL,
        imagePullPolicy ? strdup(imagePullPolicy->valuestring) : NULL,
        lifecycle ? lifecycle_local_nonprim : NULL,
        livenessProbe ? livenessProbe_local_nonprim : NULL,
        strdup(name->valuestring),
        ports ? portsList : NULL,
        readinessProbe ? readinessProbe_local_nonprim : NULL,
        resources ? resources_local_nonprim : NULL,
        securityContext ? securityContext_local_nonprim : NULL,
        startupProbe ? startupProbe_local_nonprim : NULL,
        stdin ? stdin->valueint : 0,
        stdinOnce ? stdinOnce->valueint : 0,
        terminationMessagePath ? strdup(terminationMessagePath->valuestring) : NULL,
        terminationMessagePolicy ? strdup(terminationMessagePolicy->valuestring) : NULL,
        tty ? tty->valueint : 0,
        volumeDevices ? volumeDevicesList : NULL,
        volumeMounts ? volumeMountsList : NULL,
        workingDir ? strdup(workingDir->valuestring) : NULL
        );

    return v1_container_local_var;
end:
    return NULL;

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_status.h"



v1_node_status_t *v1_node_status_create(
    list_t *addresses,
    list_t* allocatable,
    list_t* capacity,
    list_t *conditions,
    v1_node_config_status_t *config,
    v1_node_daemon_endpoints_t *daemon_endpoints,
    v1_node_features_t *features,
    list_t *images,
    v1_node_system_info_t *node_info,
    char *phase,
    list_t *runtime_handlers,
    list_t *volumes_attached,
    list_t *volumes_in_use
    ) {
    v1_node_status_t *v1_node_status_local_var = malloc(sizeof(v1_node_status_t));
    if (!v1_node_status_local_var) {
        return NULL;
    }
    v1_node_status_local_var->addresses = addresses;
    v1_node_status_local_var->allocatable = allocatable;
    v1_node_status_local_var->capacity = capacity;
    v1_node_status_local_var->conditions = conditions;
    v1_node_status_local_var->config = config;
    v1_node_status_local_var->daemon_endpoints = daemon_endpoints;
    v1_node_status_local_var->features = features;
    v1_node_status_local_var->images = images;
    v1_node_status_local_var->node_info = node_info;
    v1_node_status_local_var->phase = phase;
    v1_node_status_local_var->runtime_handlers = runtime_handlers;
    v1_node_status_local_var->volumes_attached = volumes_attached;
    v1_node_status_local_var->volumes_in_use = volumes_in_use;

    return v1_node_status_local_var;
}


void v1_node_status_free(v1_node_status_t *v1_node_status) {
    if(NULL == v1_node_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_status->addresses) {
        list_ForEach(listEntry, v1_node_status->addresses) {
            v1_node_address_free(listEntry->data);
        }
        list_freeList(v1_node_status->addresses);
        v1_node_status->addresses = NULL;
    }
    if (v1_node_status->allocatable) {
        list_ForEach(listEntry, v1_node_status->allocatable) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_node_status->allocatable);
        v1_node_status->allocatable = NULL;
    }
    if (v1_node_status->capacity) {
        list_ForEach(listEntry, v1_node_status->capacity) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_node_status->capacity);
        v1_node_status->capacity = NULL;
    }
    if (v1_node_status->conditions) {
        list_ForEach(listEntry, v1_node_status->conditions) {
            v1_node_condition_free(listEntry->data);
        }
        list_freeList(v1_node_status->conditions);
        v1_node_status->conditions = NULL;
    }
    if (v1_node_status->config) {
        v1_node_config_status_free(v1_node_status->config);
        v1_node_status->config = NULL;
    }
    if (v1_node_status->daemon_endpoints) {
        v1_node_daemon_endpoints_free(v1_node_status->daemon_endpoints);
        v1_node_status->daemon_endpoints = NULL;
    }
    if (v1_node_status->features) {
        v1_node_features_free(v1_node_status->features);
        v1_node_status->features = NULL;
    }
    if (v1_node_status->images) {
        list_ForEach(listEntry, v1_node_status->images) {
            v1_container_image_free(listEntry->data);
        }
        list_freeList(v1_node_status->images);
        v1_node_status->images = NULL;
    }
    if (v1_node_status->node_info) {
        v1_node_system_info_free(v1_node_status->node_info);
        v1_node_status->node_info = NULL;
    }
    if (v1_node_status->phase) {
        free(v1_node_status->phase);
        v1_node_status->phase = NULL;
    }
    if (v1_node_status->runtime_handlers) {
        list_ForEach(listEntry, v1_node_status->runtime_handlers) {
            v1_node_runtime_handler_free(listEntry->data);
        }
        list_freeList(v1_node_status->runtime_handlers);
        v1_node_status->runtime_handlers = NULL;
    }
    if (v1_node_status->volumes_attached) {
        list_ForEach(listEntry, v1_node_status->volumes_attached) {
            v1_attached_volume_free(listEntry->data);
        }
        list_freeList(v1_node_status->volumes_attached);
        v1_node_status->volumes_attached = NULL;
    }
    if (v1_node_status->volumes_in_use) {
        list_ForEach(listEntry, v1_node_status->volumes_in_use) {
            free(listEntry->data);
        }
        list_freeList(v1_node_status->volumes_in_use);
        v1_node_status->volumes_in_use = NULL;
    }
    free(v1_node_status);
}

cJSON *v1_node_status_convertToJSON(v1_node_status_t *v1_node_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_status->addresses
    if(v1_node_status->addresses) {
    cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
    if(addresses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *addressesListEntry;
    if (v1_node_status->addresses) {
    list_ForEach(addressesListEntry, v1_node_status->addresses) {
    cJSON *itemLocal = v1_node_address_convertToJSON(addressesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(addresses, itemLocal);
    }
    }
    }


    // v1_node_status->allocatable
    if(v1_node_status->allocatable) {
    cJSON *allocatable = cJSON_AddObjectToObject(item, "allocatable");
    if(allocatable == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = allocatable;
    listEntry_t *allocatableListEntry;
    if (v1_node_status->allocatable) {
    list_ForEach(allocatableListEntry, v1_node_status->allocatable) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)allocatableListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_node_status->capacity
    if(v1_node_status->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1_node_status->capacity) {
    list_ForEach(capacityListEntry, v1_node_status->capacity) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_node_status->conditions
    if(v1_node_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_node_status->conditions) {
    list_ForEach(conditionsListEntry, v1_node_status->conditions) {
    cJSON *itemLocal = v1_node_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_node_status->config
    if(v1_node_status->config) {
    cJSON *config_local_JSON = v1_node_config_status_convertToJSON(v1_node_status->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_status->daemon_endpoints
    if(v1_node_status->daemon_endpoints) {
    cJSON *daemon_endpoints_local_JSON = v1_node_daemon_endpoints_convertToJSON(v1_node_status->daemon_endpoints);
    if(daemon_endpoints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "daemonEndpoints", daemon_endpoints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_status->features
    if(v1_node_status->features) {
    cJSON *features_local_JSON = v1_node_features_convertToJSON(v1_node_status->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_status->images
    if(v1_node_status->images) {
    cJSON *images = cJSON_AddArrayToObject(item, "images");
    if(images == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *imagesListEntry;
    if (v1_node_status->images) {
    list_ForEach(imagesListEntry, v1_node_status->images) {
    cJSON *itemLocal = v1_container_image_convertToJSON(imagesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(images, itemLocal);
    }
    }
    }


    // v1_node_status->node_info
    if(v1_node_status->node_info) {
    cJSON *node_info_local_JSON = v1_node_system_info_convertToJSON(v1_node_status->node_info);
    if(node_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeInfo", node_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_status->phase
    if(v1_node_status->phase) {
    if(cJSON_AddStringToObject(item, "phase", v1_node_status->phase) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_status->runtime_handlers
    if(v1_node_status->runtime_handlers) {
    cJSON *runtime_handlers = cJSON_AddArrayToObject(item, "runtimeHandlers");
    if(runtime_handlers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *runtime_handlersListEntry;
    if (v1_node_status->runtime_handlers) {
    list_ForEach(runtime_handlersListEntry, v1_node_status->runtime_handlers) {
    cJSON *itemLocal = v1_node_runtime_handler_convertToJSON(runtime_handlersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(runtime_handlers, itemLocal);
    }
    }
    }


    // v1_node_status->volumes_attached
    if(v1_node_status->volumes_attached) {
    cJSON *volumes_attached = cJSON_AddArrayToObject(item, "volumesAttached");
    if(volumes_attached == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumes_attachedListEntry;
    if (v1_node_status->volumes_attached) {
    list_ForEach(volumes_attachedListEntry, v1_node_status->volumes_attached) {
    cJSON *itemLocal = v1_attached_volume_convertToJSON(volumes_attachedListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumes_attached, itemLocal);
    }
    }
    }


    // v1_node_status->volumes_in_use
    if(v1_node_status->volumes_in_use) {
    cJSON *volumes_in_use = cJSON_AddArrayToObject(item, "volumesInUse");
    if(volumes_in_use == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *volumes_in_useListEntry;
    list_ForEach(volumes_in_useListEntry, v1_node_status->volumes_in_use) {
    if(cJSON_AddStringToObject(volumes_in_use, "", (char*)volumes_in_useListEntry->data) == NULL)
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

v1_node_status_t *v1_node_status_parseFromJSON(cJSON *v1_node_statusJSON){

    v1_node_status_t *v1_node_status_local_var = NULL;

    // define the local list for v1_node_status->addresses
    list_t *addressesList = NULL;

    // define the local map for v1_node_status->allocatable
    list_t *allocatableList = NULL;

    // define the local map for v1_node_status->capacity
    list_t *capacityList = NULL;

    // define the local list for v1_node_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_node_status->config
    v1_node_config_status_t *config_local_nonprim = NULL;

    // define the local variable for v1_node_status->daemon_endpoints
    v1_node_daemon_endpoints_t *daemon_endpoints_local_nonprim = NULL;

    // define the local variable for v1_node_status->features
    v1_node_features_t *features_local_nonprim = NULL;

    // define the local list for v1_node_status->images
    list_t *imagesList = NULL;

    // define the local variable for v1_node_status->node_info
    v1_node_system_info_t *node_info_local_nonprim = NULL;

    // define the local list for v1_node_status->runtime_handlers
    list_t *runtime_handlersList = NULL;

    // define the local list for v1_node_status->volumes_attached
    list_t *volumes_attachedList = NULL;

    // define the local list for v1_node_status->volumes_in_use
    list_t *volumes_in_useList = NULL;

    // v1_node_status->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "addresses");
    if (addresses) { 
    cJSON *addresses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(addresses)){
        goto end; //nonprimitive container
    }

    addressesList = list_createList();

    cJSON_ArrayForEach(addresses_local_nonprimitive,addresses )
    {
        if(!cJSON_IsObject(addresses_local_nonprimitive)){
            goto end;
        }
        v1_node_address_t *addressesItem = v1_node_address_parseFromJSON(addresses_local_nonprimitive);

        list_addElement(addressesList, addressesItem);
    }
    }

    // v1_node_status->allocatable
    cJSON *allocatable = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "allocatable");
    if (allocatable) { 
    cJSON *allocatable_local_map = NULL;
    if(!cJSON_IsObject(allocatable) && !cJSON_IsNull(allocatable))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(allocatable))
    {
        allocatableList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(allocatable_local_map, allocatable)
        {
            cJSON *localMapObject = allocatable_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(allocatableList , localMapKeyPair);
        }
    }
    }

    // v1_node_status->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "capacity");
    if (capacity) { 
    cJSON *capacity_local_map = NULL;
    if(!cJSON_IsObject(capacity) && !cJSON_IsNull(capacity))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(capacity))
    {
        capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(capacity_local_map, capacity)
        {
            cJSON *localMapObject = capacity_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(capacityList , localMapKeyPair);
        }
    }
    }

    // v1_node_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "conditions");
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_node_condition_t *conditionsItem = v1_node_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_node_status->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "config");
    if (config) { 
    config_local_nonprim = v1_node_config_status_parseFromJSON(config); //nonprimitive
    }

    // v1_node_status->daemon_endpoints
    cJSON *daemon_endpoints = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "daemonEndpoints");
    if (daemon_endpoints) { 
    daemon_endpoints_local_nonprim = v1_node_daemon_endpoints_parseFromJSON(daemon_endpoints); //nonprimitive
    }

    // v1_node_status->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "features");
    if (features) { 
    features_local_nonprim = v1_node_features_parseFromJSON(features); //nonprimitive
    }

    // v1_node_status->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "images");
    if (images) { 
    cJSON *images_local_nonprimitive = NULL;
    if(!cJSON_IsArray(images)){
        goto end; //nonprimitive container
    }

    imagesList = list_createList();

    cJSON_ArrayForEach(images_local_nonprimitive,images )
    {
        if(!cJSON_IsObject(images_local_nonprimitive)){
            goto end;
        }
        v1_container_image_t *imagesItem = v1_container_image_parseFromJSON(images_local_nonprimitive);

        list_addElement(imagesList, imagesItem);
    }
    }

    // v1_node_status->node_info
    cJSON *node_info = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "nodeInfo");
    if (node_info) { 
    node_info_local_nonprim = v1_node_system_info_parseFromJSON(node_info); //nonprimitive
    }

    // v1_node_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "phase");
    if (phase) { 
    if(!cJSON_IsString(phase) && !cJSON_IsNull(phase))
    {
    goto end; //String
    }
    }

    // v1_node_status->runtime_handlers
    cJSON *runtime_handlers = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "runtimeHandlers");
    if (runtime_handlers) { 
    cJSON *runtime_handlers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(runtime_handlers)){
        goto end; //nonprimitive container
    }

    runtime_handlersList = list_createList();

    cJSON_ArrayForEach(runtime_handlers_local_nonprimitive,runtime_handlers )
    {
        if(!cJSON_IsObject(runtime_handlers_local_nonprimitive)){
            goto end;
        }
        v1_node_runtime_handler_t *runtime_handlersItem = v1_node_runtime_handler_parseFromJSON(runtime_handlers_local_nonprimitive);

        list_addElement(runtime_handlersList, runtime_handlersItem);
    }
    }

    // v1_node_status->volumes_attached
    cJSON *volumes_attached = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "volumesAttached");
    if (volumes_attached) { 
    cJSON *volumes_attached_local_nonprimitive = NULL;
    if(!cJSON_IsArray(volumes_attached)){
        goto end; //nonprimitive container
    }

    volumes_attachedList = list_createList();

    cJSON_ArrayForEach(volumes_attached_local_nonprimitive,volumes_attached )
    {
        if(!cJSON_IsObject(volumes_attached_local_nonprimitive)){
            goto end;
        }
        v1_attached_volume_t *volumes_attachedItem = v1_attached_volume_parseFromJSON(volumes_attached_local_nonprimitive);

        list_addElement(volumes_attachedList, volumes_attachedItem);
    }
    }

    // v1_node_status->volumes_in_use
    cJSON *volumes_in_use = cJSON_GetObjectItemCaseSensitive(v1_node_statusJSON, "volumesInUse");
    if (volumes_in_use) { 
    cJSON *volumes_in_use_local = NULL;
    if(!cJSON_IsArray(volumes_in_use)) {
        goto end;//primitive container
    }
    volumes_in_useList = list_createList();

    cJSON_ArrayForEach(volumes_in_use_local, volumes_in_use)
    {
        if(!cJSON_IsString(volumes_in_use_local))
        {
            goto end;
        }
        list_addElement(volumes_in_useList , strdup(volumes_in_use_local->valuestring));
    }
    }


    v1_node_status_local_var = v1_node_status_create (
        addresses ? addressesList : NULL,
        allocatable ? allocatableList : NULL,
        capacity ? capacityList : NULL,
        conditions ? conditionsList : NULL,
        config ? config_local_nonprim : NULL,
        daemon_endpoints ? daemon_endpoints_local_nonprim : NULL,
        features ? features_local_nonprim : NULL,
        images ? imagesList : NULL,
        node_info ? node_info_local_nonprim : NULL,
        phase && !cJSON_IsNull(phase) ? strdup(phase->valuestring) : NULL,
        runtime_handlers ? runtime_handlersList : NULL,
        volumes_attached ? volumes_attachedList : NULL,
        volumes_in_use ? volumes_in_useList : NULL
        );

    return v1_node_status_local_var;
end:
    if (addressesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, addressesList) {
            v1_node_address_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(addressesList);
        addressesList = NULL;
    }
    if (allocatableList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allocatableList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(allocatableList);
        allocatableList = NULL;
    }
    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_node_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (config_local_nonprim) {
        v1_node_config_status_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (daemon_endpoints_local_nonprim) {
        v1_node_daemon_endpoints_free(daemon_endpoints_local_nonprim);
        daemon_endpoints_local_nonprim = NULL;
    }
    if (features_local_nonprim) {
        v1_node_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    if (imagesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, imagesList) {
            v1_container_image_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(imagesList);
        imagesList = NULL;
    }
    if (node_info_local_nonprim) {
        v1_node_system_info_free(node_info_local_nonprim);
        node_info_local_nonprim = NULL;
    }
    if (runtime_handlersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, runtime_handlersList) {
            v1_node_runtime_handler_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(runtime_handlersList);
        runtime_handlersList = NULL;
    }
    if (volumes_attachedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volumes_attachedList) {
            v1_attached_volume_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volumes_attachedList);
        volumes_attachedList = NULL;
    }
    if (volumes_in_useList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volumes_in_useList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volumes_in_useList);
        volumes_in_useList = NULL;
    }
    return NULL;

}

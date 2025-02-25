#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_status.h"



static v1_stateful_set_status_t *v1_stateful_set_status_create_internal(
    int available_replicas,
    int collision_count,
    list_t *conditions,
    int current_replicas,
    char *current_revision,
    long observed_generation,
    int ready_replicas,
    int replicas,
    char *update_revision,
    int updated_replicas
    ) {
    v1_stateful_set_status_t *v1_stateful_set_status_local_var = malloc(sizeof(v1_stateful_set_status_t));
    if (!v1_stateful_set_status_local_var) {
        return NULL;
    }
    v1_stateful_set_status_local_var->available_replicas = available_replicas;
    v1_stateful_set_status_local_var->collision_count = collision_count;
    v1_stateful_set_status_local_var->conditions = conditions;
    v1_stateful_set_status_local_var->current_replicas = current_replicas;
    v1_stateful_set_status_local_var->current_revision = current_revision;
    v1_stateful_set_status_local_var->observed_generation = observed_generation;
    v1_stateful_set_status_local_var->ready_replicas = ready_replicas;
    v1_stateful_set_status_local_var->replicas = replicas;
    v1_stateful_set_status_local_var->update_revision = update_revision;
    v1_stateful_set_status_local_var->updated_replicas = updated_replicas;

    v1_stateful_set_status_local_var->_library_owned = 1;
    return v1_stateful_set_status_local_var;
}

__attribute__((deprecated)) v1_stateful_set_status_t *v1_stateful_set_status_create(
    int available_replicas,
    int collision_count,
    list_t *conditions,
    int current_replicas,
    char *current_revision,
    long observed_generation,
    int ready_replicas,
    int replicas,
    char *update_revision,
    int updated_replicas
    ) {
    return v1_stateful_set_status_create_internal (
        available_replicas,
        collision_count,
        conditions,
        current_replicas,
        current_revision,
        observed_generation,
        ready_replicas,
        replicas,
        update_revision,
        updated_replicas
        );
}

void v1_stateful_set_status_free(v1_stateful_set_status_t *v1_stateful_set_status) {
    if(NULL == v1_stateful_set_status){
        return ;
    }
    if(v1_stateful_set_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_stateful_set_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_stateful_set_status->conditions) {
        list_ForEach(listEntry, v1_stateful_set_status->conditions) {
            v1_stateful_set_condition_free(listEntry->data);
        }
        list_freeList(v1_stateful_set_status->conditions);
        v1_stateful_set_status->conditions = NULL;
    }
    if (v1_stateful_set_status->current_revision) {
        free(v1_stateful_set_status->current_revision);
        v1_stateful_set_status->current_revision = NULL;
    }
    if (v1_stateful_set_status->update_revision) {
        free(v1_stateful_set_status->update_revision);
        v1_stateful_set_status->update_revision = NULL;
    }
    free(v1_stateful_set_status);
}

cJSON *v1_stateful_set_status_convertToJSON(v1_stateful_set_status_t *v1_stateful_set_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_stateful_set_status->available_replicas
    if(v1_stateful_set_status->available_replicas) {
    if(cJSON_AddNumberToObject(item, "availableReplicas", v1_stateful_set_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->collision_count
    if(v1_stateful_set_status->collision_count) {
    if(cJSON_AddNumberToObject(item, "collisionCount", v1_stateful_set_status->collision_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->conditions
    if(v1_stateful_set_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_stateful_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_stateful_set_status->conditions) {
    cJSON *itemLocal = v1_stateful_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_stateful_set_status->current_replicas
    if(v1_stateful_set_status->current_replicas) {
    if(cJSON_AddNumberToObject(item, "currentReplicas", v1_stateful_set_status->current_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->current_revision
    if(v1_stateful_set_status->current_revision) {
    if(cJSON_AddStringToObject(item, "currentRevision", v1_stateful_set_status->current_revision) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_status->observed_generation
    if(v1_stateful_set_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_stateful_set_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->ready_replicas
    if(v1_stateful_set_status->ready_replicas) {
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1_stateful_set_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_stateful_set_status->replicas
    if (!v1_stateful_set_status->replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "replicas", v1_stateful_set_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_stateful_set_status->update_revision
    if(v1_stateful_set_status->update_revision) {
    if(cJSON_AddStringToObject(item, "updateRevision", v1_stateful_set_status->update_revision) == NULL) {
    goto fail; //String
    }
    }


    // v1_stateful_set_status->updated_replicas
    if(v1_stateful_set_status->updated_replicas) {
    if(cJSON_AddNumberToObject(item, "updatedReplicas", v1_stateful_set_status->updated_replicas) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_stateful_set_status_t *v1_stateful_set_status_parseFromJSON(cJSON *v1_stateful_set_statusJSON){

    v1_stateful_set_status_t *v1_stateful_set_status_local_var = NULL;

    // define the local list for v1_stateful_set_status->conditions
    list_t *conditionsList = NULL;

    // v1_stateful_set_status->available_replicas
    cJSON *available_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "availableReplicas");
    if (cJSON_IsNull(available_replicas)) {
        available_replicas = NULL;
    }
    if (available_replicas) { 
    if(!cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_stateful_set_status->collision_count
    cJSON *collision_count = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "collisionCount");
    if (cJSON_IsNull(collision_count)) {
        collision_count = NULL;
    }
    if (collision_count) { 
    if(!cJSON_IsNumber(collision_count))
    {
    goto end; //Numeric
    }
    }

    // v1_stateful_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
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
        v1_stateful_set_condition_t *conditionsItem = v1_stateful_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_stateful_set_status->current_replicas
    cJSON *current_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "currentReplicas");
    if (cJSON_IsNull(current_replicas)) {
        current_replicas = NULL;
    }
    if (current_replicas) { 
    if(!cJSON_IsNumber(current_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_stateful_set_status->current_revision
    cJSON *current_revision = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "currentRevision");
    if (cJSON_IsNull(current_revision)) {
        current_revision = NULL;
    }
    if (current_revision) { 
    if(!cJSON_IsString(current_revision) && !cJSON_IsNull(current_revision))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1_stateful_set_status->ready_replicas
    cJSON *ready_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "readyReplicas");
    if (cJSON_IsNull(ready_replicas)) {
        ready_replicas = NULL;
    }
    if (ready_replicas) { 
    if(!cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_stateful_set_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "replicas");
    if (cJSON_IsNull(replicas)) {
        replicas = NULL;
    }
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // v1_stateful_set_status->update_revision
    cJSON *update_revision = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "updateRevision");
    if (cJSON_IsNull(update_revision)) {
        update_revision = NULL;
    }
    if (update_revision) { 
    if(!cJSON_IsString(update_revision) && !cJSON_IsNull(update_revision))
    {
    goto end; //String
    }
    }

    // v1_stateful_set_status->updated_replicas
    cJSON *updated_replicas = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_statusJSON, "updatedReplicas");
    if (cJSON_IsNull(updated_replicas)) {
        updated_replicas = NULL;
    }
    if (updated_replicas) { 
    if(!cJSON_IsNumber(updated_replicas))
    {
    goto end; //Numeric
    }
    }


    v1_stateful_set_status_local_var = v1_stateful_set_status_create_internal (
        available_replicas ? available_replicas->valuedouble : 0,
        collision_count ? collision_count->valuedouble : 0,
        conditions ? conditionsList : NULL,
        current_replicas ? current_replicas->valuedouble : 0,
        current_revision && !cJSON_IsNull(current_revision) ? strdup(current_revision->valuestring) : NULL,
        observed_generation ? observed_generation->valuedouble : 0,
        ready_replicas ? ready_replicas->valuedouble : 0,
        replicas->valuedouble,
        update_revision && !cJSON_IsNull(update_revision) ? strdup(update_revision->valuestring) : NULL,
        updated_replicas ? updated_replicas->valuedouble : 0
        );

    return v1_stateful_set_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_stateful_set_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}

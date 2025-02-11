#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace_status.h"



static v1_namespace_status_t *v1_namespace_status_create_internal(
    list_t *conditions,
    char *phase
    ) {
    v1_namespace_status_t *v1_namespace_status_local_var = malloc(sizeof(v1_namespace_status_t));
    if (!v1_namespace_status_local_var) {
        return NULL;
    }
    v1_namespace_status_local_var->conditions = conditions;
    v1_namespace_status_local_var->phase = phase;

    v1_namespace_status_local_var->_library_owned = 1;
    return v1_namespace_status_local_var;
}

__attribute__((deprecated)) v1_namespace_status_t *v1_namespace_status_create(
    list_t *conditions,
    char *phase
    ) {
    return v1_namespace_status_create_internal (
        conditions,
        phase
        );
}

void v1_namespace_status_free(v1_namespace_status_t *v1_namespace_status) {
    if(NULL == v1_namespace_status){
        return ;
    }
    if(v1_namespace_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_namespace_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace_status->conditions) {
        list_ForEach(listEntry, v1_namespace_status->conditions) {
            v1_namespace_condition_free(listEntry->data);
        }
        list_freeList(v1_namespace_status->conditions);
        v1_namespace_status->conditions = NULL;
    }
    if (v1_namespace_status->phase) {
        free(v1_namespace_status->phase);
        v1_namespace_status->phase = NULL;
    }
    free(v1_namespace_status);
}

cJSON *v1_namespace_status_convertToJSON(v1_namespace_status_t *v1_namespace_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_namespace_status->conditions
    if(v1_namespace_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_namespace_status->conditions) {
    list_ForEach(conditionsListEntry, v1_namespace_status->conditions) {
    cJSON *itemLocal = v1_namespace_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_namespace_status->phase
    if(v1_namespace_status->phase) {
    if(cJSON_AddStringToObject(item, "phase", v1_namespace_status->phase) == NULL) {
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

v1_namespace_status_t *v1_namespace_status_parseFromJSON(cJSON *v1_namespace_statusJSON){

    v1_namespace_status_t *v1_namespace_status_local_var = NULL;

    // define the local list for v1_namespace_status->conditions
    list_t *conditionsList = NULL;

    // v1_namespace_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_namespace_statusJSON, "conditions");
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
        v1_namespace_condition_t *conditionsItem = v1_namespace_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_namespace_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_namespace_statusJSON, "phase");
    if (cJSON_IsNull(phase)) {
        phase = NULL;
    }
    if (phase) { 
    if(!cJSON_IsString(phase) && !cJSON_IsNull(phase))
    {
    goto end; //String
    }
    }


    v1_namespace_status_local_var = v1_namespace_status_create_internal (
        conditions ? conditionsList : NULL,
        phase && !cJSON_IsNull(phase) ? strdup(phase->valuestring) : NULL
        );

    return v1_namespace_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_namespace_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}

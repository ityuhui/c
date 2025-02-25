#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_access_review_status.h"



static v1_subject_access_review_status_t *v1_subject_access_review_status_create_internal(
    int allowed,
    int denied,
    char *evaluation_error,
    char *reason
    ) {
    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = malloc(sizeof(v1_subject_access_review_status_t));
    if (!v1_subject_access_review_status_local_var) {
        return NULL;
    }
    v1_subject_access_review_status_local_var->allowed = allowed;
    v1_subject_access_review_status_local_var->denied = denied;
    v1_subject_access_review_status_local_var->evaluation_error = evaluation_error;
    v1_subject_access_review_status_local_var->reason = reason;

    v1_subject_access_review_status_local_var->_library_owned = 1;
    return v1_subject_access_review_status_local_var;
}

__attribute__((deprecated)) v1_subject_access_review_status_t *v1_subject_access_review_status_create(
    int allowed,
    int denied,
    char *evaluation_error,
    char *reason
    ) {
    return v1_subject_access_review_status_create_internal (
        allowed,
        denied,
        evaluation_error,
        reason
        );
}

void v1_subject_access_review_status_free(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    if(NULL == v1_subject_access_review_status){
        return ;
    }
    if(v1_subject_access_review_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_subject_access_review_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_subject_access_review_status->evaluation_error) {
        free(v1_subject_access_review_status->evaluation_error);
        v1_subject_access_review_status->evaluation_error = NULL;
    }
    if (v1_subject_access_review_status->reason) {
        free(v1_subject_access_review_status->reason);
        v1_subject_access_review_status->reason = NULL;
    }
    free(v1_subject_access_review_status);
}

cJSON *v1_subject_access_review_status_convertToJSON(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_subject_access_review_status->allowed
    if (!v1_subject_access_review_status->allowed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "allowed", v1_subject_access_review_status->allowed) == NULL) {
    goto fail; //Bool
    }


    // v1_subject_access_review_status->denied
    if(v1_subject_access_review_status->denied) {
    if(cJSON_AddBoolToObject(item, "denied", v1_subject_access_review_status->denied) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_subject_access_review_status->evaluation_error
    if(v1_subject_access_review_status->evaluation_error) {
    if(cJSON_AddStringToObject(item, "evaluationError", v1_subject_access_review_status->evaluation_error) == NULL) {
    goto fail; //String
    }
    }


    // v1_subject_access_review_status->reason
    if(v1_subject_access_review_status->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_subject_access_review_status->reason) == NULL) {
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

v1_subject_access_review_status_t *v1_subject_access_review_status_parseFromJSON(cJSON *v1_subject_access_review_statusJSON){

    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = NULL;

    // v1_subject_access_review_status->allowed
    cJSON *allowed = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "allowed");
    if (cJSON_IsNull(allowed)) {
        allowed = NULL;
    }
    if (!allowed) {
        goto end;
    }

    
    if(!cJSON_IsBool(allowed))
    {
    goto end; //Bool
    }

    // v1_subject_access_review_status->denied
    cJSON *denied = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "denied");
    if (cJSON_IsNull(denied)) {
        denied = NULL;
    }
    if (denied) { 
    if(!cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    }

    // v1_subject_access_review_status->evaluation_error
    cJSON *evaluation_error = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "evaluationError");
    if (cJSON_IsNull(evaluation_error)) {
        evaluation_error = NULL;
    }
    if (evaluation_error) { 
    if(!cJSON_IsString(evaluation_error) && !cJSON_IsNull(evaluation_error))
    {
    goto end; //String
    }
    }

    // v1_subject_access_review_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_subject_access_review_status_local_var = v1_subject_access_review_status_create_internal (
        allowed->valueint,
        denied ? denied->valueint : 0,
        evaluation_error && !cJSON_IsNull(evaluation_error) ? strdup(evaluation_error->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_subject_access_review_status_local_var;
end:
    return NULL;

}

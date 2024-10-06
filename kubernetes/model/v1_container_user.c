#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_user.h"



v1_container_user_t *v1_container_user_create(
    v1_linux_container_user_t *linux
    ) {
    v1_container_user_t *v1_container_user_local_var = malloc(sizeof(v1_container_user_t));
    if (!v1_container_user_local_var) {
        return NULL;
    }
    v1_container_user_local_var->linux = linux;

    return v1_container_user_local_var;
}


void v1_container_user_free(v1_container_user_t *v1_container_user) {
    if(NULL == v1_container_user){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_user->linux) {
        v1_linux_container_user_free(v1_container_user->linux);
        v1_container_user->linux = NULL;
    }
    free(v1_container_user);
}

cJSON *v1_container_user_convertToJSON(v1_container_user_t *v1_container_user) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_user->linux
    if(v1_container_user->linux) {
    cJSON *linux_local_JSON = v1_linux_container_user_convertToJSON(v1_container_user->linux);
    if(linux_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "linux", linux_local_JSON);
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

v1_container_user_t *v1_container_user_parseFromJSON(cJSON *v1_container_userJSON){

    v1_container_user_t *v1_container_user_local_var = NULL;

    // define the local variable for v1_container_user->linux
    v1_linux_container_user_t *linux_local_nonprim = NULL;

    // v1_container_user->linux
    cJSON *linux = cJSON_GetObjectItemCaseSensitive(v1_container_userJSON, "linux");
    if (linux) { 
    linux_local_nonprim = v1_linux_container_user_parseFromJSON(linux); //nonprimitive
    }


    v1_container_user_local_var = v1_container_user_create (
        linux ? linux_local_nonprim : NULL
        );

    return v1_container_user_local_var;
end:
    if (linux_local_nonprim) {
        v1_linux_container_user_free(linux_local_nonprim);
        linux_local_nonprim = NULL;
    }
    return NULL;

}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_class_spec.h"



v1_ingress_class_spec_t *v1_ingress_class_spec_create(
    char *controller,
    v1_ingress_class_parameters_reference_t *parameters
    ) {
    v1_ingress_class_spec_t *v1_ingress_class_spec_local_var = malloc(sizeof(v1_ingress_class_spec_t));
    if (!v1_ingress_class_spec_local_var) {
        return NULL;
    }
    v1_ingress_class_spec_local_var->controller = controller;
    v1_ingress_class_spec_local_var->parameters = parameters;

    return v1_ingress_class_spec_local_var;
}


void v1_ingress_class_spec_free(v1_ingress_class_spec_t *v1_ingress_class_spec) {
    if(NULL == v1_ingress_class_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_class_spec->controller) {
        free(v1_ingress_class_spec->controller);
        v1_ingress_class_spec->controller = NULL;
    }
    if (v1_ingress_class_spec->parameters) {
        v1_ingress_class_parameters_reference_free(v1_ingress_class_spec->parameters);
        v1_ingress_class_spec->parameters = NULL;
    }
    free(v1_ingress_class_spec);
}

cJSON *v1_ingress_class_spec_convertToJSON(v1_ingress_class_spec_t *v1_ingress_class_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_class_spec->controller
    if(v1_ingress_class_spec->controller) { 
    if(cJSON_AddStringToObject(item, "controller", v1_ingress_class_spec->controller) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ingress_class_spec->parameters
    if(v1_ingress_class_spec->parameters) { 
    cJSON *parameters_local_JSON = v1_ingress_class_parameters_reference_convertToJSON(v1_ingress_class_spec->parameters);
    if(parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parameters", parameters_local_JSON);
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

v1_ingress_class_spec_t *v1_ingress_class_spec_parseFromJSON(cJSON *v1_ingress_class_specJSON){

    v1_ingress_class_spec_t *v1_ingress_class_spec_local_var = NULL;

    // define the local variable for v1_ingress_class_spec->parameters
    v1_ingress_class_parameters_reference_t *parameters_local_nonprim = NULL;

    // v1_ingress_class_spec->controller
    cJSON *controller = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_specJSON, "controller");
    if (controller) { 
    if(!cJSON_IsString(controller))
    {
    goto end; //String
    }
    }

    // v1_ingress_class_spec->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1_ingress_class_specJSON, "parameters");
    if (parameters) { 
    parameters_local_nonprim = v1_ingress_class_parameters_reference_parseFromJSON(parameters); //nonprimitive
    }


    v1_ingress_class_spec_local_var = v1_ingress_class_spec_create (
        controller ? strdup(controller->valuestring) : NULL,
        parameters ? parameters_local_nonprim : NULL
        );

    return v1_ingress_class_spec_local_var;
end:
    if (parameters_local_nonprim) {
        v1_ingress_class_parameters_reference_free(parameters_local_nonprim);
        parameters_local_nonprim = NULL;
    }
    return NULL;

}

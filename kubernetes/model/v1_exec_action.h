/*
 * v1_exec_action.h
 *
 * ExecAction describes a \&quot;run in container\&quot; action.
 */

#ifndef _v1_exec_action_H_
#define _v1_exec_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_exec_action_t v1_exec_action_t;




typedef struct v1_exec_action_t {
    list_t *command; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_exec_action_t;

__attribute__((deprecated)) v1_exec_action_t *v1_exec_action_create(
    list_t *command
);

void v1_exec_action_free(v1_exec_action_t *v1_exec_action);

v1_exec_action_t *v1_exec_action_parseFromJSON(cJSON *v1_exec_actionJSON);

cJSON *v1_exec_action_convertToJSON(v1_exec_action_t *v1_exec_action);

#endif /* _v1_exec_action_H_ */


/*
 * v1_exempt_priority_level_configuration.h
 *
 * ExemptPriorityLevelConfiguration describes the configurable aspects of the handling of exempt requests. In the mandatory exempt configuration object the values in the fields here can be modified by authorized users, unlike the rest of the &#x60;spec&#x60;.
 */

#ifndef _v1_exempt_priority_level_configuration_H_
#define _v1_exempt_priority_level_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_exempt_priority_level_configuration_t v1_exempt_priority_level_configuration_t;




typedef struct v1_exempt_priority_level_configuration_t {
    int lendable_percent; //numeric
    int nominal_concurrency_shares; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_exempt_priority_level_configuration_t;

__attribute__((deprecated)) v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_create(
    int lendable_percent,
    int nominal_concurrency_shares
);

void v1_exempt_priority_level_configuration_free(v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration);

v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_parseFromJSON(cJSON *v1_exempt_priority_level_configurationJSON);

cJSON *v1_exempt_priority_level_configuration_convertToJSON(v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration);

#endif /* _v1_exempt_priority_level_configuration_H_ */


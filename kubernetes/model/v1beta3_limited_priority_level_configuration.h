/*
 * v1beta3_limited_priority_level_configuration.h
 *
 * LimitedPriorityLevelConfiguration specifies how to handle requests that are subject to limits. It addresses two issues:   - How are requests for this priority level limited?   - What should be done with requests that exceed the limit?
 */

#ifndef _v1beta3_limited_priority_level_configuration_H_
#define _v1beta3_limited_priority_level_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta3_limited_priority_level_configuration_t v1beta3_limited_priority_level_configuration_t;

#include "v1beta3_limit_response.h"



typedef struct v1beta3_limited_priority_level_configuration_t {
    int borrowing_limit_percent; //numeric
    int lendable_percent; //numeric
    struct v1beta3_limit_response_t *limit_response; //model
    int nominal_concurrency_shares; //numeric

} v1beta3_limited_priority_level_configuration_t;

v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration_create(
    int borrowing_limit_percent,
    int lendable_percent,
    v1beta3_limit_response_t *limit_response,
    int nominal_concurrency_shares
);

void v1beta3_limited_priority_level_configuration_free(v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration);

v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration_parseFromJSON(cJSON *v1beta3_limited_priority_level_configurationJSON);

cJSON *v1beta3_limited_priority_level_configuration_convertToJSON(v1beta3_limited_priority_level_configuration_t *v1beta3_limited_priority_level_configuration);

#endif /* _v1beta3_limited_priority_level_configuration_H_ */


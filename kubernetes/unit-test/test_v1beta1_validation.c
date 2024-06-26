#ifndef v1beta1_validation_TEST
#define v1beta1_validation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_validation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_validation.h"
v1beta1_validation_t* instantiate_v1beta1_validation(int include_optional);



v1beta1_validation_t* instantiate_v1beta1_validation(int include_optional) {
  v1beta1_validation_t* v1beta1_validation = NULL;
  if (include_optional) {
    v1beta1_validation = v1beta1_validation_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1beta1_validation = v1beta1_validation_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1beta1_validation;
}


#ifdef v1beta1_validation_MAIN

void test_v1beta1_validation(int include_optional) {
    v1beta1_validation_t* v1beta1_validation_1 = instantiate_v1beta1_validation(include_optional);

	cJSON* jsonv1beta1_validation_1 = v1beta1_validation_convertToJSON(v1beta1_validation_1);
	printf("v1beta1_validation :\n%s\n", cJSON_Print(jsonv1beta1_validation_1));
	v1beta1_validation_t* v1beta1_validation_2 = v1beta1_validation_parseFromJSON(jsonv1beta1_validation_1);
	cJSON* jsonv1beta1_validation_2 = v1beta1_validation_convertToJSON(v1beta1_validation_2);
	printf("repeating v1beta1_validation:\n%s\n", cJSON_Print(jsonv1beta1_validation_2));
}

int main() {
  test_v1beta1_validation(1);
  test_v1beta1_validation(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_validation_MAIN
#endif // v1beta1_validation_TEST

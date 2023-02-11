include(CheckCXXSymbolExists)

check_cxx_symbol_exists(strndup "string.h" HAVE_STRNDUP)
check_cxx_symbol_exists(secure_getenv "stdlib.h" HAVE_SECURE_GETENV)
check_cxx_symbol_exists(getenv "stdlib.h" HAVE_GETENV)

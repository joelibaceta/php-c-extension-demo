#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "miller-rabin.c"

#define PHP_MY_EXTENSION_VERSION "1.0"
#define PHP_MY_EXTENSION_EXTNAME "primecalc"

PHP_FUNCTION(miller_rabin);

extern zend_module_entry primecalc_module_entry;
#define phpext_my_extension_ptr &primecalc_module_entry

static zend_function_entry prime_calc_functions[] = {
    PHP_FE(miller_rabin, NULL)
};

zend_module_entry primecalc_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MY_EXTENSION_EXTNAME,
    prime_calc_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MY_EXTENSION_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(primecalc)


PHP_FUNCTION(miller_rabin)
{
    long *number;
    int *number_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &number, &number_len) == FAILURE) {
        RETURN_NULL();
    }
    
    RETURN_BOOL(isPrime_Propab(number));
}
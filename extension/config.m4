PHP_ARG_ENABLE(primecalc, whether to enable prime calculator, [ --enable-primecalc   Enable Prim Calculator])

if test "$PHP_PRIMECALC" = "yes"; then
    AC_DEFINE(HAVE_PRIMECALC, 1, [Whether you have hello])
    PHP_NEW_EXTENSION(primecalc, primecalc.c, $ext_shared)
fi
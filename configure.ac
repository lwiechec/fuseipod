AC_PREREQ([2.65])
AC_INIT([ipodfuse], [0.1], [coquelicot408@gmail.com])
#AC_CONFIG_SRCDIR([ipodlister.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_̣AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lfuse':
#AC_CHECK_LIB([fuse], [main])
# FIXME: Replace `main' with a function in `-lgpod':
#AC_CHECK_LIB([gpod], [main])
# FIXME: Replace `main' with a function in `-lm':
#AC_CHECK_LIB([m], [main])

# Checks for header files.
#AC_CHECK_HEADERS([fcntl.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
#AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
])
AC_OUTPUT

AC_PREREQ([2.65])
AC_INIT([ipodfuse], [0.1], [coquelicot408@gmail.com])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([fuse], [fuse_main])
AC_CHECK_LIB([gpod], [itdb_new])
AC_CHECK_HEADERS([fcntl.h string.h glib.h])

# check for proper versions of required tools
GLIB_REQUIRED=2.20.0
PKG_CHECK_MODULES(GLIB, glib-2.0 >= $GLIB_REQUIRED)
GLIB_VERSION=$($PKG_CONFIG --modversion glib-2.0)
AC_SUBST(GLIB_VERSION)
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

FUSE_REQUIRED=2.9.2
PKG_CHECK_MODULES(FUSE, fuse >= $FUSE_REQUIRED)
FUSE_VERSION=$($PKG_CONFIG --modversion fuse)
AC_SUBST(FUSE_VERSION)
AC_SUBST(FUSE_CFLAGS)
AC_SUBST(FUSE_LIBS)

GPOD_REQUIRED=0.8.2
PKG_CHECK_MODULES(GPOD, libgpod-1.0 >= $GPOD_REQUIRED)
GPOD_VERSION=$($PKG_CONFIG --modversion libgpod-1.0)
AC_SUBST(GPOD_VERSION)
AC_SUBST(GPOD_CFLAGS)
AC_SUBST(GPOD_LIBS)


# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
#AC_CHECK_FUNCS([memset])

# Which files to generate
AC_CONFIG_FILES([
  Makefile
  src/Makefile
])

# Write!
AC_OUTPUT

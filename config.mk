VERSION=0.2b
RELEASE=0
DESTDIR=
OSTYPE?=gnulinux

COMPILER?=gcc
#COMPILER=tcc

# verbose error messages everywhere
STATIC_DEBUG=0
# getenv("LIBR_RTDEBUG");
RUNTIME_DEBUG?=1

ifeq (${RELEASE},1)
PREFIX=/usr/local
else
PREFIX=${PWD}/prefix
VERSION=`date '+%Y%m%d'`
endif

LIBDIR=${PREFIX}/lib

-include config-user.mk
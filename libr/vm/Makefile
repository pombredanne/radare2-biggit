NAME=r_vm
DEPS=r_util

ALL=p/plugins.h
OBJ=vm.o mmu.o reg.o extra.o setup.o stack.o op.o

include ../rules.mk

p/plugins.h:
	cd p && ${MAKE} plugins.h

SHELL=/bin/bash

SRC=src
BUILD=build
DIST=dist

TARGET_LIB=${DIST}/libmapstrstr.so
TARGET_TEST=${DIST}/map_str_str_test

CC=$(shell command -v gcc)
CFLAGS=-std=gnu11 -ggdb -Wall -Wextra -I${SRC}/cpp
LDFLAGS=-lmapstrstr

CXX=$(shell command -v g++)
CXXFLAGS=-std=gnu++11 -ggdb -Wall -Wextra -I${SRC}/cpp

all: make_dirs ${TARGET_LIB} ${TARGET_TEST}

make_dirs:
	@echo "Make directories..."
	@mkdir -p ${BUILD}
	@mkdir -p ${DIST}
	@echo "Done..."
    
clean: 
	@echo "Cleaning..."
	@rm -rf ${BUILD}
	@rm -rf ${DIST}
	@echo "Done..."

${BUILD}/map_str_str.o: ${SRC}/cpp/map_str_str.h ${SRC}/cpp/map_str_str.cpp
	@echo -e "\n>\t"$@
	${CXX} ${CXXFLAGS} -fPIC -c ${SRC}/cpp/map_str_str.cpp -o ${BUILD}/map_str_str.o

${TARGET_LIB}: ${BUILD}/map_str_str.o
	@echo -e "\n>\t"$@
	${CXX} -shared ${BUILD}/map_str_str.o -o ${TARGET_LIB}

${BUILD}/main_map_str_str_test.o: ${SRC}/c/main_map_str_str_test.c
	@echo -e "\n>\t"$@
	${CC} ${CFLAGS} -c ${SRC}/c/main_map_str_str_test.c -o ${BUILD}/main_map_str_str_test.o

${TARGET_TEST}: ${TARGET_LIB} ${BUILD}/main_map_str_str_test.o
	@echo -e "\n>\t"$@
	${CC} ${CFLAGS} -L${DIST} -no-pie ${BUILD}/main_map_str_str_test.o -o ${TARGET_TEST} ${LDFLAGS}

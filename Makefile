#
# Makefile to control the build and testing of pyinitgen
#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
LDFLAGS = 
SRC = pyinitgen.c

INSTALL_PREFIX = /usr/local/bin

NO_COMPILER_BUILD = $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

OUT = pyinitgen

DEBUG = 1

all: build-init

build-init:
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)


test: build-init
	@ls | xargs ./$(OUT)
	@cat __init__.py

clean:
	rm -rf *.o $(OUT) __init__.py

install: build-init
	mkdir -p $(INSTALL_PREFIX)
	cp $(OUT) $(INSTALL_PREFIX)

clang:
	clang $(NO_COMPILER_BUILD)


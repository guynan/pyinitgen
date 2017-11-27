#
# Makefile to control the build and testing of pyinitgen
#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
LDFLAGS = 
SRC = pyinitgen.c

OUT = pyinitgen

DEBUG = 1

ifneq ($(DEBUG), 1)
	CFLAGS += -O2
endif


all: build-init

build-init:
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

test: build-init
	@ls | xargs ./$(OUT)
	@cat __init__.py

clean:
	rm -rf *.o $(OUT) __init__.py

install: build-init
	mkdir -p /usr/local/src/
	cp $(OUT) /usr/local/src/

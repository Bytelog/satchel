CC := clang
CFLAGS := -std=c99 -Wpedantic -Weverything
RELEASE := -O3 -Werror
DEBUG := -g
SOURCES := $(wildcard src/*.c)
OBJECTS := $(SOURCES:%.c=%.o)
OBJECTS := $(OBJECTS:src/%=target/%)

all: release

release: CFLAGS += $(RELEASE)
release: build

debug: CFLAGS += $(DEBUG)
debug: build

target/%.o: src/%.c
	@echo cc -c $< -o $@
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: init build clean

init:
	@echo Initializing...
	@mkdir -p target

build: clean init $(OBJECTS)
	@echo Building...

clean:
	@echo Cleaning...
	@rm -rf target

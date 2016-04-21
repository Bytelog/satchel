CC ?= clang
CFLAGS ?= -std=c99 -Wpedantic -Weverything -O3
SOURCES = $(wildcard *.c)
TESTS = $(SOURCES:.c=.test)

all: $(TESTS)
	
%.test: %.c
	$(CC) $(CFLAGS) -I../ -o $@ $<
	./$@

.PHONY : clean

clean:
	rm -f *.test
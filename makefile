HEADERS = $(shell ls *.h)
SOURCES = $(shell ls *.c)

COMPILERFLAGS = -W -Wall
COMPILER = gcc

OBJS = $(SOURCES:.c=.o)
BINARY = color-converter

all: $(BINARY)

$(BINARY): $(OBJS)
	$(COMPILER) -o $@ $^

depend:
	makedepend -f- -- $(SOURCES) > .depend_file

clean:
	rm -rf *.o .depend_file $(BINARY) *~


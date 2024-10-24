CC = cc
AR = ar
RANLIB = ranlib

CFLAGS = -g -pedantic

COMMON_CFLAGS = -std=c99 -I. $(CFLAGS)

LIBRARIES = \
	libsequence.a

sequence_OBJECTS = dlist.o
sequence_HEADERS = dlist.h

HEADERS = \
	  $(sequence_HEADERS)

TESTBIN = main
main_SOURCES = main.c

all: $(LIBRARIES) $(TESTBIN)

$(sequence_OBJECTS): $(sequence_HEADERS)

libsequence.a: $(sequence_OBJECTS)
	$(AR) -rc $@ $?
	-$(RANLIB) $@

$(TESTBIN): $(LIBRARIES) $(main_SOURCES) $(HEADERS)
	$(CC) $(COMMON_CFLAGS) $(LDFLAGS) -o $@ $(main_SOURCES) $(LIBRARIES) $(LDLIBS)

clean:
	rm -f *.a *.o $(TESTBIN)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(COMMON_CFLAGS) -c -o $@ $<

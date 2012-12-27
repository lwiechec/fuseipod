# sample Makefile for sample FUSE filesystem :)
# taken from: sample Makefile tutorial, http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor

IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -I/usr/local/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include/ -D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26 -L$(LDIR) -L/usr/local/lib -L/usr/lib

ODIR=obj
LDIR =../lib

LIBS=-lm -lfuse -lgpod

_DEPS = #helloworld.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ipodlister.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ipodlister: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

all: ipodlister

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ helloworld

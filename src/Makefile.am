# what flags you want to pass to the C compiler & linker
AM_CFLAGS = -Wall -O2 $(GLIB_CFLAGS) $(FUSE_CFLAGS) -DFUSE_USE_VERSION=26 $(GPOD_CFLAGS)
AM_LDFLAGS =

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = ipodlister
ipodlister_SOURCES = ipodlister.c

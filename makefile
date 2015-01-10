.PHONY: install clean

LDLIBS=-lbarcode

prefix=/usr/local

all: bincodes

bincodes: debug.c bincodes.c parse.c

clean:
	rm bincodes

install:
	install -m 0755 bincodes $(prefix)/bin

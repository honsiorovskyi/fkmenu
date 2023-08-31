BINARY  ?= fkmenu
SOURCES ?= main.c mouse.c
HEADERS ?= mouse.h

PREFIX  ?= /usr/local
BINPATH ?= $(PREFIX)/bin

ARCH ?= $(shell uname -m)

all: $(BINARY)

cross-compile:
	ARCH=arm64 BINARY=$(BINARY)-arm64 $(MAKE) 
	ARCH=x86_64 BINARY=$(BINARY)-x86_64 $(MAKE) 

run: $(BINARY)
	./$(BINARY)

install: all
	install -m755 $(BINARY) $(BINPATH)

clean:
	rm -f $(BINARY)
	rm -f $(BINARY)-arm64
	rm -f $(BINARY)-x86_64

$(BINARY): *.c *.h
	clang \
		-arch $(ARCH) \
		-framework Carbon \
		-o $@ \
		$(SOURCES)



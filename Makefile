BINARY  = fkmenu
SOURCES = main.c mouse.c
HEADERS = mouse.h

PREFIX  = /usr/local
BINPATH = $(PREFIX)/bin

all: $(BINARY)

run: $(BINARY)
	./$(BINARY)

install: all
	install -m755 $(BINARY) $(BINPATH)

clean:
	rm -f $(BINARY)

$(BINARY): *.c *.h
	clang \
		-framework Carbon \
		-o $@ \
		$(SOURCES)



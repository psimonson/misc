CFLAGS+=-std=c89 -Wall -Wextra -Werror -pedantic
LDFLAGS+=

SRCDIR=$(shell pwd)
BASENAM=$(shell echo $$(basename $(SRCDIR)))
VERSION=0.1

TARNAME=$(BASENAM)-$(VERSION).tgz

TARGETS=encdec test
.PHONY: all clean
all: $(TARGETS)

%.c.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

encdec: encdec.c.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: test.c.o readline.c.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.c.o *~ $(TARGETS)

distclean: clean

dist:
	@echo Compressing $(TARNAME)...
	@cd .. && tar -cf - --exclude=.git ./$(BASENAM) | \
	gzip -9 > $(TARNAME) && \
	echo Compression done. || die Compression failed.

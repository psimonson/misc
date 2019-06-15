CFLAGS+=-std=c89 -Wall -Wextra -Werror -pedantic
LDFLAGS+=

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

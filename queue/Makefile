CC := gcc
AR := ar

CFLAGS := -Wall -Werror -pedantic -std=c11 -I../tests

lib/queue.a: queue.o
	mkdir -p lib
	$(AR) rcs $@ $^

queue.o: queue.c queue.h
	$(CC) -c $(CFLAGS) -o $@ $<


tests/test_queue.o: tests/test_queue.c queue.h
	$(CC) -c $(CFLAGS) -o $@ $<

bin/test: tests/test_queue.o queue.o
	mkdir -p bin
	$(CC) -o $@ $^

.PHONY: test
test: bin/test
	@$<


.PHONY: clean
clean:
	rm -f *.o
	rm -rf bin/ lib/

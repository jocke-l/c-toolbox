queue.a: queue.o
	ar rcs $@ $^

queue.o: queue.c queue.h
	gcc -c -o $@ $<

tests/test_queue.o: tests/test_queue.c tests/test.h queue.h
	gcc -c -o $@ $<

bin/test: tests/test_queue.o queue.o
	mkdir -p bin
	gcc -o $@ $^

.PHONY: test
test: bin/test
	@$<

.PHONY: clean
clean:
	rm -f *.o *.a
	rm -rf bin/

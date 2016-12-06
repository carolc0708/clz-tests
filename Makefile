CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	time_test_recursive time_test_binary_recursive\
	time_test_iteration time_test_binary_iteration time_test_harley\
	time_test_binary_search time_test_byte_shift\
	benchmark verify

default: clz.o
	$(CC) $(CFLAGS) clz.o time_test.c -DRECURSIVE -o time_test_recursive
	$(CC) $(CFLAGS) clz.o time_test.c -DBRECURSIVE -o time_test_binary_recursive
	$(CC) $(CFLAGS) clz.o time_test.c -DITERATION -o time_test_iteration
	$(CC) $(CFLAGS) clz.o time_test.c -DBITERATION -o time_test_binary_iteration
	$(CC) $(CFLAGS) clz.o time_test.c -DHARLEY -o time_test_harley
	$(CC) $(CFLAGS) clz.o time_test.c -DBSEARCH -o time_test_binary_search
	$(CC) $(CFLAGS) clz.o time_test.c -DBYTESHIFT -o time_test_byte_shift
	$(CC) $(CFLAGS) clz.o benchmark.c -o benchmark
	$(CC) $(CFLAGS) clz.o verify.c -o verify

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

check: default
	./verify

time: default
	time ./time_test_recursive
	time ./time_test_binary_recursive
	time ./time_test_iteration
	time ./time_test_binary_iteration
	time ./time_test_harley
	time ./time_test_binary_search
	time ./time_test_byte_shift

gencsv: default
	for i in `seq 1000000 5000 4200000000`; do \
		printf "%d," $$i;\
		./benchmark $$i; \
		done > benchmark.csv
plot: gencsv
	gnuplot runtime.gp
clean:
	rm -f $(EXECUTABLE) *.o *.s benchmark.csv




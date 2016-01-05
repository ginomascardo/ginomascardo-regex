/*
The MIT License (MIT)

Copyright (c) 2015 Terence Parr, Hanzhou Shi, Shuai Yuan, Yuanyuan Zhang

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "malloc.h"
#include "c_unit.h"
#include "replay.h"

const size_t HEAP_SIZE = 100000000; // use 100M heap
const int NUM_RUNS = 3;

extern void heap_shutdown();

Heap_Info verify_heap() {
	Heap_Info info = get_heap_info();
	assert_equal(info.heap_size, HEAP_SIZE);
	assert_equal(info.heap_size, info.busy_size+info.free_size);
	return info;
}

static void setup()		{ heap_init(HEAP_SIZE); }
static void teardown()	{ verify_heap(); heap_shutdown(); }

void replay_malloc_trace_from_real_C_program() {
	int result = replay_malloc("test/MALLOC_FREE_TRACE.trace", false);
	assert_equal(0, result);
}

int main(int argc, char *argv[]) {
	printf("simulating...\n");

	c_unit_setup = setup;
	c_unit_teardown = teardown;

	heap_init(HEAP_SIZE);

	struct timeval stop, start;
	gettimeofday(&start, NULL);


	for (int i = 1; i <= NUM_RUNS; i++) {
		test(replay_malloc_trace_from_real_C_program);
	}

	gettimeofday(&stop, NULL);
	double duration_ms = (stop.tv_sec - start.tv_sec) * 1000.0 + (stop.tv_usec - start.tv_usec) / 1000.0;
	fprintf(stderr, "simulation took %7.1fms\n", duration_ms);

	return c_unit_fails;
}
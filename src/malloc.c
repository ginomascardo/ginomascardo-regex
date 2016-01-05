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
#include "malloc.h"

static Free_Header *freelist;   // Pointer to the first free chunk in heap
static void *heap = NULL;	    // point to data obtained from OS
static int heap_size = 0;

void heap_init(size_t max_heap_size) {
	// TODO: if heap already allocated, call heap_shutdown() first
	// TODO: record the size requested and ask morecore() for that much memory
	// TODO: initialize the linked list head variable: freelist
}

void heap_shutdown() {
	// TODO: call dropcore(), reset the heap and heap size variables
}

/** Allocate and returned a chunk of memory at least size bytes long.
 *  Split a bigger chunk if no exact fit, setting size of split chunk returned.
 *  size arg must be big enough to hold Free_Header and padded to 4 or 8
 *  bytes depending on word size.
 */
void *malloc(size_t size) {
	// TODO: if keep not allocated, initialized with the default heap size
	// TODO: return NULL if we are out of memory
	// TODO: add enough space so that we have room for our header
	// TODO: aligned to a word boundary
	// TODO: find the first free chunk that's big enough to hold the requested chunk and our header
	// TODO: mark this chunk as busy and return it
}

/* Free chunk p by adding to head of free list */
void free(void *p) {
	// TODO: return if p is NULL or out of range of the heap
	// TODO: return if p is already free
	// TODO: add to the head of the free list
}

Free_Header *get_freelist() { return freelist; }
void *get_heap_base()		{ return heap; }

/* Walk heap jumping by size field of chunk header. Return an info record. */
Heap_Info get_heap_info() {
	// TODO: while p is in bounds of the heap, walk heap jumping by chunksize(p)
	// TODO: 	count busy and free chunk sizes
	// TODO: return a Heap_Info with relevant data
}

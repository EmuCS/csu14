#include "bitset.h"

// include the standard library header files that we use in this
// program, which are denoted by angle brackets < >
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// define constant dummy values to avoid compiler warnings
// static const int dummy_integer_value = -99;
//static struct bitset * dummy_pointer_value = NULL;

// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size) {
  // delete the next line when you write your own code here
	struct bitset * result;
	result = malloc(sizeof(struct bitset));
	int size_in_words = size/64;
	if(size%64!=0) {
		size_in_words++;
	}
	result -> size_in_words = size_in_words;
	result -> universe_size = size;
	result -> bits = malloc(sizeof(uint64_t) * size_in_words);
	return result;
}

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this) {
  // delete the next line when you write your own code here
  return this->universe_size;
}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this){
  // delete the next line when you write your own code here
  return this->size_in_words;
}

// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item){
  // delete the next line when you write your own code here
	int word = item / 64;
	int bit = item % 64;
	int mask = 1ULL << bit;
	if(item > this->universe_size || item < 0){return -1;}
	else {
		if ((this->bits[word] & mask) == mask){return 1;}
		else{return 0;}
	}
}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item) {
	if(bitset_lookup(this, item) == 1){return;}
	else{
		int word = item / 64;
		int bit = item % 64;
		int mask = 1ULL << bit;
		if(item < 0 || item > this->universe_size){return;}
		else {
			this->bits[word] = this->bits[word] | mask;
		}
	}
}

// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item) {
	if(bitset_lookup(this, item) == 0){return;}
	else{
		int word = item / 64;
		int bit = item % 64;
		int mask = 1ULL << bit;
		mask = ~mask;
		if(item < 0 || item > this->universe_size){return;}
		else {
			this->bits[word] = this->bits[word] & mask;
		}
	}
}

// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1,
    struct bitset * src2) {
	if(dest->universe_size == src1->universe_size && dest->universe_size == src2->universe_size)
	{
		for(int index = 0; index < dest->universe_size; index++)
		{
			int word = index / 64;
			int bit = index % 64;
			int mask = 1ULL << bit;
			if ((src1->bits[word] & mask) == mask || (src2->bits[word] & mask) == mask)
			{
				dest->bits[word] = dest->bits[word] | mask;
			}
		}
	}
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,
    struct bitset * src2) {
	if(dest->universe_size == src1->universe_size && dest->universe_size == src2->universe_size)
	{
		for(int index = 0; index < bitset_size(dest); index++)
		{
			int word = index / 64;
			int bit = index % 64;
			int mask = 1ULL << bit;
			if ((src1->bits[word] & mask) == mask && (src2->bits[word] & mask) == mask)
			{
				dest->bits[word] = dest->bits[word] | mask;
			}
		}
	}
}

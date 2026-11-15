#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// include the header files with the declarations of listset
#include "listset.h"

struct listset * listset_new() {
}

/* check to see if an item is in the set
   returns 1 if in the set, 0 if not */
int listset_lookup(struct listset * this, char * item) {
}

void listset_add(struct listset * this, char * item) {
}

void listset_remove(struct listset * this, char * item) {
}

// place the union of src1 and src2 into dest
void listset_union(struct listset * dest, struct listset * src1,
  struct listset * src2) {
}

// place the intersection of src1 and src2 into dest
void listset_intersect(struct listset * dest, struct listset * src1,
  struct listset * src2) {
}

// return the number of items in the listset
int listset_cardinality(struct listset * this) {
}

// print the elements of the list set
void listset_print(struct listset * this) {
  struct listnode * p;
  for ( p = this->head; p != NULL; p = p->next ) {
    printf("%s, ", p->str);
  }
  printf("\n");
}

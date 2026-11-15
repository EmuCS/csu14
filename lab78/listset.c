#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// include the header files with the declarations of listset
#include "listset.h"

struct listset * listset_new() {
	struct listset * result;
	result = malloc(sizeof(struct listset));
	result -> head = malloc(sizeof(struct listnode));
	result -> head = NULL;
	return result;
}

/* check to see if an item is in the set
   returns 1 if in the set, 0 if not */
int listset_lookup(struct listset * this, char * item) {
	if(this -> head != NULL)
	{
		struct listnode * element = this -> head;
		while(element != NULL)
		{
			int index = 0;
			while(strlen(element->str) == strlen(item)
				&& element->str[index] == item[index])
			{
				if(element->str[index] == '\0'
					&& item[index] == '\0')
				{
					return 1;
				}
				index++;
			}
			element = element -> next;
		}
	}
	return 0;
}

void listset_add(struct listset * this, char * item) {
	if(listset_lookup(this, item) == 0)
	{
		struct listnode * newHead = malloc(sizeof(struct listnode));
		newHead -> str = item;
		newHead -> next = this -> head;
		this -> head = newHead;
	}
}

void listset_remove(struct listset * this, char * item) {
	if(listset_lookup(this, item) == 1)
	{
		struct listnode * prevElement = NULL;
		struct listnode * element = this -> head;
		struct listnode * nextElement = element -> next;
		while(element != NULL)
		{
			int index = 0;
			while(strlen(element->str) == strlen(item)
				&& element->str[index] == item[index])
			{
				if(element->str[index] == '\0'
					&& item[index] == '\0')
				{
					if (prevElement == NULL && nextElement == NULL)
					{
						this -> head = NULL;
						return;
					}
					else if (prevElement == NULL)
					{
						this -> head = nextElement;
						return;
					}
					else if (nextElement == NULL)
					{
						prevElement -> next = NULL;
						element = NULL;
						return;
					}
					else
					{
						prevElement -> next = nextElement;
						element = NULL;
						return;
					}
				}
				index++;
			}
			prevElement = element;
			element = nextElement;
			nextElement = element -> next;
		}
	}
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

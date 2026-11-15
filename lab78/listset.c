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

// assumes element is contained, returns this element
struct listnode * listset_findnode(struct listset * this, char * item)
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
				return element;
			}
			index++;
		}
		element = element -> next;
	}
}
// place the union of src1 and src2 into dest
void listset_union(struct listset * dest, struct listset * src1,
  struct listset * src2) {
	struct listnode * element = src1 -> head;
	while(element != NULL) {
		if(listset_lookup(src2, element->str) == 0)
		{
			listset_add(dest, listset_findnode(src1, element->str)->str);
		}
		element = element -> next;
	}

	element = src2 -> head;
	while(element != NULL) {
		if(listset_lookup(src1, element->str) == 0)
		{
			listset_add(dest, listset_findnode(src2, element->str)->str);
		}
		element = element -> next;
	}
}

// place the intersection of src1 and src2 into dest
void listset_intersect(struct listset * dest, struct listset * src1,
  struct listset * src2) {
	struct listnode * element = src1 -> head;
	while(element != NULL) {
		if(listset_lookup(src2, element->str) == 1)
		{
			listset_add(dest, listset_findnode(src2, element->str)->str);
		}
	}
}

// return the number of items in the listset
int listset_cardinality(struct listset * this) {
	int cardinality = 0;
	struct listnode * element = this -> head;
        while(element != NULL){
		cardinality ++;
		element = element -> next;
	}
	return cardinality;
}

// print the elements of the list set
void listset_print(struct listset * this) {
  struct listnode * p;
  for ( p = this->head; p != NULL; p = p->next ) {
    printf("%s, ", p->str);
  }
  printf("\n");
}

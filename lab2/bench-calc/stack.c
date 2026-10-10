#include "stack.h"

struct double_stack * double_stack_new(int max_size) {
	struct double_stack * output;
	output = malloc(sizeof(struct double_stack));
	output -> max_size = max_size;
	output -> top = 0;
	output -> items = malloc(sizeof(double)*max_size);
	return output;
}

// push a value onto the stack
void double_stack_push(struct double_stack * this, double value) {
	if (this->top < this->max_size)
	{
		this->items[this->top] = value;
		this->top++;
	}
	else
	{
		printf("stack is full");
	}
}
// pop a value from the stack
double double_stack_pop(struct double_stack * this) {
	if (this->top > 0 && this -> top <= this-> max_size) {
		this->top--;
		return this->items[this->top];
	}
	else{
		printf("unknown error @pop else");
		return -1;
	}
}

int isEmpty(struct double_stack * this)
{
	if(this->top == 0){return 1;}
	else{return 0;}
}

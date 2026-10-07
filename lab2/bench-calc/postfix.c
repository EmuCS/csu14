#include "postfix.h"

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) {
  // Write your code here
	struct double_stack * stack == new double_stack(nargs/2 + 1);

	int index = 0;						//int index = 0
	//double returnValue = 0
	int j = 0;						// int j = 0
	while(index < nargs) { 					// while index < nargs
		if(args[index][j] == '+'{			//if args[index][j] == '+'
			double temp1 = double_stack_pop(stack);
			double temp2 = double_stack_pop(stack);
			double_stack_push(stack, temp2 + temp1);//	-> temp1 = pop; temp2 = pop; push = temp2 + temp1
		}
		else if (args[index][j] == '-' && args[index][j+1] == '\0') { //else if args[index][j] == '-' && args[index][j + 1] == '\0'
			double temp1 = double_stack_pop(stack);
			double temp2 = double_stack_pop(stack);
			double_stack_push(stack, temp2 - temp1);//		-> temp1 = pop; temp2 = pop; push = temp2 - temp1
		}
		else if (args[index][j] == '/') {			//else if args[index][j] == '/'
			double temp1 = double_stack_pop(stack);
			double temp2 = double_stack_pop(stack);
			double_stack_push(stack, temp2/temp1);//	-> temp1 = pop; temp2 = pop; push = temp2 / temp1
		}
		else if (args[index][j] == 'X') {		//else if args[index][j] == 'X'
			double temp1 = double_stack_pop(stack);
			double temp2 = double_stack_pop(stack);
			double_stack_push(stack, temp2*temp1);//	-> temp1 = pop; temp2 = pop; push = temp2 * temp1
		}
		else if (args[index][j] == '^') {		//else if args[index][j] == '^'
			double temp1 = double_stack_pop(stack);
			double temp2 = double_stack_pop(stack);
			double_stack_push(stack, pow(temp2,temp1));//	-> temp1 = pop; temp2 = pop; push = pow(temp2,temp1)
		}
		else {						//else
			double pushValue = strtod(arg[index], NULL)
			double_stack_push(stack, pushValue);	//	-> push strtod(arg[index], NULL)
		}
		index += 1;//index ++
	}
}

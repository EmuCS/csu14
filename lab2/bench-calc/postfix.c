#include "postfix.h"

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) {
  // Write your code here
	struct double_stack * post_fix_stack = new double_stack(nargs/2 + 1);
	int result = 0;
	int index = 0;						//int index = 0
	int j = 0;						// int j = 0
	int tokenCount = 0;

	//Compute reverse polish notation alogorithm
	while(index < nargs) { 					// while index < nargs
		if(args[index][j] ==) '+'{			//if args[index][j] == '+'
			double temp1 = double_stack_pop(post_fix_stack);
			double temp2 = double_stack_pop(post_fix_stack);
			double_stack_push(stack, temp2 + temp1);//	-> temp1 = pop; temp2 = pop; push = temp2 + temp1
			tokeCount += 1;
		}
		else if (args[index][j] == '-' && args[index][j+1] == '\0') { //else if args[index][j] == '-' && args[index][j + 1] == '\0'
			double temp1 = double_stack_pop(post_fix_stack);
			double temp2 = double_stack_pop(post_fix_stack);
			double_stack_push(post_fix_stack, temp2 - temp1);//		-> temp1 = pop; temp2 = pop; push = temp2 - temp1
			tokeCount += 1;
		}
		else if (args[index][j] == '/') {			//else if args[index][j] == '/'
			double temp1 = double_stack_pop(post_fix_stack);
			double temp2 = double_stack_pop(post_fix_stack);
			double_stack_push(post_fix_stack, temp2/temp1);//	-> temp1 = pop; temp2 = pop; push = temp2 / temp1
			tokeCount += 1;
		}
		else if (args[index][j] == 'X') {		//else if args[index][j] == 'X'
			double temp1 = double_stack_pop(post_fix_stack);
			double temp2 = double_stack_pop(post_fix_stack);
			double_stack_push(post_fix_stack, temp2*temp1);//	-> temp1 = pop; temp2 = pop; push = temp2 * temp1
			tokeCount += 1;
		}
		else if (args[index][j] == '^') {		//else if args[index][j] == '^'
			double temp1 = double_stack_pop(post_fix_stack);
			double temp2 = double_stack_pop(post_fix_stack);
			double_stack_push(post_fix_stack, pow(temp2,temp1));//	-> temp1 = pop; temp2 = pop; push = pow(temp2,temp1)
			tokeCount += 1;
		}
		else {						//else
			double pushValue = strtod(args[index], NULL);
			double_stack_push(post_fix_stack, pushValue);	//	-> push strtod(arg[index], NULL)
		}
		index += 1;//index ++
	}

	return double_stack_pop(post_fix_stack);
}

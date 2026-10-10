#include "infix.h"

int isNumber(char ** args, int index) {
  int j = 0;
  while(args[index][j] != '\0')  {
    if((args[index][0] == '+' || args[index][0] == '-' || args[index][0] == 'X' || args[index][0] == '/' || args[index][0] == '^'
        || args[index][0] == '(' || args[index][0] == ')') 
        && (args[index][1] == '\0')) {
      return 0;
    }
    j++;
  }
  return 1;
}

int precedence(char op1, char op2)
{
  int op1Val = 0;
  int op2Val = 0;
  
  if(op1 == '+' || op1 == '-') {op1Val = 0;}
  else if (op1 == 'X' || op1 == '/') {op1Val = 1;}
  else if (op1 == '^'){op1Val = 2;}
  
  if(op2 == '+' || op2 == '-') {op2Val = 0;}
  else if (op2 == 'X' || op2 == '/') {op2Val = 1;}
  else if (op2 == '^'){op2Val = 2;}
  if (op1Val  >= op2Val)
  {
    return 1;
  }
  else {return 0;}
}
// evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char ** args, int nargs) {
  // Write your code here
  char *output_string[nargs];
  int output_index = 0;
  struct double_stack * infix_stack = double_stack_new(nargs);
  
  for(int index = 0; index < nargs; index++)
  {
    if(isNumber(args, index) != 0) 
    {
      output_string[output_index] = args[index]; 
      output_index++;
    }
    else if(args[index][0] == '(')
    {
      double_stack_push(infix_stack, index);
    }
    else if(args[index][0] == '+' || args[index][0] == '-' || 
            args[index][0] == '/' || args[index][0] == 'X' || args[index][0] == '^')
    {
      while(isEmpty(infix_stack) == 0 && precedence(args[(int)infix_stack->items[infix_stack->top-1]], args[index][0]) == 1 
            && args[(int)infix_stack->items[infix_stack->top-1]][0] != '(') 
      {
          output_string[output_index] = args[(int)double_stack_pop(infix_stack)];
          output_index++;
      }
      double_stack_push(infix_stack, index);
    }
    else if(args[index][0] == ')') {
      while (args[(int)infix_stack->items[top - 1]][0] != '(') {
        output_string[output_index] = args[(int)double_stack_pop(infix_stack)];
        output_index++;
      }
      double_stack_pop(infix_stack);
    }
  }
  while (isEmpty(infix_stack) != 1){
    output_string[output_index] = args[(int)double_stack_pop(infix_stack)];
    output_index++;
  } 
  return evaluate_postfix_expression(output_string, output_index);
}



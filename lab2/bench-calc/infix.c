#include "infix.h"

int isNumber(char ** args, index) {
  int j = 0;
  while(args[index][j] != '\0')  {
    if((args[index][j] < '0' || args[index][j] > '9') && 
        (args[index][0] == '-' && args[index][1] == '\0')) {
      return 0;
    }
    j++;
  }
}

int precedence(char op1, char op2)
{
  int op1Val = 0;
  int op2Val = 0;
  
  if(op1 == '+' || op1 == '-') {op1Val = 0;}
  else if (op1 == 'X' || op1 == '/') {op1Val = 1;}
  else if (op1 == '^'){op1Val = 2;}
  
  if(op2 == '+' || op1 == '-') {op1Val = 0;}
  else if (op1 == 'X' || op1 == '/') {op1Val = 1;}
  else if (op1 == '^'){op1Val = 2;}
  if (op1  > op2)
  {
    return 1;
  }
  else {return 0;}
}
// evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char ** args, int nargs) {
  // Write your code here
  char[nargs] output_string;
  int output_index = 0;
  struct double_stack * infix_stack = double_stack_new(nargs);
  for(int index = 0; index < nargs; index++)
  {
    if(isNumber(args[index], index) != 0) 
    {
      double value = strtod(args[index], NULL);
    }
    else if(args[index][0] == '(')
    {
      double_stack_push(infix_stack, args[index][0]);//
    }
    else if(args[index][0] == '+' || args[index][0] == '-' || 
            args[index][0] == '/' || args[index][0] == 'X' || args[index][0] == '^')
    {
      double result = 0;
      while(stackEmpty() == 0 && precedence(infix_stack[infix_stack->top - 1], args[index]) == 1)
      {
        result += double_stack_pop(infix_stack);
      }
      output_string[output_index] = (char) result;
      output_index += 1;
    }
    else if(args[index][0] == ')')
    {
      while(double_stack_pop() != '(')
      {
        output_string[output_index] = (char) double_stack_pop(infix_stack); 
      }
      char throwaway = double_stack_pop(infix_stack);
    }
  } 
  int final_result /* = do the calculation by calling postfix */; 
  return final_result;
}



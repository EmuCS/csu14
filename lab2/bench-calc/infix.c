#include "infix.h"

// evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char ** args, int nargs) {
  // Write your code here
  char[nargs] output_string;
  int output_index = 0;
  struct double_stack * infix_stack = new_double_stack(nargs);
  for(int index = 0; index < nargs; index++)
  {
    if(isNumber(args[index])) 
    {
      double value = strtod(args[index], NULL);
    }
    else if(args[index] == '(')
    {
      double_stack_push(infix_satck, args[index][0]);//
    }
    else if(args[index] == '+' || args[index] == '-' || 
            args[index] == '/' || args[index] == 'X' || args[index] == '^')
    {
      double result = 0;
      while(!stackEmpty() && precedence(infix_stack[infix_stack.top - 1], args[index])
      {
        result += double_stack_pop(infix_stack);
      }
      output_string[output_index] = (char) result;
      output_index += 1;
    }
    else if(args[index] == ')')
    {
      while(double_stack_pop != '(')
      {
        output_string[output_index] = (char) double_stack_pop(infix_stack); 
      }
      char throwaway = double_stack_pop(infix_stack)
    }
  } 
}

boolean isNumber(char ** args) {
  int j = 0;
  while(args[index][j] != NULL)  
    if(args[index][j] < '0' || args[index][j] > '9') {return false};
    j++;
}

boolean precedence(char op1, char op2)
{
  int op1Val = 0;
  int op2Val = 0;
  
  if(op1 == '+' || op1 == '-') {op1Val = 0}
  else if (op1 == 'X' || op1 == '/') {op1Val = 1}
  else if (op1 == '^'){op1Val = 2}
  
  if(op2 == '+' || op1 == '-') {op1Val = 0}
  else if (op1 == 'X' || op1 == '/') {op1Val = 1}
  else if (op1 == '^'){op1Val = 2}
  return op1 > op2;
}

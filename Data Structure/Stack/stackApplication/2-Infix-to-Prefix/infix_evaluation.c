#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
    int first_val, sec_val, result =0;
    for(int i = 0; Prefix_exp[i] != '\0'; i++)
    {
        if(isdigit(Prefix_exp[i]))
        {
            push(stk, (Prefix_exp[i] - 48));
        }
        else{
            first_val = peek(stk);
            pop(stk);
            sec_val = peek(stk);
            pop(stk);

            switch(Prefix_exp[i])
            {
                case '+': //Addition
                    result = first_val + sec_val;
                    break;

                case '-': //Subtraction
                    result = first_val - sec_val;
                    break;

                case '/': //Division
                    result = first_val / sec_val; 
                    break;

                case '*': //Multiply
                    result = first_val * sec_val;
                    break;

                default : break;
            }   
            push(stk, result);
        }
    }

    return result;
}
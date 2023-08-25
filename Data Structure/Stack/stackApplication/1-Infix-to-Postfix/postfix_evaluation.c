#include "main.h"

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    int result = 0;
    int first_val, sec_val;
    for(int i = 0; Postfix_exp[i] != '\0'; i++)
    {
        if(isdigit(Postfix_exp[i]))
        {
            push(stk, (Postfix_exp[i] - 48));
        }
        else{
            sec_val = peek(stk);
            pop(stk);
            first_val = peek(stk);
            pop(stk);
            switch (Postfix_exp[i])
            {
                case '+': 
                    result = first_val + sec_val;                    
                    break;

                case '-':
                    result = first_val - sec_val;
                    break;

                case '*':
                    result = first_val * sec_val;
                    break;

                case '/':
                    result = first_val / sec_val;
                    break;
                
                default:
                    break;
            }
            push(stk, result);
        }
    }

    return peek(stk);
    
}
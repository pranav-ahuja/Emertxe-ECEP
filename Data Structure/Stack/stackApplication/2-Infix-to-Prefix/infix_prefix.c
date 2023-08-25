#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    int ind=0;
	for(int i = 0; Infix_exp[i]!='\0'; i++)
    {
        if(isdigit(Infix_exp[i]))
        {
            Prefix_exp[ind] = Infix_exp[i];
            ind++;
        }
        else{
            if(stk->top == -1)
            {
                push(stk, Infix_exp[i]);
            }
            else{
                if(Infix_exp[i] == ')')
                {
                    push(stk, Infix_exp[i]);
                }
                else if(Infix_exp[i] == '(')
                {
                    while(stk->top != -1)
                    {
                        if(stk->stack[stk->top] == ')')
                        {
                            pop(stk);
                            continue;
                        }
                        Prefix_exp[ind] = peek(stk);
                        ind++;                        
                        pop(stk);
                    }                                    
                }
                else if(priority(stk->stack[stk->top]) <= priority(Infix_exp[i]))                
                {
                    push(stk, Infix_exp[i]);
                }
                else if(priority(stk->stack[stk->top]) > priority(Infix_exp[i]))
                {
                    while(priority(stk->stack[stk->top]) > priority(Infix_exp[i]) && stk->top != -1)
                    {
                        Prefix_exp[ind] = peek(stk);
                        ind++;
                        pop(stk);
                    }
                    push(stk, Infix_exp[i]);
                }
            }
        }
    }
    while(stk->top != -1)
    {
        if(stk->stack[stk->top] == ')')
        {
            pop(stk);
            continue;
        }
        Prefix_exp[ind] = peek(stk);
        ind++;
        pop(stk);
    }
    Prefix_exp[ind] = '\0';
}


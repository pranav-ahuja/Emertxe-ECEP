#include "main.h"

void str_rev(char *string)
{
    /* TODO: Write logic for string reverse */
    int begin = 0;
    int end = strlen(string) - 1;
    char temp;
    while(begin < end)
    {
        temp = string[begin];
        string[begin] = string[end];
        string[end] = temp;
        begin++;
        end--;
    }
}
int main()
{
	char Infix_exp[50], Prefix_exp[50], ch;
	int choice, result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	str_rev(Infix_exp);
	Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);
	str_rev(Prefix_exp);
	printf("PreFix expression : %s\n", Prefix_exp);

	stk.top = -1;

	str_rev(Prefix_exp);
	result = Prefix_Eval(Prefix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}

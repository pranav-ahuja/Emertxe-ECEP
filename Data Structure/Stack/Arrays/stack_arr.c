#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include "stack_arr.h"

int main()
{
    Stack stack;
    int choice, output, data;

    trueOfalse tNf;

    create_stack(&stack);
    while(1)
    {
        choice = select_choice();

        switch(choice)
        {
            case 1: //Insert
                printf("Enter the data to be entered: ");
                scanf("%d", &data);

                output = push(&stack, &data);

                if(output == SUCCESS)
                {
                    printf("The push operation is successful.\n");
                }
                else if(output == FAIL)
                {
                    printf("The push operation is fail.\n");
                }                
                else if(output == STACK_FULL)
                {
                    printf("The stack is full.\n");
                }
                break;
            case 2: //delete
                output = pop(&stack);

                if(output == SUCCESS)
                {
                    printf("The pop operation is successful.\n");
                }
                else if(output == FAIL)
                {
                    printf("The pop operation is fail.\n");
                }                
                else if(output == STACK_EMPTY)
                {
                    printf("The stack is empty.\n");
                }
                break;
            case 3: //display
                output = peak(&stack);
                if(output == STACK_EMPTY)
                {   
                    printf("The stack is empty.\n");
                }
                else
                {
                    printf("The top element of stack is : %d.\n", output);
                }
                break;
        }
    }
    return 0;
}
int create_stack(Stack *stack)
{
    printf("Enter the size of stack: ");
    scanf("%d", &(stack)->capacity);

    (stack)->item = malloc(sizeof(int)*(stack)->capacity);
    (stack)->top = -1;
}

int select_choice()
{
    int choice;
    printf("Menu->\n");
    printf("1. Insert element\n2. Delete element\n3. Display element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int is_stack_empty(Stack *stack)
{
    if((stack)->top == -1)
    {
        return e_true;
    } 
    return e_false;
}

int is_stack_full(Stack *stack)
{
    if((stack)->top == (stack)->capacity -1)
    {
        return e_true;
    }
    return e_false;
}

int push(Stack *stack, int *element)
{
    if(is_stack_full(stack))
    {
        return STACK_FULL;
    }

    (stack)->top++;
    *((stack)->item + (stack)->top) = *element;
    return SUCCESS;
}

int pop(Stack *stack)
{
    if(is_stack_empty(stack))
    {
        return STACK_EMPTY;
    }
    (stack)->top--;
    return SUCCESS;
}

int peak(Stack *stack)
{
    if(is_stack_empty(stack))
    {
        return STACK_EMPTY;
    }

    return *(stack->item + stack->top);
}

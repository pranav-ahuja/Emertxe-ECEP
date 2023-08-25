#include<stdio.h>
#include "ll_stack.h"
#include<stdlib.h>

int main()
{
    ll_node *top = NULL;
    int choice, data, output;    

    while(1)
    {
        select_options(&choice);
        switch(choice)
        {
            case 1: //push
                printf("Enter the data to be pushed in the stack: ");
                scanf("%d", &data);

                output = push(&top, &data);

                if(output == SUCCESS)
                {
                    printf("The push function is successful.\n");
                }
                else if(output == FAIL)
                {
                    printf("The push operation is failed.\n");
                }                

                break;
            
            case 2: //pop
                output = pop(&top, &data);

                if(output == SUCCESS)
                {
                    printf("The pop function is successful.\n");
                }
                else if(output == STACK_EMPTY)
                {
                    printf("The stack is empty.\n");
                }
                break;

            case 3: //peak
                output = peak(&top);

                if(output == STACK_EMPTY)
                {
                    printf("The stack is empty.\n");
                }
                else{
                    printf("The data at the top of the stack is %d\n", output);
                }
                break;

            case 4: exit(0);
        }
    }

    return 0;
}

int select_options(int *choice)
{
    printf("Menu->\n");
    printf("1. Insert the element\n2. Remove the element\n3. Print the top element\n4. Exit the program\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}

int push(ll_node **top, int *data)
{
    ll_node *new;
    new = malloc(sizeof(ll_node));
    if(new == NULL)
    {
        return FAIL;
    }

    new->data = *data;

    if(*top == NULL)
    {
        *top = new;
        new->link = NULL;
    }
    else{
        new->link = *top;        
        *top = new;
    }

    return SUCCESS;

}

int pop(ll_node **top, int *data)
{
    if(*top == NULL)
    {
        return STACK_EMPTY;
    }

    ll_node *temp;
    temp = *top;
    *top = (*top)->link;
    temp->link = NULL;
    free(temp);

    return SUCCESS;
}

int peak(ll_node **top)
{
    if(*top == NULL)
    {
        return STACK_EMPTY;
    }

    return (*top)->data;
}

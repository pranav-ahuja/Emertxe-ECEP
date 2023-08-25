#ifndef STACK_ARR_H
#define STACK_ARR_H

#define SUCCESS 0
#define FAIL -1
#define STACK_EMPTY -2
#define STACK_FULL -3

typedef enum{
    e_false = 0,
    e_true = 1
}trueOfalse;

typedef struct StackAsArr{
    int capacity;
    int top;
    int *item;
}Stack;

int select_choice();
int is_stack_empty(Stack *);
int is_stack_full(Stack *);

int create_stack(Stack *);
int push(Stack *, int *);
int pop(Stack *);
int peak(Stack *);
#endif
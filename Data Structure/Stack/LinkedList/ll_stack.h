#ifndef LL_STACK_H
#define LL_STACK_H

#define SUCCESS 0
#define FAIL -1
#define STACK_EMPTY -2
#define STACK_FULL -3

typedef struct Node
{
    int data;
    struct Node *link;
}ll_node;

int select_options(int *);
int push(ll_node **, int *);
int pop(ll_node **, int *);
int peak(ll_node **);
#endif
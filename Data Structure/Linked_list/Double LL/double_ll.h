#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#define SUCCESS 0
#define FAIL -1
#define EMPTY -2
#define DATA_NOT_FOUND -3

typedef int data_t;

//define struct
typedef struct DList
{
    data_t data;
    struct DList *next;
    struct DList *prev;
}node;

/*Function Prototypes*/
int select_operation();
int print_list(node *head, node *tail);
int total_indexes(node **head);

int insert_at_last(node **head, node **tail, int data);
int insert_in_beginning(node **head, node**tail, int data);
int insert_after(node **head, int data, int data_after);
int insert_before(node **tail, int data, int data_after);
// int insert_at_nth(node **head, node **tail, int data, int pos);

int delete_at_last(node **tail);
int delete_in_beginning(node **head);
int delete_element(node **head, int data);
int delete_list(node **head);

int find_element(node **head, int data);
#endif

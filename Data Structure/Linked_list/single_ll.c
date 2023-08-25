#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define EMPTY_LIST -2
#define DATA_NOT_FOUND -3
#define NOT_FOUND -4

typedef int data_t;
typedef struct singleLinkedListNode
{
    data_t data;
    struct singleLinkedListNode *link;
}node;

int select_operation();
int insert_at_end(node **, int);
int insert_after(node **, int, int);
int insert_before(node **, int, int);
int insert_at_first(node **, int);
int insert_at_nth(node **, int, int);
int delete_at_first(node **);
int delete_at_last(node **);
int delete_list(node **);
int delete_at_nth(node **, int);
int find_node(node **, int);
void print_list(node *);

int main()
{
    node *head = NULL;
    
    int data, output;
    int enter_after_data, enter_before_data, pos;
    
    while(1)
    {
        switch (select_operation())
        {
            case 1: 
                printf("Enter the data to enter: ");
                scanf("%d", &data);

                output = insert_at_end(&head, data);
                if(output == SUCCESS)
                {
                    printf("Element added at the end.\n");
                }
                else{
                    printf("Error at inserting at the end.\n");
                }
                break;

            case 2:
                printf("Enter the data to enter: ");
                scanf("%d", &data);

                printf("Enter the data after which ou want to enter: ");
                scanf("%d", &enter_after_data);

                output = insert_after(&head, data, enter_after_data);
                if(output == SUCCESS)
                {
                    printf("Element is successfully added after %d.\n", enter_after_data);
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty. No item present.\n");
                }
                else if(output == DATA_NOT_FOUND)
                {
                    printf("Data %d not found in the list.\n", enter_after_data);
                }
                else{
                    printf("Unable to perform insert_after function\n");
                }
                break;

            case 3:
                printf("Enter the data to be entered at first: ");
                scanf("%d", &data);

                output = insert_at_first(&head, data);

                if(output == SUCCESS)
                {
                    printf("Insert at first successfull.\n");
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                else{
                    printf("Insert at first failed.\n");
                }
                break;
            case 4://insert before
                printf("Enter the data to enter: ");
                scanf("%d", &data);

                printf("Enter the data before which ou want to enter: ");
                scanf("%d", &enter_before_data); 

                output = insert_before(&head, data, enter_before_data);

                if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                else if(output == SUCCESS)
                {
                    printf("The insert before is success.\n");
                }
                else{
                    printf("The insert before function failed.\n");
                }
                break;

            case 5: //insert nth
                printf("Enter data to be entered: ");
                scanf("%d", &data);

                printf("Enter the position the data wants to enter: ");
                scanf("%d", &pos);

                output = insert_at_nth(&head, data, pos);

                if(output == SUCCESS)
                {
                    printf("The data is entered to the list at position %d.\n", pos);
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                else{
                    printf("The insert at nth function failed.\n");
                }
                break;

            case 6:
                output - delete_at_first(&head);
                if(output == SUCCESS)
                {
                    printf("Delete at first is successfull.\n");
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                else{
                    printf("Delete at first is failed.\n");
                }
                break;

            case 7: 

                output = delete_at_last(&head);

                if(output == SUCCESS)
                {
                    printf("Delete at last successfull\n");
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");    
                }
                break;

            case 8: //delete nth

                printf("Enter the postion at which the element to be deleted: ");
                scanf("%d", &pos);

                output = delete_at_nth(&head, pos);

                if(output == SUCCESS)
                {
                    printf("Deleted the element at position %d\n", pos);
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                else{
                    printf("Delete at Nth function failed.\n");
                }

                break;

            case 9:
                output = delete_list(&head);

                if(output == SUCCESS)
                {                 
                    printf("The list is deleted.\n");
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                break;

            case 10: 
                printf("Enter the data to find: ");
                scanf("%d", &data);

                output = find_node(&head, data);

                if(output == NOT_FOUND)
                {
                    printf("The node is present in the list.\n");
                }
                else if(output == EMPTY_LIST)
                {
                    printf("The list is empty.\n");
                }
                else{
                    printf("The node is not present at position %d.\n", output);
                }
                break;

            case 11:
                printf("Printing the elements of the list\n");
                print_list(head);
                break;

            case 12:
                exit(0);
                break;

            default:
                printf("Enter correct option from the menu.\n");
                break;          
            
        }
    }
    
    return 0;
}

int select_operation()
{
    int choice;

    printf("Menu: \n1. Insert at the end.\n2. Insert after an element.\n3. Insert at first\n4. Insert befor an element\n5. Insert at Nth\n6. Delete at first.\n7. Delete at last\n8. Delete at Nth\n9. Delete list\n10. Find node\n11. Print the list.\n12. Exit the code.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int insert_at_end(node **head, int data)
{
    node *new;
    new = malloc(sizeof(node));
    if(new == NULL)
    {
        return FAILURE;
    }
    else{
        new->data = data;
        new->link = NULL;
        if(*head == NULL)
        {
            *head = new;
        }
        else
        {
            node *temp;
            temp = *head;
            
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new;
            new->data = data;
        }
    }
    return SUCCESS;
}

int insert_after(node **head, int data, int enter_after)
{
    int data_found = 0;
    if(*head == NULL)
    {
        return EMPTY_LIST;
    }
    else{
        node *temp = *head;
        while(temp)
        {
            if(temp->data == enter_after)
            {
                data_found = 1;
                node *new = malloc(sizeof(node));

                if(new == NULL)
                {
                    printf("No memory allocated\n");
                    return FAILURE;
                }

                new->link = temp->link;
                temp->link = new;
                new->data = data;
                break;
            }
            else{
                temp = temp->link;
            }
        }
        if(data_found == 0)
        {
            return DATA_NOT_FOUND;
        }
    }
    return SUCCESS;
}

int insert_before(node **head, int data, int enter_before)
{
    if(*head == NULL || head == NULL)
    {
        return EMPTY_LIST;
    }    

    node *new = malloc(sizeof(node));

    if(new == NULL)
    {
        printf("The memory is not allocated.\n");
        return FAILURE;
    }

    new->data = data;
    node *temp = *head, *prev = NULL;

    //check for the first element
    if(temp->data == enter_before)
    {
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    while(temp)
    {
        if(temp->data == enter_before)
        {
            new->link = prev->link;
            prev->link = new;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->link;
    }
    return FAILURE;
}

int insert_at_first(node **head, int data)
{
    if(*head == NULL || head == NULL)
    {
        return EMPTY_LIST;
    }

    node *new = malloc(sizeof(node));

    if(new == NULL)
    {
        printf("Memory not allocated.\n");
        return FAILURE;
    }

    new->data = data;
    new->link = *head;
    *head = new;
    return SUCCESS;
}

int insert_at_nth(node **head, int data, int pos)
{
    if(*head == NULL || head == NULL)
    {
        if(pos == 1)
        {
            node *new = malloc(sizeof(node));
            if(new == NULL)
            {
                printf("Unable to allocate the memory.\n");
                return FAILURE;
            }
            else{
                new->data = data;
                *head = new;
                new->link = NULL;
                return SUCCESS;
            }
        }
        return EMPTY_LIST;
    }
    else{
        int count=1;
        node *new = malloc(sizeof(node));

        if(new == NULL)
        {
            return FAILURE;
        }

        node *temp = *head, *prev = NULL;
        new->data = data;
        //if position is 1
        if(pos == 1)
        {
            new->link = *head;
            *head = new;
        }
        
        while(temp)
        {
            if(count == pos)
            {
                new->link = temp;
                prev->link = new;

                return SUCCESS;
            }
            count++;
            prev = temp;
            temp = temp->link;
        }
        if(pos == count)
        {
            prev->link = new;
            new->link = NULL;
            return SUCCESS;
        }
        else{
            printf("Position not found.\n");
            return FAILURE;
        }

    }
}

int delete_at_first(node **head)
{
    if((head == NULL) || (*head == NULL))
    {
        return EMPTY_LIST;
    }

    node *temp;
    temp = *head;
    *head = (*head)->link;
    free(temp);
    return SUCCESS;
}

int delete_at_last(node **head)
{
    if(*head == NULL)
    {
        return EMPTY_LIST;
    }

    node *temp;
    if((*head)->link == NULL)
    {
        free(*head);
        return SUCCESS;
    }

    else{
        node *prev = NULL;
        temp = *head;
        while(temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        free(temp);
        prev->link = NULL;
        return SUCCESS;
    }
    
}

int delete_at_nth(node **head, int pos)
{
    if(*head == NULL || head == NULL)
    {
        return EMPTY_LIST;
    }

    else{
        int count = 1;
        node *temp = *head, *prev = NULL;

        if(pos == 1)
        {
            *head = temp->link;
            temp = NULL;
            free(temp);
            return SUCCESS;
        }

        while(temp)
        {
            if(count == pos)
            {
                prev->link = temp->link;
                temp->link = NULL;
                free(temp);

                return SUCCESS;
            }
            count++;
            prev = temp;
            temp = temp->link;
        }
    }
    return FAILURE;
}

int delete_list(node **head)
{
    if(*head == NULL)
    {
        return EMPTY_LIST;
    }

    node *temp = *head;

    while((*head)->link != NULL)
    {
        temp = *head;
        (*head) = (*head)->link;
        free(temp);
    }
    free((*head));
    *head = NULL;

    return SUCCESS;    
}

int find_node(node **head, int data)
{
    if(*head == NULL)
    {
        return EMPTY_LIST;
    }

    node *temp = *head;
    int count = 0;
    while(temp->link != NULL)
    {
        count++;
        if(temp->data == data)
        {
            return count;
        }
        else{
            temp = temp -> link;
        }
    }
    if(temp->data == data)
    {
        count++;
        return count;
    }
    
    return NOT_FOUND;
}

void print_list(node *element)
{
    if(element == NULL)
    {
        printf("The list is empty.\n");
    }
    else{
        while(element)
        {
            printf("%d-->", element->data);
            element = element->link;
        }
        printf("NULL");
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "double_ll.h"

int main()
{
    //1) declare structure head and tail
    node *head = NULL, *tail = NULL;
    
    //2) declare variable that are common
    int output, choice;

    //3) declare variable that are case specific
    int data, after_data, before_data, pos;

    while(1)
    {    
        choice = select_operation();
        switch(choice)
        {
            case 1: //insert at the end
                printf("Enter the data to be entered: ");
                scanf("%d", &data);

                output = insert_at_last(&head, &tail, data);

                if(output == SUCCESS)
                {
                    printf("Insert at end success.\n");
                }
                else{
                    printf("Insert at end failed.\n");
                }
                break;

            case 2: //insert in the beginning
                printf("Enter the data to be entered: ");
                scanf("%d", &data);

                output = insert_in_beginning(&head, &tail, data);

                if(output == SUCCESS)
                {
                    printf("Insert in beginning success.\n");
                }
                else{
                    printf("Insert in beginning failed.\n");
                }
                break;
                
            case 3: //insert after the value
                printf("Enter the data to be entered: ");
                scanf("%d", &data);

                printf("Enter the data after which data: ");
                scanf("%d", &after_data);

                output = insert_after(&head, data, after_data);
                
                if(output == SUCCESS)
                {
                    printf("Enter after data is successful.\n");
                }
                else if(output == EMPTY)
                {
                    printf("The list is empty.\n");
                }
                else if(output == DATA_NOT_FOUND)
                {
                    printf("Data is not present.\n");
                }
                else{
                    printf("Enter after data failed.\n");
                }
                break;
                
            case 4: //insert before the value
                printf("Enter the data to be entered: ");
                scanf("%d", &data);

                printf("Enter the data after which data: ");
                scanf("%d", &before_data);

                output = insert_before(&tail, data, before_data);
                
                if(output == SUCCESS)
                {
                    printf("Enter after data is successful.\n");
                }
                else if(output == EMPTY)
                {
                    printf("The list is empty.\n");
                }
                else if(output == DATA_NOT_FOUND)
                {
                    printf("Data is not present.\n");
                }
                else{
                    printf("Enter after data failed.\n");
                }
                break;

            case 5: //Deletion at last
                output = delete_at_last(&tail);

                if(output == SUCCESS)
                {
                    printf("Delete at last successfull.\n");
                }
                else if(output == EMPTY)
                {
                    printf("The list is empty.\n");
                }
                break;
            
            case 6: //Delete in beginning
                output = delete_in_beginning(&head);
                if(output == SUCCESS)
                {
                    printf("Delete in beginning successfull.\n");
                }
                else if(output == EMPTY)
                {
                    printf("The list is empty.\n");
                }
                break;

            case 7: //Delete the element
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);

                output = delete_element(&head, data);

                if(output == SUCCESS)
                {
                    printf("Delete element is successfull.\n");
                }
                else if(output == EMPTY)
                {
                    printf("The list is empty.\n");
                }
                else if(output == DATA_NOT_FOUND)
                {
                    printf("Data not found");
                }
                break;

            case 8: //delete the list
                output = delete_list(&head);

                if(output == SUCCESS)
                {
                    printf("Delete the list successfull\n");
                }
                break;

            case 9: //Find the element
                printf("Enter the data to be found: ");
                scanf("%d", &data);

                output = find_element(&head, data);

                if(output == EMPTY)
                {
                    printf("The list is empty.\n");
                }
                else if(output == DATA_NOT_FOUND)
                {
                    printf("The data is not in the list.\n");
                }
                else{
                    printf("The data: %d is found at position: %d.\n", data, output);
                }
                break;

            case 10: //printing
                printf("Printing the double linked list->\n");
                print_list(head, tail);
                break;

            case 11: exit(0);
                break;

            default: printf("Enter correct option.\n");
        }
    }

}   

int select_operation()
{
    int choice;
    printf("Menu-\n");
    printf("1. Insert at end.\n2. Insert in beginning.\n3. Insert after data.\n4. Insert before data.\n5. Deletion at last.\n6. Deletion in beginning.\n7. Delete the element.\n8. Delete the list.\n9. Find the element.\n10. Print the elements.\n11. Exit the program.\n");
    printf("Enter your choice -> ");
    scanf("%d", &choice);

    return choice;
}

int insert_at_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if(new == NULL)
    {
        return FAIL;
    }
    new->data = data;
    new->next = NULL;
    if(*head == NULL && *tail == NULL)
    {
        //if the list is empty
        new->prev = NULL;
        new->next = NULL;
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else{
        //if list is noot empty
        //node *temp = tail;

        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
        new->next = NULL;
        return SUCCESS;
    }
}

int insert_in_beginning(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;
    if(*head == NULL && *tail == NULL)
    {
        //list is empty
        new->next = NULL;
        new->prev = NULL;
        *head = *tail = new;
        return SUCCESS;
    }
    else{
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        new->prev = NULL;
    }

}

int insert_after(node **head, int data, int data_after)
{
    if(*head == NULL)
    {
        return EMPTY;
    }
    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
        return FAIL;
    }
    new->data = data;
    node *temp = *head, *temp_1 = NULL;

    while(temp)
    {
        if(temp->data == data_after)
        {
            if(temp->next == NULL)
            {
                temp->next = new;
                return SUCCESS;
            }
            temp_1 = temp->next;
            temp->next = new;
            new->next = temp_1;
            new->prev = temp;
            temp_1->prev = new;
            return SUCCESS;
        }
        temp = temp->next;
    }
    return DATA_NOT_FOUND;
}

int insert_before(node **tail, int data, int data_before)
{
    if(*tail == NULL)
    {
        return EMPTY;
    }

    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
        return FAIL;
    }
    new->data = data;
    node *temp = *tail, *temp_1;
    while(temp)
    {
        if(temp->data == data_before)
        {
            if(temp->prev == NULL)
            {
                temp->next = new;
                return SUCCESS;
            }
            temp_1 = temp->prev;
            new->prev = temp_1;
            new->next = temp;

            temp_1->next = new;
            temp->prev = new;
        }
        temp = temp->prev;
    }

    return SUCCESS;
}

int delete_at_last(node **tail)
{
    if(*tail == NULL)
    {
        return EMPTY;
    }

    if((*tail)->prev == NULL)
    {
        *tail = NULL;
        free(*tail);
        return SUCCESS;
    }
    node *temp = *tail;

    *tail = (temp->prev);
    (*tail)->next = NULL;
    temp->prev = NULL;
    return SUCCESS;
}

int delete_in_beginning(node **head)
{
    if(*head == NULL)
    {
        return EMPTY;
    }

    node *temp = *head;

    *head = temp->next;
    (*head)->prev = NULL;
    temp->next = NULL;

    return SUCCESS;
}

int delete_element(node **head, int data)
{
    if(*head == NULL)
    {
        return EMPTY;
    }

    node *temp = *head, *temp_p = NULL, *temp_n = NULL;
    int data_found=0;
    while(temp)
    {
        if(temp->data == data)
        {
            // temp_n = temp->next;
            // temp_p = temp->prev;

            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;

            temp->next = NULL;
            temp->prev = NULL;
            data_found = 1;
        }
        temp = temp->next;
    }
    if(data_found == 0)
    {
        return DATA_NOT_FOUND;
    }
    return SUCCESS;

}

int delete_list(node **head)
{
    if(*head == NULL)
    {
        return EMPTY;
    }

    node *temp;
    while(*head)
    {
        temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
    return SUCCESS;
}

int find_element(node **head, int data)
{
    int pos = 1;
    if(*head == NULL)
    {
        return EMPTY;
    }

    node *temp = *head;
    while(temp)
    {
        if(temp->data == data)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return DATA_NOT_FOUND;
}

int print_list(node *head, node *tail)
{
    if(head == NULL || tail == NULL)
    {
        printf("The list is empty.\n");
        return EMPTY;
    }

    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("\n");
}

int total_indexes(node **head)
{
    int index = 0;
    while((*head))
    {
        index++;
        (*head) = (*head)->next;
    }

    return index;
}

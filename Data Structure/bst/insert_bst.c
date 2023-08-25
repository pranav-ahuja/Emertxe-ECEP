#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{    
    Tree_t *new = malloc(sizeof(Tree_t));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    if(*root == NULL)
    {
        *root = new;
        return SUCCESS;
    }
    else{
        int flag;
        Tree_t *temp = *root;

        while(temp != NULL)
        {
            if(data > temp->data)
            {
                flag = 1; 
                if(temp->right == NULL)
                    break;                               
                temp = temp->right;                
            }
            else if(data < temp->data)
            {
                flag = 0;
                if(temp->left == NULL)
                    break;                
                temp = temp->left;                                                
            }
            else{
                flag = -1;
                break;
            }
        }
        if(flag == 1)
        {
            temp->right = new;
        }
        else if(flag == 0)
        {
            temp->left = new;
        }
        else{
            return DUPLICATE;
        }
    }
    return SUCCESS;

}
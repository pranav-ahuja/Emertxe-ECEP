#include "tree.h"

extern int status;
/* Function to delete the node  */
Tree_t * delete_BST(Tree_t * root, int data)
{
    Tree_t *temp = root, *prev;
    int flag;

    while(temp)
    {
        prev = temp;
        if(temp->data == data)
        {
            //case 1: Delete leaf node 
            if(temp->left == NULL && temp->right == NULL)
            {
                prev->left = temp->left;
                prev->right = temp->right;
                free(temp);
            }           
            else if(temp->left == NULL)
            {
                temp->data = temp->right->data;
                free(temp->right);
                temp->right = NULL;
            }
            else if(temp->right == NULL)
            {
                temp->data = temp->left->data;
                free(temp->left);
                temp->left = NULL;
            }
            else {
                temp = temp->right;
                int min_data = findmin(temp);
                prev->data = min_data;
                delete_BST(root, min_data);
            }
            //case 2: Delete node with single child
            //case 3: Delete node with 2 children
            return temp;
        }

        if(data > temp->data)
        {
            flag = 1;            
            temp = prev->right;
        }
        else if(data < temp->data)
        {
            flag = 0;            
            temp = prev->left;
        }
    }
    return temp;
}
#include "tree.h"

/* Iteratively */
int search_BST(Tree_t * root, int data)
{  
    if(root == NULL)
    {
        return NOELEMENT;
    }

    Tree_t *temp = root;

    while(temp)
    {
        if(temp->data == data)
        {
            return SUCCESS;
        }
        else if(data < temp->data)
        {
            temp = temp->left;
        }
        else if(data > temp->data)
        {
            temp = temp->right;
        }
    }
    return FAILURE;
}
#include "tree.h"

int findmax(Tree_t * root)
{
    if(root == NULL)
    {
        return FAILURE;
    }

    Tree_t *temp = root;

    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

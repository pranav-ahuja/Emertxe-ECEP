#include "tree.h"

int total_nodes(Tree_t *root)
{
    static int count = 0;
    if(root == NULL)
    {
        return NOELEMENT;
    }
    total_nodes(root->left);
    count++;
    total_nodes(root->right);
    
    return count;
}

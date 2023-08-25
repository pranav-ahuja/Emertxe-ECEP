#include "tree.h"

int find_height(Tree_t *root)
{
    int count = 1;
    int height = 0;
    if(root == NULL)
    {
        return NOELEMENT;
    }
    else{
        Tree_t *temp = root;

        if(temp->left == NULL || temp->right == NULL)
        {
            if(temp->left == NULL && temp->right == NULL)            
                return 1;            
            else if(temp->left == NULL)            
                count += find_height(temp->right);        
            else if(temp->right == NULL)
                count += find_height(temp->left);
        }
        else if(temp->left != NULL && temp->right != NULL)
        {
            count += find_height(temp->left);
            count = 1;
            count += find_height(temp->right);
        }        
    }
    return count;
}

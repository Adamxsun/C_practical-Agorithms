// Adam 
//

#include <iostream>
#include <algorithm>
#define COUNT 10
struct node
{
	int key_value;
	node* left;
	node* right;
    node(int val)
    {
        key_value = val;

        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }//node
};
void printTree(node* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    printTree(root->right, space);
    for (int i = COUNT; i < space; i++)
        std::cout << "\t";
    std::cout << root->key_value << "\n";
    printTree(root->left, space);
}//printTree
int maxDeath(node* node) {
    if (node == NULL) {
        return -1;
    }
    int left = maxDeath(node->left);
    int right = maxDeath(node->right);
    return std::max(left, right) + 1;
}
int main()
{
    node* root = new node(13);
    /* 

            13
           / \
         NULL NULL
   */

    root->left = new node(2);
    root->right = new node(3);
    /* 
                    13
                  /    \
                 2       3
               /  \     /  \
            NULL NULL  NULL NULL
    */

    root->left->left = new node(4);
    root->left->right = new node(23);
    /* 
               13
            /     \
           2       3
          / \     / \
         4  23 NULL NULL
        / \
     NULL NULL
    */
    printTree(root, 0);
    return 0;
    std::cout << maxDeath(root);
}//main

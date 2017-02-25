#include <iostream>

using namespace std;

#define INF (1000000);

struct Node
{
   Node * left;
   Node * right;
   int data;

   Node (int data) 
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};

void helper(Node * node, int & max, int & min, int level)
{
    level++;
    if (node->left) helper(node->left, max, min, level);
    if (node->right) helper(node->right, max, min, level);
    if (node->left == NULL && node->right == NULL)
    {
        if (level > max) max = level;
        if (level < min) min = level;
    }
}

bool balancedTree(Node * root)
{
    int max = -1, min = INF;
    helper(root, max, min, 0);
    return (max - min <= 1);
}

int main()
{
    Node * node = new Node(10);
    cout << balancedTree(node) << endl;
    node->left = new Node(8);
    node->right = new Node(2);
    node->left->left = new Node(3);
    node->left->right = new Node(5);
    node->right->left = new Node(2);
    node->right->left->right = new Node(1);      

    cout << balancedTree(node) << endl;
    node->right->left->right->left = new Node(0);      
    cout << balancedTree(node) << endl;

    return 0;
}

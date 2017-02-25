#include <iostream>

using namespace std;

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

bool univalTree(Node * root)
{
    if (root == NULL) return true;
    if (root->left && root->left->data != root->data) return false;
    if (root->right && root->right->data != root->data) return false;
    return (univalTree(root->left) && univalTree(root->right));
}

int helper(Node * root, Node *& temp)
{
    bool left = true, right = true;
    int countL = 0, countR = 0;
    if (root->left)
    {
        countL = helper(root->left, temp);
        if (root->left->data != root->data || temp != root->left) left = false;
    } 
    if (root->right)
    {
        countR = helper(root->right, temp);
        if (root->right->data != root->data || temp != root->right) right = false;
    }
    if (left && right)
    {
        temp = root;
        return 1;
    }
    else
    {
        return countL + countR;
    }
}

int countUnivalSubtree(Node * root)
{ 
    if (root == NULL) return 1;
    Node * temp = NULL;
    return helper(root, temp);
}

int main()
{
    Node * node = new Node(1);
    node->left = new Node(10);
    node->right = new Node(10);
    node->left->left = new Node(10);
    node->left->right = new Node(10);
    node->right->left = new Node(10);
    node->right->left->right = new Node(10);      

    cout << univalTree(node) << endl;
    cout << countUnivalSubtree(node) << endl;

    return 0;
}
     


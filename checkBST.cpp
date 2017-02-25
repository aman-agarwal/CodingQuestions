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


bool helper(Node * root, int min, int max)
{
    if (root == NULL) return true;
    
    if (root->data <= min || root->data >= max) return false;
    return helper(root->left, min, root->data) && helper(root->right, root->data, max);
}


bool checkBST(Node * root)
{
    int min = -100000, max = 100000;
    return helper(root, min, max);
}


int main()
{
    Node * root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(3);
 
    cout << checkBST(root) << endl;
   
    return 0;
}

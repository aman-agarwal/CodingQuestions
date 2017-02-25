#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
   int data;
   Node * left;
   Node * right;

   Node (int data) 
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};

void helper(Node * root, Node * node, vector<Node *> & v)
{
     if (root == node) 
     {
         v.push_back(root);
     }
     else
     {
         if (root->left) helper(root->left, node, v);
         if (root->right) helper(root->right, node, v);
         if (!v.empty()) 
         {
             v.push_back(root); 
         }
     }
}     
         
vector<Node *> path(Node * root, Node * node)
{
     vector<Node *> v;
     if (root) helper(root, node, v);
     reverse(v.begin(), v.end());
     return v; 
}

int main()
{
    Node * node = new Node(10);
    node->left = new Node(8);
    node->right = new Node(2);
    node->left->left = new Node(3);
    node->left->right = new Node(5);
    node->right->left = new Node(2);
    node->right->left->right = new Node(1);      

    vector<Node *> v = path(node, node->right->left->right);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]->data << " ";
    }
    if (v.empty()) cout << "No path" << endl;
    else cout << endl;

    return 0;
}



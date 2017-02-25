#include <iostream>
#include <stack>

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

void inOrder(Node * root)
{
   stack<Node *> S;
   Node * node = root;
   
   while (!S.empty() || node)
   {
      if (node)
      {
          S.push(node);
          node = node->left;
      }
      else
      {
          node = S.top(); 
          S.pop();
          cout << node->data << " ";
          node = node->right;
      }
   }
   cout << endl;        
} 

void preOrder(Node * root)
{
   stack<Node *> S;
   S.push(root);
   Node * node;
   while (!S.empty())
   {
       node = S.top();
       cout << node->data << " ";
       S.pop();
       if (node->right) S.push(node->right);
       if (node->left) S.push(node->left);
   }
   cout << endl;
}

/* More elegant: reverse pre-order traversal. */
void postOrder(Node * root)
{
    stack<Node *> S;
    S.push(root);
    Node * prev = NULL;
    Node * node;
    while (!S.empty())
    {
       node = S.top();
       if (prev && (node->left == prev || node->right == prev)) 
       {
           S.pop();
           prev = node;   
           cout << node->data << " ";
       }
       else if (node->left == NULL && node->right == NULL)
       {
           S.pop();
           prev = node;   
           cout << node->data << " ";
       }
       else
       { 
           if (node->right) S.push(node->right);
           if (node->left) S.push(node->left);
       }
    }        
    cout << endl;
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

    inOrder(node); 
    preOrder(node);
    postOrder(node);
   
    return 0;
}












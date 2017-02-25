#include <iostream>
#include <cassert>

using namespace std;

struct Node
{
   int data;
   Node * left;
   Node * right;
   Node * parent;
   Node (int data) 
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
      this->parent = NULL;
   }
};


Node * nextInOrder(Node * node)
{
   assert(node != NULL);
   if (node->right)
   {
       Node * temp = node->right;
       while (temp->left) temp = temp->left;
       return temp;
   }
   else 
   {
       Node * temp = node;       
       while (temp->parent && temp->parent->right == temp) temp = temp->parent;
       return temp->parent;
   }
}

Node * nextPreOrder(Node * node)
{
    assert(node != NULL);
    if (node->left) 
    {
       return node->left;
    }
    else if (node->right)
    {
       return node->right;
    }
    else
    {
       Node * temp = node;
       while (temp->parent && temp->parent->right == temp) temp = temp->parent;
       if (temp->parent == NULL || temp->parent->right == NULL) return NULL;
       else return temp->parent->right;
    }
}

Node * nextPostOrder(Node * node)
{
    assert(node != NULL);
    if (node->parent == NULL) return NULL;

    if (node->parent->right == node || node->parent->right == NULL) 
    {
        return node->parent;
    }
    else
    {
        Node * temp = node->parent->right; 
        while (temp->left) temp = temp->left;
        return temp;
    }
}

  
int main()
{
    Node * node = new Node(10);
    node->left = new Node(8);
    node->right = new Node(11);
    node->left->parent = node;
    node->right->parent = node;  
 
    Node * nextNode = nextInOrder(node);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextInOrder(node->right);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextInOrder(node->left);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;
 
    nextNode = nextPreOrder(node);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextPreOrder(node->right);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextPreOrder(node->left);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextPostOrder(node);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextPostOrder(node->right);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;

    nextNode = nextPostOrder(node->left);
    if (nextNode) cout << nextNode->data << endl;
    else cout << "None" << endl;


    return 0;
}



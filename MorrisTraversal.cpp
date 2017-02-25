#include <iostream>
#include <stack>
#include <vector>

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

void MorrisInOrder(Node * root)
{
    Node * curr = root;
    
    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node * temp = curr->left;
            while (temp->right && temp->right != curr) temp = temp->right;
 
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                temp->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }    
    cout << endl;
} 

void MorrisPreOrder(Node * root)
{
    Node * curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        } 
        else
        {
            Node * temp = curr->left;
            while (temp->right && temp->right != curr) temp = temp->right;
 
            if (temp->right == NULL)
            {  
                temp->right = curr;
                cout << curr->data << " ";
                curr = curr->left;
            }
            else
            {
                temp->right = NULL;   
                curr = curr->right;
            }
        }
    }  
    cout << endl;
}

void MorrisPostOrder(Node * root)
{
    vector<int> v;
    Node * curr = root;
  
    while (curr)
    {
        if (curr->right == NULL)
        {
            v.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            Node * temp = curr->right;
            while (temp->left && temp->left != curr) temp = temp->left;
          
            if (temp->left == NULL)
            {
                temp->left = curr;
                v.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                temp->left = NULL;
                curr = curr->left;
            }
        }
    } 
    
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " ";
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

    MorrisInOrder(node); 
    MorrisPreOrder(node); 
    MorrisPostOrder(node); 
  
    return 0;
}

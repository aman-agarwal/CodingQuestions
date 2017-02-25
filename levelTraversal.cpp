#include <iostream>
#include <vector>
#include <list>

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

void levelTraversal(Node * root)
{
     vector<Node *> v;
     v.push_back(root);
     int levelInd = 0, temp;
     while (levelInd < v.size())
     {
         temp = v.size();
         for (int j = levelInd; j < temp; j++)
         {
             cout << v[j]->data << " ";
             if (v[j]->left) v.push_back(v[j]->left);
             if (v[j]->right) v.push_back(v[j]->right);
         }     
         cout << endl;
         levelInd = temp;
     }
}  

vector<list<Node *> > levelTraversal2(Node * root)
{
    vector<list<Node *> > v;
    if (root == NULL) return v;

    list<Node *> L;
    L.push_back(root);
    v.push_back(L);

    int level = 0;
    while (true)
    {
        list<Node *> newL;
        for (list<Node *>::iterator it = v[level].begin(); it != v[level].end(); it++)
        {
            if ((*it)->left) newL.push_back((*it)->left);
            if ((*it)->right) newL.push_back((*it)->right);
        }        
        if (newL.size() > 0) 
        {
            v.push_back(newL);
            level++;
        }
        else
        {
            break;
        }
    }
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

    levelTraversal(node); 
 
    vector<list<Node *> > v = levelTraversal2(node);
    for (int i = 0; i < v.size(); i++)
    {
        for (list<Node *>::iterator it = v[i].begin(); it != v[i].end(); it++)
        {
             cout << (*it)->data << " ";
        }
        cout << endl;
    }    
 
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
   Node * left;
   Node * right;
};

int height(Node * root)
{
    if (root == NULL) return 0;
    else return 1 + max(height(root->left), height(root->right));
}

int helper(Node * root, int & hT)
{
    if (root->left == NULL && root->right == NULL) 
    {
        hT = 1;
        return 1;
    }
    else
    {
        int hL = 0, hR = 0;
        int dL = 0, dR = 0, d;   

        if (root->left) dL = helper(root->left, hL);
        if (root->right) dR = helper(root->right, hR);

        hT = 1 + max(hL, hR);
       
        d = hL + hR + 1; 
        return max(dL, max(dR, d));
    }
}
 
int treeDiameter(Node * root)
{
    if (root == NULL) return 0;
    int hT;
    return helper(root, hT);
}

int main()
{ 
    Node * node = new Node;

    cout << treeDiameter(node) << endl;

    node->left = new Node;
    node->left->left = new Node;

    cout << treeDiameter(node) << endl;

    node->left->left->left = new Node;
    node->left->right = new Node;
    node->right = new Node;
    node->right->left = new Node;
    node->right->left->left = new Node;
    node->right->left->right = new Node; 

    cout << treeDiameter(node) << endl;

    Node * root = new Node;
    root->left = new Node;
    root->left->left = new Node;
    root->left->left->left = new Node;
    root->left->left->left->left = new Node;
    root->left->left->left->left->left = new Node;
    root->left->left->left->left->left->left = new Node;
    root->left->left->right = new Node;
    root->left->left->right->right = new Node;
    root->right = new Node; 
    cout << treeDiameter(root) << endl;
   
    root->left->left->right->right->right = new Node;
    root->left->left->right->right->right->right = new Node;
 

    cout << treeDiameter(root) << endl;
    cout << height(root) << endl;

    return 0;
}

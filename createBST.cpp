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

/* arr is sorted */
Node * createBST(int arr[], int l, int h)
{
   if (l > h) return NULL;
   int mid = (l + h)/2;
   Node * root = new Node(arr[mid]);
   root->left = createBST(arr, l, mid-1);
   root->right = createBDT(arr, mid+1, h);
    
   return root;
}





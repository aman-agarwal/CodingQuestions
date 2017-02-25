
using namespace std;

struct Node 
{
   int data;
   Node * left;
   Node * right;
};

unordered_map<Node *, Node * > table;

Node * copy(Node * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (table.count(node) > 0)
    {
        return table[node];
    }
    else
    {
        Node * newNode = new Node();
        newNode->data = node->data;
        table[node] = newNode;
        newNode->left = copy(node->left);
        newNode->right = copy(node->right);
        return newNode;
    }
} 

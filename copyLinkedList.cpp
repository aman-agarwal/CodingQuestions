



Node * copy(Node * head)
{
    if (head == NULL) return NULL;
 
    Node * dup = new Node;
    dup->data = head->data;
   
    Node * curr = head->next;
    Node * prev = dup;
  
    while (curr)
    {
       Node * newNode = new Node;
       newNode->data = curr->data;
       prev->next = newNode;
       prev = prev->next;
       curr = curr->next;
    }
    prev->next = NULL;
    return dup;
}    
    
Node * helper(Node * head, unordered_map<Node *, Node *> & table)
{
    if (head == NULL) return NULL;
    if (table.count(head) > 0) return table[head];

    Node * newNode = new Node;
    newNode->data = head->data;
    table[head] = newNode;
    newNode->next = helper(head->next, table);
    newNode->random = helper(head->random, table);

    return newNode;
}

Node * copyWithRandom(Node * head)
{
    unordered_map<Node *, Node *> table;
    return helper(head, table);
}   

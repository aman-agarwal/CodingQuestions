

struct Node 
{
   Node * next;
   int data;
};

Node * detectLoop(Node * head)
{
    Node * fast = head;
    Node * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    } 
    if (fast == NULL || fast->next == NULL) return NULL;
   
    Node * temp = head;
    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }
    return slow;
}

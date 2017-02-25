#include <cstdio>
#include <cassert>
#include "linkedList.h"

int length(node * head)
{
   int count = 0;
   node * temp = head;
   while (temp)
   {
      count++;
      temp = temp->next;
   }
   return count;
}

void push(node *& head, int newData)
{
   node * newNode = new node;
   newNode->data = newData;
   newNode->next = head;
   head = newNode;
}

int pop(node *& head)
{
   assert(head != NULL);
 
   int data = head->data;
   node * temp = head;
   head = head->next;
   delete temp;
 
   return data;
} 

void pushBack(node *& head, int newData)
{
   node * newNode = new node;
   newNode->data = newData;
   newNode->next = NULL;
   
   if (head)
   {
       node * tail = head;
       while (tail->next)
       {
          tail = tail->next;
       }
       tail->next = newNode;
   }
   else
   {
       head = newNode;
   }
} 

void pushBackV2(node *& head, int newData)
{
   node * tail = head;
   while (tail && tail->next)
   {
       tail = tail->next;
   }
   if (tail)
      push(tail->next, newData);
   else 
      push(head, newData);
}

void print(node * head)
{
   node * temp = head;
   while(temp)
   {
       printf("%d ", temp->data);
       temp = temp->next;
   }
   printf("\n");
}   
   
void del(node *& head)
{
   node * temp;
   while (head)
   {
      temp = head;
      head = head->next;
      delete temp;
   }
}      

void delNode(node * Node)
{
   assert(Node != NULL);

   if (Node->next)
   {
       Node->data = Node->next->data;
       node * temp = Node->next;
       Node->next = temp->next;
       delete temp;
   }
   else
   {
       printf("Cannot delete last node\n");
   }
}   

node * buildOneTwoThree()
{
   node * one = new node;
   node * two = new node;
   node * three = new node;
   one->data = 1;
   two->data = 2;
   three->data = 3;
   one->next = two;
   two->next = three;
   three->next = NULL;
   return one;
}

void buildSpecial()
{
   node * head = NULL;
   node ** lastPtr = &head;
  
   for(int i = 1; i < 5; i++)
   {
       push(*lastPtr, i);
       lastPtr = &((*lastPtr)->next);
   }
   print(head);
   del(head);
}

int getNth(node * head, int index)
{
   int count = 0;
   node * temp = head; 
   while (temp)
   {
       if (count == index) return temp->data;
       temp = temp->next;
       count++;
   }
   return -1;
}

void insertNth(node *& head, int index, int data)
{
   if (index == 0)
   {
      push(head, data);
   }
   else 
   {
      node * temp = head;
      int count = 0;
      while (temp && count < index - 1)
      {
         temp = temp->next;         
         count++;
      }
      if (temp)
      {
         push(temp->next, data);
      }
      else
      {
         printf("Not enough nodes\n");
      }
   }
}  

int getNthLast(node * head, int index)
{
   int count = 0;
   node * temp = head;
   while (temp && count < index)
   {
       temp = temp->next;
       count++;
   }
   if (count < index) return -1;
   
   node * prev = head;
   while (temp)
   {
       prev = prev->next;
       temp = temp->next;
   }
   return prev->data;
}

void sortedInsert(node *& head, node * newNode)
{
   if (head == NULL || head->data > newNode->data)
   {
      newNode->next = head;
      head = newNode;
   }
   else
   {  
      node * temp = head;
      while (temp->next && temp->next->data <= newNode->data)
      {
          temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode; 
   }
}

void insertSort(node *& head)
{
   node * result = NULL;
   node * curr = head;
   node * temp;
   while (curr)
   {
       temp = curr->next;
       sortedInsert(result, curr);
       curr = temp;
   }
   head = result;    
}

void append(node *& a, node *& b)
{
   node * tail = a;
   while (tail && tail->next)
   {
       tail = tail->next;
   } 
   if (tail)
   {
       tail->next = b;
       b = NULL;
   }
   else
   {
       a = b; 
       b = NULL;
   }
}

void frontBackSplit(node * source, node *& front, node *& back)
{
   if (source == NULL || source->next == NULL)
   {
       front = source;
       back = NULL;
   }
   else 
   {
       node * slow = source;
       node * fast = source->next;
       while (fast)
       {
           fast = fast->next;
           if (fast)
           {
               fast = fast->next;
               slow = slow->next;
           }
       }
       front = source;
       back = slow->next;
       slow->next = NULL;
   }
} 

void removeDuplicates(node * head)
{
    node * curr = head;
    node * temp;
    while (curr && curr->next)
    { 
        if (curr->data == curr->next->data)
        {
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}     

void moveNode(node *& dest, node *& source)
{
    if (source == NULL)
    {
        fprintf(stderr, "Source cannot be empty\n");
    }
    else
    {
        node * temp = source;
        source = source->next;
        temp->next = dest;
        dest = temp;
    }
}

void alternatingSplit(node * source, node *& a, node *& b)
{
    int fl = 0;
    a = NULL;
    b = NULL;
    while (source)
    {
        if (fl)
        {
            moveNode(b, source);
            fl--;
        } 
        else
        {
            moveNode(a, source);
            fl++;
        }
    }
} 

node * shuffleMerge(node * a, node * b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    else
    {  
        a->next = shuffleMerge(b, a->next);
        return a;
    }
}          

node * sortedMerge(node * a, node * b)
{
    if (a == NULL)
    {  
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    else
    {
        if (a->data < b->data)
        {
            a->next = sortedMerge(a->next, b);
            return a;
        }
        else
        {
            b->next = sortedMerge(a, b->next);
            return b;
        }
    }
}

void mergeSort(node *& head)
{ 
    if (head && head->next)
    {   
        node * front, * back;
        frontBackSplit(head, front, back);
        mergeSort(front);
        mergeSort(back);
        head = sortedMerge(front, back);
    }
}

node * sortedIntersect(node * a, node * b)
{
    if (a == NULL || b == NULL)
    {
        return NULL;
    }
    else
    {
        if (a->data == b->data)
        {
            node * result = new node;
            result->data = a->data;
            result->next = sortedIntersect(a->next, b->next);
            return result;
        }
        else if (a->data < b->data)
        {
            return sortedIntersect(a->next, b);
        }
        else
        {
            return sortedIntersect(a, b->next);
        }
    }
}

void reverse(node *& head)
{
    node * curr = head;
    node * temp;
    node * prev = NULL;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}            

void recursiveReverse(node *& head)
{   
    if (head && head->next)
    {
        node * temp = head->next;
        recursiveReverse(temp);     
        head->next->next = head;
        head->next = NULL;
        head = temp;
    }
}

void pairwiseSwap(node * head)
{
   while (head && head->next)
   {
       int temp = head->data;
       head->data = head->next->data;
       head->next->data = temp;
       head = head->next->next;
   }
}       

void basicCaller()
{
   node * list = buildOneTwoThree();
   print(list);
   del(list);
  
   push(list, 10);
   push(list, 20);
   push(list, 30);
   print(list);

   push(list->next, 15);
   print(list);

   printf("%d\n", length(list));
   printf("%d\n", pop(list));
   print(list);

   del(list);
 
   pushBack(list, 10);
   pushBack(list, 20);
   pushBack(list, 30);
   print(list);
   del(list);

   pushBackV2(list, 10);
   pushBackV2(list, 20);
   pushBackV2(list, 30);
   print(list);
   del(list);
}

void test1()
{
   node * list = buildOneTwoThree();
   assert(getNth(list, 0) == 1);
   assert(getNth(list, 1) == 2);
   assert(getNth(list, 2) == 3);
   
   insertNth(list, 1, 4);
   print(list);
   insertNth(list, 1, 5);
   print(list);
   insertNth(list, 5, 6);
   print(list);
   insertNth(list, 0, 7);
   print(list);
   insertNth(list, 6, 8);
   print(list);
   insertNth(list, 9, 9);    
   insertSort(list);
   print(list);
   del(list);

   insertNth(list, 1, 1);
   insertNth(list, 0, 1);
   print(list);
   del(list);   
}

void test2()
{
   node * list = buildOneTwoThree();
   node * newNode1 = new node;
   newNode1->data = 4; 
   sortedInsert(list, newNode1);
   print(list);
   
   node * newNode2 = new node;
   newNode2->data = 0; 
   sortedInsert(list, newNode2);
   print(list);
   
   node * newNode3 = new node;
   newNode3->data = 1; 
   sortedInsert(list, newNode3);
   print(list);
   
   del(list);
 
   node * newNode4 = new node;
   newNode4->data = 1; 
   sortedInsert(list, newNode4);
   print(list);

   node * newNode5 = new node;
   newNode5->data = 1; 
   sortedInsert(list, newNode5);
   print(list);

   del(list);
   insertSort(list);
   push(list, 5);
   insertSort(list);
   push(list, 3);
   push(list, 4);
   insertSort(list);
   print(list);
   
   del(list);
}   

void test3()
{
   node * a = buildOneTwoThree();
   node * b = NULL;
   push(b, 5);
   push(b, 4);
   append(a, b);
   print(a);
   assert(b == NULL);
 
   del(a);
   push(b, 1);
   append(a, b);
   print(a);
   del(a);

   a = buildOneTwoThree();
   node * front, * back;
   frontBackSplit(a, front, back);
   print(front);
   print(back);
   del(front);
   del(back);
   
   a = buildOneTwoThree();
   push(a, 1);
   push(a, 1);
   insertNth(a, 3, 2);
   pushBack(a, 3);
   pushBack(a, 3);
   print(a);
   removeDuplicates(a);
   print(a);
   del(a);

   push(a, 1);
   push(a, 1);
   push(a, 1);
   removeDuplicates(a);
   print(a);
   del(a);

   a = buildOneTwoThree();
   b = buildOneTwoThree();
   moveNode(a, b);
   print(a);
   print(b);
   del(a);
   del(b);
}

void test4()
{
   node * list = buildOneTwoThree();
   node * a, * b;
   alternatingSplit(list, a, b);
   print(a);
   print(b);
   del(a);
   del(b);

   list = buildOneTwoThree();
   push(a, 4);
   b = shuffleMerge(list, a);
   print(b);
   del(b);

   list = buildOneTwoThree();
   a = NULL;
   push(a, 4);
   push(a, 5);
   push(a, 6);
   b = shuffleMerge(list, a);
   print(b);
   mergeSort(b);
   print(b);
   del(b);

   list = buildOneTwoThree();
   a = NULL;
   push(a, 2);
   b = sortedMerge(list, a);
   print(b);
   del(b);

   list = buildOneTwoThree();
   a = NULL;
   push(a, 4);
   push(a, 2);
   push(a, 1);
   b = sortedMerge(list, a);
   print(b);
   del(b);
}

void test5()
{
   node * list = buildOneTwoThree();
   node * a = buildOneTwoThree();
   node * b = sortedIntersect(a, list);
   print(b);
   reverse(b);
   print(b);
   del(a);
   del(b);
   del(list);

   recursiveReverse(list);
   push(list, 1);
   recursiveReverse(list);
   print(list);
   push(list, 2);
   recursiveReverse(list);
   print(list);
   push(list, 3);
   recursiveReverse(list);
   print(list);
   pairwiseSwap(list);
   print(list);
   del(list);
}

int main(int argc, char ** argv)
{
   basicCaller();
   buildSpecial();
   test1();
   test2();     
   test3();
   test4();
   test5();

   return 0;
}







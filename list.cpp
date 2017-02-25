#include <cstdio>
#include <iostream>

using namespace std;

template <typename T>
struct List
{
   struct Node
   {
      T value;
      Node * next;
   };

   Node * head;

   List()
   {
      this->head = NULL;
   }

   ~List()
   {
      Node * temp;
      while (head != NULL)
      {
          temp = head;
          head = head->next;
          delete temp;
      }
   }
 
   void insert(T value)
   {
       Node * node = new Node();
       node->value = value;
       node->next = NULL;

       if (this->head == NULL)
       {
           this->head = node;
       }
       else 
       {
           Node * temp = this->head;
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next = node;
       }
   }   

   void printList()
   {
      Node * temp = this->head;
      while (temp != NULL)
      {
          cout << temp->value << endl;
          temp = temp->next;
      }
   }

     
};


int main (int argc, char **argv)
{
    List<int> list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.printList();
    
    List<char> list2;
    list2.printList();
    list2.insert('a');
    list2.printList();
     
    return 0;
}    




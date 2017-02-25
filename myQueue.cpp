#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue
{
   stack<T> stack1;
   stack<T> stack2;
   int size;

   void move()
   {
       while (!stack1.empty()) 
       {
          stack2.push(stack1.top());
          stack1.pop();
       }
   }  
    
   public:
     
   bool empty()
   {
       return (this->size == 0);
   }

   void push(T val)
   {
      stack1.push(val);
      this->size++;
   }
  
   void pop()
   {
      if (stack2.empty()) this->move();
      this->size--;
      stack2.pop();
   }

   T& top()
   {
       if (stack2.empty()) this->move();
       return stack2.top();
   }
};
           
int main()
{
   MyQueue<int> queue;
   queue.push(1);
   queue.push(2);
   queue.push(3);
   
   cout << queue.top() << " ";
   queue.pop();
   cout << queue.top() << " ";
   queue.pop();
   cout << endl;
    
   queue.top() = 5;
   queue.push(6);  
   cout << queue.top() << " ";
   queue.pop();
   cout << queue.top() << " ";
   queue.pop();
   cout << endl;
    
   return 0;
}
   



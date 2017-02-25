#include <iostream>
#include <stack>

using namespace std;

template <class T>
void stackSort(stack<T> & S)
{
   stack<T> S2;
   while (!S.empty())
   {
       if (S2.empty() || S.top() <= S2.top()) 
       {
           S2.push(S.top());
           S.pop();
       }
       else 
       {
           T val = S.top();
           S.pop();
           S.push(S2.top());
           S2.pop();
           S.push(val);
       }
   }

   while (!S2.empty())
   {
       S.push(S2.top());
       S2.pop();
   }
}

int main()
{
   stack<int> S;
   S.push(1);
   S.push(5);
   S.push(2);
   S.push(4);
   S.push(0);
   S.push(3);
   stackSort(S);
  
   while (!S.empty())
   {
       cout << S.top() << " ";
       S.pop();
   }
   cout << endl;
   return 0;
}
   

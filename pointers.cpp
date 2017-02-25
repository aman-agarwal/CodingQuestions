#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void f(int * a)
{
   int b = *a + 1;
   a = &b;
}

void g(int ** aref)
{
   int * b = new int;
   *b = **aref + 1; 

   delete *aref;
 
   *aref = b;
}

void h(int *& a)
{
   int * b = new int;
   *b = *a + 1;
   delete a;
   a = b;
}

int main()
{
   int * a = new int;
  
   *a = 1;
   printf("%d %p\n", *a, a);
   f(a);
   printf("%d %p\n", *a, a);
   g(&a);
   printf("%d %p\n", *a, a);
   h(a);
   printf("%d %p\n", *a, a);
 
   char * c = new char[4];
   strcpy(c, "abc");
   cout << c << endl;   
   
   delete[] c;
   delete a;


   return 0;
}

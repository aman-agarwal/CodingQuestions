#include <iostream>

using namespace std;

int gcd(int a, int b)
{ 
   if (a > b) 
   {
       int temp = a;
       a = b;
       b = temp;
   }
   while (a)
   {
       int temp = b % a;
       b = a;
       a = temp;
   }
   return b;
}

int main()
{
   int N;
   cin >> N;
   for (int i = 1; i <= N; i++)
   {
       int a, b, g;
       cin >> a >> b;
       g = gcd(a, b);
       cout << i << " " << g << " " << a * b / g << endl;
   }
   return 0;
}

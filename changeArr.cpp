#include <iostream>

using namespace std;

void change(int arr[], int n)
{
   if (n > 0) change(arr, n -1);
}

int main()
{
   int arr[2];
   arr[0] = 1;
   arr[1] = 2;
   change(arr, 5);
   cout << arr[0] << " " << arr[1] << endl;
   return 0;
}

#include <iostream>

using namespace std;

int helper(int n, int arr[], int d)
{
    if (d == 0) return 1;
    
    int count = 0;
    for (int i = 0; i * arr[d] <= n; i++)
    {
        count += helper(n - i * arr[d], arr, d-1);
    }
    return count;
}

int coins(int n)
{
    int arr[4] = {1, 5, 10, 25};
    return helper(n, arr, 3);
}

int main()
{
   int n;
   cin >> n;
   cout << coins(n) << endl;
   return 0;
}








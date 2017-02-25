#include <iostream>
#include <cstring>

using namespace std;

int getNumPrimes(int n)
{ 
    int count = 0;
    bool arr[n+1];
    memset(arr, true, sizeof(bool) * (n+1));
    
    for (int i = 2; i <= n; i++)
    {
        if (arr[i]) 
        {
           count++; 
           for (int j = 2; j * i <= n; j++) arr[j * i] = false;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << getNumPrimes(n) << endl;
    return 0;
}
     
                 

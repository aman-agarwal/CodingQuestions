#include <iostream>
#include <cmath>

using namespace std;

void printAllSubsets(int arr[], int n)
{
    for (int i = 1; i < pow(2, n); i++)
    {
        int m = i;
        int j = 0;
        while (m)
        {
            if (m % 2) cout << arr[j] << " ";
            j++;
            m = m >> 1;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
     
    printAllSubsets(arr, n);
    return 0;
}           
  

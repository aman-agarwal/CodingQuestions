#include <iostream>
#include <algorithm>

using namespace std;

void SUM3(int arr[], int K, int N)
{
    sort(arr, arr + N);
    for (int i = 0; i < N-2; i++)
    {
        int l = i+1;
        int h = N-1;
        while (l < h)
        {
            int S = arr[i] + arr[l] + arr[h];
            if (S == K) 
            { 
                cout << i << " " << l << " " << h << endl;
                l++;
                h--;
            }    
            else if (S < K) 
            {
                l++;
            }
            else 
            {
                h--;
            }
        }
    }
}

int main()
{
    int arr[4] = {1, 3, 2, 0};
    sort(arr, arr + 4);
    for (int i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << endl;
 
    return 0;
}
             

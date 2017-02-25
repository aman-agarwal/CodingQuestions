#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

int rotateMin(int arr[], int n)
{
    int l = 0, h = n - 1;
    int mid;
    while (l < h)
    { 
        mid = (l + h)/2;
        if (mid > 0 && arr[mid] < arr[mid - 1]) 
        {  
            return arr[mid];
        }
        else if (arr[mid] > arr[h])
        {
            l = mid + 1;
        }
        else if (arr[mid] < arr[h])
        {
            h = mid - 1;
        }
        else if (arr[l] < arr[mid])
        {
            return arr[l];
        }
        else if (arr[l] > arr[mid])
        {
            h = mid - 1;
        }
        else 
        {
            l++;
        }
    }
    return arr[l];
} 

int main(int argc, char ** argv)
{
    assert(argc > 1);
    int arr[argc-1];
    for(int i = 0; i < argc - 1; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }    
    cout << rotateMin(arr, argc - 1) << endl;
    return 0;
}

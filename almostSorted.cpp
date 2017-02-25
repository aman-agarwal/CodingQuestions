#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int compare(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}

void almostSort(int * arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pqueue (arr, arr + k + 1);

    for (int i = 0; i < n - k - 1; i++)
    {
        arr[i] = pqueue.top();
        pqueue.pop();
        pqueue.push(arr[i + k + 1]);
    }
    for (int i = n - k - 1; i < n; i++)
    {
        arr[i] = pqueue.top();
        pqueue.pop();
    }
} 

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Wrong input\n");
        return 0;
    }
    
    int k = atoi(argv[1]);
    int n = argc - 2;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
 
    if (n >= k + 1) 
       almostSort(arr, n, k);
    else
       qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}    



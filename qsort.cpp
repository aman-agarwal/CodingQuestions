#include <cstdio>
#include <cstdlib>

/* Similarly, bsearch can also be used. */

int compare(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char **argv)
{
    int arr[] = {5, 1, 3, -1, 10, 9};
    
    qsort(arr, 6, sizeof(int), compare);
    
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    

    return 0;
}
     

#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv)
{
    int a = 10, b = 20;
    swap(a, b);
    printf("%d %d\n", a, b);

    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    swap(arr1, arr2);
    printf("%d\n", arr1[0]);

    swap(arr1[0], arr1[1]);
    printf("%d\n", arr1[0]);
    
    return 0;
}

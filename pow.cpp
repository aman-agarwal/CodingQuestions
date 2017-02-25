#include <iostream>
using namespace std;

int pow(int p, int q)
{
    int prod = 1, m = p;
    while (q)
    {
        if (q % 2) prod *= m;
        m = m * m;
        q = q/2;
    }
    return prod;
}
    
int main()
{ 
    int p, q;
    cin >> p >> q;
    cout << pow(p, q) << endl;
    return 0;
}
 

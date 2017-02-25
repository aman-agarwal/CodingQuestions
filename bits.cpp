#include <iostream>
#include <cassert>
using namespace std;

void f(unsigned int & N, unsigned int M, char i, char j)
{
    assert (j >= i);
    unsigned int mask = ((1 << (j-i+2)) - 1) << i;
    N = (N | mask) & (M << i);
}

void swap(unsigned int & a)
{
    a = ((a & 0xAAAAAAAA) >> 1) | ((a & 0x55555555) << 1);
}



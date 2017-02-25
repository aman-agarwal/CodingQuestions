#include <iostream>
using namespace std;

class Singleton
{
    Singleton() {};
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    public:

    int val;
    static Singleton& getInstance()
    {

        static Singleton instance;
        return instance;
    }
};


int main()
{
   
   Singleton& S = Singleton::getInstance();
   Singleton& T = Singleton::getInstance();
   S.val = 1; 
   cout << T.val << endl;
   
   return 0;
}
   

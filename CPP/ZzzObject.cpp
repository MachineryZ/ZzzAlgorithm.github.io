#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "Default construct function" << endl;
    };
    A(const A &a)
    {
        cout << "Copy construct called" << endl;
    }
};

void Func(A &a)
{
    
    return;
}

int main()
{
    A a;
    Func(a);
    return 0;
}
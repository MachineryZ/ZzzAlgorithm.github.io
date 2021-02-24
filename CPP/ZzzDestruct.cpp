# include <iostream>
using namespace std;

class Demo
{
    int id;
public:
    Demo(int i)
    {
        id = i;
        cout << "id = " << id << "constructed" << endl;
    }
    ~Demo()
    {
        cout << "id = " << id << "constructed" << endl;
    }
};

Demo d1(1);

void Func()
{
    static Demo d2(2);
    Demo d3(3);
    cout << "func" << endl;
}

int main()
{
    Demo d4(4);
    d4 = 6;
    cout << "main" << endl;
    {
        Demo d5(5);
    }
    Func();
    cout << "main ends" << endl;
    return 0;
}

// id = 1constructed
// id = 4constructed
// id = 6constructed
// id = 6constructed
// main
// id = 5constructed
// id = 5constructed
// id = 2constructed
// id = 3constructed
// func
// id = 3constructed
// main ends
// id = 6constructed
// id = 2constructed
// id = 1constructed






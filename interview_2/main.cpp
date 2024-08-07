#include <iostream>
#include <string>



using namespace std;
#define FIRST_BIT 0x01u

void some_func1(const string& str){
    for(size_t i = 0; i<str.size(); i++)
    {
        if(!(i&FIRST_BIT))
            cout << str[i];
    }
}

class Base
{
public:
    int value;
    Base(){}
};

class Derived : public Base
{
public:
    int value2;
    Derived(){}
};

int main()
{
    Base b1;
    Derived d1;
    b1 = d1;

    Base *b2;
    Derived *d1;
    
    b2 = &b1;


    some_func1("Wojciech Konior");
    return 0;
}
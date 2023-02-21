#include<iostream>
using namespace std;

class B;

class A
{
    int a;
    public:
    A(int num)
    {
        a=num;
    }
    friend int add(A,B);
};

class B
{
    int b;
    public:
    B(int num)
    {
        b=num;
    }
    friend int add(A,B);
};

int add(A v1, B v2)
{
    return v1.a+v2.b;
}

int main()
{
    int x;
    int a,b;
    cout << "Enter a number : ";
    cin >> a;
    cout << "Enter a number : ";
    cin >> b;
    A v1(a);
    B v2(b);
    x=add(v1,v2);
    cout << "Sum = " << x << endl;
    return 0;
}
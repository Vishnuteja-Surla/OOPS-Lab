#include<iostream>
using namespace std;

class test
{
    private:
        int x;
    public:
        test(int x)
        {
            this->x=x;              //Here this pointer makes the first x referenced to class and second one as argument
            //But x=x is invalid
        }
        void print()
        {
            cout << "x = " << x << endl;
            cout << "Address of this = " << this << endl;
        }
};

int main()
{
    test t1(12);
    test t2(10);
    t1.print();
    t2.print();
    cout << "Address of t1 = " << &t1 << endl;
    cout << "Address of t2 = " << &t2 << endl;
    return 0;
}
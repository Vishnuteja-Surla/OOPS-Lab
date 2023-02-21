#include<iostream>

using namespace std;

class myclass
{
    private:
        int data;
    public:
    //These are member functions defined outside
        void set_value(int value);
        void put_value();
    //A non-member function can access data using friend function
        friend void print(myclass);
};

void myclass :: set_value(int value)
{
    data = value;
}

void myclass :: put_value()
{
    cout << "Put Value : " << data << endl;
}

void print(myclass m)
{
    cout << "Print : "<< m.data << endl;
}

int main()
{
    int value;
    cout << "Enter data : ";
    cin >> value;
    myclass m;
    m.set_value(value);
    m.put_value();
    print(m);
    return 0;
}
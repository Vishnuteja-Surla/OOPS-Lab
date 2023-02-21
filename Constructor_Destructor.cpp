#include<iostream>

using namespace std;

class cars
{
    private:
        string company;
        string model;
        string fuel;
        double mileage;
        double price;
    public:
    //This is a special member function called as a constructor - The function with same name as class - Used to initialise variables
        //Default Constructor
        cars()
        {
            cout << "Default Constructor:-" << endl;
            company = "Tata";
            model = "Nexon";
            fuel = "Petrol";
            mileage = 18.6;
            price = 15;
        }
        //Parameterised Constructor
        cars(string c_name, string m_name, string f_name, double mil, double pri)
        {
            cout << "Parameterised Constructor :-" << endl;
            company = c_name;
            model = m_name;
            fuel = f_name;
            mileage = mil;
            price = pri;            
        }
        //Copy Costructor
        cars(cars &c)
        {
            cout << "Copy Constructor:-" << endl;
            company = c.company;
            model = c.model;
            fuel = c.fuel;
            mileage = c.mileage;
            price = c.price;
        }

        void display()
        {
            cout << "Company Name : " << company << endl;
            cout << "Model Name : " << model << endl;
            cout << "Fuel Type : " << fuel << endl;
            cout << "Mileage : " << mileage << endl;
            cout << "Price : " << price << " Lakhs" << endl;
        }

    //This is a special member function called as a destructor - The function with same name as class and a ~ - Used to destroy variables
        ~cars()
        {
            cout << "Destroyed an Object :( " << endl;
        }
};

int main()
{
    cars c1;                                                  //Default Constructor is called
    c1.display();
    cars c2("Hyundai","I10","Petrol",20.6,10.6);              //Parameterised Constructor is called
    c2.display();
    cars c3 = c2;                                             //Copy Constructor is called
    c3.display();
    cars c4(c1);                                              //Copy Constructor is called
    c4.display();
    return 0;
}
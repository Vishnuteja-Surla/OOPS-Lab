/*

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class account
{
    protected:
        double balance;
        string name;
        int acno;
    public:
        account(string name, int acno)
        {
            this->name=name;
            this->acno=acno;
            this->balance=0.0;
        }
        int get_accountnumber()
        {
            return acno;
        }
        
};

class savings : public account
{
    protected:
        double interest;
        double interest_percentage=4.0;
    public:
        savings(string name, int acno) : account(name,acno)
        {}
        void set_interest_percentage(double interest_percentage)
        {
            this->interest_percentage=interest_percentage;
        }
        void calculate_interest()
        {
            cout << "Interest : " << this->interest << endl;
        }
        void credit(double amount)
        {
            this->balance=this->balance+amount;
            this->interest=this->balance*this->interest_percentage/100.0;
            this->balance=this->balance+this->interest;
        }
        void debit(double amount)
        {
            if(this->balance>amount)
            {
                this->balance=this->balance-amount;
                this->interest=this->balance*this->interest_percentage/100.0;
                this->balance=this->balance+this->interest;
            }
            else
            {
                cout << "<--- INSUFFICIENT BALANCE --->" << endl;
            }
        }
        void show()
        {
            cout << "Account Holder : " << this->name << endl;
            cout << "Account Number : " << this->acno << endl;
            cout << "Type of Account : Savings Account" << endl;
            cout << "Balance : " << this->balance << endl;
        }
};

class checking : public account
{
    protected:
        double fee=0.0;
        double fee_amount=1.50;
    public:
        checking(string name, int acno) : account(name,acno)
        {}
        void set_fee_price(double fee_amount)
        {
            this->fee_amount = fee_amount;
        }
        void credit(double amount)
        {
            this->balance=this->balance+amount;
            this->fee=this->fee+this->fee_amount;
        }
        void debit(double amount)
        {
            if(this->balance>amount)
            {
                this->balance=this->balance-amount;
                this->fee=this->fee+this->fee_amount;
            }
            else
            {
                cout << "<--- INSUFFICIENT BALANCE --->" << endl;
            }
        }
        void show()
        {
            cout << "Account Holder : " << this->name << endl;
            cout << "Account Number : " << this->acno << endl;
            cout << "Type of Account : Checking Account" << endl;
            cout << "Balance : " << this->balance << endl;
        }
};

int main()
{
    vector<savings> sav;
    vector<checking> che;
    int ch,choice;
    int acc_no;
    double interest_rate;
    int i=0;
    cout << "--- WELCOME TO SABERTOOTH BANK ---" << endl;
    cout << "What do you wish to do?" << endl;
    cout << "1.Open a new Account  2.Credit Money  3.Debit Money" << endl;
    cout << "For Savings Account Users only: 4.Update Interest Rate  5.Calculate Interest  6.Add Interest to your balance" << endl;
    cout << "For Checking Account Users only: 7.Update Fee amount  8.Print Checking Fee  9.Transact and update" << endl;
    cout << "10.Exit" << endl;
    while(1)
    {
        cout << "****************" << endl;
        cout << "Your choice : ";
        cin >> ch;
        if(ch==1)
        {
            cout << "1.Savings Account  2.Checking Account" << endl;
            cin >> choice;
            if(choice==1)
            {
                string name;
                int acno;
                cout << "Enter your Name : ";
                cin >> name;
                cout << "Enter your Account Number : ";
                cin >> acno;
                savings s1(name,acno);
                sav.push_back(s1);
            }
            else if(choice==2)
            {
                string name;
                int acno;
                cout << "Enter your Name : ";
                cin >> name;
                cout << "Enter your Account Number : ";
                cin >> acno;
                checking c1(name,acno);
                che.push_back(c1);
            }
            else
            {
                cout << "<--- INVALID INPUT --->" << endl;
            }
        }
        else if(ch==2)
        {
            double amount;
            cout << "1.Savings Account  2.Checking Account" << endl;
            cin >> choice;
            cout << "Enter your account number : ";
            cin >> acc_no;
            if(choice==1)
            {
                for(i=0; i<sav.size(); i++)
                {
                    if(sav[i].get_accountnumber()==acc_no)
                    {
                        break;
                    }
                }
                if(i==sav.size())
                {
                    cout << "<--- ACCOUNT NOT FOUND --->" << endl;
                }
                else
                {
                    cout << "Enter amount to credit : ";
                    cin >> amount;
                    sav[i].credit(amount);
                }
            }
            else if(choice==2)
            {
                for(i=0; i<che.size(); i++)
                {
                    if(che[i].get_accountnumber()==acc_no)
                    {
                        break;
                    }
                }
                if(i==che.size())
                {
                    cout << "<--- ACCOUNT NOT FOUND --->" << endl;
                }
                else
                {
                    cout << "Enter amount to credit : ";
                    cin >> amount;
                    che[i].credit(amount);
                }
            }
            else
            {
                cout << "<--- INVALID INPUT --->" << endl;
            }
        }
        else if(ch==3)
        {
            double amount;
            cout << "1.Savings Account  2.Checking Account" << endl;
            cin >> choice;
            cout << "Enter your account number : ";
            cin >> acc_no;
            if(choice==1)
            {
                for(i=0; i<sav.size(); i++)
                {
                    if(sav[i].get_accountnumber()==acc_no)
                    {
                        break;
                    }
                }
                if(i==sav.size())
                {
                    cout << "<--- ACCOUNT NOT FOUND --->" << endl;
                }
                else
                {
                    cout << "Enter amount to debit : ";
                    cin >> amount;
                    sav[i].debit(amount);
                }
            }
            else if(choice==2)
            {
                for(i=0; i<che.size(); i++)
                {
                    if(che[i].get_accountnumber()==acc_no)
                    {
                        break;
                    }
                }
                if(i==che.size())
                {
                    cout << "<--- ACCOUNT NOT FOUND --->" << endl;
                }
                else
                {
                    cout << "Enter amount to debit : ";
                    cin >> amount;
                    che[i].debit(amount);
                }
            }
            else
            {
                cout << "<--- INVALID INPUT --->" << endl;
            }
        }
        else if(ch==4)
        {
            cout << "Enter your account number : ";
            cin >> acc_no;
            for(i=0; i<sav.size(); i++)
            {
                if(sav[i].get_accountnumber()==acc_no)
                {
                    break;
                }
            }
            if(i==sav.size())
            {
                cout << "<--- ACCOUNT NOT FOUND --->" << endl;
            }
            else
            {
                cout << "Enter new interest rate : ";
                cin >> interest_rate;
                sav[i].set_interest_percentage(interest_rate);
            }
        }
        else if(ch==5)
        {
            cout << "Enter your account number : ";
            cin >> acc_no;
            for(i=0; i<sav.size(); i++)
            {
                if(sav[i].get_accountnumber()==acc_no)
                {
                    break;
                }
            }
            if(i==sav.size())
            {
                cout << "<--- ACCOUNT NOT FOUND --->" << endl;
            }
            else
            {
                sav[i].calculate_interest();
            }
        }
        else if(ch==7)
        {
            double fee_price;
            cout << "Enter your account number : ";
            cin >> acc_no;
            for(i=0; i<che.size(); i++)
            {
                if(che[i].get_accountnumber()==acc_no)
                {
                    break;
                }
            }
            if(i==che.size())
            {
                cout << "<--- ACCOUNT NOT FOUND --->" << endl;
            }
            else
            {
                cout << "Enter new fee : ";
                cin >> fee_price;
                che[i].set_fee_price(fee_price);
            }
        }
        else if(ch==10)
        {
            break;
        }
    }
    cout << "--- THANKS AND VISIT AGAIN ---" << endl;
    return 0;
}
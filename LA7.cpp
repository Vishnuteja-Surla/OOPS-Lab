#include<iostream>
#include<string>
#include<vector>
using namespace std;

class account
{
    protected:
        double balance;
        int id;
        int acno;
    public:
        account(int id, int acno)
        {
            this->id=id;
            this->acno=acno;
            this->balance=0.0;
        }
        int get_id()
        {
            return id;
        }
        void get_balance()
        {
            cout << "Account Id : " << this->id << endl;
            cout << "Balance : " << this->balance << endl;
        }
        virtual void credit(double amount)
        {
            this->balance=this->balance+amount;
        }
        virtual void debit(double amount)
        {
            if(this->balance>amount)
            {
                this->balance=this->balance-amount;
            }
            else
            {
                cout << "<--- INSUFFICIENT BALANCE --->" << endl;
            }
        }
};

class savings : public account
{
    protected:
        double interest;
        double interest_percentage=2.70;
    public:
        savings(int id, int acno) : account(id,acno)
        {}
        void interest_credit()
        {
            this->interest=(this->balance*this->interest_percentage*30.0)/(365);
            this->balance=this->balance+this->interest;
            this->interest=0.0;
        }
        void show()
        {
            cout << "Account Holder Id : " << this->id << endl;
            cout << "Account Number : " << this->acno << endl;
            cout << "Type of Account : Savings Account" << endl;
            cout << "Balance : " << this->balance << endl;
        }
        void update_interest_percentage()
        {
            cout << "Current Interest Rate : " << this->interest_percentage << "%" << endl;
            double new_interest_percent;
            cout << "Enter new Interest Rate : ";
            cin >> new_interest_percent;
            this->interest_percentage = new_interest_percent;
        }
        double calculate_interest()
        {
            this->interest=(this->balance*this->interest_percentage*30.0)/(365);
            return this->interest;
        }
};

class checking : public account
{
    protected:
        double fee_amount=500;
    public:
        checking(int id, int acno) : account(id,acno)
        {}
        void credit(double amount)
        {
            if(this->balance+amount>=this->fee_amount)
            {
                this->balance=this->balance+amount-this->fee_amount;
            }
            else
            {
                cout << "<--- TRANSACTION FAILED DUE TO INSUFFICIENT FUNDS FOR PROCESSING FEE --->" << endl;
            }
        }
        void debit(double amount)
        {
            if(this->balance>amount+this->fee_amount)
            {
                this->balance=this->balance-amount-this->fee_amount;
            }
            else
            {
                cout << "<--- INSUFFICIENT BALANCE --->" << endl;
            }
        }
        void show()
        {
            cout << "Account Holder Id : " << this->id << endl;
            cout << "Account Number : " << this->acno << endl;
            cout << "Type of Account : Checking Account" << endl;
            cout << "Balance : " << this->balance << endl;
        }
        void update_fees()
        {
            cout << "Current Transaction Fees : " << this->fee_amount << "/-" << endl;
            double new_fee;
            cout << "Enter new Transaction Fee : ";
            cin >> new_fee;
            this->fee_amount = new_fee;
        }
        void print_fees()
        {
            cout << "Your current fee per transaction : " << this->fee_amount << endl;
        }
};


int main()
{
    vector<savings> sav;
    vector<checking> che;
    int ch,choice;
    int id_no;
    int i=0,j=0;
    cout << "--- WELCOME TO SABERTOOTH BANK ---" << endl;
    cout << "What do you wish to do?" << endl;
    cout << "1.Open a new Account  2.Credit Money  3.Debit Money" << endl;
    cout << "For Savings Account Users only: 4.Update Interest Rate  5.Calculate Interest  6.Calculate and Update Interest" << endl;
    cout << "For Checking Account Users only: 7.Update Fee amount  8.Print Checking Fee  9.Search Customer" << endl;
    cout << "10.Exit" << endl;
    while(1)
    {
        cout << "****************" << endl;
        cout << "Your choice : ";
        cin >> ch;
        if(ch==1)
        {
            cout << "1.Savings Account  2.Checking Account : " ;
            cin >> choice;
            if(choice==1)
            {
                int id;
                int acno;
                cout << "Enter your id : ";
                cin >> id;
                cout << "Enter your Account Number : ";
                cin >> acno;
                savings s1(id,acno);
                sav.push_back(s1);
            }
            else if(choice==2)
            {
                int id;
                int acno;
                cout << "Enter your id : ";
                cin >> id;
                cout << "Enter your Account Number : ";
                cin >> acno;
                checking c1(id,acno);
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
            cout << "1.Savings Account  2.Checking Account : " ;
            cin >> choice;
            cout << "Enter your id : ";
            cin >> id_no;
            if(choice==1)
            {
                for(i=0; i<sav.size(); i++)
                {
                    if(sav[i].get_id()==id_no)
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
                    sav[i].get_balance();
                }
            }
            else if(choice==2)
            {
                for(i=0; i<che.size(); i++)
                {
                    if(che[i].get_id()==id_no)
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
                    che[i].get_balance();
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
            cout << "1.Savings Account  2.Checking Account : ";
            cin >> choice;
            cout << "Enter your id : ";
            cin >> id_no;
            if(choice==1)
            {
                for(i=0; i<sav.size(); i++)
                {
                    if(sav[i].get_id()==id_no)
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
                    sav[i].get_balance();
                }
            }
            else if(choice==2)
            {
                for(i=0; i<che.size(); i++)
                {
                    if(che[i].get_id()==id_no)
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
                    che[i].get_balance();
                }
            }
            else
            {
                cout << "<--- INVALID INPUT --->" << endl;
            }
        }
        else if(ch==4)
        {
            cout << "Enter your id : ";
            cin >> id_no;
            for(i=0; i<sav.size(); i++)
            {
                if(sav[i].get_id()==id_no)
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
                sav[i].update_interest_percentage();
            }
        }
        else if(ch==5)
        {
            double interest_amount;
            cout << "Enter your id : ";
            cin >> id_no;
            for(i=0; i<sav.size(); i++)
            {
                if(sav[i].get_id()==id_no)
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
                interest_amount=sav[i].calculate_interest();
                cout << "Your Monthly Interest for this month : " << interest_amount << endl;
            }
        }
        else if(ch==6)
        {
            cout << "Enter your id : ";
            cin >> id_no;
            for(i=0; i<sav.size(); i++)
            {
                if(sav[i].get_id()==id_no)
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
                cout << "Your Account Deatils:-" << endl;
                sav[i].show();
                sav[i].interest_credit();
                cout << "Successfully Updated" << endl;
                cout << "Your Account Deatils:-" << endl;
                sav[i].show();
            }
        }
        else if(ch==7)
        {
            cout << "Enter your id : ";
            cin >> id_no;
            for(i=0; i<che.size(); i++)
            {
                if(che[i].get_id()==id_no)
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
                che[i].update_fees();
            }
        }
        else if(ch==8)
        {
            cout << "Enter your id : ";
            cin >> id_no;
            for(i=0; i<che.size(); i++)
            {
                if(che[i].get_id()==id_no)
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
                che[i].print_fees();
            }
        }
        else if(ch==9)
        {
            cout << "Enter your id : ";
            cin >> id_no;
            for(i=0; i<sav.size(); i++)
            {
                if(sav[i].get_id()==id_no)
                {
                    break;
                }
            }
            for(j=0; j<che.size(); j++)
            {
                if(che[j].get_id()==id_no)
                {
                    break;
                }
            }
            if(i==sav.size() && j==che.size())
            {
                cout << "<--- ACCOUNT NOT FOUND --->" << endl;
            }
            else
            {
                if(i<sav.size()&&j==che.size())
                    sav[i].show();
                else if(j<che.size()&&i==sav.size())
                    che[j].show();
                else
                {
                    sav[i].show();
                    che[j].show();
                }
            }
        }
        else if(ch==10)
        {
            break;
        }
        else
        {
            cout << "<--- INVALID INPUT --->" << endl;
        }
    }
    cout << "--- THANKS AND VISIT AGAIN ---" << endl;
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

int prec(char a)
{
    if(a=='/' || a=='*')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return -1;
}

queue<char> pop(queue<char> q1)
{
    queue<char> q2;
    while(q1.front() !=q1.back())
    {
        q2.push(q1.front());
        q1.pop();
    }
    return q2;
}
void infix_to_postfix(string s)
{
    queue<char> q;
    string result = "";
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            result+=c;
        }
        else
        {
            while(q.size()!=0 && prec(s[i]) <= prec(q.back()))
            {
                result += q.back();
                q = pop(q);
            }
            q.push(c);
        }
    }
    while(q.size()!=0)
    {
        result += q.back();
        q = pop(q);
    }
    cout<<"Postfix expression : " << result << endl;
}

int check_char(char a)
{
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || a=='+' || a=='-' || a=='/' || a=='*')
        return 1;
    else 
        return -1;
}

void check_exp(string s)
{
    if(s[0]=='+' || s[0]=='-' || s[0]=='/' || s[0]=='*')
        throw 0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(check_char(s[i])!=1)
            throw i;
        else if(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && ((s[i+1]>='a' && s[i+1]<='z') || (s[i+1]>='A' && s[i+1]<='Z')))
            throw i;
        else if(prec(s[i])!=-1 && prec(s[i+1])!=-1)
            throw i;
    }
    if(check_char(s[s.length()-1])!=1)
        throw (int)s.length()-1;
    else if(prec(s[s.length()-1])!=-1)
        throw (int)s.length()-1;
}

int main()
{
    cout << "1. Get Infix Expression" << endl;
    cout << "2. Print Infix Expression" << endl;
    cout << "3. Print Postfix Expression" << endl;
    cout << "4. Exit" << endl;
    cout << "****************************************" << endl;
    string infix = "";
    int ch;
    while(1)
    {
        cout << "Choose a number to perform an operation : ";
        cin >> ch;
        if(ch==1)
        {
            cout << "Enter the expression in infix form : ";
            cin >> infix;
            try
            {
                check_exp(infix);
            }
            catch(...)
            {
                cout << "Faulty Infix Expression" << endl;
            }
        }
        else if(ch==2)
        {
            cout << "Infix expression : " << infix << endl;
        }
        else if(ch==3)
        {
            infix_to_postfix(infix);
        }
        else if(ch==4)
        {
            break;
        }
        else
            cout<<"<-- INVALID COMMAND -->"<<endl;
        cout << "****************************************" << endl;
    }
    cout << "****************************************" << endl;
    return 0;
}
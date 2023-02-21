#include<iostream>
#include<string>
using namespace std;

struct node
{
    char c;
    struct node *next;
};

class queue
{
    public:
        node *front;
        node *rear;
        
        queue()
        {
            front = NULL;
            rear = NULL;
        }
        void enqueue(char character)
        {
            node *temp = new node;
            temp->c = character;
            temp->next = NULL;
            if(rear==NULL)
            {
                front = temp;
                rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
        }
        char dequeue()
        {
            char flag;
            if(front == NULL)
            {
                throw "Queue Empty Error!";
            }
            node *temp;
            temp = front;
            front = front->next;
            flag = temp->c;
            delete temp;
            if(front == NULL)
            {
                rear = NULL;
            }
            return flag;
        }
};

class stack
{
    public:
        node *top;
        queue qm,qt;
    
        stack()
        {
            top = NULL;
        }
        void push(char character)
        {
            qm.enqueue(character);
            top = qm.rear;
        }
        char pop()
        {
            char dummy,flag;
            while(qm.front->next != NULL)
            {
                try{
                    dummy = qm.dequeue();
                }catch(const char *msg){
                    cerr << msg << endl;
                }
                qt.enqueue(dummy);
            }
            try{
                flag = qm.dequeue();
            }catch(const char *msg){
                cerr << msg << endl;
            }
            queue q;
            q = qt;
            qt = qm;
            qm = q;
            top = qm.rear;
            return flag;
        }
        bool isempty()
        {
            if(qm.front == NULL)
            return true;
            else
            return false;
        }
};

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void check_infix(string s)
{
    int e;
    int brackets_count=0;
    for (int i = 0; i < s.length()-1; i++) 
    {
        if(prec(s[i])!=-1 && prec(s[i+1])!=-1)
            throw e;
        else if(((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) && ((s[i+1]>='a'&&s[i+1]<='z')||(s[i+1]>='A'&&s[i+1]<='Z')))
            throw e;
    }
}

 

void infix_to_postfix(string s)
{
 
    stack st;
    string result;
 
    for (int i = 0; i < s.length(); i++) 
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') 
        {
            while (st.top->c != '(') 
            {
                result += st.top->c;
                st.pop();
            }
            st.pop();
        }
        else 
        {
            while (!st.isempty() && prec(s[i]) <= prec(st.top->c)) 
            {
                result += st.top->c;
                st.pop();
            }
            st.push(c);
        }
    }
    
    while (!st.isempty()) 
    {
        result += st.top->c;
        st.pop();
    }
 
    cout << "Postfix Expression : " << result << endl;
}

int main()
{
    
    cout << "1. Get Infix Expression" << endl;
    cout << "2. Print Infix Expression" << endl;
    cout << "3. Print Postfix Expression" << endl;
    cout << "4. Exit" << endl;
    cout << "****************************************" << endl;
    int ch;
    string infix;
    while(1)
    {
        cout << "Choose a number to perform an operation : ";
        cin >> ch;
        if(ch==1)
        {
            cout << "Enter the expression in infix form : ";
            cin >> infix;
        }
        else if(ch==2)
        {
            cout << "Infix Expression : " << infix << endl;
        }
        else if(ch==3)
        {
            try
            {
                check_infix(infix);
                infix_to_postfix(infix);
            }
            catch(...)
            {
                cout << "Faulty Infix Expression" << endl;
            }
            
        }
        else if(ch==4)
        {
            break;
        }
        else
        {
            cout << "<--- INVALID INPUT --->" << endl;
        }
        cout << "****************************************" << endl;
    }
    cout << "****************************************" << endl;
    return 0;
}
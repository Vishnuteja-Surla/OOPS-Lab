#include<iostream>
using namespace std;

class node
{
    int data;
    node *next;
    public:
        node()
        {
            this->data=0;
            this->next=NULL;
        }
        node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
        friend class CLinkedlist;
};

class CLinkedlist
{
    node *head;
    public:
        CLinkedlist()
        {
            head=NULL;
        }
        void insert(int value)
        {
            if(head==NULL)
            {
                head=new node;
                head->data=value;
                head->next=head;
            }
            else
            {
                node *newnode=new node;
                newnode->data=value;
                newnode->next=NULL;
                node *temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->next=head;
            }
        }
        void insert(int value, int position)
        {
            int size=0;
            int ch;
            int pos=1;
            if(head==NULL)
            {
                if(position==1)
                {
                    head=new node;
                    head->data=value;
                    head->next=head;
                    return ;
                }
                else
                {
                    cout << "List Empty and only insertion at Position 1 is possible. Do you wish to insert?" <<endl;
                    cout << "1.Yes  2.No" << endl;
                    cout << "Input : " << endl;
                    cin >> ch;
                    if(ch==1)
                    {
                        head=new node;
                        head->data=value;
                        head->next=head;
                        return ;
                    }
                    else if(ch==2)
                    {
                        return ;
                    }
                    else
                    {
                        cout << "--- INVALID INPUT ---" << endl;
                        return ;
                    }
                }
            }
            if(head!=NULL)
            {
                node *temp=head;
                size++;
                while(temp->next!=head)
                {
                    size++;
                    temp=temp->next;
                }
            }
            if(position > size+1)
            {
                cout << "Position out of the list, What do you wish to do?" << endl;
                cout << "1.Don't Insert  2.Insert at " << (position%(size+2))+1 << " th position?" << endl;
                cout << "Input : ";
                cin >> ch;
                if(ch==1)
                {
                    return ;
                }
                else if(ch==2)
                {
                    position=(position%(size+2))+1;
                    insert(value,position);
                }
                else
                {
                    cout << "--- INVALID INPUT ---" << endl;
                }
            }
            else
            {
                node *newnode=new node;
                newnode->data=value;
                newnode->next=NULL;
                node *temp=head;
                node *last=head->next;
                while(last->next!=head)
                {
                    last=last->next;
                }
                if(position==1)
                {
                    last->next=newnode;
                    newnode->next=head;
                    head=newnode;
                    return ;
                }
                while(pos<position-1)
                {
                    temp=temp->next;
                    pos++;
                }
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
        void delete_node()
        {
            if(head==NULL)
            {
                cout << "--- LIST EMPTY ---" << endl;
                return ;
            }
            else if(head->next==head)
            {
                head=NULL;
                return ;
            }
            else
            {
                node *temp=head;
                node *dummy;
                while(temp->next->next!=head)
                {
                    temp=temp->next;
                }
                dummy=temp->next;
                temp->next=head;
                delete dummy;
            }
        }
        void delete_node(int position)
        {
            if(head==NULL)
            {
                cout << "--- LIST EMPTY ---" << endl;
                return ;
            }
            int size=0;
            int ch;
            int pos=1;
            node *temp=head;
            size++;
            while(temp->next!=head)
            {
                size++;
                temp=temp->next;
            }
            if(position > size || position < 1)
            {
                position=position%size;
                if(position<1)
                {
                    position=position+size;
                }
                cout << "Position out of the list, What do you wish to do?" << endl;
                cout << "1.Don't Delete  2.Delete the " << position << " th position?" << endl;
                cout << "Input : ";
                cin >> ch;
                if(ch==1)
                {
                    return ;
                }
                else if(ch==2)
                {
                    delete_node(position);
                }
                else
                {
                    cout << "--- INVALID INPUT ---" << endl;
                }
            }
            else
            {
                node *last=head->next;
                while(last->next!=head)
                {
                    last=last->next;
                }
                if(last==head)
                {
                    head=NULL;
                }
                if(position==1)
                {
                    if(last==head)
                    {
                        head=NULL;
                        return ;
                    }
                    node *temp=head;
                    head=head->next;
                    last->next=head;
                    delete temp;
                }
                else
                {
                    node *temp=head;
                    while(pos<position-1)
                    {
                        pos++;
                        temp=temp->next;
                    }
                    node *dummy;
                    dummy=temp->next;
                    temp->next=temp->next->next;
                    delete dummy;
                }
            }
        }
        void search(int value)
        {
            if(head==NULL)
            {
                cout << "--- LIST EMPTY ---" << endl;
                return ;
            }
            int size=0;
            int ch;
            int pos=0;
            node *temp=head;
            if(head!=NULL)
            {
                size++;
                while(temp->next!=head)
                {
                    size++;
                    temp=temp->next;
                }
            }
            temp=head;
            while(pos<size)
            {
                pos++;
                if(temp->data==value)
                {
                    cout << "Value is found at position-" << pos << endl;
                    return ;
                }
                temp=temp->next;
            }
            cout << "Value not found in the list" << endl;
        }
        void display()
        {
            if(head==NULL)
            {
                cout << "--- LIST EMPTY ---" << endl;
                return ;
            }
            node *temp=head->next;
            cout << head->data << " ";
            while(temp!=head)
            {
                cout << temp->data << " ";
                temp=temp->next;
            }
            cout << "\n";
        }
};

int main()
{
    int choice,ch;
    int value,pos;
    CLinkedlist list1;
    while(1)
    {
        cout << "What action do you want to perform? :-" << endl;
        cout << "1.Insert  2.Delete  3.Search  4.Display  5.Exit" << endl;
        cout << "Input : ";
        cin >> choice;
        cout << "***************" << endl;
        if(choice==1)
        {
            cout << "Enter the value to be inserted : ";
            cin >> value;
            cout << "Where do you want to insert? :-" << endl;
            cout << "1.Beginning  2.End  3.At k th position" << endl;
            cout << "Input : ";
            cin >> ch;
            if(ch==1)
            {
                list1.insert(value,1);
            }
            else if(ch==2)
            {
                list1.insert(value);
            }
            else if(ch==3)
            {
                cout << "Enter the position at which you wish to insert : ";
                cin >> pos;
                list1.insert(value,pos);
            }
            else
            {
                cout << "--- INVALID INPUT ---" << endl;
            }
        }
        else if(choice==2)
        {
            cout << "Where do you want to delete? :-" << endl;
            cout << "1.Beginning  2.End  3.At k th position" << endl;
            cout << "Input : ";
            cin >> ch;
            if(ch==1)
            {
                list1.delete_node(1);
            }
            else if(ch==2)
            {
                list1.delete_node();
            }
            else if(ch==3)
            {
                cout << "Enter the position at which you wish to delete : ";
                cin >> pos;
                list1.delete_node(pos);
            }
            else
            {
                cout << "--- INVALID INPUT ---" << endl;
            }
        }
        else if(choice==3)
        {
            cout << "Enter the value to be searched for : ";
            cin >> value;
            list1.search(value);
        }
        else if(choice==4)
        {
            list1.display();
        }
        else if(choice==5)
        {
            break;
        }
        else
        {
            cout << "--- INVALID INPUT ---" << endl;
        }
    }
    return 0;
}
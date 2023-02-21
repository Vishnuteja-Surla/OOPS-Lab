#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;
        node *prev;
        node()
        {
            this->data=0;
            this->next=NULL;
            this->prev=NULL;
        }
        node(int data)
        {
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
        friend class DLinkedlist;
};

class DLinkedlist
{
    public:
        node *head;
        DLinkedlist()
        {
            head=NULL;
        }
        void insert_node(int value)
        {
            if(head==NULL)
            {
                head=new node;
                head->data=value;
                head->prev=NULL;
                head->next=NULL;
            }
            else
            {
                node *newnode;
                newnode = new node;
                newnode->data=value;
                newnode->next=NULL;
                newnode->prev=NULL;
                node *temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                node *last=temp;
                temp=head;
                while(temp->data<=value)
                {
                    temp=temp->next;
                    if(temp==NULL)
                    {
                        break;
                    }
                }
                if(temp==head)
                {
                    newnode->next=temp;
                    temp->prev=newnode;
                    head=newnode;
                }
                else if(temp==NULL)
                {
                    last->next=newnode;
                    newnode->prev=last;
                }
                else
                {
                    temp->prev->next=newnode;
                    newnode->next=temp;
                    newnode->prev=temp->prev;
                    temp->prev=newnode;
                }
            }
        }

        void *delete_node(int value)
        {
            node *temp=head;
            int size=0;
            while(temp!=NULL)
            {
                temp=temp->next;
                size++;
            }
            if(value>size)
            {
                cout << "Position out of list" << endl;
                return head;
            }
            temp=head;
            if(value==1)
            {
                head=head->next;
                head->prev=NULL;
                delete temp;
            }
            else
            {
                for(int i=1; i<value-1; i++)
                {
                    temp=temp->next;
                }
                if(value==size)
                {
                    node *flag=temp->next;
                    temp->next=NULL;
                    delete flag;
                }
                else
                {
                    node *flag;
                    flag=temp->next;
                    temp->next=flag->next;
                    flag->next->prev=temp;
                    delete flag;
                }
            }
        }

        void display()
        {
            node *temp;
            temp=head;
            if(temp==NULL)
            {
                cout << "List Empty" << endl;
                return ;
            }
            while(temp!=NULL)
            {
                cout << temp->data << " ";
                temp=temp->next;
            }
            cout << "\n";
        }

        void *basic_insert(int value)
        {
            if(head==NULL)
            {
                head=new node;
                head->data=value;
                head->prev=NULL;
                head->next=NULL;
            }
            else
            {
                node *newnode;
                newnode = new node;
                newnode->data=value;
                newnode->next=NULL;
                newnode->prev=NULL;
                node *temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
            }
        }

};


DLinkedlist merge(DLinkedlist *list1, DLinkedlist *list2)
{
    DLinkedlist list;
    node *temp1=list1->head;
    node *temp2=list2->head;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data<=temp2->data)
        {
            list.basic_insert(temp1->data);
            temp1=temp1->next;
        }
        else
        {
            list.basic_insert(temp2->data);
            temp2=temp2->next;
        }
    }
    if(temp1==NULL)
    {
        while(temp2!=NULL)
        {
            list.basic_insert(temp2->data);
            temp2=temp2->next;
        }
    }
    else
    {
        while(temp1!=NULL)
        {
            list.basic_insert(temp1->data);
            temp1=temp1->next;
        }
    }
    return list;
}

int main()
{
    DLinkedlist list1;
    DLinkedlist list2;
    DLinkedlist merged_head;
    int ch,choice;
    while(1)
    {
        cout << "Select a choice from below:-" << endl;
        cout << "1.Insert  2.Delete  3.Display  4.Merge  5.Exit" << endl;
        cout << "Input : ";
        cin >> ch;
        cout << "************" << endl;
        if(ch==1)
        {
            cout << "Select list 1 or 2 : ";
            cin >> choice;
            int value;
            cout << "Enter a value to be inserted : ";
            cin >> value;
            if(choice==1)
            {
                list1.insert_node(value);
            }
            else if(choice==2)
            {
                list2.insert_node(value);
            }
            else
            {
                cout << "*** Invalid Command ***" << endl;
            }
        }
        else if(ch==2)
        {
            cout << "Select list 1 or 2 : ";
            cin >> choice;
            int value;
            cout << "Enter a position of value to be deleted : ";
            cin >> value;
            if(choice==1)
            {
                list1.delete_node(value);
            }
            else if(choice==2)
            {
                list2.delete_node(value);
            }
            else
            {
                cout << "*** Invalid Command ***" << endl;
            }
        }
        else if(ch==3)
        {
            cout << "Select list 1 or 2 : ";
            cin >> choice;
            if(choice==1)
            {
                list1.display();
            }
            else if(choice==2)
            {
                list2.display();
            }
            else
            {
                cout << "*** Invalid Command ***" << endl;
            }
        }
        else if(ch==4)
        {
            merged_head=merge(&list1,&list2);
            merged_head.display();
        }
        else if(ch==5)
        {
            break;
        }
        else
        {
            cout << "*** Invalid Command ***" << endl;
        }
    }
    return 0;
}
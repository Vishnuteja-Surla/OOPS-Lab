#include<cstdio>
#include<cstdlib>

#define size 5

class stack
{
    int arr[size];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    bool is_full()
    {
        if(top==size-1)
        return true;
        else
        return false;
    }
    bool is_empty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
    void push(int num)
    {
        if(is_full())
        printf("**********Stack Overflow**********\n");
        else
        {
            top++;
            arr[top]=num;
        }
    }
    int pop()
    {
        int temp;
        if(is_empty())
        {
            printf("**********Stack Underflow**********\n");
            exit(0);
        }
        else
        {
            temp=top;
            top--;
            return(arr[temp]);
        }
    }
    void peek()
    {
        printf("Top most element : %d\n",arr[top]);
    }
    void display()
    {
        if(is_empty())
        printf("**********Stack Empty**********");
        else
        {
            for(int i=top; i>=0; i--)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
    }
    void r_display()
    {
        if(is_empty())
        printf("**********Stack Empty**********");
        else
        {
            for(int i=0; i<=top; i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }        
    }
    void palindrome()
    {
        int i,j;
        i=0; j=top;
        if(is_empty())
        printf("**********Stack Empty**********");
        else
        {
            while(i<top)
            {
                if(arr[i]==arr[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    break;
                }
            }
            if(i==top)
            printf("Yes, it is a palindrome\n");
            else
            printf("No, it is not a palindrome\n");
        }
    }
    void digit_in_text(int num)
    {
        if(num==1)
        printf("One ");
        else if(num==2)
        printf("Two ");
        else if(num==3)
        printf("Three ");
        else if(num==4)
        printf("Four ");
        else if(num==5)
        printf("Five ");
        else if(num==6)
        printf("Six ");
        else if(num==7)
        printf("Seven ");
        else if(num==8)
        printf("Eight ");
        else if(num==9)
        printf("Nine ");
        else
        printf("Zero ");
    }
    void num_to_text()
    {
        int i;
        for(i=top; i>=0; i--)
        {
            digit_in_text(arr[i]);
        }
        printf("\n");
    }
};
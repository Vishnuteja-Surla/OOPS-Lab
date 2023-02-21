/*
Write a C++ program to implement a stack ADT as a header file using class. Create a class for a stack with the following operations, push, pop, display, peek, isFull, and isEmpty functions. Define all the functions inside the stack class. The data members (variables declared inside the class) should use "Private" access specifiers and member functions (functions declared and defined within the scope of a class) should use "Public" access specifiers. Assume the stack stores integers and can store a maximum of  5 integers. Import the created stack header file into an "application.cpp" file. The application.cpp has the following menus,

1. Get Number
2. Digit in Text
3. Reverse
4. Palindrome Check
5. Exit

Note: Stack stores the digits of the number entered in option 1. Option 1 is mandatory before using options 2 to 4 (Boundary condition). If option 1 is selected multiple times, a new number is obtained from the user and the stack is reset with the digits of the last entered number.
Option 1 gets a number from the user. Extracts the digits and pushes the digits to a stack object.
Option 2 writes a number in text form (Eg: Input: 12345, Output: one two three four five.)
Option 3 reverses the given input number. (Eg: 123, Output: 321)
Option 4 checks if the given number is palindrome or not
Option 5 exits the program.

*/

#include<cstdio>
#include "stack.h"

int main()
{
    stack s1;
    int choice,num,rem,count=0,flag;
    while(1)
    {
        printf("Enter\n1.Get Number\n2.Digit in Text\n3.Reverse\n4.Palindrome Check\n5.Exit\n");
        printf("Choice : ");
        scanf("%d",&choice);
        if(choice==1)
        { 
            while(1)
            {
                if(s1.is_empty())
                {
                    break;
                }
                else
                {
                    flag=s1.pop();
                }

            }
            printf("Enter the number : ");
            scanf("%d",&num);
            while(num>0)
            {
                rem=num%10;
                s1.push(rem);
                num=num/10;
            }  
        }
        else if(choice==2)
        {
            s1.num_to_text();
        }
        else if(choice==3)
        {
            s1.r_display();
        }
        else if(choice==4)
        {
            s1.palindrome();
        }
        else if(choice==5)
        {
            break;
        }
        else
        {
            printf("Enter an input from 1 to 5\n");
        }
    }
    return 0;
}
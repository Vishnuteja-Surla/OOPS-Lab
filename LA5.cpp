#include<iostream>
#include<cmath>
using namespace std;

class coordinate
{
    int xnum;
    int ynum;
    public:
        coordinate()
        {
            this->xnum=0;
            this->ynum=0;
        }
        double sum_of_coordinates()
        {
            double temp;
            temp=this->xnum+this->ynum;
            return temp;
        }
        friend ostream & operator << (ostream &out, const coordinate &c);
        friend istream & operator >> (istream &in, coordinate &c);
        coordinate operator ! ()
        {
            if(xnum<0)
            {
                xnum=xnum*(-1);
            }
            if(ynum<0)
            {
                ynum=ynum*(-1);
            }
        }
        coordinate operator - (coordinate point2)
        {
            coordinate temp;
            temp.xnum=(this->xnum)-(point2.xnum);
            temp.ynum=(this->ynum)-(point2.ynum);
            return temp;
        }
        coordinate operator ^ (double num)
        {
            coordinate temp;
            temp.xnum=pow(this->xnum,num);
            temp.ynum=pow(this->ynum,num);
            return temp;
        }
};

ostream & operator << (ostream &out, const coordinate &c)
{
    out << "(" << c.xnum << "," << c.ynum << ")";
    return out;
}

istream & operator >> (istream &in, coordinate &c)
{
    cout << "Enter the X-Coordinate of point : ";
    in >> c.xnum;
    cout << "Enter the Y-Coordinate of point : ";
    in >> c.ynum;
    return in;
}

double dist(coordinate c1, coordinate c2)
{
    double temp; 
    coordinate c;
    c=c1-c2;
    c=c^2;
    temp=c.sum_of_coordinates();
    temp=sqrt(temp);
    return temp;
}

int main()
{
    int ch;
    coordinate c1,c2,c3;
    int choice;
    while(1)
    {
        cout << "Enter a command number from the following:-" << endl;
        cout << "1.Set Point   2.Display Point   3.Distance between two points   4.Check Right Angle   5.Exit" << endl;
        cout << "Choice : ";
        cin >> ch;
        cout << "********************" << endl;
        if(ch==1)
        {
            cout << "Which point do you want to set? 1.Point-1  2.Point-2  3.Point-3  : ";
            cin >> choice;
            if(choice==1)
            {
                cin >> c1;
                !c1;
            }
            else if(choice==2)
            {
                cin >> c2;
                !c2;
            }
            else if(choice==3)
            {
                cin >> c3;
                !c3;
            }
            else
            {
                cout << "**** INVALID COMMAND ****" << endl;
            }
        }
        else if(ch==2)
        {
            cout << "Which point do you want to display? 1.Point-1  2.Point-2  3.Point-3  : ";
            cin >> choice;
            if(choice==1)
            {
                cout << c1 << endl;
            }
            else if(choice==2)
            {
                cout << c2 << endl;
            }
            else if(choice==3)
            {
                cout << c3 << endl;
            }
            else
            {
                cout << "**** INVALID COMMAND ****" << endl;
            }
        }
        else if(ch==3)
        {
            int opt1,opt2;
            cout << "Select two points from 1,2, and 3 : ";
            cin >> opt1;
            cin >> opt2;
            if(opt1==1)
            {
                if(opt2==1)
                {
                    cout << "Distance between the points = " << dist(c1,c1) << endl;
                }
                else if(opt2==2)
                {
                    cout << "Distance between the points = " << dist(c1,c2) << endl;
                }
                else if(opt2==3)
                {
                    cout << "Distance between the points = " << dist(c1,c3) << endl;
                }
                else
                {
                    cout << "**** INVALID COMMAND ****" << endl;
                }
            }
            else if(opt1==2)
            {
                if(opt2==1)
                {
                    cout << "Distance between the points = " << dist(c2,c1) << endl;
                }
                else if(opt2==2)
                {
                    cout << "Distance between the points = " << dist(c2,c2) << endl;
                }
                else if(opt2==3)
                {
                    cout << "Distance between the points = " << dist(c2,c3) << endl;
                }
                else
                {
                    cout << "**** INVALID COMMAND ****" << endl;
                }
            }
            else if(opt1==3)
            {
                if(opt2==1)
                {
                    cout << "Distance between the points = " << dist(c3,c1) << endl;
                }
                else if(opt2==2)
                {
                    cout << "Distance between the points = " << dist(c3,c2) << endl;
                }
                else if(opt2==3)
                {
                    cout << "Distance between the points = " << dist(c3,c3) << endl;
                }
                else
                {
                    cout << "**** INVALID COMMAND ****" << endl;
                }
            }
            else
            {
                cout << "**** INVALID COMMAND ****" << endl;
            }
        }
        else if(ch==4)
        {
            cout << "**** Un-initialised points are by default considered origin ****" << endl;
            double l1,l2,l3;
            l1=dist(c1,c2);
            l2=dist(c2,c3);
            l3=dist(c3,c1);
            if(l1>l2 && l1>l3)
            {
                if(l1*l1==(l2*l2)+(l3*l3))
                {
                    cout << "Yes, it forms a right angled triangle" << endl;
                }
                else
                {
                    cout << "No, it dosen't form a right angled triangle" << endl;
                }
            }
            else if(l2>l1 && l2>l3)
            {
                if(l2*l2==(l1*l1)+(l3*l3))
                {
                    cout << "Yes, it forms a right angled triangle" << endl;
                }
                else
                {
                    cout << "No, it dosen't form a right angled triangle" << endl;
                }
            }
            else if(l3>l1 && l3>l2)
            {
                if(l3*l3==(l1*l1)+(l2*l2))
                {
                    cout << "Yes, it forms a right angled triangle" << endl;
                }
                else
                {
                    cout << "No, it dosen't form a right angled triangle" << endl;
                }
            }
            else
            {
                cout << "No, it dosen't form a right angled triangle" << endl;
            }
        }
        else if(ch==5)
        {
            break;
        }
        else
        {
            cout << "**** INVALID COMMAND ****" << endl;
        }
    }
    return 0;
}
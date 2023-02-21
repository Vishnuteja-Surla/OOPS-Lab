#include<iostream>
#include<cmath>
using namespace std;

class Volume;

class Area
{
    private:
        double side;
        double length;
        double breadth;
        double radius;
    public:
        Area()
        {
            this->side=1.0;
            this->length=1.0;
            this->breadth=1.0;
            this->radius=1.0;
        }
        void set_side(double side=1.0)
        {
            this->side=side;
        }
        void set_length(double length=1.0)
        {
            this->length=length;
        }
        void set_breadth(double breadth=1.0)
        {
            this->breadth=breadth;
        }
        void set_radius(double radius=1.0)
        {
            this->radius=radius;
        }
        inline double square()
        {
            return side*side;
        }
        inline double rectangle()
        {
            return length*breadth;
        }
        inline double circle()
        {
            return M_PI*radius*radius;
        }
        friend double cube(Area,Volume);
        friend double cuboid(Area,Volume);
        friend double sphere(Area,Volume);
};

class Volume
{
    private:
    double height;
    public:
        Volume()
        {
            height=1.0;
        }
        void set_height(double height)
        {
            this->height=height;
        }
        friend double cube(Area,Volume);
        friend double cuboid(Area,Volume);
        friend double sphere(Area,Volume);
};


inline double cube(Area a,Volume v)
{
    return(a.side*a.side*a.side);
}

inline double cuboid(Area a,Volume v)
{
    return(a.length*a.breadth*v.height);
}

inline double sphere(Area a,Volume v)
{
    return((4/3)*M_PI*a.radius*a.radius*a.radius);
}

inline void compare(double v1, double v2)
{
    if(v1>v2)
    {
        cout << "Maximum Volume = " << v1 << endl;
    }
    else
    {
        cout << "Maximum Volume = " << v2 << endl;
    }
}

int main()
{
    int choice,ch,flag;
    double area,volume;
    while(1)
    {
        cout << "*********************" << endl;
        cout << "Select a number from below:-\n1.Area of a Square  2.Area of a Rectangle  3.Area of a Circle\n4.Volume of a Cube  5.Volume of a Cuboid  6.Volume of a Sphere\n7.Compare Cubes  8.Compare Cuboids  9.Compare Spheres\n10.Exit" << endl;
        cout << "Input : ";
        cin >> choice;
        cout << "*********************" << endl;
        if(choice == 1)
        {
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                Area a;
                area=a.square();
                cout << "Area of Square = " << area << endl; 
            }
            else
            {
                Area a;
                double side;
                cout << "Enter side length : ";
                cin >> side;
                a.set_side(side);
                area=a.square();
                cout << "Area of Square = " << area << endl; 
            }
        }
        else if(choice == 2)
        {
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                Area a;
                area=a.rectangle();
                cout << "Area of Rectangle = " << area << endl; 
            }
            else
            {
                Area a;
                double length,breadth;
                cout << "Do you wish to enter length? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Length : ";
                    cin >> length;
                    a.set_length(length);
                }
                cout << "Do you wish to enter breadth? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Breadth : ";
                    cin >> breadth;
                    a.set_breadth(breadth);
                }
                area=a.rectangle();
                cout << "Area of Rectangle = " << area << endl;
            }
        }
        else if(choice == 3)
        {
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                Area a;
                area=a.circle();
                cout << "Area of Circle = " << area << endl; 
            }
            else
            {
                Area a;
                double radius;
                cout << "Enter Radius : ";
                cin >> radius;
                a.set_radius(radius);
                area=a.circle();
                cout << "Area of Square = " << area << endl; 
            }
        }
        else if(choice == 4)
        {
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                Area a;
                Volume v;
                volume=cube(a,v);
                cout << "Volume of Cube = " << volume << endl; 
            }
            else
            {
                Area a;
                Volume v;
                double side;
                cout << "Enter Side : ";
                cin >> side;
                a.set_side(side);
                volume=cube(a,v);
                cout << "Volume of Cube = " << volume << endl;
            }
        }
        else if(choice == 5)
        {
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                Area a;
                Volume v;
                volume=cuboid(a,v);
                cout << "Volume of Cuboid = " << volume << endl; 
            }
            else
            {
                Area a;
                Volume v;
                double length,breadth,height;
                cout << "Do you wish to enter length? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Length : ";
                    cin >> length;
                    a.set_length(length);
                }
                cout << "Do you wish to enter breadth? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Breadth : ";
                    cin >> breadth;
                    a.set_breadth(breadth);
                }
                cout << "Do you wish to enter height? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Height : ";
                    cin >> height;
                    v.set_height(height);
                }
                volume=cuboid(a,v);
                cout << "Volume of Cuboid = " << volume << endl;
            }
        }
        else if(choice == 6)
        {
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                Area a;
                Volume v;
                volume=sphere(a,v);
                cout << "Volume of Sphere = " << volume << endl; 
            }
            else
            {
                Area a;
                Volume v;
                double radius;
                cout << "Enter Radius : ";
                cin >> radius;
                a.set_radius(radius);
                volume=sphere(a,v);
                cout << "Volume of Sphere = " << volume << endl;
            }
        }
        else if(choice == 7)
        {
            Area a1,a2;
            Volume v1,v2;
            double vol1,vol2;
            cout << "For Cube-1:-" << endl;
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                vol1=cube(a1,v1); 
            }
            else
            {
                double side;
                cout << "Enter Side : ";
                cin >> side;
                a1.set_side(side);
                vol1=cube(a1,v1); 
            }
            cout << "For Cube-2:-" << endl;
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                vol2=cube(a2,v2); 
            }
            else
            {
                double side;
                cout << "Enter Side : ";
                cin >> side;
                a2.set_side(side);
                vol2=cube(a2,v2); 
            }
            compare(vol1,vol2);
        }
         else if(choice == 8)
        {
            Area a1,a2;
            Volume v1,v2;
            double vol1,vol2;
            cout << "For Cuboid-1:-" << endl;
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                vol1=cuboid(a1,v1);
            }
            else
            {
                double length,breadth,height;
                cout << "Do you wish to enter length? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Length : ";
                    cin >> length;
                    a1.set_length(length);
                }
                cout << "Do you wish to enter breadth? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Breadth : ";
                    cin >> breadth;
                    a1.set_breadth(breadth);
                }
                cout << "Do you wish to enter height? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Height : ";
                    cin >> height;
                    v1.set_height(height);
                }
                vol1=cube(a1,v1); 
            }
            cout << "For Cuboid-2:-" << endl;
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                vol2=cuboid(a2,v2);
            }
            else
            {
                double length,breadth,height;
                cout << "Do you wish to enter length? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Length : ";
                    cin >> length;
                    a2.set_length(length);
                }
                cout << "Do you wish to enter breadth? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Breadth : ";
                    cin >> breadth;
                    a2.set_breadth(breadth);
                }
                cout << "Do you wish to enter height? 1.Yes 2.No : ";
                cin >> flag;
                if(flag==1)
                {
                    cout << "Enter Height : ";
                    cin >> height;
                    v2.set_height(height);
                }
                vol2=cube(a2,v2); 
            }
            compare(vol1,vol2);
        }
        else if(choice == 9)
        {
            Area a1,a2;
            Volume v1,v2;
            double vol1,vol2;
            cout << "For Sphere-1:-" << endl;
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                vol1=sphere(a1,v1); 
            }
            else
            {
                double radius;
                cout << "Enter Radius : ";
                cin >> radius;
                a1.set_radius(radius);
                vol1=sphere(a1,v1); 
            }
            cout << "For Cube-2:-" << endl;
            cout << "1.Default or 2.Selected Parameters? : ";
            cin >> ch;
            if(ch==1)
            {
                vol2=sphere(a2,v2); 
            }
            else
            {
                double radius;
                cout << "Enter Radius : ";
                cin >> radius;
                a2.set_radius(radius);
                vol1=sphere(a2,v2);  
            }
            compare(vol1,vol2);
        }
        else if(choice == 10)
        {
            break;
        }
        else
        {
            cout << "Invalid Command" << endl;
        }
    }
    return 0;
}
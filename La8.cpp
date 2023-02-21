#include<iostream>
#include<string>
#include<vector>
using namespace std;

class student
{
    protected:
        string name;
        string roll_no;
    public:
        student()
        {
            this->name="Not Assigned Yet";
            this->roll_no="Not Assigned Yet";
        }
        student(string name, string roll_no)
        {
            this->name=name;
            this->roll_no=roll_no;
        }
        virtual void display() = 0;
};

class pg_student : public student
{
    protected:
        string course_1;
        string course_2;
        string course_3;
    public:
        pg_student():student()
        {
            this->course_1 = "Not Enrolled Yet";
            this->course_2 = "Not Enrolled Yet";
            this->course_3 = "Not Enrolled Yet";
        }
        pg_student(string name, string roll_no, string course_1 = "Not Enrolled Yet", string course_2 = "Not Enrolled Yet", string course_3 = "Not Enrolled Yet") : student(name,roll_no)
        {
            this->course_1 = course_1;
            this->course_2 = course_2;
            this->course_3 = course_3;
        }
        void display()
        {
            cout << "Name            : " << this->name << endl;
            cout << "Roll No         : " << this->roll_no << endl;
            cout << "Course-1        : " << this->course_1 << endl;
            cout << "Course-2        : " << this->course_2 << endl;
            cout << "Course-3        : " << this->course_3 << endl;
        }
};

class research_student : public student
{
    protected:
        string course_1;
        string research_area;
    public:
        research_student():student()
        {
            this->course_1 = "Not Enrolled Yet";
            this->research_area = "Not Enrolled Yet";
        }
        research_student(string name, string roll_no, string course_1 = "Not Enrolled Yet", string research_area = "Not Enrolled Yet") : student(name,roll_no)
        {
            this->course_1 = course_1;
            this->research_area = research_area;
        }
        void display()
        {
            cout << "Name            : " << this->name << endl;
            cout << "Roll No         : " << this->roll_no << endl;
            cout << "Course          : " << this->course_1 << endl;
            cout << "Research        : " << this->research_area << endl;
        }
};

class TA : public pg_student, public research_student
{
    protected:
        string course_assigned;
        string role;
    public:
        TA()
        {
            this->course_assigned = "Not Assigned";
            this->role = "Not Assigned";
        }
        TA(string name, string roll_no, string course_1, string course_2, string course_3, string course, string role) : pg_student(name,roll_no,course_1,course_2,course_3)
        {
            if(course!=course_1 && course!=course_2 && course!=course_3)
            {
                this->course_assigned = course;
                this->role = role;
            }
            else
            {
                cout << "Not Accepted Course as it matches with one of the courses you undertook" << endl;
                this->role = role;
            }
        }
        TA(string name, string roll_no, string course_1, string research_area, string course, string role) : research_student(name,roll_no,course_1,research_area)
        {
            if(course!=course_1)
            {
                this->course_assigned = course;
                this->role = role;
            }
            else
            {
                cout << "Not Accepted Course as it matches with the course you undertook" << endl;
                this->role = role;
            }
        }
        void show()
        {
            if(this->course_2 == "Not Enrolled Yet")
            {
                (*this).research_student::display();
            }
            else
            {
                (*this).pg_student::display();
            }
            cout << "Assigned Course : " << this->course_assigned << endl;
            cout << "Role            : " << this->role << endl;
            cout << "*******************" << endl;
        }
};

int main()
{
    string name, rno, c1, c2, c3, c, ra;
    int role;
    int ch;
    vector<TA> vec;
    while(1)
    {
        cout << "Select an Option:-" <<endl;
        cout << "1.Set Details  2.Display  3.Exit" << endl;
        cout << "Input : ";
        cin >> ch;
        if(ch==1)
        {
            cout << "Enter Name : ";
            cin >> name;
            cout << "Enter Roll Number : ";
            cin >> rno;
            cout << "Enter Role : 1.PG Student  2.Research Student : ";
            cin >> role;
            if(role==1)
            {
                cout << "Enter Course-1 : ";
                cin >> c1;
                cout << "Enter Course-2 : ";
                cin >> c2;
                cout << "Enter Course-3 : ";
                cin >> c3;
                cout << "Enter Course Assigned : ";
                cin >> c;
                TA t(name,rno,c1,c2,c3,c,"PG student");
                vec.push_back(t);
            }
            else if(role==2)
            {
                cout << "Enter Course-1 : ";
                cin >> c1;
                cout << "Enter Research Area : ";
                cin >> ra;
                cout << "Enter Course Assigned : ";
                cin >> c;
                TA t(name,rno,c1,ra,c,"Research student");
                vec.push_back(t);
            }
            else
            {
                cout << "**** INVALID ROLE ****" << endl;
            }
        }
        else if(ch==2)
        {
            for(int i=0; i<vec.size(); i++)
            {
                vec[i].show();
            }
        }
        else if(ch==3)
        {
            break;
        }
        else
        {
            cout << "**** INVALID INPUT ****" << endl;
        }
    }
    return 0;
}
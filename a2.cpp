/* Develop a program in C++ to create a database of student's information system containing the following 
information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, 
Driving license no. and other. 
Construct the database with suitable member functions. Make use of constructor, default constructor, 
copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic 
memory allocation operators-new and delete as well as exception handling. */

#include <iostream>
using namespace std;

class Student {
    string name, cls, dob, *bg, add;
    int rollno;
    char *div;
    long *tel, *driv;
    static int count;

    public:
        // Default constructor: initializes variables with default values
        Student() {
            name = " ";
            rollno = 0;
            cls = " ";
            div = new char; // "new" allocates memory dynamically
            dob = "dd/mm/yyyy";
            bg = new string[3];
        }

        // Destructor: releases dynamically allocated memory
        ~Student() {
            delete div;
            delete bg;
        }

        // Copy constructor: creates copy of another Student object
        Student(Student &o1) {
            /* Value of member variable(eg: name) of current object('this') is assigned to same member 
            variable(name) of object o1. */
            this->name = o1.name;
            this->rollno = o1.rollno;
            this->cls = o1.cls;
            this->div = o1.div;
            this->dob = o1.dob;
            this->bg = o1.bg;
        }
        
        inline static void getcount() {
            count++;
        }
        inline static int showcount() {
            return count;
        }

        void getdata();
        void display();

        friend class Info;
};

int Student::count = 0;

inline void Student::getdata() {
    cout << "\nEnter name: ";
    cin >> name;

    cout << "Enter class: ";
    cin >> cls;

    cout << "Enter division: ";
    cin >> *div;

    cout << "Enter roll number: ";
    cin >> rollno;

    cout << "Enter date of birth: ";
    cin >> dob;

    cout << "Enter blood group: ";
    cin >> *bg;
}

inline void Student::display() {
    cout << "\nName: " << name << endl;
    cout << "Class: " << cls << endl;
    cout << "Div: " << *div << endl;
    cout << "Roll number: " << rollno << endl;
    cout << "Date of birth: " << dob << endl;
    cout << "Blood group: " << *bg << endl;
}

// class Info is a friend class of Student, and is allowed access to private members of class Student
class Info : public Student {
    public:
        // Default constructor
        Info() {
            add = " ";
            tel = new long;
            driv = new long;
        }

        // Destructor
        ~Info() {
            delete tel;
            delete driv;
        }

        // Copy constructor
        Info(Info &o2) {
            this->add = o2.add;
            this->tel = o2.tel;
            this->driv = o2.driv;
        }
    
    void getinfo();
    void display();
};

/* The 'inline' keyword means that the function code can be substituted directly at the call site instead 
of making a function call. This can potentially lead to more efficient code in terms of execution speed. */
inline void Info::getinfo() {
    cout << "Enter address: ";
    cin >> add;

    cout << "Enter driving licence number: ";
    cin >> *driv;

    int n, total, flag = 0;
    
    while (flag == 0) {
        cout << "Enter telephone number: ";
        cin >> *tel;

        string telstring = to_string(*tel);
        total = telstring.length();

        n = 0;
        for(int i = 1; i <= total; i++) {
            n++;
        }
        cout << "Number of digits in the telephone number: " << n << endl;

        try {
            if (n == 10) {
                cout << "Number entered is valid." << endl;
                flag = 1;
            }
            else {
                throw(*tel);
            }
        }
        catch(...) {
            cout << "Number entered is invalid." << endl;
            *tel = 0;
        }
    }
}

inline void Info::display() {
    cout << "Address: " << add << endl;
    cout << "Telephone number: " << *tel << endl;
    cout << "Driving licence number: " << *driv << endl;
}

int main() {
    Student *o1[20]; // Array of pointers to student objects
    Info *o2[20]; // Array of pointers to info objects

    int m = 1;
    string ans;

    do {
        cout << "\nStudent " << m << ": " << endl;

        o1[m] = new Student; // To create a new student object and store its address in the array
        o2[m] = new Info; // To create a new info object and store its address in the array

        o1[m]->getdata(); // Calls the getdata() function for the student object
        o2[m]->getinfo(); // Calls the getinfo() function for the info object

        o1[m]->getcount(); // Increments the count of student objects
        o1[m]->showcount();

        o1[m]->display(); // Displays information for the student object
        o2[m]->display(); // Displays information for the info object

        m++; // To increment count of students

        cout << "\nDo you want to add more data? (enter yes/no): ";
        cin >> ans;
    } 
    while (ans == "yes");
}

/* Write C++ program using STL for sorting and searching user defined records such as personal 
records (Name, DOB, Telephone number etc) using vector container. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class stl {
    public:
        string name, dob;
        long tel;

        void read() {
            cout << "\nEnter name: ";
            cin >> name;
            cout << "Enter date of birth: ";
            cin >> dob;
            cout << "Enter telephone number: ";
            cin >> tel;
        }

        void display() {
            cout << "\nName: " << name << endl;
            cout << "Date of birth: " << dob << endl;
            cout << "Telephone number: " << tel << endl;
        }
};

int main() {
    int n, a, ch;
    string key, ans;

    cout << "\nEnter the amount of data to be added: ";
    cin >> n;

    /* Declaration of vector 'v' that can store objects of class stl whose size is determined by value of 'n'.
    In context of program, it is used to store user-defined records, where each record is an object of 
    class stl. */
    vector<stl> v(n); 

    /* Declaration of vector 'name' that can store strings(string objects). Size is determined by value of
    'n'. In the context of the program, it is used to store names extracted from the user-defined records 
    for sorting and searching operations. */
    vector<string> name(n);

    cout << "\n\nMENU:\n" << endl;
    cout << "1. To enter data" << endl;
    cout << "2. To sort data" << endl;
    cout << "3. To search data" << endl;
    cout << "\nEND\n" << endl;

    a = 1;
    while(a==1) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                for (int i = 0; i < n; i++) {
                v[i].read(); // Here, the user-defined records get stored into vector 'v'
                }
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                name[i] = v[i].name; // Here, name attributes of 'v' are assigned to 'name' vector
                }

                /* 'sort' algorithm from C++ Standard Template Library is used to sort names in 'name' vector
                in alphabetical order. */
                sort(name.begin(), name.end());

                cout << "\nSorted Data:" << endl;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (name[i] == v[j].name) {
                            v[j].display();
                            break;
                        }
                    }
                }
                break;

            /* In C++, the 'sort' and 'binary_search' functions are part of the C++ Standard Template 
            Library(STL) and are available by default. These functions are included in the <algorithm> header. */

            case 3:
                for (int i = 0; i < n; i++) {
                    name[i] = v[i].name; // Here, name attributes of 'v' are assigned to 'name' vector
                }

                sort(name.begin(), name.end()); // Sorting is mandatory before applying binary search
            
                cout << "\nEnter the name to be searched: ";
                cin >> key;

                if (binary_search(name.begin(), name.end(), key)) {
                    cout << "\nRecord found." << endl;
                }
                else {
                    cout << "\nRecord not found." << endl;
                }
                break;
            
            default:
                cout << "\nInvalid choice.";
                break;
        }

        cout << "\nDo you want to choose again? (enter yes/no)" << endl;
        cin >> ans;
        if(ans == "yes") {
            a = 1;
        }
        else {
            a = 0;
            cout << "Thank you!";
        }
    }
}

/* Implement a class complex which represents the Complex Number data type. Implement the following: 
1. Constructor(Including a default constructor which creates the complex number 0+0i)
2. Overload operator + to add two complex numbers.
3. Overload operator * to multiply two complex numbers.
4. Overload operator << and >> to print and read Complex Numbers. */

#include <iostream>
using namespace std;

class complex {
    private:
        int real, img;
    public:
        // Default constructor Complex() creates complex number 0+0i
        complex() {
            real = 0;
            img = 0;
        }

        /* In C++, 'operator' is a special keyword whose use in a function definition indicates that an 
        operator is being overloaded. Binary operator overloading is applied below. It requires one parameter,
        usually the RHS of the operation. 'this' pointer is used implicitly to call the LHS of the operation. */

        // Function to overload + operator
        complex operator+(complex c2) {
            complex c3;
            c3.real = real + c2.real;
            c3.img = img + c2.img;
            return c3;
        }

        // Function to overload * operator
        complex operator*(complex c2) {
            complex c3;
            c3.real = (real * c2.real) - (img * c2.img);
            c3.img = (real * c2.img) + (img * c2.real);
            return c3;
        }

        /* In the case of operator overloading, operators like >> and << are often overloaded as friend 
        functions because they typically involve input/output streams(istream and ostream), and you want them 
        to have access to the private members of your class. */
        friend void operator>>(istream& in, complex& c);
        friend void operator<<(ostream& out, complex& c);
};

/* istream& in: parameter to specify the input stream from which you want to read values(usually cin, the 
standard input stream). 
complex& c: parameter to specify the complex object to which you want to assign input values. 

The & indicates that it is passed by reference, which allows the function to modify the original object 
directly. Without the &, the function would receive a copy of the complex object, and any changes made to it 
inside the function would not affect the original object. */

// Function to overload >> operator
void operator>>(istream& in, complex& c) {
    cout << "Enter the real part of the complex number: ";
    in >> c.real;
    cout << "Enter the imaginary part of the complex number: ";
    in >> c.img;
}

// Function to overload << operator
void operator<<(ostream& out, complex& c) {
    out << c.real << " + " << c.img << "i" << endl;
}

int main() {
    int a, ch;
    complex c1, c2, c3;

    cout << "\n\n\t* MENU *\n";
    cout << "1. Add two complex numbers" << endl;
    cout << "2. Multiply two complex numbers\n" << endl;

    a = 1;
    while(a == 1) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        cout << "\nFor the first complex number-" << endl;
        cin >> c1;
        cout << "\nFor the second complex number-" << endl;
        cin >> c2;

        cout << "\nFirst complex number: " << c1;
        cout << "Second complex number: " << c2;

        switch(ch) {
            case 1:
                c3 = c1 + c2;
                cout << "\nSum of two complex numbers: " << c3;
                break;

            case 2:
                c3 = c1 * c2;
                cout << "\nProduct of two complex numbers: " << c3;
                break;

            default:
                cout << "\nInvalid choice." << endl;
                break;
        }

        char ans;
        cout << "\nWould you like to continue? (enter y/n): ";
        cin >> ans;
        if(ans == 'y')
            a = 1;
        else {
            a = 0;
            cout << "\nThank you!" << endl;
        }
    }
}

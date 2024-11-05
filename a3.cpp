/* Imagine a publishing company which does marketing for book and audio cassette versions. 
Create a class publication that stores the title (a string) and price (type float) of publications. 
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing 
time in minutes (type float). Write a program that instantiates the book and tape class, 
allows user to enter data and displays the data members. If an exception is caught, replace all the 
data member values with zero values. */

#include <iostream>
using namespace std;

// To create a class Publication that stores title and price of publication
class Publication {
    public:
        string title;
        float price; 

        // Default constructor to initailise title and price
        Publication() {
            title = " ";
            price = 0.0;      
       
            cout << "\nEnter the title of the publication." << endl;
            cin >> title;
            cout << "\nEnter the price of the publication." << endl;
            cin >> price;
        }
};

// To derive properties of base class Publication into derived class Book
class Book : public Publication {
    public:
        int pagecount;

        // Default constructor to initailise page count of book
        Book() {
            pagecount = 0;
        }

        void getdata() {
            // try: represents a block of code that can throw an exception
            try {
                cout << "\nEnter the number of pages of the book." << endl;
                cin >> pagecount;

                if(pagecount<=0) {
                    throw pagecount; // throw: used to throw an exception
                }
            }
            // catch: represents a block of code executed when an exception is thrown
            catch(...) { // special syntax to catch exception of any data type
                cout << "Invalid page count!" << endl;
                pagecount = 0;
            }
        }

        void display() {
            cout << "\nName of the book: " << title << endl;
            cout << "Price of the book: " << price << endl;
            cout << "Number of pages in the book: " << pagecount << endl;
        }
};

// To derive properties of base class Publication into derived class Tape
class Tape : public Publication {
    public:
        float playtime;

        // Default constructor to initailise play time of audio cassette
        Tape() {
            playtime = 0.0;
        }
        
        void getdata() {
            // try: represents a block of code that can throw an exception
            try{
                cout << "\nEnter the playing time of the audio tape in minutes." << endl;
                cin >> playtime;

                if(playtime<=0) {
                    throw playtime; // throw: used to throw an exception
                }
            }
            // catch: represents a block of code executed when an exception is thrown
            catch(...) {
                cout << "Invalid playtime!" << endl;
                playtime = 0;
            }
        }

        void display() {
            cout << "\nName of the audio tape: " << title << endl;
            cout << "Price of the audio tape: " << price << endl;
            cout << "Playing time of the audio tape: " << playtime << " minutes" << endl;
        }
};

int main() {
    string ans;
    cout << "\nIs the publication information about a book or an audio tape? (Enter book/audio)" << endl;
    cin >> ans;

    if(ans=="book") {
        Book obj1; // Instantiation of class Book
        obj1.getdata();
        obj1.display();
    }
    else {
        Tape obj2; // Instantiation of class Tape
        obj2.getdata();
        obj2.display();
    }
}

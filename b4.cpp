/* Write a C++ program that creates an output file, writes information to it, closes the file, open it again 
as an input file and read the information from the file. */

#include <iostream>
#include <fstream> // Header for file operations
using namespace std;

int main() {
    string str; // A string variable to store each line read from the file
    fstream file; // To create an object for fstream, used for file ip/op operations
    int i = 1;

    /* ios::out (output mode) is used when a file is opened for writing.
    If a file is opened in writing mode, you can only write data to it, not read. */
    file.open("Ishita.txt", ios::out); // To open file named Ishita.txt in output mode
    file << "Hello, Ishita here!" << endl; // To write string to file
    file << i << endl; // To write integer to file on new line
    file.close(); // To close the file

    /* ios::in (input mode) is used when a file is opened for reading.
    If a file is opened in reading mode, you can only read data from it, not write to it. */
    file.open("Ishita.txt", ios::in); // To open same file in input mode
    while(getline(file, str)) { // To read each line from the file and store it in the str variable
        cout << str << endl; // To print each line to the console
    }
    file.close(); // To close the file
}


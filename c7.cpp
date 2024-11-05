/* Write a program in C++ to use map associative container. The keys will be the names of states and 
the values will be the populations of the states. When the program runs, the user is prompted to type the 
name of a state. The program then looks in the map, using the state name as an index and returns the 
population of the state. */

#include <iostream>
#include <map>
using namespace std;

/* An associative container is a type of container in C++ that organizes and stores elements based on 
key-value pairs. It allows efficient retrieval of elements using their associated keys. 
The C++ Standard Template Library (STL) provides several associative container classes, and two of the most 
commonly used ones are std::map and std::unordered_map. 
std::map is an ordered associative container that stores elements as key-value pairs and automatically 
maintains the keys in sorted order. It is implemented as a balanced binary search tree. */

class Stat {
    public:
        map<string, int> map1; // Declares variable map1 of template and specifies data type of key & value
        string state;
        int population;

        void read() {
            cout << "\nEnter the name of the state: ";
            cin >> state;
            cout << "Enter the population of the state: ";
            cin >> population;
            map1[state] = population;
        }

        void display() {
            cout << "\nStates and their populations: " << endl;

            // Declares an iterator named i for iterating over the elements of the std::map.
            map<string, int>::iterator i;

            /* Initiates a for loop that iterates over the elements of the map using the iterator. 
            map1.begin(): returns an iterator pointing to the first element of the map.
            map1.end(): returns an iterator pointing one past the last element of the map.
            i++: increments the iterator to move to the next element in the map. */
            for(i = map1.begin(); i != map1.end(); i++) {
                /* Prints the current key-value pair.
                i->first: accesses the key (state name) of the current map element through the iterator.
                i->second: accesses the value (population) of the current map element through the iterator. */
                cout << i->first << "  " << i->second << endl;
            }
        }
        
        /* map1.find(x): searches for the key x in the map1. The find function returns an iterator to the 
        element with the specified key, or map1.end() if the key is not found.
        If the iterator returned by find is equal to map1.end(), it indicates that the state is not found in 
        the map. If the state is found, state name and its corresponding population is printed. */
        void findpop() {
            string x;
            cout << "Enter state to view population: ";
            cin >> x;

            if(map1.find(x) == map1.end()) {
                cout << "State not found." << endl;
            }
            else {
                // Accesses the value(population) associated with the key x in the map.
                cout << x << "  " << map1.find(x)->second << endl; 
            }
        }
};

int main() {
    Stat obj;
    int n, a, ch;

    cout << "\n\nMENU:\n" << endl;
    cout << "1. To enter data" << endl;
    cout << "2. To view data" << endl;
    cout << "3. To search data" << endl;
    cout << "\nEND\n" << endl;

    a = 1;
    while(a==1) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Number of states to be input: ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    obj.read();
                }
                break;
            
            case 2:
                obj.display();
                break;

            case 3:
                obj.findpop();
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }

        string ans;
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

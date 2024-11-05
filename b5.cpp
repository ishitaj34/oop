/* Write a function template for selection sort that inputs, sorts and outputs an integer
array and a float array. */

#include <iostream>
using namespace std;

int n; // Number of elements in each array

template <class T> // Declares function template with single template parameter T
void sort(T arr[10]) { // Definition of function template 'sort' which takes array 'arr' of type T and size 10
    int min;

    // Selection sort algorithm
    for(int i = 0; i < n; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        
        // After each iteration, minimum element is swapped with the unsorted array element i at the beginning
        T temp = arr[i]; // temp is a variable of type T
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // To display sorted array
    cout << "\nSorted array: " << endl;
    for(int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main() {
    int A[10], a, ch;
    float B[10];

    cout << "\n\nMENU:\n" << endl;
    cout << "1. Sort integer array" << endl;
    cout << "2. Sort float array" << endl;
    cout << "\nEND\n" << endl;

    a = 1;
    while(a == 1) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "\nEnter number of elements in the array: ";
                cin >> n;

                for(int i = 0; i < n; i++) {
                    cout << "Enter an element: ";
                    cin >> A[i];
                }

                sort(A);
                break;

            case 2:
                cout << "\nEnter number of elements in the array: ";
                cin >> n;

                for(int i = 0; i < n; i++) {
                    cout << "Enter an element: ";
                    cin >> B[i];
                }

                sort(B);
                break;

            default:
                cout << "\nInvalid choice. Please try again.";
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

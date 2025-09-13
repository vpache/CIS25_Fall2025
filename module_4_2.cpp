#include <iostream>

using namespace std;

int main() {
    float n1, n2, n3; // Declare the three float variables
    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3; // Correctly read input into the variables

    // Check if n1 is the largest
    if (n1 >= n2 && n1 >= n3) {
        cout << "Largest number: " << n1 << endl;
    }
    // Check if n2 is the largest
    else if (n2 >= n1 && n2 >= n3) { // Use else if for exclusive conditions
        cout << "Largest number: " << n2 << endl;
    }
    // If neither n1 nor n2 is the largest, then n3 must be
    else {
        cout << "Largest number: " << n3 << endl;
    }

    return 0;
}
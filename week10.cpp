#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item() {
        name = "";
        quantity = 0;
    }

    void display() const {
        cout << "Item: " << name << " | Quantity: " << quantity << endl;
    }
};

void searchItem(Item items[], int size, const string& searchName) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (items[i].name == searchName) {
            cout << "Found item: " << items[i].name 
                 << " | Quantity: " << items[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Item \"" << searchName << "\" not found in inventory.\n";
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];

    cout << "=== Inventory Input ===\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter name for item " << i + 1 << ": ";
        getline(cin, inventory[i].name);
        cout << "Enter quantity for " << inventory[i].name << ": ";
        cin >> inventory[i].quantity;
        cin.ignore(); 
    }

    cout << "\n=== Inventory List ===\n";
    for (int i = 0; i < SIZE; ++i) {
        inventory[i].display();
    }

    char choice;
    do {
        string searchName;
        cout << "\nEnter item name to search: ";
        getline(cin, searchName);
        searchItem(inventory, SIZE, searchName);

        cout << "Search again? (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the Inventory System!\n";
    return 0;
}

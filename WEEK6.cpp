#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>  
using namespace std;

class Item {
public:
    string name;
    int quantity;

    void saveToFile() const {
        ofstream out("items.txt", ios::app);
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    static vector<Item> loadAllFromFile() {
        vector<Item> items;
        ifstream in("items.txt");

        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                stringstream ss(line);
                string namePart, quantityPart;

                if (getline(ss, namePart, ',') && getline(ss, quantityPart)) {
                    Item item;
                    item.name = namePart;
                    item.quantity = stoi(quantityPart); 
                    items.push_back(item);
                }
            }
            in.close();
        } else {
            cout << "Unable to open file for reading." << endl;
        }

        return items;
    }

    void display() const {
        cout << "Name: " << name << ", Quantity: " << quantity << endl;
    }
};

int main() {
    Item tool;
    tool.name = "Screwdriver";
    tool.quantity = 10;
    tool.saveToFile();

    vector<Item> items = Item::loadAllFromFile();

    cout << "\nItems loaded from file:" << endl;
    for (const Item& it : items) {
        it.display();
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Product {
    int id;
    string name;
    float price;

public:
    Product(int i, string n, float p)
        : id(i), name(n), price(p)
    {
        cout << "Constructor called\n";
    }

    ~Product() {
        cout << "Destructor called\n";
    }

    void printDetails() {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: $" << price
             << endl;
    }
};

int main() {
    Product p(101, "Notebook", 4.99f);
    p.printDetails();

    return 0;
}

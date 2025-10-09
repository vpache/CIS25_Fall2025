#include <iostream>
#include <string>

struct Item {
    std::string name;
    int id;
};

int main() {
    const int numRecords = 100;
    Item* items = new Item[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        items[i].id = i + 1;
        items[i].name = "Item " + std::to_string(i + 1);
    }

    int searchId;
    std::cout << "Enter the ID to search for: ";
    std::cin >> searchId;

    Item* foundItem = nullptr;
    for (int i = 0; i < numRecords; ++i) {
        if (items[i].id == searchId) {
            foundItem = &items[i];
            break;
        }
    }

    if (foundItem != nullptr) {
        std::cout << "Item found: Name = " << foundItem->name << ", ID = " << foundItem->id << std::endl;
    } else {
        std::cout << "Item with ID " << searchId << " not found." << std::endl;
    }
    
    delete[] items;
    items = nullptr;

    return 0;
}



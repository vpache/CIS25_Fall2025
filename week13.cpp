#include <iostream>
#include <memory>
#include <limits>
#include <string>

class User {
public:
    virtual void accessLevel() const {
        std::cout << "General Access" << std::endl;
    }
};

class Employee : public User {
public:
    void accessLevel() const override {
        std::cout << "Employee Access" << std::endl;
    }
};

class InventoryManager : public Employee {
public:
    void accessLevel() const override {
        std::cout << "Full Inventory Management Access" << std::endl;
    }
};

int get_user_choice() {
    int choice = 0;
    while (true) {
        std::cout << "Select your access level:" << std::endl;
        std::cout << "1. Standard User" << std::endl;
        std::cout << "2. Employee" << std::endl;
        std::cout << "3. Inventory Manager" << std::endl;
        std::cout << "Enter choice (1-3): ";

        if (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return choice;
        }
    }
}

int main() {
    std::cout << "--- Demonstrating direct access call from an InventoryManager instance ---" << std::endl;
    InventoryManager mgr;
    mgr.accessLevel();

    std::cout << "\n--- Demonstrating User Choice Function ---" << std::endl;
    int user_type_choice = get_user_choice();
    std::cout << "User selected choice: " << user_type_choice << std::endl;

    std::unique_ptr<User> currentUser;

    if (user_type_choice == 1) {
        currentUser = std::make_unique<User>();
    } else if (user_type_choice == 2) {
        currentUser = std::make_unique<Employee>();
    } else {
        currentUser = std::make_unique<InventoryManager>();
    }

    std::cout << "Assigned access level: ";
    currentUser->accessLevel(); 

    return 0;
}

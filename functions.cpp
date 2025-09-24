#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "1. Enter Whole Number:\n";
    std::cout << "2. Enter Decimal: \n";
    std::cout << "3. Exit\n";
}

int main() {
    int choice;
    do {
        showMenu();
        std::cout << "Pick a Number: ";
        std::cin >> choice;

        if (choice == 1) {
            int wholeNumber;
            std::cout << "Enter a whole number: ";
            std::cin >> wholeNumber;
            std::cout << "You have entered the whole number: " << wholeNumber << std::endl;
        } else if (choice == 2) {
            double decimalNumber;
            std::cout << "Enter a decimal: ";
            std::cin >> decimalNumber;
            std::cout << "You have entered the decimal: " << decimalNumber << std::endl;
        } else if (choice == 3) {
            std::cout << "Exiting program.\n";
        } 

    } while (choice != 3);

    return 0;
}
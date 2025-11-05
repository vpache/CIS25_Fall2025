#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
        ofstream file("transactions.txt");
        if (file.is_open()) {
            file << "=== Transaction History ===" << endl;
            file.close();
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive." << endl;
            return;
        }
        balance += amount;
        cout << fixed << setprecision(2);
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase() {
        string item;
        double cost;

        cout << "\nEnter item name: ";
        cin.ignore();             
        getline(cin, item);

        cout << "Enter cost of " << item << ": $";
        cin >> cost;

        if (cost <= 0) {
            cout << "Purchase amount must be positive." << endl;
            return;
        }

        if (cost > balance) {
            cout << "Insufficient funds for " << item << "!" << endl;
            return;
        }

        balance -= cost;
        cout << fixed << setprecision(2);
        cout << "Purchased " << item << " for $" << cost 
             << ". Remaining balance: $" << balance << endl;

        saveTransaction("Purchase - " + item, -cost);
    }

    void displayBalance() const {
        cout << fixed << setprecision(2);
        cout << "\nCurrent Balance: $" << balance << endl;
    }

private:
    void saveTransaction(const string& type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << fixed << setprecision(2);
            file << type << ": $" << amount << endl;
            file.close();
        }
    }
};

int main() {
    BankAccount myAccount;
    double startAmount;
    int purchaseCount;

    cout << "Enter starting deposit amount: $";
    cin >> startAmount;
    myAccount.deposit(startAmount);

    cout << "\nHow many purchases would you like to make? ";
    cin >> purchaseCount;

    for (int i = 0; i < purchaseCount; ++i) {
        myAccount.makePurchase();
    }

    myAccount.displayBalance();

    cout << "\nAll transactions saved to transactions.txt\n";
    return 0;
}


#include "BankAccount.h"
#include <iostream>
#include <limits>

int main() {
    // setting up a default account to mess around with
    BankAccount myAccount(1001, "Default User", 500.00);
    BankAccount compareAccount(1002, "Test Compare", 1000.00);

    int choice;
    double amount;

    do {
        std::cout << "\n--- Bank Account Menu ---\n";
        std::cout << "1. Create new account\n"; // static function 
        std::cout << "2. Print account\n"; // static function 
        std::cout << "3. Deposit\n";   // adding +=
        std::cout << "4. Withdraw\n";  // subtracting -=
        std::cout << "5. Compare against test account\n"; // comparison operators (==, >, <)
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\n--- Creating New Account ---\n";
                // calling the static function directly from the class scope
                myAccount = BankAccount::createAccountFromInput();
                break;
            case 2:
                std::cout << "\n--- Current Account Info ---\n";
                BankAccount::printAccount(myAccount);
                break;
            case 3:
                std::cout << "Amount to deposit: $";
                std::cin >> amount;
                myAccount += amount; // using the overloaded +=
                break;
            case 4:
                std::cout << "Amount to withdraw: $";
                std::cin >> amount;
                myAccount -= amount; // using the overloaded -=
                break;
            case 5:
                std::cout << "\n--- Comparing Accounts ---\n";
                std::cout << "Test Account Balance: $" << compareAccount.getBalance() << "\n\n";
                
                if (myAccount == compareAccount) {
                    std::cout << "Accounts have the same ID number.\n";
                } else {
                    std::cout << "Accounts have different ID numbers.\n";
                }

                if (myAccount < compareAccount) {
                    std::cout << "Current account has less money than test account.\n";
                } else if (myAccount > compareAccount) {
                    std::cout << "Current account has more money than test account.\n";
                } else {
                    std::cout << "Both accounts have the exact same balance.\n";
                }
                break;
            case 6:
                std::cout << "Exiting program....!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
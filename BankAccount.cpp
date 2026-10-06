#include "BankAccount.h"
#include <iostream>
#include <cstring>
#include <limits>

BankAccount::BankAccount() {
    accountNumber = 0;
    balance = 0.0;
    accountHolder = new char[1];
    accountHolder[0] = '\0';
}

BankAccount::BankAccount(int accNum, const char* name, double initialBalance) {
    accountNumber = accNum;
    balance = (initialBalance >= 0) ? initialBalance : 0.0;
    
    // gotta allocate exact space for the string so we dont waste memory
    accountHolder = new char[strlen(name) + 1];
    strcpy(accountHolder, name);
}

// Rule of three: copy constructor so we dont just copy pointers and crash later
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    balance = other.balance;
    
    accountHolder = new char[strlen(other.accountHolder) + 1];
    strcpy(accountHolder, other.accountHolder);
}

// Rule of three: copy assignment operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    // just checking if we are trying to assign the object to itself
    if (this == &other) {
        return *this;
    }

    // clear out the old memory first so we dont get a leak
    delete[] accountHolder;

    accountNumber = other.accountNumber;
    balance = other.balance;
    
    accountHolder = new char[strlen(other.accountHolder) + 1];
    strcpy(accountHolder, other.accountHolder);

    return *this;
}

// Rule of three: destructor cleans up the dynamic char array
BankAccount::~BankAccount() {
    delete[] accountHolder;
}

// overload += for deposits
BankAccount& BankAccount::operator+=(double amount) {
    // making sure the deposit is actually a positive number
    if (amount > 0) {
        balance += amount;
    } else {
        std::cout << "Error: Deposit amount must be positive.\n";
    }
    return *this;
}

// overload -= for withdrawals
BankAccount& BankAccount::operator-=(double amount) {
    // checking if we even have enough money to take out and if the amount is valid
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    } else if (amount <= 0) {
        std::cout << "Error: Withdrawal amount needs to be positive.\n";
    } else {
        std::cout << "Error: Insufficient funds for withdrawal amount.\n";
    }
    return *this;
}

// compare account numbers
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

// compare balances for <
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

// compare balances for >
bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

// static function to print without needing a calling object
void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "Account Number: " << account.accountNumber << "\n";
    std::cout << "Account Holder: " << account.accountHolder << "\n";
    std::cout << "Account Balance: $" << account.balance << "\n";
}

// static function to build an account from standard input
BankAccount BankAccount::createAccountFromInput() {
    int accNum;
    char nameBuffer[256];
    double startBalance;

    std::cout << "Enter your account number: ";
    std::cin >> accNum;
    
    // clear the buffer so the getline doesnt just skip instantly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your account holder name: ";
    std::cin.getline(nameBuffer, 256);

    std::cout << "Enter initial balance: ";
    std::cin >> startBalance;

    // creating and returning the new object right here
    return BankAccount(accNum, nameBuffer, startBalance);
}

int BankAccount::getAccountNumber() const { return accountNumber; }
const char* BankAccount::getAccountHolder() const { return accountHolder; }
double BankAccount::getBalance() const { return balance; }
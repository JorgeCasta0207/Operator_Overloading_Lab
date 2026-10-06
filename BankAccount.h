/**
 * Name: Jorge Rochin Castaneda
 * Date: October 5, 2026
 * Purpose: C++ Lab covering Operator Overloading & The Rule of Three. 
 * Manages dynamic memory and demonstrates operator overloading with standard C++ operators.
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
private:
    int accountNumber;
    char* accountHolder; // using a pointer here so we actually have to use the rule of three
    double balance;

public:
    /**
     * Default constructor
     */
    BankAccount();

    /**
     * Parameterized constructor
     * @param accNum The account number
     * @param name The name of the account holder
     * @param initialBalance The starting balance
     */
    BankAccount(int accNum, const char* name, double initialBalance);

    // --- Rule of Three ---

    /**
     * Copy Constructor
     * @param other The BankAccount object to copy from
     */
    BankAccount(const BankAccount& other);

    /**
     * Copy Assignment Operator
     * @param other The BankAccount object to assign from
     * @return Reference to the current object
     */
    BankAccount& operator=(const BankAccount& other);

    /**
     * Destructor
     */
    ~BankAccount();

    // --- Overloaded Arithmetic Assignment Operators ---

    /**
     * Adds an amount to the balance in-place
     * @param amount The amount to deposit
     * @return Reference to the modified object
     */
    BankAccount& operator+=(double amount);

    /**
     * Subtracts an amount from the balance in-place
     * @param amount The amount to withdraw
     * @return Reference to the modified object
     */
    BankAccount& operator-=(double amount);

    // --- Overloaded Comparison Operators ---

    /**
     * Checks if two accounts have the same account number
     * @param other The account to compare against
     * @return true if account numbers match, false otherwise
     */
    bool operator==(const BankAccount& other) const;

    /**
     * Checks if current account balance is less than the other
     * @param other The account to compare against
     * @return true if current balance is less, false otherwise
     */
    bool operator<(const BankAccount& other) const;

    /**
     * Checks if current account balance is greater than the other
     * @param other The account to compare against
     * @return true if current balance is greater, false otherwise
     */
    bool operator>(const BankAccount& other) const;

    // --- Static Utility Functions ---

    /**
     * Prints the details of a BankAccount object
     * @param account The account to print
     */
    static void printAccount(const BankAccount& account);

    /**
     * Prompts user for data and returns a new BankAccount object
     * @return A newly created BankAccount object
     */
    static BankAccount createAccountFromInput();

    // Getters just in case we need them outside
    int getAccountNumber() const;
    const char* getAccountHolder() const;
    double getBalance() const;
};

#endif
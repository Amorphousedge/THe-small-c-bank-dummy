#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

class Account {
private:
    unsigned int acc;
    std::string pass;

public:
    float balance;
    float wd;
    float dep;
    std::string name;
    std::string logpass;
    unsigned int logacc;

    Account() : balance(0), acc(0) {}

    void start();
    void withdraw();
    void deposit();
    void details();
    void signup();
    void login();
    void saveData();
    void loadData();
};

void Account::start() {
    balance = 0;
}

void Account::withdraw() {
    std::cout << "\nEnter the Withdraw Amount: ";
    std::cin >> wd;
    if (balance >= wd) {
        balance -= wd;
        std::cout << "\n" << wd << " is Withdrawn from balance. Your current balance is " << balance << "\n";
    } else {
        std::cout << "\nInsufficient Balance, Please Deposit cash before Withdraw.\n";
    }
    saveData();
}

void Account::deposit() {
    std::cout << "\nEnter Amount to be deposited: ";
    std::cin >> dep;
    balance += dep;
    std::cout << "\n" << dep << " is added to balance successfully.\n";
    saveData();
}

void Account::details() {
    std::cout << "\n\t\tSASTA BANK\n";
    std::cout << "\nAccount No.\tName\t\tBalance\n";
    std::cout << acc << "\t" << name << "\t" << balance << "\n";
}

void Account::signup() {
    std::cout << "\nWelcome to SASTA BANK Account creation portal\n";
    std::cout << "\nENTER your Name: ";
    std::cin >> name;
    std::cout << "\nEnter your 9 digit account code: ";
    std::cin >> acc;
    std::cout << "\nEnter your password (at least 9 characters): ";
    std::cin >> pass;

    if (pass.length() < 9) {
        std::cout << "Insufficient length of password. Please retry.\n";
        signup();
    }

    std::cout << "\nYou have to keep a minimum balance of 5000 in Account before using our services.\n";
    std::cout << "Want to add minimum balance now? If Yes press 1, Else press 2: ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        deposit();
    } else {
        std::cout << "\nIt's OK, but don't forget to add it later.\n";
    }
    saveData();
}

void Account::login() {
    for (int i = 0; i < 3; ++i) {
        std::cout << "\nENTER Correct ACCOUNT NO. and Password Combination for Accessing our Services\n";
        std::cout << "Account no: ";
        std::cin >> logacc;
        std::cout << "Password: ";
        std::cin >> logpass;

        if (logacc == acc && logpass == pass) {
            std::cout << "\nLogin Successful! Enjoy your Services.\n";
            return;
        } else {
            std::cout << "\nIncorrect Account No. or Password. Please try again.\n";
        }
    }

    std::cout << "\nDid you Forget Password? Press 1 if yes, 2 if you remember: ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        signup();
    }
}

void Account::saveData() {
    std::ofstream outFile("account_data.txt");
    if (outFile.is_open()) {
        outFile << acc << "\n";
        outFile << pass << "\n";
        outFile << balance << "\n";
        outFile << name << "\n";
        outFile.close();
    } else {
        std::cout << "Unable to open file for writing.\n";
    }
}

void Account::loadData() {
    std::ifstream inFile("account_data.txt");
    if (inFile.is_open()) {
        inFile >> acc;
        inFile >> pass;
        inFile >> balance;
        inFile >> name;
        inFile.close();
    } else {
        std::cout << "Unable to open file for reading.\n";
    }
}

int main() {
    Account a;
    a.start();
    a.loadData();

    std::cout << "\n\t\tWelcome TO Sasta Bank\n";

    char x;
    do {
        std::cout << "\nCHOOSE Option from the given menu:\n";
        std::cout << "1: Create Account (Ignore if already created)\n";
        std::cout << "2: Login (necessary to use other services)\n";
        std::cout << "Enter Your Choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                a.signup();
                break;
            case 2:
                a.login();
                char x;
                do {
                    std::cout << "\nCHOOSE Option from the given menu:\n";
                    std::cout << "1: Withdraw\n";
                    std::cout << "2: Deposit\n";
                    std::cout << "3: Details\n";
                    std::cout << "4: Exit\n";
                    std::cout << "Enter Your Choice: ";
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                            a.withdraw();
                            break;
                        case 2:
                            a.deposit();
                            break;
                        case 3:
                            a.details();
                            break;
                        case 4:
                            return 0;
                        default:
                            std::cout << "\nInvalid Choice. Please try again.\n";
                    }
                    std::cout << "\nWant to continue? [y/n]: ";
                    std::cin >> x;
                } while (x == 'y' || x == 'Y');
                break;
            default:
                std::cout << "\nInvalid Choice. Please try again.\n";
        }
        std::cout << "\nWant to continue? [y/n]: ";
        std::cin >> x;
    } while (x == 'y' || x == 'Y');

    return 0;
}

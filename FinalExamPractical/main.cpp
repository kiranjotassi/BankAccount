/*
Kiranjot Assi <assik@sherdidancollege.ca>
----------------------------------------------------------------------
 */

/* 
 * File:   main.cpp
 * Author: Kiranjot Assi <assik@sherdidancollege.ca>
 *
 * Created on December 11, 2019, 4:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

int rand();

class BasicAccount {
protected:
    int accountNumber;
    float tranactionFee;
    float overLimitFee;
    float balance;
    vector<float> transactions;

public:

    BasicAccount(int accountNumber) {
        this->accountNumber = accountNumber;
    }
    virtual void addTransaction(float amount) = 0;
    virtual void setBalance(float balance) = 0;
    virtual float getBalance() = 0;

    ~BasicAccount() {
    };
};

class CheckingAccount : public BasicAccount {
public:

    CheckingAccount(int accountNumber) :
    BasicAccount(accountNumber) {
        this->tranactionFee = 0.10;
        this->overLimitFee = 5.0;
    }

    ~CheckingAccount() {
    };

    float getOverLimitFee() {
        return overLimitFee;
    }

    void setOverLimitFee(float overLimitFee) {
        this->overLimitFee = overLimitFee;
    }

    float getTranactionFee() {
        return tranactionFee;
    }

    void setTranactionFee(float tranactionFee) {
        this->tranactionFee = tranactionFee;
    }

    void setBalance(float balance) {
        this->balance += balance;
    }

    float getBalance() {
        return (this->balance);
    }
};

int main() {

    int randAccountNumber = rand() % 11 + 10100;

    int randAccountBalance = rand() % 100 + 10;
    
    double randTransaction;



    //BasicAccount account1;
    //account1.setBalance(randAccountBalance);

    //shows account number and balance
    printf("Setting checking account number %d.", randAccountNumber);
    printf("\nOpening balance:\t%d", randAccountBalance);
    printf("\nTransactions: \n");


    //random transaction generator
    for (int i = 0; i <= 9; i++) {
        randTransaction = rand() % 600 - 300;
        printf("\t\t%f\n", randTransaction);
    }
    if(randTransaction<0){
          randAccountBalance =randAccountBalance-(randTransaction);
          printf("\t\t-0.10");
        }else{
            randAccountBalance -= randTransaction;
        }
    printf("End balance: \t%d", randAccountBalance);

}
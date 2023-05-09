#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer
{
    // variables to store user information
private:
    string name;
    long number;
    string address;

public:
    Customer();
    string get_name();
    string get_address();
    long get_number();
};
#endif
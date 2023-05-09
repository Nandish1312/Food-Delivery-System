#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

Customer::Customer()
{
    name = "";
    address = "";
    number = '0';
}

string Customer::get_name()
{
    cout << "Enter name:";
    getline(cin, name);
    return name;
}

long Customer::get_number()
{
    cout << "\nEnter phone number:";
    cin >> number;
    cin.ignore();
    return number;
}

string Customer::get_address()
{
    cout << "\nEnter Address:";
    getline(cin, address);
    return address;
}
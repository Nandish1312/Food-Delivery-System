#include <iostream>
#include <string>
#include "Bill.h"
#include "Restaurants.h"
#include "Customer.h"
#include <unistd.h>
using namespace std;

Bill::Bill()
{
    total = 0.0;
}

// function to get the total amount to be paid
void Bill::get_total(Restaurants ob)
{
    for (int i = 0; i < ob.cart_amount.size(); i++)
    {
        total = total + (ob.cart_amount[i] * ob.quan[i]);
    }
}

// function to display the final bill
void Bill::display_bill(float discount, string name, long number, string address)
{
    system("clear");
    cout << "                                         FINAL BILL\n";
    cout << "\n"
         << name << " your bill amount is: $" << total << "\n";
    cout << "Discount is: $" << discount << ".\n";
    cout << "Net amount to pay: $" << total - discount << "\n";
    cout << "Your account is linked to the phone number:" << number;
    cout << " and will be delivered to the address " << address << "\n";
    cout << "\n"
         << "Enjoy your meal!\n";
}
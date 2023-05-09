#ifndef BILL_H
#define BILL_H
#include <iostream>
#include <string>
#include "Restaurants.h"
using namespace std;

class Bill
{
public:
    Bill();
    // variable for total amount to be paid
    float total;
    void get_total(Restaurants ob);
    void display_bill(float discount, string name, long number, string address);
};
#endif
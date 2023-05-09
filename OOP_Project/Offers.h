#ifndef OFFERS_H
#define OFFERS_H
#include <iostream>
#include <string>
#include "Restaurants.h"
using namespace std;

// class for entering all the variables to be used in offers.cpp

class Offers
{

public:
    // string offer_name; for having stored the different offers

    int offer_name;
    Offers();

    //  int default_amount; float discounted_amount; for getting the amounts from the final bill

    int default_amount;
    float discounted_amount;

    // 2 functions named get_offers (to get the offer according to the bill) and display_offers (to display the different offers)

    void get_offers(float default_amount);
    void display_offers();
};
#endif
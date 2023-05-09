#include <iostream>
#include <string>
#include "Offers.h"
#include <unistd.h>
using namespace std;

Offers::Offers()

// initializing the variables diclared in offers.h

{
    offer_name = 0;
    discounted_amount = 0.0;
}

// calling the first function display_offers

void Offers::display_offers()
{
    int option = 0;
    // displaying the different offers and their respective conditions

    cout << "             \nOur list of offers are as follows:\n";
    cout << "1.   HELLO25  (get upto $2 off)     *valid on orders above $5\n";
    cout << "2.   HELLO50  (get upto $3.5 off)   *valid on orders above $8\n";
    cout << "3.   HELLO100 (get upto $5 off)     *valid on orders above $12\n";
    cout << "\n";
}

// calling the second function getting the offers according to the bill

void Offers::get_offers(float default_amount)
{
    cout << "Your total is: $" << default_amount << "\n";

    // first if statement for printing a statement with wrong inputs

    do
    {
        cout << "Enter a coupon. Enter 0 when done:";
        cin >> offer_name;
        if (offer_name != 0)
        {
            if (offer_name != 1 && offer_name != 2 && offer_name != 3)
            {
                cout << "Enter the correct option number" << endl;
                // offer_name = ;
                // get_offers(default_amount);
                continue;
            }

            // conditional statments below with different offers and their respective outputs

            // conditional statments below with billing amount greater thasn $4
            if (offer_name == 1 && default_amount >= 5.0)
            {
                discounted_amount = ((25 * default_amount) / 100);
                if (discounted_amount > 2.0)
                    discounted_amount = 2.0;
                break;
            }

            // conditional statments below with billing amount greater thasn $6

            else if (offer_name == 2 && default_amount >= 8.0)
            {
                discounted_amount = ((35 * default_amount) / 100);
                if (discounted_amount > 3.50)
                    discounted_amount = 3.50;
                break;
            }

            // conditional statments below with billing amount greater thasn $8

            else if (offer_name == 3 && default_amount >= 12.0)
            {
                discounted_amount = ((50 * default_amount) / 100);
                if (discounted_amount > 5.0)
                    discounted_amount = 5.0;
                break;
            }
            if (discounted_amount == 0.0)
            {
                cout << "\nNo discount applied since offer condition was not met. Please apply a valid offer!\n";
                cout << "\n";
                get_offers(default_amount);
            }
        }
    } while (offer_name != 0);
}
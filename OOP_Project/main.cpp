#include <iostream>
#include <string>
#include "Customer.h"
#include "Restaurants.h"
#include "Offers.h"
#include "Bill.h"
#include <unistd.h>
#include <stdlib.h>
using namespace std;

// function to print the main menu
int main_menu()
{
    int option = 0;
    cout << "\nEnter 1 to view current offers\n";
    cout << "Enter 2 to select a restaurant\n";
    cout << "Enter 3 to view and edit your cart\n";
    cout << "Enter 4 to view your Bill \n";
    cout << "Enter 5 to exit\n";
    cout << "\nYour option:";
    cin >> option;
    if (option < 1 || option > 5)
    {
        cout << "Please enter the correct option!";
    }
    return option;
}

int main()
{
    cout << "                    Welcome to Online Food Ordering System!      \n";
    // objects to be used
    Customer ob;
    Restaurants obj;
    Dominoes dom;
    McDonalds mc;
    Tacobell taco;
    Offers ob4;
    Bill ob5;
    int option = 0;
    cout << "Enter customer Details\n";
    // functions to get information about the customer
    string name = ob.get_name();
    long number = ob.get_number();
    string address = ob.get_address();
    // command to clear the terminal
    //  system("clear");
    do
    {
        option = main_menu();
        // to display the offers
        if (option == 1)
        {
            system("clear");
            ob4.display_offers();
        }
        // for adding to the menu and cart
        if (option == 2)
        {
            int decision = obj.display_restaurants();
            if (decision == 0)
            {
                while (decision == 0)
                    decision = obj.display_restaurants();
            }
            if (decision == 1)
            {
                dom.getd_menu_and_amounts();
                obj.get_data(dom.menu, dom.item_amounts, dom.restaurant_name);
            }
            if (decision == 2)
            {
                mc.getm_menu_and_amounts();
                obj.get_data(mc.menu, mc.item_amounts, mc.restaurant_name);
            }
            if (decision == 3)
            {
                taco.gett_menu_and_amounts();
                obj.get_data(taco.menu, taco.item_amounts, taco.restaurant_name);
            }

            obj.display_menu();
            obj.add_to_cart();
        }
        // for viewing and editing the cart
        if (option == 3)
        {
            char s = ' ';
            if (obj.cart.size() == 0)
            {
                cout << "Your cart is Empty! Please select a restaurant and add some items\n";
                sleep(3);
            }
            else
            {
                obj.display_cart();
                cout << "\nDo you want to edit your cart? (y or n)\n";
                cin >> s;
                while (s != 'y' && s != 'n')
                {
                    cin >> s;
                    cout << "\nPlease input a valid option!\n";
                }
                if (s == 'y')
                    obj.edit_cart();
                if (s == 'n')
                {
                    cout << "Returning to main menu..\n";
                    sleep(2);
                    system("clear");
                }
            }
        }
        // for displaying the final bill
        if (option == 4)
        {
            if (obj.cart.size() == 0)
            {
                cout << "Your cart is Empty! Please select a restaurant and add some items\n";
                sleep(3);
            }
            else
            {
                char h = ' ';
                obj.display_cart();
                if (ob5.total == 0.0)
                    ob5.get_total(obj);
                ob4.display_offers();
                if (ob4.discounted_amount == 0.0)
                    ob4.get_offers(ob5.total);
                cout << "New total after discount: $" << ob5.total - ob4.discounted_amount << "\n";
                cout << "\nPayment will be via Cash on Delivery. Confirm Order? (y or n)\n";
                cout << "Your choice:";
                while (h != 'y' && h != 'n')
                {
                    cin >> h;
                    cout << "\nPlease input a valid option!\n";
                }
                if (h == 'y')
                {
                    ob5.display_bill(ob4.discounted_amount, name, number, address);
                    exit(0);
                }
                else
                {
                    system("clear");
                    cout << "\nOrder cancelled! You can edit your cart,add more items or exit from the main menu.\n";
                }
            }
        }
    } while (option != 5);
    // freeing memory of all the data structures used in the program
    free(obj.quan);
    obj.cart.clear();
    obj.cart_amount.clear();
    obj.menu.clear();
    obj.item_amounts.clear();
}

#ifndef RESTAURANTS_H
#define RESTAURANTS_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Restaurants
{
public:
    // vector for storing menu for specific restaurant
    vector<string> menu;
    // vector for storing amount for the menu items
    vector<float> item_amounts;
    // vector for storing items added to the cart
    vector<string> cart;
    // vector for storing amount of items added to the cart
    vector<float> cart_amount;
    // pointer to store quantities of cart items
    int *quan;
    // variable to store length of quan pointer
    int count = 1;
    string restaurant_name;
    Restaurants();
    int display_restaurants();
    void display_menu();
    void add_to_cart();
    void get_data(vector<string> menu_temp, vector<float> item_amounts_temp, string rest_name);
    void display_cart();
    void edit_cart();
};

class Dominoes : public Restaurants
{
public:
    void getd_menu_and_amounts();
};

class McDonalds : public Restaurants
{
public:
    void getm_menu_and_amounts();
};

class Tacobell : public Restaurants
{
public:
    void gett_menu_and_amounts();
};
#endif
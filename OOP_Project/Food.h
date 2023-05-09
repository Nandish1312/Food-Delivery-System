#ifndef FOOD_H
#define FOOD_H
#include <vector>
#include <iostream>
#include <string>
#include "Restaurants.h"
using namespace std;

class Food : public Restaurants
{
private:
    vector<string> menu;
    vector<float> item_amounts;

public:
    vector<string> cart;
    vector<float> cart_amount;
    Food *work;
    void get_food_names(Food ob);
    void get_menu_items();
    void display_cart();
    int quantity[10] = {0};
};
#endif
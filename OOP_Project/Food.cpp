#include <iostream>
#include <string>
#include "Food.h"
#include "Restaurants.h"
using namespace std;

void Food::get_menu_items() {
    cout<<"Enter your choice to add it to your cart. Enter 0 when done:\n";
    int option=0;
    int temp=0;
    int i=0;
    do {
        cin>>option;
        if(option!=0) {
            temp = option-1;
            cart.push_back(menu[temp]);
            cout<<"Enter quantity:";
            cin>>quantity[i];
            cart_amount.push_back(item_amounts[temp]);
            cout<<"Added\n";
            i++;
        }
    }
    while (option!=0);
    system("clear");
}

void Food::display_cart() {
    system("clear");
    if(cart.size() == 0)
        cout<<"Your cart is Empty! Please select a restaurant and add some items\n";
    else {
        cout<<"The cart is:\n";
        for(int i=0;i<cart.size();i++) {
            cout<<cart[i]<<"    quantity:"<<quantity[i]<<"\n";
        }
        cout<<"\n";
    }

}
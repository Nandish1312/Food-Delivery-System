#include <iostream>
#include <string>
#include "Restaurants.h"
#include <unistd.h>
using namespace std;

Restaurants::Restaurants()
{
    restaurant_name = "";
    quan = (int *)malloc(sizeof(int) * count);
}

// funciton to display the list of restaurants
int Restaurants::display_restaurants()
{
    char s;
    if (restaurant_name != "")
    {
        cout << "\nYou can only order from a single restaurant at a time!\n";
        cout << "If you want to order from another restaurant, empty your cart and choose it from the menu!\n";
        sleep(8);
        if (restaurant_name == "Dominoes")
            return 1;
        if (restaurant_name == "McDonalds")
            return 2;
        else
            return 3;
    }
    int option = 0;
    system("clear");
    cout << "             \nOur list of Restaurant's is as follows:     \n";
    cout << "1.   Dominoes\n";
    cout << "2.   McDonalds\n";
    cout << "3.   Tacobell\n";
    cout << "Enter an option to continue:";
    cin >> option;
    if (option > 3 || option < 1)
    {
        cout << "Please enter the correct option!\n";
        sleep(1);
        return 0;
    }
    return option;
}

// funciton to assign the proper values to the vectors
void Dominoes::getd_menu_and_amounts()
{
    restaurant_name = "Dominoes";
    menu.push_back("Margherita Pizza");
    menu.push_back("Chicken Dominator Pizza");
    menu.push_back("Garlic Bread");
    menu.push_back("Choco Lava Cake");
    item_amounts.push_back(5.0);
    item_amounts.push_back(8.0);
    item_amounts.push_back(2.75);
    item_amounts.push_back(2.25);
}

// function to assign the proper values to the vectors
void McDonalds::getm_menu_and_amounts()
{
    restaurant_name = "McDonalds";
    menu.push_back("McSpicy Chicken");
    menu.push_back("Mc Veggie");
    menu.push_back("Fillet-o-Fish");
    menu.push_back("Happy Meal");
    item_amounts.push_back(2.35);
    item_amounts.push_back(1.5);
    item_amounts.push_back(4.0);
    item_amounts.push_back(3.0);
}

// funciton to assign the proper values to the vectors
void Tacobell::gett_menu_and_amounts()
{
    restaurant_name = "Tacobell";
    menu.push_back("Soft/Crunchy Taco");
    menu.push_back("Chicken Supreme Taco");
    menu.push_back("Cheesy Double Taco");
    menu.push_back("Veggie Taco");
    item_amounts.push_back(1.79);
    item_amounts.push_back(4.0);
    item_amounts.push_back(3.0);
    item_amounts.push_back(2.0);
}

// function to copy the data into main Restaurant object
void Restaurants::get_data(vector<string> menu_temp, vector<float> item_amounts_temp, string rest_name)
{
    for (int i = 0; i < 4; i++)
    {
        restaurant_name = rest_name;
        string temp = menu_temp[i];
        float temp2 = item_amounts_temp[i];
        menu.push_back(temp);
        item_amounts.push_back(temp2);
    }
}

// function to display the menu for the specific restaurant
void Restaurants::display_menu()
{
    system("clear");
    cout << "             \nList of Food items for " << restaurant_name << " are:\n";
    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        cout << (i + 1) << ". " << menu[i] << "     $" << item_amounts[i] << "\n";
    }
}

// function to add to the cart
void Restaurants::add_to_cart()
{
    cout << "\nEnter your choice to add it to your cart. Enter 0 when done:\n";
    int option = 0;
    int temp = 0;
    do
    {
        cout << "\nYour choice:";
        cin >> option;
        if (option < 0 || option > 4)
        {
            cout << "Please enter an option from the menu!\n";
            sleep(1);
            continue;
        }
        if (option != 0)
        {
            temp = option - 1;
            cout << "Enter quantity:";
            quan = (int *)realloc(quan, sizeof(int) * count);
            if (cart.size() == 0)
                count = 0;
            scanf("%d", &quan[count]);
            cart.push_back(menu[temp]);
            cart_amount.push_back(item_amounts[temp]);
            cout << quan[count] << " x " << cart[count] << " added to cart.\n";
            count++;
        }
    } while (option != 0);
    system("clear");
}

// function to display the cart
void Restaurants::display_cart()
{
    system("clear");
    cout << "Your cart has " << cart.size() << " items:\n";
    for (int i = 0; i < cart.size(); i++)
    {
        cout << i + 1 << ". " << cart[i] << "    quantity:" << quan[i] << "\n";
    }
}

// function to edit the cart
void Restaurants::edit_cart()
{
    int option2;
    int temp2 = 0;
    do
    {
        system("clear");
        display_cart();
        cout << "\nEnter the Serial Number of the item you wish to delete. Enter 0 when done\n";
        cout << "\nYour choice:";
        cin >> option2;
        if (option2 < 0 || option2 > 4)
        {
            cout << "Please enter an option from the menu!\n";
            sleep(1);
            continue;
        }
        if (option2 != 0)
        {
            if (cart.size() == 1)
            {
                cart.clear();
                cart_amount.clear();
                restaurant_name = "";
                quan[0] = 0;
                cout << "Deleted\n";
                cout << "Cart now empty!";
                sleep(2);
                option2 = 0;
                continue;
            }
            temp2 = option2 - 1;
            cout << cart[temp2] << " deleted from the cart.\n";
            sleep(3);
            cart_amount.erase(cart_amount.begin() + temp2);
            cart.erase(cart.begin() + temp2);
            for (int i = temp2; i < count - 1; i++)
            {
                quan[i] = quan[i + 1];
            }
            quan = (int *)realloc(quan, (count - 1) * sizeof(int));
            count--;
        }
    } while (option2 != 0);
    system("clear");
}
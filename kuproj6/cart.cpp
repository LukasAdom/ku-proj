#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <random>
#include <ranges>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <math.h>

#define __FLT_EVAL_METHOD__ 0

struct item{
    std::string name;
    float_t price;
    uint16_t left;

    void createItem(const std::string itemName, const float_t itemPrice, const uint16_t itemLeft){
        name = itemName;
        price = itemPrice;
        left = itemLeft;
    }
};

struct cart{
    std::string name;
    float_t price;
    uint16_t left;

    void addCart(const std::string itemName, const float_t itemPrice, const uint16_t itemsLeft){
        name = itemName;
        price = itemPrice;
        left = itemsLeft;
    }
};
const uint16_t MAX_MENU = 12u;

uint16_t select;
auto fullPrice = std::make_unique<float_t>(0.0f);
auto num = std::make_unique<uint16_t>(0u);
auto amt = std::make_unique<uint16_t>(0u);

std::vector<std::string> itemNames {"Risotto","Miso Soup","Lomo Saltado","Burrito","Chicken Biryani","Pancakes","Pizza","Burger","Tacos","Croissants","Lasagna","Caesar Salad",
"Sushi","Strawberry Shortcake","Strawberry Shortcake","Sushi Platter","Fajitas","Mango Sticky Rice","Cinnamon Rolls","Eggs Benedict","Creme Brulee","Ratatouille"};

std::vector<item> displayItemVector;
std::vector<cart> purchasedItemVector;

cart purchased[MAX_MENU];
item displayedItem[MAX_MENU];

void displayMenu(){
    for(auto i {0uz}; i < displayItemVector.size(); ++i){
        if(displayItemVector[i].left <= 0u){
            std::cout << std::setw(42) << std::format("{:<10} {:.2f} EUR ({})", " " + std::to_string(i + 1) + ". " + displayItemVector[i].name + " ",
            displayItemVector[i].price, "ISPARDUOTA");
        } else {
            std::cout << std::setw(42) << std::format("{:<10} {:.2f} EUR ({})", " " + std::to_string(i + 1) + ". " + displayItemVector[i].name + " ",
            displayItemVector[i].price, displayItemVector[i].left);
        }
        if((i + 1u) % 3u == 0u){
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void addToCart(){

    int16_t pos = -1;

    std::cout << "Prekes numeris: ";
    std::cin >> *num;

    for(;;){
        if(displayItemVector[*num-1].left <= 0){
            std::cout << "Error: The item is no longer available";
            break;
        }
    std::cout << "Kiekis: ";
    std::cin >> *amt;

        if(*amt <= displayItemVector[*num-1].left){
                purchased[pos + 1u].addCart(displayItemVector[*num-1u].name, displayItemVector[*num-1u].price, displayItemVector[*num-1].left);
                displayItemVector[*num-1u].left -= *amt;
                purchasedItemVector.push_back(purchased[pos + 1u]); // Adds new struct into another "purchased" vector, for later use when needing to view the cart.
            break;
        }
        std::cout << "Error: The amount is larger than the item's quantity\n";
    }
}

void viewCart(){
    if(purchasedItemVector.size() > 0){
        fullPrice.reset(new float_t(0.0f));

        for(auto i{0uz}; i < purchasedItemVector.size(); ++i){
            std::cout << std::setprecision(2) << std::fixed << i+1 << ". " << purchasedItemVector[i].name << " " << purchasedItemVector[i].left << " x " 
            << purchasedItemVector[i].price << " = " 
            << purchasedItemVector[i].left * purchasedItemVector[i].price << "\n";

            *fullPrice += (purchasedItemVector[i].left * purchasedItemVector[i].price);
        }
        std::cout << std::setprecision(2) << std::fixed << "Is viso: " << *fullPrice << " EUR\n";
    } else { std::cout << "Error: Empty cart.\n"; }
}

void deleteCart(){
    viewCart();
    if(purchasedItemVector.size() > 0){
        std::cout << "Select what to remove: ";
        std::cin >> *num;
        for(;;){
            std::cout << "Select amount: ";
            std::cin >> *amt;
            if(*amt <= purchasedItemVector[*num - 1u].left){
                purchasedItemVector[*num - 1u].left -= *amt;

                for(auto i{0uz}; i < displayItemVector.size(); ++i){
                    if(purchasedItemVector[*num - 1].name == displayItemVector[i].name){
                        displayItemVector[i].left += *amt; // Removing the item from cart adds the item back into the menu.
                    }
                }

                if(purchasedItemVector[*num - 1u].left <= 0u){
                    purchasedItemVector.erase(purchasedItemVector.begin() + (*num - 1u));
                }
            } else { std::cout << "Error: The amount is larger than the amount of quantity left..\n"; continue;}
            break;
        }
    }
}

void buyCart(){
    if(purchasedItemVector.size() > 0){
        viewCart();
        purchasedItemVector.clear();

        std::cout << "Aciu, kad pirkote!\n";
        
    } else { std::cout << "Error: Empty cart.\n"; }
}

int main(){

        if(MAX_MENU >= itemNames.size()){
            std::cout << "Error: MAX_MENU is larger than the itemNames vector!\n";
            return 0;
        }

    auto itemInit = [](){ // Initializes all of the names, prices and quantities. And all items have their prices and quantities randomly generated.
    
        std::random_device rd;
        std::ranges::shuffle(itemNames,rd);
        std::uniform_real_distribution<float_t> dist(1.0f,9.9f);
        std::uniform_int_distribution<uint32_t> lDist(0u,9u);

        for(auto i {0uz}; i < MAX_MENU; ++i){
            displayedItem[i].createItem(itemNames.front(), dist(rd), lDist(rd));
            displayItemVector.push_back(displayedItem[i]);
            itemNames.erase(itemNames.begin()); // Inserts the struct into a vector, for later.
        }
    };
    itemInit();

    std::cout << "\n1. Rodyti parduotuve  2. Deti i krepseli  3. Salinti is krepselio\n";
    std::cout << "4. Rodyti krepseli    5. Apmoketi         6. Iseiti\n";
    for(;;){

        std::cout << "\nPasirinkite (1-6): ";
        std::cin >> select;
        switch(select){

            case 1:
                displayMenu();
            continue;

            case 2:
                addToCart();
            continue;

            case 3:
                deleteCart();
            continue;

            case 4:
                viewCart();
            continue;

            case 5:
                buyCart();
            continue;

            case 6:
            break;

            default:
            std::cout << "Error: Wrong input.\n";
            continue;;

        }
        break;
    }

    return 0;
}
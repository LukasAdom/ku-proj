#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main(){
    uint16_t men;

    uint16_t low = 1u;
    uint16_t max = 12u;

    cout << "Iveskite menesio numeri: ";
    cin >> men;

    men = clamp(men, low, max);

    if(men == 12u || (men >= 1u && men <= 2u)){
        cout << "Ziema\n";
    } else if (men >= 3u && men <= 5u){
        cout << "Pavasaris\n";
    } else if(men >= 6u && men <= 8u){
        cout << "Vasara\n";
    } else if(men >= 9u && men <= 11u){
        cout << "Ruduo\n";
    }
    
    return 0;
}
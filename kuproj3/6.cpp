#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
    uint16_t men;

    cout << "Iveskite menesio numeri: ";
    cin >> men;

    if(men > 12u){
        men = 12u;
    }

    if(men != 0u && (men == 12u || (men >= 1u && men <= 2u))){
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

#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

// Zodziu cia skirta kad leistu zmogui rasyti Y/y arba N/n
bool checkstr(string& str1, string& str2){
    if (str1.length() != str2.length()){
        return false;
    }

    for(uint8_t i = 0u; i<str1.length(); i++){
        if(tolower(str1[i]) != tolower(str2[i])){
            return false;
        }
    }
    return true;
}


int main(){
    string YorN = "Y"; //kazkodel taip reikia daryti kitaip c++ matys "Y" kaip char?
    uint16_t age;
    string patikra;
    string VIP;
    string bilietas;
    
    cout << "Koks jusu amzius?\n";
    cin >> age;

    cin.ignore();

    cout << "perejot saugimo patikra? (Y/N)\n";
    cin >> patikra;

    cout << "VIP? (Y/N)\n";
    cin >> VIP;

    cout << "Turite bilieta? (Y/N)\n";
    cin >> bilietas;

    if(age >= 18u && (checkstr(patikra, YorN) || checkstr(VIP, YorN)) && checkstr(bilietas, YorN)){
        cout << "Okay, galite ieiti :)\n";
    } else{
        cout << "No, negalite ieiti :(\n";
    }

    return 0;    
}
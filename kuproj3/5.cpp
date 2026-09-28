#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

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
    string YorNo = "Y";
    uint16_t age;
    string pazymejimas;

    cout << "Koks jusu amzius?\n";
    cin >> age;

    cin.ignore();

    cout << "Ar turite pazymejima? (Y/N)\n";
    cin >> pazymejimas;

    if(age >= 18u){
        if(checkstr(pazymejimas, YorNo)){
            cout << "Gali vairuoti\n";
            return 0;
        }
        cout << "Reikia pazymejimo\n";

    }else{
        cout << "Per jaunas vairuoti\n";
    }

    return 0;
}
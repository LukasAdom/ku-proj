#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
   uint16_t suma;
   uint16_t taskai;
   
   cout << "Kokia pirkimo suma?\n";
   cin >> suma;

   cout << "Kiek turite lojalumo tasku?\n";
   cin >> taskai;

    if(suma >= 50u || taskai >= 100u){
        cout << "Nuolaida taikoma :)\n";
    } else {
        cout << "Nuolaida netaikoma :(\n";
    }

    return 0;
}
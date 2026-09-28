#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
   uint16_t suma;
    uint16_t privilege;
   
   cout << "Kokia jusu krepselio suma?\n";
    cin >> suma;

    if(suma >= 100u){
        privilege = 2u;

        cout << "Papildomai 10% nuolaida sekanciam pirkiniui\n";
    }

    if(suma >= 50u || privilege >= 2u){
        privilege = 1u;
        cout << "Dovana prie uzsakymo\n";
    }

   if(suma >= 30 || (privilege >= 1 && privilege <= 2)){
    cout << "Nemokamas pristatymas\n";
   }

    return 0;
}
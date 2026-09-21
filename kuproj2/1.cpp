#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
    char8_t marsrutas;
    uint16_t atstumas;

    cin >> marsrutas;
    uint16_t imarsrutas = marsrutas - '0';

    switch(imarsrutas){
        case 27: // K
            atstumas = 100u;
        break;

        case 28: // L
            atstumas = 300u;
        break;

        case 38: // V
            atstumas = 150u;
        break;

        default:
            cout << "neteisingas marsutras >:(\n";
            atstumas = 0u;
        break;

    }
        cout << "Jusu atsumas yra " << atstumas << "KM" << endl;

    return 0;
}
#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
    char marsrutas;
    uint16_t atstumas;

    cin >> marsrutas;

    switch(marsrutas){
        case 'K': // K
            atstumas = 100u;
        break;

        case 'L': // L
            atstumas = 300u;
        break;

        case 'V': // V
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
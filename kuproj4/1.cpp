
#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
    uint16_t n;
    uint16_t result;

    cout << "iveskite N: ";
    cin >> n;

    result = (n * (n + 1u))/2u;
    cout << "Suma nuo 1 iki " << n << ": " << result << endl;

    return 0;    
}
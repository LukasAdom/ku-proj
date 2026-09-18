#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main() {
uint32_t x1, y1, x2, y2;
    cout << "Iveskite pirmo tasko koordinates (x1 y1): ";
        cin >> x1 >> y1;

    cout << "Iveskite antro tasko koordinates (x2 y2): ";
        cin >> x2 >> y2;

    uint32_t atstumas = sqrt(pow(x2 - x1, 2u) + pow(y2 + y1, 2u));
        cout << "Atstumas tarp tasku yra: " << atstumas << endl;

    return 0;
}
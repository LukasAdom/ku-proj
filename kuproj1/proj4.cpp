#include "iostream"
using namespace std

int main() {
int x1, y1, x2, y2;
    cout << "Iveskite pirmo tasko koordinates (x1 y1): "
    cin >> x1 >> y1;
    std::cout << "Iveskite antro tasko koordinates (x2 y2): ";
    cin >> x2 >> y2
    int atstumas = sqrt(pow(x2 - x1, 2) + pow(y2 + y1, 2));
    std::cout << "Atstumas tarp tasku yra: " << atstumas << std::endl;
    return 0
}
#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

string vardas;
string pavarde;

int main() {
    cout << "Iveskite savo varda:";
    cin >> vardas;

    cout << "Iveskite savo pavarde:";
    cin >> pavarde;

    cout << "Sveiki, " << vardas << " " << pavarde << endl;

    return 0;
}

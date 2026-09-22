#include<iostream>
#include <cstdint>
#include <cfloat>
#include <cmath>

#define FLT_EVAL_METHOD 0
using namespace std;

float_t svoris;
float_t ugis;

int main(){
float_t KMI;

cout << "iveskite svori (kg): ";
    cin >> svoris;

cout << "iveskite ugi (m): ";
    cin >> ugis;

KMI = (svoris/pow(ugis, 2u));
    cout << "Jusu KMI yra: " << KMI;

return 0;
}
#include<iostream>
#include <cstdint>
using namespace std;

uint32_t mins;
uint32_t sec;

int main(){
uint32_t time;

cout << "iveskite sekundes:";
    cin >> time;

    mins = time/60u;
    sec = time%60u;

    cout << mins << " mins " << sec << " sec";
return 0;
}
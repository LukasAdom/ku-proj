#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <uchar.h>
using namespace std;

int main(){
   uint16_t age;
   
   cout << "Koks jusu amzius?\n";
   cin >> age;

   if(age >= 18u){
    cout << "Jus esate pilnametis\n";
   } else{
    cout << "Jus nesate pilnametis\n";    
   }

    return 0;
}
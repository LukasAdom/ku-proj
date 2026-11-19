#include <iostream>
#include <cstdint>

int16_t a,b,c;

bool trikampis(const int16_t a, const int16_t b, const int16_t c){
    if(a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)){
        return true;
    } else { return false; }
}

int main(){

    std::cout << "iveskite a, b ir c: ";
    std::cin >> a >> b >> c;

    std::cout << "Is duotu atkarpu, trikampio sudarymas yra: " << std::boolalpha << trikampis(a,b,c);

    return 0;    
}
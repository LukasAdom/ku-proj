#include <iostream>
#include <cstdint>
#include <cmath>

int16_t a,b,c;

void sqrtLygtis(const int16_t a, const int16_t b, const int16_t c){
    if(a == 0){
        std::cout << "Nera lygties";
        return;
    }

    // Diskriminantas //
    float_t d = b * b - 4 * a * c;

    if(d > 0){
        float_t x1 = (-b + std::sqrt(d)) / (2 * a);
        float_t x2 = (-b - std::sqrt(d)) / (2 * a);

        std::cout << "x1 = " << x1 << "\n";
        std::cout << "x2 = " << x2;
        
    } else if (d == 0){
        float_t x1 = -b / (2 * a);

        std::cout << "x1 = " << x1 << "\n";
        std::cout << "x2: Neegzistuoja";

    } else { std::cout << "Neturi realiu sprendiniu."; }
    
}

int main(){

    std::cout << "iveskite a, b ir c: \n";
    std::cin >> a >> b >> c;

    sqrtLygtis(a,b,c);

    return 0;    
}
#include <iostream>
#include <cstdint>
#include <vector>
#include <math.h>

using namespace std;

uint16_t N;
uint64_t a{1u}, b{1u}, fib;

uint64_t factorial(const uint16_t n){
    uint64_t result = 1u;
    cout << __func__ << '(' << n << "): ";

    if(n<1u){
        return result;
    }
    for(auto i{2uz}; i<=n; i++){
        result *= i;
    }    
    return result;
}

uint64_t fibonacci(const uint16_t n){
    cout << __func__ << '(' << n << "): ";

    struct fibStruct {
        static uint64_t fib(const uint16_t u_){
            if(u_ <= 1u){
                return u_;
            }
            return fib(u_ - 1) + fib(u_ - 2);
        }
    };
    return fibStruct::fib(n);
}


int main(){

    cin >> N;
        cout << factorial(N) << endl;
        cout << factorial(0u) << endl;

    cin >> N;
        cout << fibonacci(N) << endl;
        cout << fibonacci(0u) << endl;
    return 0;
}
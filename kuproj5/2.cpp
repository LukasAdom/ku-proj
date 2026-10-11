#include <iostream>
#include <cstdint>
#include <vector>
#include <math.h>

using namespace std;

uint16_t N;
uint64_t a{1}, b{1}, fib;

uint64_t factorial(const uint16_t n){
    uint64_t result = 1;
    cout << __func__ << '(' << n << "): ";

    if(n<1){
        return result;
    }
    for(auto i{2uz}; i<=n; i++){
        result *= i;
    }    
    return result;
}

uint64_t fibonacci(const uint16_t n){
    cout << __func__ << '(' << n << "): ";
    if(n <= 1){
        return n;
    }
    for(auto i{2uz}; i<n; ++i){
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}


int main(){

    cin >> N;
        cout << factorial(N) << endl;
        cout << factorial(0) << endl;

    cin >> N;
        cout << fibonacci(N) << endl;
        cout << fibonacci(0) << endl;
    return 0;
}
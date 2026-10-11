#include <iostream>
#include <cstdint>

using namespace std;

uint16_t N;

uint32_t factorial(const uint16_t n){
    cout << __func__ << '(' << n << "): ";

    auto fac = [](const auto& self, const uint16_t f) -> uint32_t {
        if(f<1u){
            return 1u;
        }
        return f * self(self, f-1u);
    };
    return fac(fac,n);
}

uint32_t fibonacci(const uint16_t n){
    cout << __func__ << '(' << n << "): ";

    struct fibStruct {
        static uint32_t fib(const uint16_t u_){
            if(u_ <= 1u){
                return u_;
            }
            return fib(u_ - 1u) + fib(u_ - 2u);
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
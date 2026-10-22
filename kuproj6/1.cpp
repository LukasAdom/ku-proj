#include <iostream>
#include <cstdint>
#include <array>

int32_t data[6] = {4,9,2,9,1,6};
int32_t *tmpp;

int32_t* sum(const int32_t a[], const int32_t n){
    delete tmpp; // Deallocating data before writing
    tmpp = new int32_t;

for(auto i{0uz}; i<n; ++i){
    tmpp += a[i];
}
return tmpp;
}

int main(){

    std::cout << sum(data,6);

    return 0;
}
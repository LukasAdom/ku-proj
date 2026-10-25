#include <iostream>
#include <cstdint>
#include <array>
#include <memory>

int32_t data[6] = {4,9,2,9,1,6};
auto tmpp = std::make_unique<int32_t>(0);
std::unique_ptr<int32_t> sum(const int32_t a[], const int32_t n){

for(auto i{0uz}; i<n; ++i){
    *tmpp += a[i];
}
return std::move(tmpp);
}

int main(){
    std::cout << *sum(data,6);

    return 0;
}
#include <iostream>
#include <cstdint>
#include <array>
#include <stdexcept>

int32_t data[6] = {4,9,2,9,1,6};

int32_t sum(const int32_t a[], const int32_t n){
    std::cout << __func__ << ": ";
    int32_t tmp;

for(auto i{0uz}; i<n; ++i){
        tmp += a[i];
    }
return tmp;
}

int32_t count_value(const int32_t a[], const int32_t n, const int32_t value){
    std::cout << __func__ << "(" << value << "): ";

    for(auto i{0uz}; i<n; ++i){
        if(a[i] == value){
           return i+1;
        }
    }
   std::cout << "Error: Can't find the value. ";
   return 0;
}

bool is_sorted(const int32_t a[], const int32_t n){
    std::cout << __func__ << ": ";

    for(auto i{1uz}; i<n; ++i){
        if(a[i - 1u] > a[i]){
            return false;
        }
    }
    return true;
}

void reverse(int32_t a[], const int32_t n){
    std::cout << __func__ << ": ";

    for(auto i {0uz}; i<n/2; ++i){
        int32_t tmpArr = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmpArr;
    }

    for(auto i {0uz}; i<n; ++i){
        std::cout << a[i] << " ";
    }
}

int main(){
    std::cout << sum(data,6) << "\n";
    std::cout << count_value(data,6,9) << "\n";
    std::cout << std::boolalpha << is_sorted(data,6) << "\n";
    reverse(data,6);

    return 0;
}
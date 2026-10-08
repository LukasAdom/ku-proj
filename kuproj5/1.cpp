#include <iostream>
#include <cstdint>
#include <vector>
#include <math.h>

using namespace std;
#define __FLT_EVAL_METHOD__ 0

int16_t num;
double_t C;

int16_t a,b,c;
int16_t mainNum, minNum, maxNum;

bool is_even(const int16_t n){

    cout << __func__ << '(' << n << "): ";    

    if(!(n%2) == 0){
        return false;
    }
    return true;
}

int16_t maximum(const int16_t a, const int16_t b, const int16_t c){ // Takes 3 numbers, return the largest one
    vector<int16_t> vec = {a,b,c};
    cout << __func__ << '(' << a << ", " << b << ", " << c << "): ";

    for(auto i{0uz}; i + 1 < vec.size(); ++i){
        if(vec[i]>vec[i+1]){
            swap(vec[i],vec[i+1]);
        }
    }
    return vec.back();
}

double_t celsius_to_fahrenheit(const double_t c){
    cout << __func__ << '(' << c << "): ";
    return c*9/5+32;
}

int16_t clamp(const int16_t number, const int16_t min, const int16_t max){
    cout << __func__ << '(' << number << ", " << min << ", " << max << "): ";

    if(number >= max){
        return max;
    } else if(number <= min){
        return min;
    }

    return number;
}

int main(){

    cin >> num;
    cout << boolalpha << is_even(num) << endl;

    cin >> a >> b >> c;
    cout << maximum(a,b,c) << endl;

    cin >> C;
    cout << celsius_to_fahrenheit(C) << endl;

    cin >> mainNum >> minNum >> maxNum;
    cout << clamp(mainNum, minNum, maxNum);

    return 0;
}
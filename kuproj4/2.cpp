#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <array>
#include <cstddef>
using namespace std;

int main(){
    uint16_t N;
    uint16_t result;
    cout << "Irasykite betkoki naturalu skaiciu: ";
        cin >> N;
        cout << "\n";

    for(uint16_t i{1uz}; i<N+1; i++){

        result =  (i%3u + i%5u);
            if (result == 0u) { 
                cout << "FizzBuzz\n";
            continue;
        }

        result = i%3u;
        if(result == 0u){
            cout << "Fizz\n";
            continue;
        } else {
            result = i%5u;
            if(result == 0){
                cout << "Buzz\n";
                continue;
            } 
        }

        cout << i << endl;
    }
    return 0;    
}
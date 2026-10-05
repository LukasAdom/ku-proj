#include <iostream>
#include <cstdint>
#include <cstddef>
using namespace std;

int main(){
    uint16_t N;

    cout << "Irasykite betkoki naturalu skaiciu: ";
        cin >> N;
        cout << "\n";

    for(uint16_t i{1uz}; i<N+1; i++){
        if ((i%3u + i%5u) == 0u) { 
                cout << "FizzBuzz\n";
            continue;
        }

        if(i%3u == 0u){
            cout << "Fizz\n";
        continue;
        } else if(i%5u == 0u){
                cout << "Buzz\n";
            continue;
        } 
            cout << i << endl;
        }  
    return 0;
}
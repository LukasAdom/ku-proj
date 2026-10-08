#include <iostream>
#include <cstdint>
#include <cstddef>
using namespace std;

int main(){
    uint32_t N;
    uint16_t cnt;

    cout << "Iveskite skaiciu: ";
    cin >> N;
    cout << "\n";
    cout << "Pirminiai skaiciai nuo 1 iki " << N << ":" << endl;

    // Optimized algorithm to find prime numbers :)
    for(auto i{0uz}; i<N; i++){
        cnt = 0u;

        if(i <= 1u){
            continue;
        } else {
            for(uint32_t k{2uz}; k * k <= i; k++){
                if(i%k == 0u){
                    cnt++;
                    continue;
                }
            }

            if(cnt > 0u){
                continue;
            } else {
                
                cout << i << " ";
            }
        }
    }
    return 0;
}
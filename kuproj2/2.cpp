
#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cfloat>
#include <uchar.h>
#define __FLT_EVAL_METHOD__ 0

using namespace std;


int main(){
    uint16_t atstumas;

    cin >> atstumas;

    float_t kaina = atstumas * 0.1f;

    if(kaina > 150.0f){
        kaina = kaina + 3.0f;
    }

    cout << "Jusu kelione bus " << kaina << " EUR" << endl;

    return 0;
}
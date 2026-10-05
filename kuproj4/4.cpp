#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <list>
#include <cfloat>

#define __FLT_EVAL_METHOD__ 0
using namespace std;

char Y = 'Y';

// Lowers and compares 2 chars //
bool checkch(char& ch1, char& ch2){
        if(char(tolower(ch1)) != char(tolower(ch2))){
            return false;
        }
    return true;
}

int main(){
    list<uint16_t> visuBalai = {};

    float_t balai;

    uint16_t failed = 0u;
    float_t ffailed;

    float_t fpazymys;
    uint16_t pazymys;

    uint16_t cnt = 0u;
    float_t fcnt;

    uint16_t vid;
    uint16_t sum;
    float_t fpassed;
    
    char answer;

    for(;;){

        if(cnt > 0u){
            cout << "Ar suvesti dar viena? (Y/N) ";
                cin >> answer;
                cout << "\n";
                
                // Shows all of the results then quits //
            if(!checkch(answer,Y)){
                visuBalai.sort();

                for(auto num = visuBalai.begin(); num != visuBalai.end(); num++){
                    sum += *num;
                }

                vid = sum/visuBalai.size();
                ffailed = (float_t)failed;
                fcnt = (float_t)cnt;

                fpassed = 100.f - (((ffailed)/(fcnt))*100.f);
                
                cout << "Klases vidurkis: " << vid << endl;
                cout << "Geriausias balas: " << visuBalai.back() << endl;
                cout << "Blogiausias balas: " << visuBalai.front() << endl;
                cout << "Neislaikiusiuju skaicius: " << failed << endl;
                cout << "Islaikiusiuju procentas: ~" << fpassed << "%" << endl;
                break;
            }
        }

        if(failed >= 5u){
            cout << "Opps neislaikiusiuju skaicius pasiekia 5 :(\n";
            break;
        }
            
        // Main function start here //
    cout << "Iveskite studento bala: ";
    cin >> balai;

    cnt++; // Counter for students
        if(balai < 0.f || balai > 100.f){
            cout << "Opps you entered an number either too large or too small!";
            break;
        }

        
        fpazymys = ceil((balai + 1.f)/10.f);

        if(fpazymys <= 5.f){
            cout << "Studentas neislaike :(\n";
                failed++;
            continue;
        } else {
            pazymys = (uint16_t)fpazymys;
            cout << "Studento pazymys yra: " << pazymys << endl;
            visuBalai.push_front(pazymys);
        }

    }

    return 0;
}

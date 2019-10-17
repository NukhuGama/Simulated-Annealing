#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

float randomEnergy(){
    double x1 = (rand()/(float)RAND_MAX*20)-10; /**menggatur x1 antara -10 dan 10**/
    double x2 = (rand()/(float)RAND_MAX*20)-10; /**mengatur x2 antara -10 dan 10**/
    return -abs(sin(x1)*cos(x2)*exp(abs(1-(sqrt(pow(x1,2)+pow(x2,2)))/M_PI))); /**  rumus yang diketahui di dalam  soal**/
}

int main()
{
    // Inisialisasi temperature;
    double temperatur = 1000;

    double current_energi = randomEnergy();
    double optimal_energi = randomEnergy();

    double current_state = rand();
    double optimal_state = current_state;

    bool renewEnergy = true;

    do{
        float new_energi = randomEnergy();
        double new_state = rand();

        if(new_energi < current_energi){
            /** Terdapat  Minimum Terbaik yg baru**/
            renewEnergy = true;
        }
        else{
            /**   Menggenerate probabilitas apakah dapat diterima atau tidak**/
            double acceptProbability = exp(-(new_energi - current_energi)/(temperatur));
            if(acceptProbability > rand()){
                /** Terdapat Minimum Terbaik yang baru**/
                renewEnergy = true;
            }
            /** Minimum Terbaik masih tetap yg lama **/
            renewEnergy = false;
        }
        if (renewEnergy==true){
            if (current_energi > new_energi){
            	/** Update optimal_energy dengan new_energy **/
                optimal_energi = new_energi;
                /** Update optimal_state dengan new_state **/
                optimal_state = new_state;
            }
            /** Update current_energy dengan new_energy **/
            current_energi = new_energi;
        }
         /** Current State diisi dengan new State**/
         current_state  = new_state;

        /** Decrease temperatur **/
         temperatur = temperatur - 1;

    }
    while (temperatur > 0);

    cout<<"                             BEST SOLUTION "<<endl;
    cout<<"             |==================================================|"<<endl;
    cout<<"             |Terdapat Minimum Terbaik pada state ke:"<<optimal_state<<"      |"<<endl;
    cout<<"             |==================================================|"<<endl;
    cout<<"             |Hasil nilai SA yang paling optimum adalah "<<optimal_energi<<"|"<<endl;
    cout<<"             |==================================================|"<<endl;


}

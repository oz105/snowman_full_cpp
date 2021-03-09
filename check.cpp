#include <iostream>
#include "snowman.hpp"
#include <ctime>
#include <cstdlib> // random num with help here https://www.youtube.com/watch?v=ZjTDuP-aI88
#include <string>
using namespace std;
using namespace ariel;
#define min_num 11111111
#define max_num 44444444




int main(){
    // srand(time(0));
    // for (size_t i = 0; i < 30; i++){
    //     //int min_rnd = (rand() % min_num);
    //     //cout << "min rnd " << min_rnd << endl;
    //     //CHECK_THROWS_AS(snowman(min_rnd),length_error);
    //     int max_rnd = rand()+(max_num+1) ;
    //     cout << "maxx rnd " << max_rnd << endl;
    //     //CHECK_THROWS_AS(snowman(max_rnd),invalid_argument);
    //     //int minus_rnd = (rand() % max_num) - (max_num + 1 ) ;
    //     //cout << "minus rnd " << minus_rnd << endl;
    //     //CHECK_THROWS_AS (snowman(minus_rnd),invalid_argument);
    // }

    int x = 123456789 ;
    cout << ariel::snowman(11214321)<<endl;
//     string s = std::to_string(x);
//     cout << s[4]<<endl ;
} 
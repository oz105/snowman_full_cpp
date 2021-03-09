#include <iostream>
#include "doctest.h"
#include "snowman.hpp"
#include <ctime>
#include <cstdlib> // random num with help here https://www.youtube.com/watch?v=ZjTDuP-aI88
#include <string>
using namespace std;
using namespace ariel;
#define min_num 11111111
#define max_num 44444444

//Snowman build :

//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)

TEST_CASE("Good snowman code") {
    
    // //Check Hats
    CHECK("\n"+snowman(11114411) == string("\n _===_\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(21114411) == string("\n  ___\n .....\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(31114411) == string("\n   _\n  /_\\\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(41114411) == string("\n  ___\n (_*_)\n (.,.)\n ( : )\n ( : )\n"));

    //Check Noses 
    CHECK("\n"+snowman(11114411) == string("\n _===_\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(12224411) == string("\n _===_\n (o.o)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(13114411) == string("\n _===_\n (._.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(14114411) == string("\n _===_\n (. .)\n ( : )\n ( : )\n"));

    //Check left eye
    CHECK("\n"+snowman(11114411) == string("\n _===_\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(12224411) == string("\n _===_\n (o.o)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(13314411) == string("\n _===_\n (O_.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(14414411) == string("\n _===_\n (- .)\n ( : )\n ( : )\n"));

    //Check right eye
    CHECK("\n"+snowman(11114411) == string("\n _===_\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(12224411) == string("\n _===_\n (o.o)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(13334411) == string("\n _===_\n (O_O)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(14444411) == string("\n _===_\n (- -)\n ( : )\n ( : )\n"));

    //Check left arm
    CHECK("\n"+snowman(11111411) == string("\n _===_\n (.,.)\n<( : )\n ( : )\n"));
    CHECK("\n"+snowman(12222411) == string("\n _===_\n\\(o.o)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(13333411) == string("\n _===_\n (O_O)\n/( : )\n ( : )\n"));
    CHECK("\n"+snowman(14444411) == string("\n _===_\n (- -)\n ( : )\n ( : )\n"));

    //Check right arm
    CHECK("\n"+snowman(11111111) == string("\n _===_\n (.,.)\n<( : )>\n ( : )\n"));
    CHECK("\n"+snowman(12222211) == string("\n _===_\n\\(o.o)/\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(13333311) == string("\n _===_\n (O_O)\n/( : )\\\n ( : )\n"));
    CHECK("\n"+snowman(14444411) == string("\n _===_\n (- -)\n ( : )\n ( : )\n"));

    //Check Torso
    CHECK("\n"+snowman(11111111) == string("\n _===_\n (.,.)\n<( : )>\n ( : )\n"));
    CHECK("\n"+snowman(12222221) == string("\n _===_\n\\(o.o)/\n (] [)\n ( : )\n"));
    CHECK("\n"+snowman(13333331) == string("\n _===_\n (O_O)\n/(> <)\\\n ( : )\n"));
    CHECK("\n"+snowman(14444441) == string("\n _===_\n (- -)\n (   )\n ( : )\n"));

    //Check base
    CHECK("\n"+snowman(11111111) == string("\n _===_\n (.,.)\n<( : )>\n ( : )\n"));
    CHECK("\n"+snowman(22222222) == string("\n  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")\n"));
    CHECK("\n"+snowman(33333333) == string("\n   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)\n"));
    CHECK("\n"+snowman(44444444) == string("\n  ___\n (_*_)\n (- -)\n (   )\n (   )\n"));


    //Random good cases
    CHECK("\n"+snowman(11114411) == string("\n _===_\n (.,.)\n ( : )\n ( : )\n"));
    CHECK("\n"+snowman(11111111) == string("\n _===_\n (.,.)\n<( : )>\n ( : )\n"));
    CHECK("\n"+snowman(22222222) == string("\n  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")\n"));
    CHECK("\n"+snowman(33333333) == string("\n   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)\n"));
    CHECK("\n"+snowman(44444444) == string("\n  ___\n (_*_)\n (- -)\n (   )\n (   )\n"));
    CHECK("\n"+snowman(12222212) == string("\n _===_\n\\(o.o)/\n ( : )\n (\" \")\n"));
    CHECK("\n"+snowman(33232124) == string("\n   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )\n"));
    CHECK("\n"+snowman(32443333) == string("\n   _\n  /_\\\n (-.-)\n/(> <)\\\n (___)\n"));
    // CHECK("\n"+snowman(44444432) == string("\n  ___ \n (_*_)\n (- -)\n (> <)\n (\" \")\n"));
    // CHECK("\n"+snowman(44242123) == string("\n  ___ \n (_*_)\n\\(O -)\n (] [)>\n (___)\n"));
    // CHECK("\n"+snowman(41341144) == string("\n  ___ \n (_*_)\n (O,-)\n<(   )>\n (   )\n"));
    
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    
    srand(time(0));
    for (size_t i = 0; i < 30; i++){
        int min_rnd = (rand() % min_num); // pick random number between [0,11111111) - small num 
        CHECK_THROWS(snowman(min_rnd));
        int max_rnd = rand()+(max_num+1) ; // pick random number between [44444445,max value) - big num
        CHECK_THROWS(snowman(max_rnd));
        int minus_rnd = (rand() % max_num) - (max_num + 1 ) ; // pick random number between [-1, -44444445] - nagtive number
        CHECK_THROWS(snowman(minus_rnd));
    }
}


TEST_CASE("input with digit diffrent from 1,2,3,4") {
    CHECK_THROWS(snowman(01111111));
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(11611111));
    CHECK_THROWS(snowman(11171111));
    CHECK_THROWS(snowman(11118111));
    CHECK_THROWS(snowman(11111911));
    CHECK_THROWS(snowman(11111101));
    CHECK_THROWS(snowman(11111115));
}

TEST_CASE("input with numbers <11111111") {
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
}



/* Add more test cases here */
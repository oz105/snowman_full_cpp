#include<iostream>
#include "snowman.hpp"
#include<array>

const int min_num = 11111111 ;
const int max_num = 44444444 ;
const int length = 8 ;
const int hat = 0 ;
const int nose = 1 ;
const int l_eye = 2 ;
const int r_eye = 3 ;
const int left_arm = 4 ;
const int right_arm = 5 ;
const int torso_num = 6 ;
const int base_num = 7 ;

using namespace std;

namespace ariel {
    int range_check (int num){
        if (num > max_num || num < min_num) {return 0 ;}
        return 1 ;
    }
    int check_digits (int num){
        std::string digits = std::to_string(num); //convert num to string https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
        for (size_t i = 0; i < length; i++){
            if(digits[i] > '4' || digits[i] < '1'){
                return 0 ;
            }
        }
        return 1 ;
    }

    string snowman(int num){
        if(range_check(num) == 0) {
            throw std::out_of_range{"Invalid code '" + to_string(num)+"'"};
        }
        if(check_digits(num) == 0) {
            throw std::invalid_argument{ "num can only contains the digits 1-4 " + to_string(num)} ;
        }
        std::string res ="";
        std::array<std::string,4> hats = {" _===_" , "  ___\n ....." , "   _\n  /_\\" , "  ___\n (_*_)"} ;
        std::array<std::string,4> noses = {",",".","_"," "} ;
        std::array<std::string,4> left_eye = {".","o","O","-"} ;
        std::array<std::string,4> right_eye = {".","o","O","-"} ;
        std::array<std::string,4> left_arm_low = {"<"," ","/"," "} ;
        std::array<std::string,4> left_arm_up = {" ","\\"," "," "} ;
        std::array<std::string,4> right_arm_low = {">","","\\",""} ;
        std::array<std::string,4> right_arm_up = {"","/","",""} ;
        std::array<std::string,4> torso = {" : ","] [","> <","   "} ;
        std::array<std::string,4> base = {" : ","\" \"","___","   "} ;

        std::string digits = std::to_string(num); // convert num to string 
        int left = 0 ;
        int right = 0 ;
        if(digits[left_arm] == '2'){
           left = 1 ; // 1 means the arm is up 
        }
        if(digits[right_arm] == '2'){
            right = 1 ; // 1 means the arm is up 
        }
        //cout << "left arm " << digits[left_arm] << endl ;
        //cout << "right arm " << digits[right_arm] << endl ;
        //cout<<"left " << left << endl ;
        //cout<<"right " << right << endl ;

        res.append(hats[(digits[hat]-'1')]+"\n") ;


        if(left == 1 && right == 1){
            res.append(left_arm_up[1]+"("+(left_eye[(digits[l_eye]-'1')])+noses[digits[nose]-'1'] + right_eye[digits[r_eye]-'1']+")"+right_arm_up[1]+"\n"
            +" ("+torso[digits[torso_num]-'1']+")\n"+ " ("+base[digits[base_num]-'1']+")\n");

        }
        else if(left == 1 && right == 0){
            res = res + (left_arm_up[1]+"("+(left_eye[(digits[l_eye]-'1')])+noses[digits[nose]-'1']+right_eye[digits[r_eye]-'1']+")\n")
            +" ("+torso[digits[torso_num]-'1']+")"+right_arm_low[digits[right_arm]-'1']+"\n"
            +" ("+base[digits[base_num]-'1']+")\n";
        }
        else if(left == 0 && right == 1){
            res.append(" ("+(left_eye[(digits[l_eye]-'1')]+noses[digits[nose]-'1'] + right_eye[digits[r_eye]-'1']+")"+right_arm_up[1]+"\n")
             +left_arm_low[digits[left_arm]-'1']+"("+torso[digits[torso_num]-'1']+")\n"
             +" ("+base[digits[base_num]-'1']+")\n");
        }
        else if (left == 0 && right == 0){
            res.append(" ("+(left_eye[(digits[l_eye]-'1')]+noses[digits[nose]-'1'] + right_eye[digits[r_eye]-'1']+")\n")
            +left_arm_low[digits[left_arm]-'1']+"("+torso[digits[torso_num]-'1']+")"+right_arm_low[digits[right_arm]-'1']+"\n"
            +" ("+base[digits[base_num]-'1']+")\n");
        }

        return res;
        //return "none";


    }
} 
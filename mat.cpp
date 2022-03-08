#include<iostream>
#include<string>
#include"mat.hpp"

using namespace std;

namespace ariel { 
    std::string mat(int length, int breadth, char sym_one, char sym_two){
        // check Input
        
        // check for odd and zero input
        if( length%2 == 0 || breadth%2 == 0){
            throw std::invalid_argument("Mat size is always odd");
        }

        // check for negative input
        if( length < 0 || breadth < 0){
            throw std::invalid_argument(" arguments must be positive");
        }

        // check if the given symbols are legal
        if(sym_one == ' ' || sym_one == '\t' || sym_one == '\n' || sym_one == '\r'){
            throw std::invalid_argument("Illegal symbols");
        }
        if(sym_two == ' ' || sym_two == '\t' || sym_two == '\n' || sym_two == '\r'){
            throw std::invalid_argument("Illegal symbols");
        }
        // Build the rag
        return "test";
    };
};
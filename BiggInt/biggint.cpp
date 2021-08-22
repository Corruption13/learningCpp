#include "biggint.hpp"
#include <iostream>


BiggInt::BiggInt(std::string val){
    stringToBiggInt(val);

}

void BiggInt::stringToBiggInt(std::string val){

    if(val[0] == '-'){
        this->sign = true ;
        val = val.substr(1); 
    }
    else{ 
        if(val[0] == '+'){
            val = val.substr(1); 
        }
        this->sign == false ;
    }

    int stack_count = ceil((val.length() / STACKSIZE)) ;

    for(int i = 0; i < stack_count; i++){


        std::string digit_substr = val.substr(i*STACKSIZE, STACKSIZE);
        long longStack = std::stol(digit_substr, nullptr, 10) ;

        this->digitStack.push_back(longStack);
        
    }
}

std::string BiggInt::BiggIntToString(){

    std::string resString = "";

    if(this->sign == true){
        resString = "-";
    }

    for(auto it = this->digitStack.begin(); it != this->digitStack.end(); it++ ){
        resString += std::to_string(*it); 
    }

    return resString; 


}





int main(){

    BiggInt b = BiggInt("-123456789123456789");

    std::cout<< b.BiggIntToString() ;


    

}


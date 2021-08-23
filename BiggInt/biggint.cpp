#include "biggint.hpp"
#include <iostream>


bool BiggInt::getSign(){
    return this->sign; 
}

BiggInt::BiggInt(void){
    this->sign = false;
}

BiggInt::BiggInt(std::string val){
    if(val[0] == '-'){
        this->sign = 1 ;
        val = val.substr(1); 
    }
    else{ 
        this->sign == 0 ;
        if(val[0] == '+'){
            val = val.substr(1); 
        }
    }

    int stack_count = ceil((val.length() / STACKSIZE)) ;

    for(int i = 0; i < stack_count; i++){

        std::string digit_substr = val.substr(i*STACKSIZE, STACKSIZE);
        long longStack = std::stol(digit_substr, nullptr, 10) ;

        this->digitStack.push_back(longStack);
        
    }
}


BiggInt::BiggInt(long val){
    if(val >= 0){
        sign = false;
    }
    else{
        sign = true; 
    }

    this->digitStack.push_back(val);

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


BiggInt BiggInt::operator+(BiggInt y){

    BiggInt x = *this; 
    BiggInt res ; 

    
    if(x.getSign() == y.getSign()){
        res.sign = x.sign;
        auto itx = x.digitStack.rbegin();
        auto ity = y.digitStack.rbegin();

        short int carry = 0;
        long stackval = 0;  

        while(itx != x.digitStack.rend() && ity != y.digitStack.rend()){
                
            stackval = *itx + *ity + carry ;
            std::cout<<"\nx: "<<*itx << "\ny: "<<*ity << "\n\n"; 
            res.digitStack.insert(res.digitStack.begin(), stackval);
            ++itx; 
            ++ity;
            carry = stackval / STACKMOD; 
            
        }

        while(itx != x.digitStack.rend()){
            std::cout<<"\nx: "<<*itx << "\n\n"; 
            res.digitStack.insert(res.digitStack.begin(), *itx + carry);
            ++itx; 
            carry = 0; 
 
        }
        while(ity != y.digitStack.rend()){
            std::cout<<"\ny: "<<*ity + carry << "\n\n"; 
            res.digitStack.insert(res.digitStack.begin(), *ity + carry);
            ++ity;
            carry = 0; 
            
            
        }
    }
    else{
        std::cout<<"TODO!!"; 
        // res = x - y.negetive() ;
    }



    return res; 

    
}


int main(){

    long l = 123456789;
    BiggInt a = BiggInt("1223234");
    BiggInt b = BiggInt("123456789987654321");

    BiggInt c = a + b;

    // BiggInt d = a - b;
    
    std::cout<<"\nA: "<< a.BiggIntToString() ; 

    std::cout<<"\nB: "<<b.BiggIntToString() ;

    std::cout<<"\nC: "<< c.BiggIntToString()<<std::endl ;






    

}


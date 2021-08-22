#ifndef BIGGINT_H
#define BIGGINT_H

#include <vector>
#include <string>
#include <cmath>

double STACKSIZE = 9 ; // Long int

class BiggInt{

public:

    BiggInt(std::string val);
    
    void stringToBiggInt(std::string val); 
    std::string BiggIntToString(); 
    




    std::vector<long> digitStack ;
    bool sign; 


};

#endif
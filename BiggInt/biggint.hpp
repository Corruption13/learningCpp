#ifndef BIGGINT_H
#define BIGGINT_H

#include <vector>
#include <string>
#include <cmath>


static double STACKSIZE = 9 ; // Long int digits allowed. 
                              //Keep double for cieling function behaviour.

                      //10**9
static int STACKMOD = 1000000000;    // STACKSIZE+1 digits.


class BiggInt{

public:

    BiggInt(void); 
    BiggInt(std::string val);
    BiggInt(long val);
    
    bool getSign(); 
    std::string BiggIntToString(); 
    BiggInt operator+(BiggInt y);



private:

    std::vector<long> digitStack ;
    bool sign; 


};

#endif
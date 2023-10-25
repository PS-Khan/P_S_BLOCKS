#ifndef S_BLOCK
#define S_BLOCK
#include <iostream>
#include <vector>

class S_P_block{
    public:
        S_P_block();
        unsigned char SBox(unsigned char input);
        unsigned char SBox_Decr(unsigned char input);
        unsigned char Permute(unsigned char input);
        unsigned char Permute_Decr(unsigned char permutedInput);

    private:

        std::vector<unsigned char> sBox ;
        std::vector<unsigned char> sBox_Decr ;
        std::vector<unsigned char> pTable ;


};

#endif
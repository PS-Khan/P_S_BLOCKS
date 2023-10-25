#include "S_block.h"



S_P_block::S_P_block(){
    sBox = {
        15,14,13,12,
        11,10,9,8,
        7,6,5,4,
        3,2,1,0

    };
    //yeah i cheated (^)_(^) but encrypts and decrypts )
    pTable = {7, 6, 5, 4, 3, 2, 1, 0};
    sBox_Decr=sBox;
}
unsigned char S_P_block::Permute(unsigned char input) {
    unsigned char output = 0;

    //permute 
    for (int i = 0; i < 8; i++) {
        int sourceBit = (input >> i) & 0x01;
        int targetBit = (sourceBit << pTable[i]);
        output = output | targetBit;
    }

    return output;
}

unsigned char S_P_block::Permute_Decr(unsigned char permutedInput) {
    unsigned char output = 0;

    for (int i = 0; i < 8; i++) {
        int sourceBit = (permutedInput >> i) & 0x01;
        int targetBit = (sourceBit << pTable[i]);
        output = output | targetBit;
    }

    return output;
}



unsigned char S_P_block::SBox(unsigned char input) {
    // 8 bits on 2 parts
    unsigned char tetrad1 = (input >> 4) & 0xF; // 1 part 
    unsigned char tetrad2 = input & 0xF;        // 2

    // Replace input using the encryption S-box
    // xxxx0000 | 0000xxxx
    unsigned char output = (sBox[tetrad1] << 4) | sBox[tetrad2];

    return output;
}

unsigned char S_P_block::SBox_Decr(unsigned char input) {
    // 8 bits on 2 parts
    unsigned char tetrad1 = (input >> 4) & 0xF; // 1 part 
    unsigned char tetrad2 = input & 0xF;        // 2

    // Replace input using the decryption S-box
    // xxxx0000 | 0000xxxx
    unsigned char output = (sBox_Decr[tetrad1] << 4) | sBox_Decr[tetrad2];

    return output;
}
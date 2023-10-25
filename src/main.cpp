#include <iostream>
#include <string>
#include <vector>

#include "S_block.h"


int main(){
    
    std::string text;
    std::cout << "Enter your text:\n";
    std::getline(std::cin, text);

    S_P_block sBlock;
    

    std::vector<unsigned char> hexValues;
    std::vector<unsigned char> SValues;

    for (char letter : text) {
        // Convert the character to its ASCII value (8 bits)
        unsigned char asciiValue = static_cast<unsigned char>(letter);
        hexValues.push_back(asciiValue);

        unsigned char sBoxResult = sBlock.SBox(asciiValue);
        SValues.push_back(sBoxResult);
    }

    for (unsigned char byte : hexValues) {
        std::cout <<static_cast<int>(byte) << " ";
    }
    std::cout<<"\n after SBox: \n";
    for (unsigned char byte : SValues) {
        unsigned char sBoxResult = sBlock.SBox_Decr(byte);
        std::cout << "Original: " << static_cast<int>(byte) << " ( " << byte << " ) - Decrypted: " << static_cast<int>(sBoxResult) << " ( "  << sBoxResult << " )\n";
    }

    std::cout << "Testing S-box:\n";
    for (unsigned char i = 0; i < 255; ++i) {
        unsigned char encrypted = sBlock.SBox(i);
        unsigned char decrypted = sBlock.SBox_Decr(encrypted);
        if (i != decrypted) {
            std::cout << "Mismatch at index " << static_cast<int>(i) << ": " << static_cast<int>(i) << " -> " << static_cast<int>(encrypted) << " -> " << static_cast<int>(decrypted) << std::endl;
        }
    }
    

    S_P_block pBlock;
    std::string text2;
    std::cout << "Enter your text:\n";
    std::getline(std::cin, text2);

    std::vector<unsigned char> hexValues2;
    std::vector<unsigned char> PValues;

    for (char letter : text2) {
        // Convert the character to its ASCII value (8 bits)
        unsigned char asciiValue = static_cast<unsigned char>(letter);
        hexValues2.push_back(asciiValue);

        unsigned char pBoxResult = pBlock.Permute(asciiValue);
        PValues.push_back(pBoxResult);
    }

    for (unsigned char byte : hexValues2) {
        std::cout <<static_cast<int>(byte) << " ";
    }
    std::cout<<"\n after SBox: \n";
    for (unsigned char byte : PValues) {
        unsigned char pBoxResult = pBlock.Permute_Decr(byte);
        std::cout << "Original: " << static_cast<int>(byte) << " ( " << byte << " ) - Decrypted: " << static_cast<int>(pBoxResult) << " ( "  << pBoxResult << " )\n";
    }


    std::cout << "Testing Permutation:\n";
    for (unsigned char i = 0; i < 255; ++i) {
        unsigned char permuted = sBlock.Permute(i);
        unsigned char decrypted = sBlock.Permute_Decr(permuted);
        if (i != decrypted) {
            std::cout << "Mismatch at index " << static_cast<int>(i) << ": " << static_cast<int>(i) << " -> " << static_cast<int>(permuted) << " -> " << static_cast<int>(decrypted) << std::endl;
        }
    }



    
   
    
    return 0;
}
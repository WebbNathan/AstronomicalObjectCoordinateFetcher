#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "GeneralFunctions.h"

std::string csvReturnAt(std::ifstream &inpFile, int row, int col, char delimiter) {
    std::string tempStr;
    std::vector<std::string> tokens;
    int front = -1;
    int back = 0;
    int count = 0;

    for(int i = 0; i < row; i++) {
        std::getline(inpFile, tempStr);
    }

    while (back != std::string::npos) {
        back = tempStr.find(delimiter, front + 1);
        if(back != std::string::npos) {
            tokens.push_back(tempStr.substr(front + 1, back - front - 1));
            front = back;
            //std::cout << tokens[count] << std::endl;
        }
        //count++;
    }
    tokens.push_back(tempStr.substr(front + 1, tempStr.length() - front - 1));
    //std::cout << tokens[count - 1] << std::endl;

    return tokens[col - 1];
}
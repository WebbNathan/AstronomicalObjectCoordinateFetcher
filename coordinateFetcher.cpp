#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include "AstronomicalObjectsProto.h"

/* Step zero: catalog preperation and source data (NON SOLAR SYSTEM OBJECTS)

    - Probably the first step should be to load the J2000 data into an object

*/

void returnLookUpTable(std::vector<std::array<std::string, 20>> &dataTable, std::string fileName, const int parameters) {
    std::ifstream inpFile;
    std::string tempStr;
    std::array<std::string, 20> tempArr;
    int colIter = 0; //This will count how many data memebers ive input into table for each row
    
    inpFile.open(fileName);
    
    while(getline(inpFile, tempStr)) {
        //std::cout << tempStr.substr(0,6) << std::endl;
        //Formula for calulting substr args:
        //arg 1 = first byte - 1
        //arg 2 = last byte - first byte + 1
        tempArr[0] = tempStr.substr(0,6); //ID
        tempArr[1] = tempStr.substr(7, 2); //R_a_Hour
        tempArr[2] = tempStr.substr(9, 2); //R_a_Min
        tempArr[3] = tempStr.substr(11, 6); //R_a_Sec
        tempArr[4] = tempStr.substr(17, 7); //Proper motion in R_a
        dataTable.push_back(tempArr);
    }

    inpFile.close();
}

void searchTableByID(std::string id) {

}

void setObjectData(AstronomicalObject &newObj) {
    
}

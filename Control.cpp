#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include "AstronomicalObjects.h"
#include "Control.h"

Control::Control() {
    this->currentObj = AstronomicalObject();
    this->dataFileName = "sao.txt";
}

Control::Control(std::string dataFileName) {
    this->currentObj = AstronomicalObject();
    this->dataFileName = dataFileName;
}

void Control::populateDataTable() {
    std::ifstream inpFile;
    std::string tempStr;
    std::array<std::string, 20> tempArr;
    
    inpFile.open(this->dataFileName);
    
    while(getline(inpFile, tempStr)) {
        //std::cout << tempStr.substr(0,6) << std::endl;
        //Formula for calulting substr args:
        //arg 1 = first byte - 1
        //arg 2 = last byte - first byte + 1
        //Using byte mapping from https://cdsarc.cds.unistra.fr/ftp/cats/I/131A/ReadMe

        tempArr[0] = tempStr.substr(0,6); //ID
        tempArr[1] = tempStr.substr(7, 2); //R_a_Hour
        tempArr[2] = tempStr.substr(9, 2); //R_a_Min
        tempArr[3] = tempStr.substr(11, 6); //R_a_Sec
        tempArr[4] = tempStr.substr(17, 7); //Proper motion in R_a
        tempArr[5] = tempStr.substr(24, 2); //Standard deviation in R_a proper motion
        tempArr[6] = tempStr.substr(41, 1); //Sign of dec
        tempArr[7] = tempStr.substr(42, 2); //Dec degree
        tempArr[8] = tempStr.substr(44, 2); //Dec arcmin
        tempArr[9] = tempStr.substr(46, 5); //Dec arcsec
        this->dataTable.push_back(tempArr);
    }

    inpFile.close();
}

void Control::setAstroObject(int SAOid) {
    currentObj.setId(std::stoi(dataTable[SAOid - 1][0]));
    currentObj.setJ2000_R_a_Hour(std::stod(dataTable[SAOid - 1][1]));
    currentObj.setJ2000_R_a_Min(std::stod(dataTable[SAOid - 1][2]));
    currentObj.setJ2000_R_a_Sec(std::stod(dataTable[SAOid - 1][3]));
    currentObj.setJ2000_R_a_PM(std::stod(dataTable[SAOid - 1][4]));
    currentObj.setJ2000_R_a_PMSD(std::stod(dataTable[SAOid - 1][5]));
    currentObj.setDecSign(dataTable[SAOid - 1][6]);
    currentObj.setJ2000_Dec_deg(std::stod(dataTable[SAOid - 1][7]));
    currentObj.setJ2000_Dec_min(std::stod(dataTable[SAOid - 1][8]));
    currentObj.setJ2000_Dec_sec(std::stod(dataTable[SAOid - 1][9]));
}

void Control::displayObjectData() {
    std::cout << "Object ID: " << this->currentObj.getId() << std::endl
              << "R_a_Hour: " << this->currentObj.getJ2000_R_a_Hour() << std::endl
              << "R_a_Min: " << this->currentObj.getJ2000_R_a_Min() << std::endl
              << "R_a_Sec: " << this->currentObj.getJ2000_R_a_Sec() << std::endl
              << "Proper Motion R_a: " << this->currentObj.getJ2000_R_a_PM() << std::endl
              << "Proper Motion Standard Deviation R_a: " << this->currentObj.getJ2000_R_a_PMSD() << std::endl
              << "Dec degree: " << this->currentObj.getDecSign() << this->currentObj.getJ2000_Dec_deg() << std::endl
              << "Dec minutes: " << this->currentObj.getJ2000_Dec_min() << std::endl
              << "Dec seconds: " << this->currentObj.getJ2000_Dec_sec() << std::endl;
}
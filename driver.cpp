#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sys/time.h>
#include "AstronomicalObjects.h"
#include "Control.h"
#include "DataTypes.h"
#include "GeneralFunctions.h"
using namespace std;

//This file will act as a test driver for my project

int main() {

    timeval currTime;
    std::string DUT1;

    Control controlObj = Control();

    controlObj.populateDataTable();

    controlObj.setAstroObject(209865);

    controlObj.displayObjectData();

    Control::getLST(currTime);

    std::ifstream file;
    file.open("bulletina-xxxviii-039.csv");
    if(!file.is_open()) {
        std::cout << "file did not open" << std::endl;
    }

    DUT1 = csvReturnAt(file, 13, 15, ';');
    std::cout << DUT1 << std::endl;

    return 0;
}
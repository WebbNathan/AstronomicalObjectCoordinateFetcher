#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include "AstronomicalObjects.h"
#include "Control.h"
#include "DataTypes.h"
using namespace std;

//This file will act as a test driver for my project

int main() {

    Control controlObj = Control();

    controlObj.populateDataTable();

    controlObj.setAstroObject(209865);

    controlObj.displayObjectData();

    return 0;
}
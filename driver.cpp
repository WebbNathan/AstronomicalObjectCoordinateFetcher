#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include "AstronomicalObjects.h"
#include "Control.h"
using namespace std;

//This file will act as a test driver for my project

int main() {

    Control controlObj = Control();

    controlObj.populateDataTable();

    controlObj.setAstroObject(1);

    controlObj.displayObjectData();

    return 0;
}
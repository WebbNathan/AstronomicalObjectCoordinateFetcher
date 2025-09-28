#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sys/time.h>
#include "AstronomicalObjects.h"
#include "Control.h"
using namespace std;

//This file will act as a test driver for my project

int main() {

    Control controlObj = Control();

    controlObj.populateDataTable();

    controlObj.setAstroObject(209865);

    controlObj.displayObjectData();

    controlObj.setObserverLong(-110.90282182636426);

    controlObj.getLST("bulletina-xxxviii-039.csv");

    return 0;
}
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

    controlObj.setObserverLat(32.33561175229357);

    controlObj.setObserverLong(-110.90282182636426);

    controlObj.setDUT1Data("bulletina-xxxviii-039.csv");

    controlObj.getLST();

    return 0;
}
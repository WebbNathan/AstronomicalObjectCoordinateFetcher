#include <iostream>
#include "AstronomicalObjectsProto.h"
using namespace std;

//This file will act as a test driver for my project

int main() {

    AstronomicalObject newObj = AstronomicalObject("Jupiter", 0, 0, 0);

    cout << newObj.getId() << endl;

    return 0;
}
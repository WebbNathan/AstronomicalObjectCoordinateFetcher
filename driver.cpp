#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "AstronomicalObjectsProto.h"
#include "coordinateFetcher.h"
using namespace std;

//This file will act as a test driver for my project

int main() {
    AstronomicalObject newObj = AstronomicalObject("Jupiter", 0, 0, 0);
    vector<array<string, 20>> j2000DataTable; 
    const string dataFile = "sao.txt";
    const int dataParameters = 20;

    returnLookUpTable(j2000DataTable, dataFile, dataParameters);

    std::cout << j2000DataTable[0][0] << " " << j2000DataTable[0][1] << " " << j2000DataTable[0][2] << endl;

    return 0;
}
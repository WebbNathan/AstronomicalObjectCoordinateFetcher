#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "AstronomicalObjects.h"
#include "coordinateFetcher.h"
using namespace std;

//This file will act as a test driver for my project

int main() {
    AstronomicalObject newObj = AstronomicalObject("Jupiter", 0, 0, 0, 0, 0);
    vector<array<string, 20>> j2000DataTable; 
    const string dataFile = "sao.txt";

    returnLookUpTable(j2000DataTable, dataFile);

    std::cout << j2000DataTable[0][0] << " " << j2000DataTable[0][1] << " " << j2000DataTable[0][2] << " " <<
                j2000DataTable[0][3] << " " <<  j2000DataTable[0][4] << " " << j2000DataTable[0][5] << endl;

    newObj.setId(j2000DataTable[0][0]);
    newObj.setJ200_R_a_Hour(stoi(j2000DataTable[0][1]));

    cout << newObj.getId() << " " << newObj.getJ200_R_a_Hour();

    return 0;
}
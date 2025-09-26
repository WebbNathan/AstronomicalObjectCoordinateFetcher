#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AstronomicalObjectsProto.h"
using namespace std;

/* Step zero: catalog preperation and source data (NON SOLAR SYSTEM OBJECTS)

    - Probably the first step should be to load the J2000 data into an object

*/

void setObjectData(AstronomicalObject &newObj, FILE* J200_data) {
    
}

void returnLookUpTable(vector<vector<string>> &dataTable, string fileName, const int parameters) {
    ifstream inpFile;
    string tempStr;
    int colIter = 0; //This will count how many data memebers ive input into table for each row
    int rowIter = 0;
    
    inpFile.open(fileName);
    
    while(getline(inpFile, tempStr, ',')) {
        dataTable[rowIter][colIter] = tempStr;
        colIter++;
        if(colIter >= parameters - 1) {
            rowIter++;
            colIter = 0;
        }
    }

    inpFile.close();
}

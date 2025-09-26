#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AstronomicalObjectsProto.h"

void setObjectData(AstronomicalObject &newObj, FILE* J200_data);
void returnLookUpTable(vector<vector<string>> &dataTable, string fileName, const int parameters);
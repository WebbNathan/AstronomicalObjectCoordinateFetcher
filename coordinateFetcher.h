#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "AstronomicalObjectsProto.h"

void returnLookUpTable(std::vector<std::array<std::string, 20>> &dataTable, std::string fileName, const int parameters);
void searchTableByID(std::string id);
void setObjectData(AstronomicalObject &newObj);
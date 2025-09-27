#pragma once
#include <iostream>
#include <fstream>

std::string csvReturnAt(std::ifstream &inpFile, int row, int col, char delimiter);
#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include "AstronomicalObjects.h"

class Control {

    private:
        std::vector<std::array<std::string, 20>> dataTable;
        AstronomicalObject currentObj;
        std::string dataFileName; //Defualt: sao.txt

    public:
        Control();
        Control(std::string dataFileName); //For inputting different data
        void populateDataTable();
        void setAstroObject(int SAOid);
        AstronomicalObject getAstroObject(); //May not keep
        void displayObjectData();
        void pointing(); //This will run the coordinate calulation routine PROBABLY RENAME
        void getLST();
};
#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sys/time.h>
#include "AstronomicalObjects.h"

class Control {

    private:
        std::vector<std::array<std::string, 20>> dataTable;
        AstronomicalObject currentObj;
        std::string dataFileName; //Defualt: sao.txt

        double observerLat;
        double observerLong;

        static void csvTokenizeLine(std::vector<std::string> &tokens, 
                                    std::ifstream &inpFile, int row, char delimiter);

    public:
        Control();
        Control(std::string dataFileName); //For inputting different data
        void populateDataTable();
        void setAstroObject(int SAOid);
        void setObserverLat(double observerLat);
        void setObserverLong(double observerLong);
        AstronomicalObject getAstroObject(); //May not keep
        double getObserverLat();
        double getObserverLong();
        void displayObjectData();
        void targetPointing(); //This will run the coordinate calulation routine PROBABLY RENAME
        void getLST();
};
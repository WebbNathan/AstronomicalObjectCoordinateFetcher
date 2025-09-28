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
        R_a currentLST;

        static void csvTokenizeLine(std::vector<std::string> &tokens, 
                                    std::ifstream &inpFile, int row, char delimiter);
        static double returnUT1(std::string DUT1fileName);
        static double returnJulianDay(double UT1);
        static double returnGMST(double julianDay, double UT1);

    public:
        struct R_a;
        struct Dec;
            
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
        void getLST(std::string DUT1data);  //Maybe make dut1data a member of the class
};
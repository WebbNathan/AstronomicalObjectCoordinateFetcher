#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sys/time.h>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <cmath>
#include <format>
#include "AstronomicalObjects.h"
#include "Control.h"
#include "DataTypes.h"

void Control::csvTokenizeLine(std::vector<std::string> &tokens, std::ifstream &inpFile, int row, char delimiter) {
    std::string tempStr;
    int front = -1;
    int back = 0;
    int count = 0;

    for(int i = 0; i < row; i++) {
        std::getline(inpFile, tempStr);
    }

    while (back != std::string::npos) {
        back = tempStr.find(delimiter, front + 1);
        if(back != std::string::npos) {
            tokens.push_back(tempStr.substr(front + 1, back - front - 1));
            front = back;
            //std::cout << tokens[count] << std::endl;
        }
        //count++;
    }
    tokens.push_back(tempStr.substr(front + 1, tempStr.length() - front - 1));
    //std::cout << tokens[count - 1] << std::endl;

}

Control::Control() {
    this->currentObj = AstronomicalObject();
    this->dataFileName = "sao.txt";
}

Control::Control(std::string dataFileName) {
    this->currentObj = AstronomicalObject();
    this->dataFileName = dataFileName;
}

void Control::populateDataTable() {
    std::ifstream inpFile;
    std::string tempStr;
    std::array<std::string, 20> tempArr;
    
    inpFile.open(this->dataFileName);
    
    while(getline(inpFile, tempStr)) {
        //std::cout << tempStr.substr(0,6) << std::endl;
        //Formula for calulting substr args:
        //arg 1 = first byte - 1
        //arg 2 = last byte - first byte + 1
        //Using byte mapping from https://cdsarc.cds.unistra.fr/ftp/cats/I/131A/ReadMe

        tempArr[0] = tempStr.substr(0,6); //ID
        tempArr[1] = tempStr.substr(7, 2); //R_a_Hour
        tempArr[2] = tempStr.substr(9, 2); //R_a_Min
        tempArr[3] = tempStr.substr(11, 6); //R_a_Sec
        tempArr[4] = tempStr.substr(17, 7); //Proper motion in R_a
        tempArr[5] = tempStr.substr(24, 2); //Standard deviation in R_a proper motion
        tempArr[6] = tempStr.substr(41, 1); //Sign of dec
        tempArr[7] = tempStr.substr(42, 2); //Dec degree
        tempArr[8] = tempStr.substr(44, 2); //Dec arcmin
        tempArr[9] = tempStr.substr(46, 5); //Dec arcsec
        this->dataTable.push_back(tempArr);
    }

    inpFile.close();
}

void Control::setAstroObject(int SAOid) {
    currentObj.setId(std::stoi(dataTable[SAOid - 1][0]));
    currentObj.setJ2000_R_a_Hour(std::stod(dataTable[SAOid - 1][1]));
    currentObj.setJ2000_R_a_Min(std::stod(dataTable[SAOid - 1][2]));
    currentObj.setJ2000_R_a_Sec(std::stod(dataTable[SAOid - 1][3]));
    currentObj.setJ2000_R_a_PM(std::stod(dataTable[SAOid - 1][4]));
    currentObj.setJ2000_R_a_PMSD(std::stod(dataTable[SAOid - 1][5]));
    currentObj.setJ2000_DecSign(dataTable[SAOid - 1][6]);
    currentObj.setJ2000_Dec_deg(std::stod(dataTable[SAOid - 1][7]));
    currentObj.setJ2000_Dec_min(std::stod(dataTable[SAOid - 1][8]));
    currentObj.setJ2000_Dec_sec(std::stod(dataTable[SAOid - 1][9]));
}

void Control::setObserverLat(double observerLat) {
    this->observerLat = observerLat;
}

void Control::setObserverLong(double observerLong) {
    this->observerLong = observerLong;
}

double Control::getObserverLat() {
    return observerLat;
}

double Control::getObserverLong() {
    return observerLong;
}

void Control::displayObjectData() {
    std::cout << "Object ID: " << this->currentObj.getId() << std::endl
              << "R_a_Hour: " << this->currentObj.getJ2000_R_a().hours << std::endl
              << "R_a_Min: " << this->currentObj.getJ2000_R_a().minutes << std::endl
              << "R_a_Sec: " << this->currentObj.getJ2000_R_a().seconds << std::endl
              << "Proper Motion R_a: " << this->currentObj.getJ2000_R_a_PM() << std::endl
              << "Proper Motion Standard Deviation R_a: " << this->currentObj.getJ2000_R_a_PMSD() << std::endl
              << "Dec degree: " << this->currentObj.getJ2000_Dec().sign * this->currentObj.getJ2000_Dec().degrees << std::endl
              << "Dec minutes: " << this->currentObj.getJ2000_Dec().arcminutes << std::endl
              << "Dec seconds: " << this->currentObj.getJ2000_Dec().arcseconds << std::endl;
}

void Control::targetPointing() {
    
}

void Control::getLST(std::string DUT1data) { //Currently does not have sub-second accuracy 
    double UT1, julianDate, GMST, LST;
    double LSTIntegral, LSTFractional, LSTMinIntegral, LSTMinFractional;

    UT1 = returnUT1(DUT1data);
    julianDate = returnJulianDay(UT1);
    GMST = returnGMST(julianDate, UT1);
    LST = GMST + (observerLong / 15.0);
    if(LST < 0) {
        LST += 24;
    }
    LSTFractional = std::modf(LST, &LSTIntegral);
    currentLST.hours = LSTIntegral;
    LSTMinFractional = std::modf(LSTFractional * 60, &LSTMinIntegral);
    currentLST.minutes = LSTMinIntegral;
    currentLST.seconds = 60 * LSTMinFractional; 

    std::cout <<"LST: " << currentLST.hours << " " << currentLST.minutes <<
              " " << currentLST.seconds << std::endl; 

    //std::cout << std::fixed << julianDate << std::endl;

}

double Control::returnUT1(std::string DUT1fileName) {
    std::vector<std::string> tokenizedCSV;
    timeval currTime;  
    double DUT1, UTC, UT1; 

    //Loading the IERA Bulletin  A file (may want to make the name an argument or something)
    std::ifstream file;
    file.open("bulletina-xxxviii-039.csv");
    if(!file.is_open()) {
        std::cout << "DUT1 data file could not open" << std::endl;
    }

    //Getting a tokenized line from the IERS Bulletin A file
    Control::csvTokenizeLine(tokenizedCSV, file, 14, ';');
    
    //Calculating UT1 time
    DUT1 = stod(tokenizedCSV[14]);
    gettimeofday(&currTime, NULL);
    UTC = currTime.tv_sec + (currTime.tv_usec / 1000000.0);
    UT1 = UTC + DUT1;

    return UT1;
}

double Control::returnJulianDay(double UT1) {
    char outputTimeArr[20];
    std::string outputTimeStr;

    int day;
    int month;
    int year;
    double julianDate;
    double UT1Hour;
    double UT1Integral;
    double UT1Fractional;
    double UT1SecSinceStartofDayIntegral;
    double UT1SecSinceStartofDayFractional;

    //Get Julian Day
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now(); 
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm utc_tm = *gmtime(&tt);
    //Got above code from stack overflow 
    //https://stackoverflow.com/questions/15957805/extract-year-month-day-etc-from-stdchronotime-point-in-c

    day = utc_tm.tm_mday;
    month = utc_tm.tm_mon + 1;
    year = utc_tm.tm_year + 1900;

    if(month < 3) { //Correcting for JD defintions of start and end of year
        month += 12;
        year--;
    }

    UT1Fractional = std::modf(UT1, &UT1Integral); //Getting fractional and Integral part of UT1 time
    UT1SecSinceStartofDayFractional =  std::modf((int)UT1Integral % 86400 + (UT1 - UT1Integral),
                                       &UT1SecSinceStartofDayIntegral);
    UT1Hour = (UT1SecSinceStartofDayIntegral / 3600.0) + (UT1SecSinceStartofDayFractional / 3600.0); //Converting to hours

    julianDate = 367.0 * year - std::trunc(((7.0 * (year + std::trunc((month + 9.0) / 12.0))) / 4.0)) +
                 std::trunc((275.0 * month) / 9.0) + day + 1721013.5 + (UT1Hour / 24.0) -
                 (0.5 * std::copysign(1.0, (100.0 * year) + month - 190002.5)) + 0.5;

    return julianDate;

    //https://aa.usno.navy.mil/faq/JD_formula    Info on UT1 -> Julian date

}

double Control::returnGMST(double julianDay, double UT1) {
    double UT1StartofDay;
    double SecondsSinceDayStart;
    double SecondsSinceDayStartIntegral;
    double SecondsSinceDayStartFractional;
    double HoursSinceDayStart;
    double D_ut;
    double T;
    double GMST;
    int UT1Integral = (int)std::trunc(UT1);


    SecondsSinceDayStart = (UT1Integral % 86400) + (UT1 - UT1Integral);
    UT1StartofDay = UT1 - SecondsSinceDayStart;
    SecondsSinceDayStartFractional = std::modf(SecondsSinceDayStart, &SecondsSinceDayStartIntegral);
    HoursSinceDayStart = (SecondsSinceDayStartIntegral / 3600.0) + (SecondsSinceDayStartFractional / 3600.0);

    double JD_0 = returnJulianDay(UT1StartofDay); //This will store julian Day at start of day
    D_ut = JD_0 - 2451545.0;
    T = D_ut / 36525.0;

    GMST = 6.697375 + (0.065709824279 * D_ut) + (1.0027379 * HoursSinceDayStart) +
           (0.0000258 * T * T);

    GMST = ((int)std::trunc(GMST) % 24) + GMST - std::trunc(GMST);

    //GMST = mod (6.697375 + 0.065707485828 DUT + 1.0027379 H + 0.0854103 T + 0.0000258 T2, 24) h

    return GMST;

    //https://aa.usno.navy.mil/faq/GAST       Info on Julian date -> GWMST
}
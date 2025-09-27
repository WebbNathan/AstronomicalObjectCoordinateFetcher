#pragma once
#include <iostream>
#include <string>
#include "DataTypes.h"

class AstronomicalObject {  //Stores information about an object

    private:
        R_a J2000_R_a;
        Dec J2000_Dec;
        R_a currR_a;
        Dec currDec;
        int id;
        double J2000_R_a_PM;
        double J2000_R_a_PMSD;
        double magnitude;
        //Possibly more

    public:
        AstronomicalObject();
        void setId(int id);
        void setJ2000_R_a_Hour(double J2000_R_a_Hour);
        void setJ2000_R_a_Min(double J2000_R_a_Min);
        void setJ2000_R_a_Sec(double J2000_R_a_Sec);
        void setJ2000_R_a_PM(double J2000_R_a_PM);
        void setJ2000_R_a_PMSD(double J2000_R_a_PMDS);
        void setJ2000_DecSign(std::string DecSign);
        void setJ2000_Dec_deg(double J2000_Dec_deg);//
        void setJ2000_Dec_min(double J2000_Dec_min);//
        void setJ2000_Dec_sec(double J2000_Dec_sec);//
        void setMagnitude(double magnitude);
        void setCurr_R_a(R_a curr_R_a);
        void setCurr_Dec(Dec curr_Dec);
        int getId();
        R_a getJ2000_R_a();
        double getJ2000_R_a_PM();
        double getJ2000_R_a_PMSD();      
        Dec getJ2000_Dec();//
        double getMagnitude();
        R_a getCurr_R_a();
        Dec getCurr_Dec();
};
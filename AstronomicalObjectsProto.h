#pragma once
#include <iostream>
#include <string>

class AstronomicalObject {  //Stores information about an object
    private:
        std::string id;
        double J2000_R_a_Hour;
        double J2000_R_a_Min;
        double J2000_R_a_Sec;
        double J2000_Dec;
        double magnitude;
        //Possibly more

        double curr_R_a;
        double curr_Dec;

    public:
        AstronomicalObject(std::string id, double J2000_R_a_Hour, double J2000_R_a_Min, 
                           double J2000_R_a_Sec, double J2000_Dec, double magnitude);
        void setId(std::string id);
        void setJ200_R_a_Hour(double J200_R_a_Hour);
        void setJ200_R_a_Min(double J200_R_a_Min);
        void setJ200_R_a_Sec(double J200_R_a_Sec);
        void setJ200_Dec(double J200_Dec);
        void setMagnitude(double magnitude);
        void setCurr_R_a(double curr_R_a);
        void setCurr_Dec(double curr_Dec);
        std::string getId();
        double getJ200_R_a_Hour();
        double getJ200_R_a_Min();  
        double getJ200_R_a_Sec();        
        double getJ200_Dec();
        double getMagnitude();
        double getCurr_R_a();
        double getCurr_dec();
};
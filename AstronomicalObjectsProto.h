#pragma once
#include <iostream>
#include <string>

class AstronomicalObject {  //Stores information about an object
    private:
        std::string id;
        double J2000_R_a;
        double J2000_Dec;
        double magnitude;
        //Possibly more

        double curr_R_a;
        double curr_Dec;

    public:
        AstronomicalObject(std::string id, double J2000_R_a, double J2000_Dec, 
                           double magnitude);
        AstronomicalObject();
        void setId(std::string id);
        void setJ200_R_a(double J200_R_a);
        void setJ200_Dec(double J200_Dec);
        void setMagnitude(double magnitude);
        void setCurr_R_a(double curr_R_a);
        void setCurr_Dec(double curr_Dec);
        std::string getId();
        double getJ200_R_a();      
        double getJ200_Dec();
        double getMagnitude();
        double getCurr_R_a();
        double getCurr_dec();
};
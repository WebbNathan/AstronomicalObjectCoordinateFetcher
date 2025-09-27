#pragma once
#include <iostream>
#include <string>

class AstronomicalObject {  //Stores information about an object
    private:
        int id;
        double J2000_R_a_Hour;
        double J2000_R_a_Min;
        double J2000_R_a_Sec;
        double J2000_R_a_PM;
        double J2000_R_a_PMSD;
        std::string decSign;
        double J2000_Dec_deg;
        double J2000_Dec_min;
        double J2000_Dec_sec;
        double magnitude;
        //Possibly more

        double curr_R_a;
        double curr_Dec;

    public:
        AstronomicalObject();
        void setId(int id);
        void setJ2000_R_a_Hour(double J2000_R_a_Hour);
        void setJ2000_R_a_Min(double J2000_R_a_Min);
        void setJ2000_R_a_Sec(double J2000_R_a_Sec);
        void setJ2000_R_a_PM(double J2000_R_a_PM);
        void setJ2000_R_a_PMSD(double J2000_R_a_PMDS);
        void setDecSign(std::string DecSign);
        void setJ2000_Dec_deg(double J2000_Dec_deg);//
        void setJ2000_Dec_min(double J2000_Dec_min);//
        void setJ2000_Dec_sec(double J2000_Dec_sec);//
        void setMagnitude(double magnitude);
        void setCurr_R_a(double curr_R_a);
        void setCurr_Dec(double curr_Dec);
        int getId();
        double getJ2000_R_a_Hour();
        double getJ2000_R_a_Min();  
        double getJ2000_R_a_Sec();
        double getJ2000_R_a_PM();
        double getJ2000_R_a_PMSD();     
        std::string getDecSign();   
        double getJ2000_Dec_deg();//
        double getJ2000_Dec_min();//
        double getJ2000_Dec_sec();//
        double getMagnitude();
        double getCurr_R_a();
        double getCurr_dec();
        void calcCurrentR_a_Dec(); //Thinking this should be a memeber of the class
};
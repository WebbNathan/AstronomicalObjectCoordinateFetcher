#include <iostream>

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
                           double magnitude) 
        {
            this->id = id;
            this->J2000_R_a = J2000_R_a;
            this->J2000_Dec = J2000_Dec;
            this->magnitude = magnitude;
        }

        void setId(std::string id) {
            this->id = id;
        }

        void setJ200_R_a(double J200_R_a) {
            this->J2000_R_a = J2000_R_a;
        }

        void setJ200_Dec(double J200_Dec) {
            this->J2000_Dec = J200_Dec;
        }

        void setMagnitude(double magnitude) {
            this->magnitude = magnitude;
        }

        void setCurr_R_a(double curr_R_a) {
            this->curr_R_a = curr_R_a;
        }

        void setCurr_Dec(double curr_Dec) {
            this->curr_Dec = curr_Dec;
        }

        std::string getId() {
            return id;
        }

        double getJ200_R_a() {
            return J2000_R_a;

        }
        
        double getJ200_Dec() {
            return J2000_Dec;
        }

        double getMagnitude() {
            return magnitude;
        }

        double getCurr_R_a() {
            return curr_R_a;
        }

        double getCurr_dec() {
            return curr_Dec;
        }
};
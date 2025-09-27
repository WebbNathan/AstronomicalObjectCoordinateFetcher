#include <iostream>
#include <string>
#include "AstronomicalObjectsProto.h"

AstronomicalObject::AstronomicalObject(std::string id, double J2000_R_a, double J2000_Dec, 
                   double magnitude) 
{
    this->id = id;
    this->J2000_R_a = J2000_R_a;
    this->J2000_Dec = J2000_Dec;
    this->magnitude = magnitude;
}

AstronomicalObject::AstronomicalObject() {
    this->id = "Blank";
    this->J2000_R_a = 0;
    this->J2000_Dec = 0;
    this->magnitude = 0;
}

void AstronomicalObject::setId(std::string id) {
    this->id = id;
}

void AstronomicalObject::setJ200_R_a(double J200_R_a) {
    this->J2000_R_a = J2000_R_a;
}

void AstronomicalObject::setJ200_Dec(double J200_Dec) {
    this->J2000_Dec = J200_Dec;
}

void AstronomicalObject::setMagnitude(double magnitude) {
    this->magnitude = magnitude;
}

void AstronomicalObject::setCurr_R_a(double curr_R_a) {
    this->curr_R_a = curr_R_a;
}

void AstronomicalObject::setCurr_Dec(double curr_Dec) {
    this->curr_Dec = curr_Dec;
}

std::string AstronomicalObject::getId() {
    return id;
}

double AstronomicalObject::getJ200_R_a() {
    return J2000_R_a;

}

double AstronomicalObject::getJ200_Dec() {
    return J2000_Dec;
}

double AstronomicalObject::getMagnitude() {
    return magnitude;
}

double AstronomicalObject::getCurr_R_a() {
    return curr_R_a;
}

double AstronomicalObject::getCurr_dec() {
    return curr_Dec;
}
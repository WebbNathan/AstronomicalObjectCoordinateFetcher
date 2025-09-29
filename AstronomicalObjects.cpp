#include <iostream>
#include <string>
#include "AstronomicalObjects.h"
#include "Control.h"

AstronomicalObject::AstronomicalObject() {
    this->id = 0;
    this->J2000_R_a.hours = 0;
    this->J2000_R_a.minutes = 0;
    this->J2000_R_a.seconds = 0;
    this->J2000_R_a_PM = 0;
    this->J2000_R_a_PMSD - 0;
    this->J2000_Dec.sign = 0;
    this->J2000_Dec.degrees = 0;
    this->J2000_Dec.arcminutes = 0;
    this->J2000_Dec.arcseconds = 0;
    this->magnitude = 0;
}

void AstronomicalObject::setId(int id) {
    this->id = id;
}

void AstronomicalObject::setJ2000_R_a_Hour(double J2000_R_a_Hour) {
    this->J2000_R_a.hours = J2000_R_a_Hour;
}

void AstronomicalObject::setJ2000_R_a_Min(double J2000_R_a_Min) {
    this->J2000_R_a.minutes = J2000_R_a_Min;
}

void AstronomicalObject::setJ2000_R_a_Sec(double J2000_R_a_Sec) {
    this->J2000_R_a.seconds = J2000_R_a_Sec;
}

void AstronomicalObject::setJ2000_R_a_PM(double J2000_R_a_PM) {
    this->J2000_R_a_PM = J2000_R_a_PM;
}

void AstronomicalObject::setJ2000_R_a_PMSD(double J2000_R_a_PMSD) {
    this->J2000_R_a_PMSD = J2000_R_a_PMSD;
}

void AstronomicalObject::setJ2000_DecSign(std::string decSign) {
    this->J2000_Dec.sign = stoi(decSign + "1"); //totally might not work
}

void AstronomicalObject::setJ2000_Dec_deg(double J2000_Dec_deg) {
    this->J2000_Dec.degrees = J2000_Dec_deg;
}

void AstronomicalObject::setJ2000_Dec_min(double J2000_Dec_min) {
    this->J2000_Dec.arcminutes = J2000_Dec_min;
}

void AstronomicalObject::setJ2000_Dec_sec(double J2000_Dec_sec) {
    this->J2000_Dec.arcseconds = J2000_Dec_sec;
}

void AstronomicalObject::setMagnitude(double magnitude) {
    this->magnitude = magnitude;
}

void AstronomicalObject::setCurr_R_a(R_a curr_R_a) { 
    this->currR_a = curr_R_a;
}

void AstronomicalObject::setCurr_Dec(Dec curr_Dec) {
    this->currDec = curr_Dec;
}

void AstronomicalObject::setAlt(double Alt) {
    this->Alt = Alt;
}

void AstronomicalObject::setAz(double Az) {
    this->Az = Az;
}

int AstronomicalObject::getId() {
    return id;
}

R_a AstronomicalObject::getJ2000_R_a() {
    return J2000_R_a;
}

double AstronomicalObject::getJ2000_R_a_PM() {
    return J2000_R_a_PM;
}

double AstronomicalObject::getJ2000_R_a_PMSD() {
    return J2000_R_a_PMSD;
}

Dec AstronomicalObject::getJ2000_Dec() {
    return J2000_Dec;
}

double AstronomicalObject::getMagnitude() {
    return magnitude;
}

R_a AstronomicalObject::getCurr_R_a() {
    return currR_a;
}

Dec AstronomicalObject::getCurr_Dec() {
    return currDec;
}

double AstronomicalObject::getAlt() {
    return Alt;
}

double AstronomicalObject::getAz() {
    return Az;
}
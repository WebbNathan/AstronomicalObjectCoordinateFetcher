#include <iostream>
#include <string>
#include "AstronomicalObjects.h"

AstronomicalObject::AstronomicalObject() {
    this->id = 0;
    this->J2000_R_a_Hour = 0;
    this->J2000_R_a_Min = 0;
    this->J2000_R_a_Sec = 0;
    this->J2000_R_a_PM = 0;
    this->J2000_R_a_PMSD - 0;
    this->decSign = "";
    this->J2000_Dec_deg = 0;
    this->J2000_Dec_min = 0;
    this->J2000_Dec_sec = 0;
    this->magnitude = 0;
}

void AstronomicalObject::setId(int id) {
    this->id = id;
}

void AstronomicalObject::setJ2000_R_a_Hour(double J2000_R_a_Hour) {
    this->J2000_R_a_Hour = J2000_R_a_Hour;
}

void AstronomicalObject::setJ2000_R_a_Min(double J2000_R_a_Min) {
    this->J2000_R_a_Min = J2000_R_a_Min;
}

void AstronomicalObject::setJ2000_R_a_Sec(double J2000_R_a_Sec) {
    this->J2000_R_a_Sec = J2000_R_a_Sec;
}

void AstronomicalObject::setJ2000_R_a_PM(double J2000_R_a_PM) {
    this->J2000_R_a_PM = J2000_R_a_PM;
}

void AstronomicalObject::setJ2000_R_a_PMSD(double J2000_R_a_PMSD) {
    this->J2000_R_a_PMSD = J2000_R_a_PMSD;
}

void AstronomicalObject::setDecSign(std::string decSign) {
    this->decSign = decSign;
}

void AstronomicalObject::setJ2000_Dec_deg(double J2000_Dec_deg) {
    this->J2000_Dec_deg = J2000_Dec_deg;
}

void AstronomicalObject::setJ2000_Dec_min(double J2000_Dec_min) {
    this->J2000_Dec_min = J2000_Dec_min;
}

void AstronomicalObject::setJ2000_Dec_sec(double J2000_Dec_sec) {
    this->J2000_Dec_sec = J2000_Dec_sec;
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

int AstronomicalObject::getId() {
    return id;
}

double AstronomicalObject::getJ2000_R_a_Hour() {
    return J2000_R_a_Hour;
}

double AstronomicalObject::getJ2000_R_a_Min() {
    return J2000_R_a_Min;
}

double AstronomicalObject::getJ2000_R_a_Sec() {
    return J2000_R_a_Sec;
}

double AstronomicalObject::getJ2000_R_a_PM() {
    return J2000_R_a_PM;
}

double AstronomicalObject::getJ2000_R_a_PMSD() {
    return J2000_R_a_PMSD;
}

std::string AstronomicalObject::getDecSign() {
    return decSign;
}

double AstronomicalObject::getJ2000_Dec_deg() {
    return J2000_Dec_deg;
}

double AstronomicalObject::getJ2000_Dec_min() {
    return J2000_Dec_min;
}

double AstronomicalObject::getJ2000_Dec_sec() {
    return J2000_Dec_sec;
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
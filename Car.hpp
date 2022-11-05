// Car.h
#pragma once

#include "Misc.h"

using namespace std;

string manufacturerArray[] = { "Ford", "Opel", "Toyota", "Volkswagen", "Volvo" };
string ford[] = { "Focus", "Fiesta", "Mondeo", "Puma", "Kuga" };
string opel[] = { "Astra", "Adam", "Corsa", "Mokka", "Vectra" };
string toyota[] = { "Prius", "Camry", "Supra", "Yaris", "Corolla" };
string volkswagen[] = { "Golf", "Passat", "Polo", "Scirocco", "Jetta" };
string volvo[] = { "S60", "V50", "V70", "XC90", "S90" };

class Car {
public:
    string manufacturer;
    string model;
    int year;

    Car() {
        manufacturer = manufacturerArray[randomNumber(0, 4)];
        if (manufacturer == "Ford") {
            model = ford[randomNumber(0, 4)];
        }
        else if (manufacturer == "Opel") {
            model = opel[randomNumber(0, 4)];
        }
        else if (manufacturer == "Toyota") {
            model = toyota[randomNumber(0, 4)];
        }
        else if (manufacturer == "Volkswagen") {
            model = volkswagen[randomNumber(0, 4)];
        }
        else if (manufacturer == "Volvo") {
            model = volvo[randomNumber(0, 4)];
        }
        year = randomNumber(2000, 2022);
    }

    friend ostream& operator << (ostream& os, const Car* ca) {
        os << ca->manufacturer << " " << ca->model << " " << ca->year << "\n";
        return os;
    }

    friend ostream& operator << (ostream& os, const Car& ca) {
        os << ca.manufacturer << " " << ca.model << " " << ca.year << "\n";
        return os;
    }
	
    bool operator == (const Car& car2) {
        if (manufacturer == car2.manufacturer && model == car2.model && year == car2.year) return true;
        return false;
    }
	
};

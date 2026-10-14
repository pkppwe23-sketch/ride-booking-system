#pragma once
#include <iostream>
#include <string>
using namespace std;

class Driver {
public:
    string id;
    string name;
    double latitude;
    double longitude;
    bool available;

    Driver(string id, string name, double lat, double lon) {
        this->id = id;
        this->name = name;
        latitude = lat;
        longitude = lon;
        available = true;
    }

    bool acceptRide() {
        cout << name << " accepted the ride.\n";
        available = false;
        return true;
    }
};

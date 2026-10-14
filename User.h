#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
public:
    string id;
    string name;
    double latitude;
    double longitude;

    User(string id, string name, double lat, double lon) {
        this->id = id;
        this->name = name;
        latitude = lat;
        longitude = lon;
    }

    void bookRide() {
        cout << name << " booked a ride.\n";
    }
};

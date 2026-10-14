#pragma once
#include <string>
using namespace std;

class Ride {
public:
    string rideId;
    string userId;
    string driverId;
    string status;
    double fare;

    Ride(string id, string user, string driver) {
        rideId = id;
        userId = user;
        driverId = driver;
        status = "ACCEPTED";
        fare = 0;
    }

    void startRide() {
        status = "IN_PROGRESS";
    }

    void completeRide() {
        status = "COMPLETED";
    }
};

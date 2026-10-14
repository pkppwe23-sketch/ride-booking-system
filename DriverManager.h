#pragma once
#include "Driver.h"
#include "LocationFinder.h"
#include "User.h"
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class DriverManager {
private:
    vector<Driver*> drivers;
    LocationFinder locationFinder;

public:
    void addDriver(Driver* driver) {
        drivers.push_back(driver);
    }

    Driver* findDriver(User& user) {
        priority_queue<
            pair<double, Driver*>,
            vector<pair<double, Driver*>>,
            greater<pair<double, Driver*>>
        > minHeap;

        for (Driver* driver : drivers) {
            if (driver->available) {
                double distance = locationFinder.getDistance(
                    user.latitude, user.longitude,
                    driver->latitude, driver->longitude
                );

                minHeap.push({distance, driver});
            }
        }

        while (!minHeap.empty()) {
            Driver* driver = minHeap.top().second;
            minHeap.pop();

            if (driver->acceptRide()) {
                return driver;
            }
        }

        return nullptr;
    }
};

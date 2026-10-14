#pragma once
#include <iostream>
using namespace std;

class PaymentService {
public:
    void pay(double fare) {
        double commission = fare * 0.20;
        double driverEarning = fare - commission;

        cout << "Total fare: Rs. " << fare << '\n';
        cout << "Platform commission: Rs. "
             << commission << '\n';
        cout << "Driver earning: Rs. "
             << driverEarning << '\n';
    }
};

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "User.h"
#include "Driver.h"
#include "Ride.h"
#include "DriverManager.h"
#include "OTPService.h"
#include "PaymentService.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    User user("U1", "Rahul", 23.3441, 85.3096);

    Driver d1("D1", "Aman", 23.3500, 85.3200);
    Driver d2("D2", "Rohit", 23.3450, 85.3100);

    DriverManager manager;
    manager.addDriver(&d1);
    manager.addDriver(&d2);

    user.bookRide();

    Driver* driver = manager.findDriver(user);

    if (driver == nullptr) {
        cout << "No driver available.\n";
        return 0;
    }

    Ride ride("R1", user.id, driver->id);

    OTPService otpService;
    int otp = otpService.generateOTP();

    // Demo only: real apps send the OTP to the user's phone.
    cout << "OTP sent to user: " << otp << '\n';
    cout << "Enter OTP: ";

    int enteredOTP;
    cin >> enteredOTP;

    if (!otpService.verifyOTP(otp, enteredOTP)) {
        cout << "Wrong OTP. Ride not started.\n";
        driver->available = true;
        return 0;
    }

    ride.startRide();
    cout << "Ride started.\n";

    ride.completeRide();
    cout << "Ride completed.\n";

    PaymentService payment;
    payment.pay(200);

    driver->available = true;
    cout << driver->name << " is now available for another ride.\n";

    return 0;
}

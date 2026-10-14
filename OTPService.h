#pragma once
#include <cstdlib>
#include <ctime>

class OTPService {
public:
    int generateOTP() {
        return 1000 + rand() % 9000;
    }

    bool verifyOTP(int original, int entered) {
        return original == entered;
    }
};

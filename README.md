# Ride Booking System (LLD)

A simple C++17 low-level design project inspired by ride-hailing apps such as Uber and Rapido.

## Features
- User can book a ride.
- DriverManager selects the nearest available driver using a min-heap.
- OTP verification starts the ride.
- Driver completes the ride.
- Payment service calculates platform commission and driver earnings.
- LocationFinder provides a simple distance calculation for this demo.

## Files
- `User.h` — passenger details
- `Driver.h` — driver details and availability
- `Ride.h` — ride details and status
- `LocationFinder.h` — distance calculation
- `DriverManager.h` — available drivers and nearest-driver selection
- `OTPService.h` — OTP generation and verification
- `PaymentService.h` — fare split calculation
- `main.cpp` — demo workflow

## Build
```bash
g++ -std=c++17 main.cpp -o ride
```
Run on Windows with `./ride.exe` in PowerShell, or run `./ride` on Linux/macOS.

This is an educational demo. Distances and payment are simulated; Google Maps and a real payment gateway are not connected.
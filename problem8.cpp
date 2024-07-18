#include <iostream>

using namespace std;

class ParkingGarage {
private:
    int numCars;
public:
    ParkingGarage() : numCars(0) {}

    int getNumCars() const {
        return numCars;
    }

    ParkingGarage& operator++() {
        numCars++;
        return *this;
    }

    ParkingGarage& operator--() {
        if (numCars > 0) {
            numCars--;
        }
        return *this;
    }
};

class Time {
private:
    int hours, minutes, seconds;
    int yr, mon, day;
public:
    void set() {
        cout << "enter date (year/month/day): ";
        cin >> yr >> mon >> day;
        cout << "enter time (hr/min/sec)(use 24hr formate): ";
        cin >> hours >> minutes >> seconds;
    }

    int getHours() const {
        return hours;
    }

    int getDays() const {
        return day;
    }

    int getYears() const {
        return yr;
    }
};

int calculateCharges(const Time& entryTime, const Time& exitTime) {
    int hours = ((exitTime.getYears() - entryTime.getYears()) * 365 * 24) + ((exitTime.getDays() - entryTime.getDays()) * 24) + (exitTime.getHours() - entryTime.getHours());
    
    if (hours <= 3) {
        return 2.00; 
    } else if (hours <= 24) {
        return 2.00 + (hours - 3) * 0.50; 
    } else {
        int days = hours / 24;
        hours %= 24;
        return days * 8.00 + (hours <= 3? 2.00 : 2.00 + (hours - 3) * 0.50); 
    }
}

int main() {
    ParkingGarage garage;
    Time entryTime, exitTime;

    cout << "Enter the entry date and time:" << endl;
    entryTime.set();
    ++garage;
    cout << "Number of cars in the garage: " << garage.getNumCars() << endl;

    cout << "Enter the exit date and time:" << endl;
    exitTime.set();
    --garage;

    int charges = calculateCharges(entryTime, exitTime);
    cout << "Parking charges: $" << charges << endl;
    cout << "Number of cars in the garage: " << garage.getNumCars() << endl;

    return 0;
}

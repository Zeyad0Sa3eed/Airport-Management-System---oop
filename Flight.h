#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
using namespace std;


class Flight {
private:
    string flightID;
    string destination;
    int    capacity;
    int    bookedSeats;

public:
    // --- Constructors (Overloading) ---
    Flight();
    Flight(string flightID, string destination, int capacity);

    // --- Getters ---
    string getFlightID()       const;
    string getDestination()    const;
    int    getCapacity()       const;
    int    getBookedSeats()    const;
    int    getAvailableSeats() const;

    // --- Setters ---
    void setFlightID(string flightID);
    void setDestination(string destination);
    void setCapacity(int capacity);

    // --- Methods ---
    bool bookSeat();
    bool hasAvailableSeats() const;

    // --- Display (Function Overloading) ---
    void display()           const;
    void display(bool title) const;

    // --- Friend Function ---
    friend bool sameDestination(const Flight& f1, const Flight& f2);
};

#endif

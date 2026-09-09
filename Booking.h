#ifndef BOOKING_H
#define BOOKING_H

#include "Passenger.h"
#include "Flight.h"


class Booking {
private:
    int    bookingID;
    int    passengerID;
    string passengerName;
    string flightID;
    string destination;
    int    ticketNumber;

public:
    // --- Constructors (Overloading) ---
    Booking();
    Booking(int bookingID, Passenger& passenger, Flight& flight, int ticketNumber);

    // --- Getters ---
    int    getBookingID()    const;
    int    getPassengerID()  const;
    string getFlightID()     const;
    int    getTicketNumber() const;

    // --- Display ---
    void display() const;
};

#endif

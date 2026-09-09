#ifndef PASSENGER_H
#define PASSENGER_H

#include "Person.h"


class Passenger : public Person {
private:
    int    ticketNumber;
    string bookingInfo;
    bool   hasTicket;

public:
    // --- Constructors (Overloading) ---
    Passenger();
    Passenger(string name, int id);
    Passenger(string name, int id, int ticketNumber);

    // --- Getters ---
    int    getTicketNumber() const;
    string getBookingInfo()  const;
    bool   getHasTicket()    const;

    // --- Setters ---
    void setTicketNumber(int ticketNumber);
    void setBookingInfo(string info);
    void setHasTicket(bool status);

    // --- Override display (Polymorphism) ---
    void display() const override;

    // --- Friend Function ---
    friend bool samePassenger(const Passenger& p1, const Passenger& p2);
};

#endif

#include "../include/Passenger.h"

// ╔══════════════════════════════════════════════════╗
// ║        Passenger Class - Implementation         ║
// ╚══════════════════════════════════════════════════╝

Passenger::Passenger() : Person() {
    ticketNumber = 0;
    bookingInfo  = "No Booking";
    hasTicket    = false;
}

Passenger::Passenger(string name, int id) : Person(name, id) {
    ticketNumber = 0;
    bookingInfo  = "No Booking";
    hasTicket    = false;
}

Passenger::Passenger(string name, int id, int ticketNumber) : Person(name, id) {
    this->ticketNumber = ticketNumber;
    bookingInfo        = "No Booking";
    hasTicket          = false;
}

int    Passenger::getTicketNumber() const { return ticketNumber; }
string Passenger::getBookingInfo()  const { return bookingInfo;  }
bool   Passenger::getHasTicket()    const { return hasTicket;    }

void Passenger::setTicketNumber(int t)   { ticketNumber = t; }
void Passenger::setBookingInfo(string i) { bookingInfo  = i; }
void Passenger::setHasTicket(bool s)     { hasTicket    = s; }

void Passenger::display() const {
    cout << "  Passenger Name   : " << name        << endl;
    cout << "  Passenger ID     : " << id          << endl;
    cout << "  Ticket Number    : ";
    if (hasTicket) cout << ticketNumber            << endl;
    else           cout << "Not Booked Yet"        << endl;
    cout << "  Booking Info     : " << bookingInfo << endl;
}

// ---- Friend Function --------------------------------
bool samePassenger(const Passenger& p1, const Passenger& p2) {
    return p1.id == p2.id;
}

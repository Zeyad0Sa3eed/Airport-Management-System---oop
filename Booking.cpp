#include "../include/Booking.h"


Booking::Booking() {
    bookingID     = 0;
    passengerID   = 0;
    flightID      = "N/A";
    passengerName = "N/A";
    destination   = "N/A";
    ticketNumber  = 0;
}

Booking::Booking(int bookingID, Passenger& passenger, Flight& flight, int ticketNumber) {
    this->bookingID     = bookingID;
    this->passengerID   = passenger.getId();
    this->passengerName = passenger.getName();
    this->flightID      = flight.getFlightID();
    this->destination   = flight.getDestination();
    this->ticketNumber  = ticketNumber;
}

int    Booking::getBookingID()    const { return bookingID;    }
int    Booking::getPassengerID()  const { return passengerID;  }
string Booking::getFlightID()     const { return flightID;     }
int    Booking::getTicketNumber() const { return ticketNumber; }

void Booking::display() const {
    cout << "  Booking ID       : " << bookingID     << endl;
    cout << "  Passenger Name   : " << passengerName << endl;
    cout << "  Passenger ID     : " << passengerID   << endl;
    cout << "  Flight ID        : " << flightID      << endl;
    cout << "  Destination      : " << destination   << endl;
    cout << "  Ticket Number    : " << ticketNumber  << endl;
}

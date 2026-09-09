#include "../include/Flight.h"



Flight::Flight() {
    flightID    = "N/A";
    destination = "N/A";
    capacity    = 0;
    bookedSeats = 0;
}

Flight::Flight(string flightID, string destination, int capacity) {
    this->flightID    = flightID;
    this->destination = destination;
    this->capacity    = capacity;
    bookedSeats       = 0;
}

string Flight::getFlightID()       const { return flightID;               }
string Flight::getDestination()    const { return destination;            }
int    Flight::getCapacity()       const { return capacity;               }
int    Flight::getBookedSeats()    const { return bookedSeats;            }
int    Flight::getAvailableSeats() const { return capacity - bookedSeats; }

void Flight::setFlightID(string id)   { flightID    = id; }
void Flight::setDestination(string d) { destination = d;  }
void Flight::setCapacity(int c)       { capacity    = c;  }

bool Flight::bookSeat() {
    if (bookedSeats < capacity) { bookedSeats++; return true; }
    return false;
}

bool Flight::hasAvailableSeats() const { return bookedSeats < capacity; }

void Flight::display() const { display(true); }

void Flight::display(bool title) const {
    if (title) cout << "  ---------------------------" << endl;
    cout << "  Flight ID        : " << flightID             << endl;
    cout << "  Destination      : " << destination          << endl;
    cout << "  Capacity         : " << capacity             << endl;
    cout << "  Booked Seats     : " << bookedSeats          << endl;
    cout << "  Available Seats  : " << getAvailableSeats()  << endl;
}

// ---- Friend Function --------------------------------
bool sameDestination(const Flight& f1, const Flight& f2) {
    return f1.destination == f2.destination;
}

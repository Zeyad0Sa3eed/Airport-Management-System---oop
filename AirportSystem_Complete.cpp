// ============================================================
// FILE: Person.h
// ============================================================
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int    id;

public:
    Person();
    Person(string name, int id);

    string getName() const;
    int    getId()   const;
    void   setName(string name);
    void   setId(int id);

    virtual void display() const;
};

#endif


// ============================================================
// FILE: Person.cpp
// ============================================================
// #include "Person.h"   <-- uncomment when using separate files

Person::Person() {
    name = "Unknown";
    id   = 0;
}

Person::Person(string name, int id) {
    this->name = name;
    this->id   = id;
}

string Person::getName() const { return name; }
int    Person::getId()   const { return id;   }

void Person::setName(string name) { this->name = name; }
void Person::setId(int id)        { this->id   = id;   }

void Person::display() const {
    cout << "  Name : " << name << endl;
    cout << "  ID   : " << id   << endl;
}


// ============================================================
// FILE: Passenger.h
// ============================================================
#ifndef PASSENGER_H
#define PASSENGER_H

// #include "Person.h"   <-- uncomment when using separate files

class Passenger : public Person {
private:
    int    ticketNumber;
    string bookingInfo;
    bool   hasTicket;

public:
    Passenger();
    Passenger(string name, int id);
    Passenger(string name, int id, int ticketNumber);

    int    getTicketNumber() const;
    string getBookingInfo()  const;
    bool   getHasTicket()    const;

    void setTicketNumber(int ticketNumber);
    void setBookingInfo(string info);
    void setHasTicket(bool status);

    void display() const override;

    friend bool samePassenger(const Passenger& p1, const Passenger& p2);
};

#endif


// ============================================================
// FILE: Passenger.cpp
// ============================================================
// #include "Passenger.h"   <-- uncomment when using separate files

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

void Passenger::setTicketNumber(int t)   { ticketNumber = t;    }
void Passenger::setBookingInfo(string i) { bookingInfo  = i;    }
void Passenger::setHasTicket(bool s)     { hasTicket    = s;    }

void Passenger::display() const {
    cout << "  Passenger Name   : " << name         << endl;
    cout << "  Passenger ID     : " << id           << endl;
    cout << "  Ticket Number    : ";
    if (hasTicket) cout << ticketNumber             << endl;
    else           cout << "Not Booked Yet"         << endl;
    cout << "  Booking Info     : " << bookingInfo  << endl;
}

bool samePassenger(const Passenger& p1, const Passenger& p2) {
    return p1.id == p2.id;
}


// ============================================================
// FILE: Flight.h
// ============================================================
#ifndef FLIGHT_H
#define FLIGHT_H

// #include <iostream>   <-- uncomment when using separate files
// #include <string>
// using namespace std;

class Flight {
private:
    string flightID;
    string destination;
    int    capacity;
    int    bookedSeats;

public:
    Flight();
    Flight(string flightID, string destination, int capacity);

    string getFlightID()      const;
    string getDestination()   const;
    int    getCapacity()      const;
    int    getBookedSeats()   const;
    int    getAvailableSeats() const;

    void setFlightID(string flightID);
    void setDestination(string destination);
    void setCapacity(int capacity);

    bool bookSeat();
    bool hasAvailableSeats() const;

    void display()           const;
    void display(bool title) const;   // Function Overloading

    friend bool sameDestination(const Flight& f1, const Flight& f2);
};

#endif


// ============================================================
// FILE: Flight.cpp
// ============================================================
// #include "Flight.h"   <-- uncomment when using separate files

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
    this->bookedSeats = 0;
}

string Flight::getFlightID()       const { return flightID;              }
string Flight::getDestination()    const { return destination;           }
int    Flight::getCapacity()       const { return capacity;              }
int    Flight::getBookedSeats()    const { return bookedSeats;           }
int    Flight::getAvailableSeats() const { return capacity - bookedSeats; }

void Flight::setFlightID(string id)     { flightID    = id;   }
void Flight::setDestination(string d)   { destination = d;    }
void Flight::setCapacity(int c)         { capacity    = c;    }

bool Flight::bookSeat() {
    if (bookedSeats < capacity) { bookedSeats++; return true; }
    return false;
}

bool Flight::hasAvailableSeats() const { return bookedSeats < capacity; }

void Flight::display() const { display(true); }

void Flight::display(bool title) const {
    if (title) cout << "  ---------------------------" << endl;
    cout << "  Flight ID        : " << flightID              << endl;
    cout << "  Destination      : " << destination           << endl;
    cout << "  Capacity         : " << capacity              << endl;
    cout << "  Booked Seats     : " << bookedSeats           << endl;
    cout << "  Available Seats  : " << getAvailableSeats()   << endl;
}

bool sameDestination(const Flight& f1, const Flight& f2) {
    return f1.destination == f2.destination;
}


// ============================================================
// FILE: Booking.h
// ============================================================
#ifndef BOOKING_H
#define BOOKING_H

// #include "Passenger.h"   <-- uncomment when using separate files
// #include "Flight.h"

class Booking {
private:
    int    bookingID;
    int    passengerID;
    string flightID;
    string passengerName;
    string destination;
    int    ticketNumber;

public:
    Booking();
    Booking(int bookingID, Passenger& passenger, Flight& flight, int ticketNumber);

    int    getBookingID()    const;
    int    getPassengerID()  const;
    string getFlightID()     const;
    int    getTicketNumber() const;

    void display() const;
};

#endif


// ============================================================
// FILE: Booking.cpp
// ============================================================
// #include "Booking.h"   <-- uncomment when using separate files

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


// ============================================================
// FILE: main.cpp
// ============================================================
// #include "Person.h"      <-- uncomment when using separate files
// #include "Passenger.h"
// #include "Flight.h"
// #include "Booking.h"

// ---- Constants ----
const int MAX_FLIGHTS    = 50;
const int MAX_PASSENGERS = 100;
const int MAX_BOOKINGS   = 200;

// ---- Global Arrays of Objects ----
Flight    flights[MAX_FLIGHTS];
Passenger passengers[MAX_PASSENGERS];
Booking   bookings[MAX_BOOKINGS];

int flightCount    = 0;
int passengerCount = 0;
int bookingCount   = 0;
int ticketCounter  = 1000;

// ---- Helpers ----
void printLine()              { cout << "  ==========================================" << endl; }
void printHeader(string title){ printLine(); cout << "     " << title << endl; printLine(); }

int findFlight(string flightID) {
    for (int i = 0; i < flightCount; i++)
        if (flights[i].getFlightID() == flightID) return i;
    return -1;
}

int findPassenger(int id) {
    for (int i = 0; i < passengerCount; i++)
        if (passengers[i].getId() == id) return i;
    return -1;
}

// ---- Menu Actions ----
void addFlight() {
    printHeader("ADD NEW FLIGHT");
    if (flightCount >= MAX_FLIGHTS) { cout << "  [!] Storage full." << endl; return; }

    string flightID, destination;
    int capacity;

    cout << "  Enter Flight ID      : "; cin >> flightID;
    if (findFlight(flightID) != -1) { cout << "  [!] Flight ID already exists!" << endl; return; }

    cout << "  Enter Destination    : "; cin >> destination;
    cout << "  Enter Capacity       : "; cin >> capacity;
    if (capacity <= 0) { cout << "  [!] Capacity must be > 0." << endl; return; }

    flights[flightCount++] = Flight(flightID, destination, capacity);
    cout << endl << "  [+] Flight added successfully!" << endl;
}

void addPassenger() {
    printHeader("ADD NEW PASSENGER");
    if (passengerCount >= MAX_PASSENGERS) { cout << "  [!] Storage full." << endl; return; }

    string name; int id;
    cout << "  Enter Passenger Name : "; cin >> name;
    cout << "  Enter Passenger ID   : "; cin >> id;
    if (findPassenger(id) != -1) { cout << "  [!] Passenger ID already exists!" << endl; return; }

    passengers[passengerCount++] = Passenger(name, id);
    cout << endl << "  [+] Passenger registered successfully!" << endl;
}

void bookTicket() {
    printHeader("BOOK A TICKET");
    if (flightCount    == 0) { cout << "  [!] No flights available."    << endl; return; }
    if (passengerCount == 0) { cout << "  [!] No passengers registered." << endl; return; }
    if (bookingCount >= MAX_BOOKINGS) { cout << "  [!] Booking storage full." << endl; return; }

    int passengerID; string flightID;

    cout << "  Enter Passenger ID   : "; cin >> passengerID;
    int pIdx = findPassenger(passengerID);
    if (pIdx == -1)                         { cout << "  [!] Passenger not found!"        << endl; return; }
    if (passengers[pIdx].getHasTicket())    { cout << "  [!] Already has a booking!"      << endl; return; }

    cout << "  Enter Flight ID      : "; cin >> flightID;
    int fIdx = findFlight(flightID);
    if (fIdx == -1)                         { cout << "  [!] Flight not found!"            << endl; return; }
    if (!flights[fIdx].hasAvailableSeats()) { cout << "  [!] Flight is fully booked!"      << endl; return; }

    int newTicket = ticketCounter++;
    flights[fIdx].bookSeat();
    passengers[pIdx].setTicketNumber(newTicket);
    passengers[pIdx].setBookingInfo("Booked on flight " + flightID + " to " + flights[fIdx].getDestination());
    passengers[pIdx].setHasTicket(true);
    bookings[bookingCount++] = Booking(bookingCount + 1, passengers[pIdx], flights[fIdx], newTicket);

    cout << endl << "  [+] Ticket booked successfully!" << endl;
    cout << "      Ticket Number : " << newTicket       << endl;
}

void viewFlights() {
    printHeader("ALL FLIGHTS");
    if (flightCount == 0) { cout << "  No flights added yet." << endl; return; }
    for (int i = 0; i < flightCount; i++) {
        cout << endl << "  Flight #" << (i + 1) << endl;
        flights[i].display();
    }
}

void viewPassengers() {
    printHeader("ALL PASSENGERS");
    if (passengerCount == 0) { cout << "  No passengers registered yet." << endl; return; }
    for (int i = 0; i < passengerCount; i++) {
        cout << endl << "  Passenger #" << (i + 1) << endl;
        passengers[i].display();
    }
}

void viewBookings() {
    printHeader("ALL BOOKINGS");
    if (bookingCount == 0) { cout << "  No bookings made yet." << endl; return; }
    for (int i = 0; i < bookingCount; i++) {
        cout << endl << "  Booking #" << (i + 1) << endl;
        bookings[i].display();
    }
}

void showMenu() {
    cout << endl;
    printLine();
    cout << "       AIRPORT MANAGEMENT SYSTEM"   << endl;
    cout << "       ACU - OOP Project | C++"      << endl;
    printLine();
    cout << "    1.  Add Flight"                  << endl;
    cout << "    2.  Add Passenger"               << endl;
    cout << "    3.  Book Ticket"                 << endl;
    cout << "    4.  View All Flights"            << endl;
    cout << "    5.  View All Passengers"         << endl;
    cout << "    6.  View All Bookings"           << endl;
    cout << "    7.  Exit"                        << endl;
    printLine();
    cout << "    Enter your choice: ";
}

int main() {
    cout << endl;
    printLine();
    cout << "    Welcome to Airport Management System!" << endl;
    printLine();

    int choice;
    do {
        showMenu();
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: addFlight();      break;
            case 2: addPassenger();   break;
            case 3: bookTicket();     break;
            case 4: viewFlights();    break;
            case 5: viewPassengers(); break;
            case 6: viewBookings();   break;
            case 7: printLine(); cout << "    Goodbye! See you next flight." << endl; printLine(); break;
            default: cout << "  [!] Invalid choice. Try again." << endl; break;
        }
    } while (choice != 7);

    return 0;
}

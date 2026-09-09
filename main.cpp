#include "../include/Person.h"
#include "../include/Passenger.h"
#include "../include/Flight.h"
#include "../include/Booking.h"

// ╔══════════════════════════════════════════════════╗
// ║          MAIN - Menu & Entry Point              ║
// ║  Responsible Team : Team 3                      ║
// ╚══════════════════════════════════════════════════╝

// ---- Storage Constants ------------------------------
const int MAX_FLIGHTS    = 50;
const int MAX_PASSENGERS = 100;
const int MAX_BOOKINGS   = 200;

// ---- Arrays of Objects ------------------------------
Flight    flights[MAX_FLIGHTS];
Passenger passengers[MAX_PASSENGERS];
Booking   bookings[MAX_BOOKINGS];

int flightCount    = 0;
int passengerCount = 0;
int bookingCount   = 0;
int ticketCounter  = 1000;

// ---- Helper Utilities -------------------------------
void printLine() {
    cout << "  ==========================================" << endl;
}

void printHeader(string title) {
    printLine();
    cout << "     " << title << endl;
    printLine();
}

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

// ---- Menu Actions -----------------------------------
void addFlight() {
    printHeader("ADD NEW FLIGHT");
    if (flightCount >= MAX_FLIGHTS) { cout << "  [!] Storage full." << endl; return; }

    string flightID, destination;
    int    capacity;

    cout << "  Enter Flight ID      : "; cin >> flightID;
    if (findFlight(flightID) != -1) { cout << "  [!] Flight ID already exists!" << endl; return; }
    cout << "  Enter Destination    : "; cin >> destination;
    cout << "  Enter Capacity       : "; cin >> capacity;
    if (capacity <= 0) { cout << "  [!] Capacity must be greater than 0." << endl; return; }

    flights[flightCount++] = Flight(flightID, destination, capacity);
    cout << endl << "  [+] Flight added successfully!" << endl;
}

void addPassenger() {
    printHeader("ADD NEW PASSENGER");
    if (passengerCount >= MAX_PASSENGERS) { cout << "  [!] Storage full." << endl; return; }

    string name;
    int    id;

    cout << "  Enter Passenger Name : "; cin >> name;
    cout << "  Enter Passenger ID   : "; cin >> id;
    if (findPassenger(id) != -1) { cout << "  [!] Passenger ID already exists!" << endl; return; }

    passengers[passengerCount++] = Passenger(name, id);
    cout << endl << "  [+] Passenger registered successfully!" << endl;
}

void bookTicket() {
    printHeader("BOOK A TICKET");
    if (flightCount    == 0) { cout << "  [!] No flights available. Add a flight first."    << endl; return; }
    if (passengerCount == 0) { cout << "  [!] No passengers registered. Add a passenger first." << endl; return; }
    if (bookingCount   >= MAX_BOOKINGS) { cout << "  [!] Booking storage full." << endl; return; }

    int    passengerID;
    string flightID;

    cout << "  Enter Passenger ID   : "; cin >> passengerID;
    int pIdx = findPassenger(passengerID);
    if (pIdx == -1)                        { cout << "  [!] Passenger not found!"       << endl; return; }
    if (passengers[pIdx].getHasTicket())   { cout << "  [!] Passenger already booked!"  << endl; return; }

    cout << "  Enter Flight ID      : "; cin >> flightID;
    int fIdx = findFlight(flightID);
    if (fIdx == -1)                         { cout << "  [!] Flight not found!"          << endl; return; }
    if (!flights[fIdx].hasAvailableSeats()) { cout << "  [!] Flight is fully booked!"    << endl; return; }

    int newTicket = ticketCounter++;
    flights[fIdx].bookSeat();
    passengers[pIdx].setTicketNumber(newTicket);
    passengers[pIdx].setBookingInfo("Booked on flight " + flightID + " to " + flights[fIdx].getDestination());
    passengers[pIdx].setHasTicket(true);
    bookings[bookingCount++] = Booking(bookingCount + 1, passengers[pIdx], flights[fIdx], newTicket);

    cout << endl << "  [+] Ticket booked successfully!" << endl;
    cout << "      Ticket Number : " << newTicket << endl;
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
    cout << "       AIRPORT MANAGEMENT SYSTEM"     << endl;
    cout << "       ACU  |  C++ OOP Project"       << endl;
    printLine();
    cout << "    1.  Add Flight"                   << endl;
    cout << "    2.  Add Passenger"                << endl;
    cout << "    3.  Book Ticket"                  << endl;
    cout << "    4.  View All Flights"             << endl;
    cout << "    5.  View All Passengers"          << endl;
    cout << "    6.  View All Bookings"            << endl;
    cout << "    7.  Exit"                         << endl;
    printLine();
    cout << "    Enter your choice: ";
}

// ---- Entry Point ------------------------------------
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
            case 7:
                printLine();
                cout << "    Goodbye! See you next flight." << endl;
                printLine();
                break;
            default:
                cout << "  [!] Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}

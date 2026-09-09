# ✈️ Airport Management System

> **C++ OOP Console Application**
> Ahram Canadian University — CS104 Project

---



## 📁 Project Structure

```
AirportManagementSystem/
│
├── include/               ← Header files (.h)
│   ├── Person.h
│   ├── Passenger.h
│   ├── Flight.h
│   └── Booking.h
│
├── src/                   ← Source files (.cpp)
│   ├── Person.cpp
│   ├── Passenger.cpp
│   ├── Flight.cpp
│   ├── Booking.cpp
│   └── main.cpp
│
└── README.md
```

---


## 🗂️ Menu Options

```
1.  Add Flight
2.  Add Passenger
3.  Book Ticket
4.  View All Flights
5.  View All Passengers
6.  View All Bookings
7.  Exit
```

---

## 🧠 OOP Concepts Used

| Concept | Where |
|---------|-------|
| **Classes & Objects** | Person, Passenger, Flight, Booking |
| **Inheritance** | `Passenger` inherits from `Person` |
| **Constructor Overloading** | All 4 classes |
| **Function Overloading** | `Flight::display()` and `Flight::display(bool)` |
| **Friend Functions** | `samePassenger()`, `sameDestination()` |
| **Virtual / Override** | `Person::display()` → `Passenger::display()` |
| **Arrays of Objects** | `flights[]`, `passengers[]`, `bookings[]` |
| **Encapsulation** | Private members with public getters/setters |

---

## 🔗 Class Diagram

```
        Person  (Base)
       ┌────────────┐
       │ # name     │
       │ # id       │
       │ display()  │  ← virtual
       └────────────┘
             ▲
         inherits
             │
      Passenger (Derived)
       ┌──────────────────┐
       │ - ticketNumber   │
       │ - bookingInfo    │
       │ - hasTicket      │
       │ display() override│
       │ friend: same...  │
       └──────────────────┘

        Flight
       ┌──────────────────┐
       │ - flightID       │
       │ - destination    │
       │ - capacity       │
       │ - bookedSeats    │
       │ display()        │  ← overloaded
       │ display(bool)    │
       └──────────────────┘

        Booking  (links Passenger ↔ Flight)
       ┌──────────────────┐
       │ - bookingID      │
       │ - passengerID    │
       │ - flightID       │
       │ - ticketNumber   │
       └──────────────────┘
```

---

## 👨‍💻 Course Info

- **University:** Ahram Canadian University (ACU)
- **Course:** CS104 — Object Oriented Programming
- **Language:** C++
- **Type:** Console Application

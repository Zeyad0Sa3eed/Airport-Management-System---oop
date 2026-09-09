#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// ╔══════════════════════════════════════════════════╗
// ║            BASE CLASS : Person                  ║
// ║  Responsible Team : Team 1                      ║
// ╚══════════════════════════════════════════════════╝
class Person {
protected:
    string name;
    int    id;

public:
    // --- Constructors (Overloading) ---
    Person();
    Person(string name, int id);

    // --- Getters ---
    string getName() const;
    int    getId()   const;

    // --- Setters ---
    void setName(string name);
    void setId(int id);

    // --- Virtual Display (Polymorphism) ---
    virtual void display() const;
};

#endif

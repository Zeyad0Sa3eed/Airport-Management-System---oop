#include "../include/Person.h"


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

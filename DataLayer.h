

#ifndef DATALAYER_H
#define DATALAYER_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  PersonBase — stores person related data
// ============================================================
class PersonBase {
private:
    string fullName;
    string nationalID;
    string nationality;
    string contactNumber;

public:
    // Default constructor
    PersonBase() : fullName(""), nationalID(""), nationality(""), contactNumber("") {}

    // Parameterized constructor
    PersonBase(string name, string id, string nat, string contact)
        : fullName(name), nationalID(id), nationality(nat), contactNumber(contact) {}

    // Virtual destructor
    virtual ~PersonBase() {}

    // Getters
    string getFullName()      const { return fullName; }
    string getNationalID()    const { return nationalID; }
    string getNationality()   const { return nationality; }
    string getContactNumber() const { return contactNumber; }

    // Setters
    void setFullName(string v)      { fullName = v; }
    void setNationalID(string v)    { nationalID = v; }
    void setNationality(string v)   { nationality = v; }
    void setContactNumber(string v) { contactNumber = v; }

    // Virtual display — overridden in derived classes
    virtual void display() const {
        cout << "  Name       : " << fullName      << endl;
        cout << "  National ID: " << nationalID    << endl;
        cout << "  Nationality: " << nationality   << endl;
        cout << "  Contact    : " << contactNumber << endl;
    }
};

// ============================================================
//  CrimeBase — stores crime related data
// ============================================================
class CrimeBase {
private:
    string caseID;
    string crimeType;
    string crimeDate;
    string crimeLocation;

public:
    // Default constructor
    CrimeBase() : caseID(""), crimeType(""), crimeDate(""), crimeLocation("") {}

    // Parameterized constructor
    CrimeBase(string id, string type, string date, string location)
        : caseID(id), crimeType(type), crimeDate(date), crimeLocation(location) {}

    // Virtual destructor
    virtual ~CrimeBase() {}

    // Getters
    string getCaseID()        const { return caseID; }
    string getCrimeType()     const { return crimeType; }
    string getCrimeDate()     const { return crimeDate; }
    string getCrimeLocation() const { return crimeLocation; }

    // Setters
    void setCaseID(string v)        { caseID = v; }
    void setCrimeType(string v)     { crimeType = v; }
    void setCrimeDate(string v)     { crimeDate = v; }
    void setCrimeLocation(string v) { crimeLocation = v; }

    // Virtual display — overridden in derived classes
    virtual void display() const {
        cout << "  Case ID   : " << caseID        << endl;
        cout << "  Crime Type: " << crimeType     << endl;
        cout << "  Date      : " << crimeDate     << endl;
        cout << "  Location  : " << crimeLocation << endl;
    }
};

#endif

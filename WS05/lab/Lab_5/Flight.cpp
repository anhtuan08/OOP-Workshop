/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (m_passengers > 0 && m_fuel > (m_passengers * 600)) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << m_title;
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << m_passengers;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_fuel;
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (m_passengers == 0) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << m_title;
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(m_passengers);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(m_fuel);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator const char* () const
    {
        return this->m_title;
    }

    Flight::operator double() const
    {
        return this->m_fuel;
    }

    Flight::operator int() const
    {
        return this->m_passengers;
    }

    Flight& Flight::operator+=(const Flight& flight)
    {
        this->m_passengers += flight.m_passengers;
        this->m_fuel += flight.m_fuel;

        if (m_passengers > Boen747Capacity) {
            m_passengers = Boen747Capacity;
        }
        if (m_fuel > FuelTankCapacity) {
            m_fuel = FuelTankCapacity;
        }

        return *this;
    }

    Flight& Flight::operator+=(const int& passengers)
    {
        m_passengers += passengers;
        if (m_passengers > Boen747Capacity) {
            m_passengers = Boen747Capacity;
        }
        return *this;
    }

    Flight& Flight::operator+=(const double& fuel)
    {
        m_fuel += fuel;
        if (m_fuel > FuelTankCapacity) {
            m_fuel = FuelTankCapacity;
        }
        return *this;
    }

    Flight& Flight::operator-=(const int& passengers)
    {
        // TODO: insert return statement here
        m_passengers -= passengers;
        if (m_passengers < 0) {
            m_passengers = 0;
        }
        return *this;
    }

    Flight& Flight::operator-=(const double& fuel)
    {
        // TODO: insert return statement here
        m_fuel -= fuel;
        if (m_fuel < 0) {
            m_fuel = 0;
        }
        return *this;
    }

    Flight& Flight::operator=(const int& passengers)
    {
        // TODO: insert return statement here
        m_passengers = passengers;
        return *this;
    }

    Flight& Flight::operator=(const double& fuel)
    {
        // TODO: insert return statement here
        this->m_fuel = fuel;
        return *this;
    }

    Flight& Flight::operator=(Flight& flight1)
    {
        if (this != &flight1) {  // Prevent self-assignment
            // Transfer passengers and fuel
            this->m_passengers = flight1.m_passengers;
            this->m_fuel = flight1.m_fuel;
            strcpy(this->m_title, flight1.m_title);

            flight1.emptyPlane();
        }
        return *this;

    }

    Flight& Flight::operator-=(Flight& flight)
    {
        this->m_passengers -= flight.m_passengers;
        this->m_fuel -= flight.m_fuel;

        if (m_passengers < 0) {
            m_passengers = 0;
        }
        if (m_fuel < 0) {
            m_fuel = 0;
        }

        return *this;
    }

    Flight operator+(const Flight& flight1, const Flight& flight2)
    {
        Flight result;

        result.m_passengers = flight1.m_passengers + flight2.m_passengers;

        result.m_fuel = flight1.m_fuel + flight2.m_fuel;

        if (result.m_passengers > Boen747Capacity) {
            result.m_passengers = Boen747Capacity;
        }
        if (result.m_fuel > FuelTankCapacity) {
            result.m_fuel = FuelTankCapacity;
        }

        return result;
    }

    Flight operator>>( Flight& flight1, Flight& flight2)
    {
        int remainPasenger;
        remainPasenger = Boen747Capacity - flight2.m_passengers;

        if (remainPasenger >= flight1.m_passengers) {
            flight2.m_passengers += flight1.m_passengers;
            flight1.m_passengers = 0;
        }
        else {
            flight2.m_passengers = Boen747Capacity;
            flight1.m_passengers -= remainPasenger;
        }

        return flight2;
    }

}
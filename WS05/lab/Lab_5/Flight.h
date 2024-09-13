/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;

        operator const char* () const;

        operator double() const;

        operator int() const;

        Flight& operator += (const Flight& flight);

        Flight& operator += (const int& passengers);

        Flight& operator += (const double& passengers);

        Flight& operator -= (const int& fuel);

        Flight& operator -= (const double& fuel);

        Flight& operator = (const int& passengers);

        Flight& operator = (const double& fuel);

        Flight& operator = (Flight& flight1);

        friend Flight operator + (const Flight& flight1, const Flight& flight2);

        friend Flight operator >> ( Flight& flight1,  Flight& flight2);

        Flight& operator -= (Flight& flight);
    };

}
#endif // SDDS_FLIGHT_H
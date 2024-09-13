/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Tuan Tran
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        void emptyPortfolio();

        Portfolio(double value, const char* stock, char type);

        Portfolio();
        
        operator bool() const;

        operator const char*() const;

        operator double() const;

        operator char() const;

        bool operator~() const;

        bool operator*() const;

        double& operator +(const Portfolio& p2);

        Portfolio& operator << (Portfolio& rhs);

        Portfolio& operator >> (Portfolio& lhs);

        Portfolio& operator +=(const double& total) ;

        friend double& operator += (double& d1,const Portfolio& p1) ;

        Portfolio& operator -= (const double& total);

        void dispPortfolio() const;

        std::ostream& display() const;

    };
}
#endif // SDDS_Portfolio_H_
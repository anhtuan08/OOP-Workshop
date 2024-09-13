/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
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

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    Portfolio::operator bool() const
    {
        if (m_type == 'G' || m_type == 'V' || m_type == 'I') {

            return true;
        }
        return false;
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    Portfolio::operator const char*() const
    {
        return this->m_stock;
    }
    Portfolio::operator double() const
    {
        return this->m_value;
    }

    Portfolio::operator char() const
    {
        return this->m_type;
    }

    bool Portfolio::operator~() const
    {
        if (m_value < 0) {
            return true;
        }
        return false;
    }

    bool Portfolio::operator*() const
    {
        if (m_value > 0) {
            return true;
        }
        return false;
    }

    double& Portfolio::operator+(const Portfolio& p2)
    {
        double total;
        total = m_value + p2.m_value;
        return total;
    }

    Portfolio& Portfolio::operator<<(Portfolio& rhs)
    {
        m_value += rhs.m_value;
        rhs.emptyPortfolio();
        return (*this);
    }

    Portfolio& Portfolio::operator>>(Portfolio& lhs)
    {
        lhs.m_value += m_value;
        emptyPortfolio();

        return (*this);
    
    }


    Portfolio& Portfolio::operator+=(const double& total) 
    {
        if (*this) {
            this->m_value += total;
            
        }
        return *this;

    }

    Portfolio& Portfolio::operator-=(const double& total)
    {
        this->m_value -= total;

        if (this->m_value < 0) {
            this->m_value = 0;
        }

        return *this;
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << (double)(*this);
        cout << " | ";
        cout << " Type: ";
        cout << (char)(*this);
    }


    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }




    double& operator+=(double& lhs, const Portfolio& rhs) {
        lhs += static_cast<double>(rhs);  // Add the value of the Portfolio to the double
        return lhs;  // Return the updated double reference
    }

}
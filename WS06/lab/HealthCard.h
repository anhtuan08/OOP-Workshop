#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include <iostream>  // for std::ostream
#include <cstring>   // for std::strlen, std::strcpy, etc.
#include <iomanip>
#include <sstream>
#include <vector>

namespace sdds {
    const int MaxNameLength = 55;

    class HealthCard {
        char* m_name;           // Pointer for dynamically allocated name
        long long m_number;     // Health card number
        char m_vCode[3];        // Validation code (2 characters + null terminator)
        char m_sNumber[10];     // Serial number (9 characters + null terminator)

        void allocateAndCopy(const char* name); // Utility for dynamic allocation
        void setEmpty(); // Utility to set empty state
        void printIDValid(std::ostream& ostr) const;

    public:
        // Default constructor
        HealthCard();

        // Parameterized constructor
        HealthCard(const char* name, long long number, const char* vCode, const char* sNumber);

        // Destructor
        ~HealthCard();

        //bool operator HelthCard
        bool validID(const char* name, long long number, const char* vCode, const char* sNumber) const;

        // Copy constructor
        HealthCard(const HealthCard& hc);

        // Output stream operator (friend function)
        friend std::ostream& operator<<(std::ostream& out, const HealthCard& rhs);

        std::ostream& print(std::ostream& ostr, bool toFile = true) const;

        friend std::istream& operator >>(std::istream& in, HealthCard& rhs);
    };
}
#endif // !SDDS_HealthCard_H


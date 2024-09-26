#define  _CRT_SECURE_NO_WARNINGS


#include "HealthCard.h"
using namespace std;
namespace sdds {
	void HealthCard::allocateAndCopy(const char* name)
	{
		if (name != nullptr) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else {
			m_name = nullptr;
		}
	}
	void HealthCard::setEmpty()
	{
		delete[] m_name;
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';

	}
	void HealthCard::printIDValid(ostream& ostr) const
	{
		ostr << m_name << " " << m_number << " " << m_vCode << endl;
	}

	HealthCard::HealthCard()
	{

	}
	HealthCard::HealthCard(const char* name, long long number, const char* vCode, const char* sNumber)
	{
		allocateAndCopy(name);
		m_number = number;
		strncpy(this->m_vCode, vCode, 2);
		m_vCode[2] = '\0';  // Ensure null-terminated
		strncpy(this->m_sNumber, sNumber, 9);
		m_sNumber[9] = '\0';  // Ensure null-terminated
		
	}
	HealthCard::~HealthCard()
	{
		setEmpty();
	}
	bool HealthCard::validID(const char* name, long long number, const char* vCode, const char* sNumber) const
	{
		if (m_name == nullptr || strlen(m_name) > MaxNameLength) {
			return false;
		}

		if (m_number < 999999999 || m_number > 9999999999) {
			return false;
		}
		if (strlen(m_vCode) != 2) {
			return false;
		}
		if (strlen(m_sNumber) != 9) {
			return false;
		}
		return true;
	}
	HealthCard::HealthCard(const HealthCard& hc)
	{
		allocateAndCopy(hc.m_name);
		m_number = 0;
		strcpy(m_vCode, hc.m_vCode);
		strcpy(m_sNumber, hc.m_sNumber);
	}

	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const
	{
		
	}

	

	std::ostream& operator<<(std::ostream& out, const HealthCard& rhs)
	{
		if (rhs.validID(rhs.m_name, rhs.m_number, rhs.m_vCode, rhs.m_sNumber)) {
			out << rhs.m_name << "............................." << rhs.m_number << "-" << rhs.m_vCode <<", "<< rhs.m_sNumber << endl;
		}
		else {
			out << "Invalid Health Card Record" << endl;

		}
		return out;
	}

	std::istream& operator>>(std::istream& in, HealthCard& rhs)
	{		
		std::string input;
		getline(in, input);

		std::stringstream ss(input);
		std::string token;

		// Parse the name (delimited by ',')
		std::getline(ss, token, ',');
		rhs.setEmpty();
		rhs.m_name = new char[token.length() + 1];
		std::strcpy(rhs.m_name, token.c_str());

		// Parse the number (delimited by '-')
		std::getline(ss, token, '-');
		try {
			rhs.m_number = std::stoll(token);
		}
		catch (const std::invalid_argument& e) {
			rhs.m_name = nullptr;
			return in;
		}
		catch (const std::out_of_range& e) {
			rhs.m_name = nullptr;
			return in;
		}

		// Parse the validation code (delimited by ',')
		std::getline(ss, token, ',');
		std::strncpy(rhs.m_vCode, token.c_str(), 2);
		rhs.m_vCode[2] = '\0';  // Ensure null-terminated

		// Parse the serial number (delimited by ',')
		std::getline(ss, token, ',');
		std::strncpy(rhs.m_sNumber, token.c_str(), 9);
		rhs.m_sNumber[9] = '\0';  // Ensure null-terminated

		return in;
	}


}
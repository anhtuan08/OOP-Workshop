#define _CRT_SECURE_NO_WARNINGS
#include "Pack.h"

namespace sdds {

	Pack::Pack(const char* namePack, int size, int unitSize, int numbersofUnit):
		m_Size(size), m_numbersofUnit(numbersofUnit), m_unitSize(unitSize)
	{
		m_namePack = new char [strlen(namePack) + 1];
		strcpy(m_namePack, namePack);
	}

	Pack::Pack(const char* name, int size) :
		m_Size(size), m_unitSize(330), m_numbersofUnit(0)
	{
		m_namePack = new char[strlen(name) + 1];
		strcpy(m_namePack, name);
	}


	int Pack::unit()
	{
		return m_unitSize;
	}

	Pack& Pack::clear(int size, int unitSize, const char* packName)
	{
		if (strlen(packName) <= MAXLENGTH) {
			delete[] m_namePack;
			m_namePack = new char[strlen(packName) + 1];
			strcpy(m_namePack, packName);
			m_unitSize = unitSize;
			m_Size = size;
			m_numbersofUnit = 0;
		}
		return *this;
	}


	int Pack::operator+=(const int value)
	{
		int res;
		if (value <= (m_Size - m_numbersofUnit)) {
			m_numbersofUnit += value;
			res = value;
		}
		else {
			res = m_Size - m_numbersofUnit;
			m_numbersofUnit = m_Size;
		}
		return res;
	}

	int Pack::operator-=(const int value)
	{
		int res;
		if (value * this->m_unitSize <= this->m_numbersofUnit * this->m_unitSize) {
			res = value;
				this->m_numbersofUnit = this->m_Size - value;
		}
		else {
			res = m_numbersofUnit;
			this->m_numbersofUnit = 0;
		}

		return res;
	}

	bool Pack::isValid()
	{
		if (this->m_numbersofUnit <= this->m_Size) {
			return true;
		}
		return false;
	}

	Pack::~Pack()
	{
		delete[] m_name;
	}

	std::ostream& operator<<(std::ostream& ostream, Pack& rhs)
	{
		if (rhs.isValid()) {
			ostream << rhs.m_namePack << ": (" << rhs.m_numbersofUnit * rhs.m_unitSize << "cc/"
				<< rhs.m_Size * rhs.m_unitSize << ")" << "," << rhs.m_numbersofUnit << " in a pack of " << rhs.m_Size << std::endl;
		}
		return ostream;
	}

	std::istream& operator >>(std::istream& in, Pack& rhs)
	{
		if (rhs.isValid()) {
			std::cout << "Add to " << rhs << std::endl;

			int res;
			int flag = true;
			int value = rhs.m_Size - rhs.m_numbersofUnit;
			while (flag) {
				in >> res;
				if (!value) {
					std::cout << "Pack is full!, press <ENTER> to continue..." << std::endl;
					flag = false;

				}
				else if (res > value) {
					std::cout << "Value out of range [1 <= val <=" << (rhs.m_Size - rhs.m_numbersofUnit)
						<< "]: ";
				}
				else {
					std::cout << "Added " << res << std::endl;
					rhs += res;
					flag = false;
				}
			}
		}
		else {
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
		}

		return in;
	}

}
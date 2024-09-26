#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"

namespace sdds {
	Container::Container() :m_name(nullptr), m_capacity(0), m_contenVolume(0)
	{
	}
	Container::Container(const char* name, int capacity, int contentVolume)
	{

		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_capacity = capacity;
		m_contenVolume = contentVolume;
	}
	Container::Container(const char* name, int capacity) :m_contenVolume(0)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_capacity = capacity;
	}
	bool Container::isValid()
	{
		if (this->m_contenVolume <= this->m_capacity) {
			return true;
		}
		return false;
	}

	int Container::operator+=(const int value)
	{
		// TODO: insert return statement here
		int res;
		if (value <= (this->m_capacity - this->m_contenVolume)) {
			this->m_contenVolume += value;
			res = value;
		}
		else {
			res = (this->m_capacity - this->m_contenVolume);
			this->m_contenVolume = this->m_capacity;
		}

		return res;
	}

	int Container::operator-=(const int value)
	{
		int res;
		if (value <= this->m_contenVolume) {
			this->m_contenVolume -= value;
			res = value;
		}
		else {
			res = this->m_contenVolume;
			this->m_contenVolume = 0;
		}

		return res;
	}

	Container& Container::clear(int newCapacity, const char* newDescription)
	{
		if (strlen(newDescription) <= MAXLENGTH) {
			delete[] m_name;
			m_name = new char[strlen(newDescription) + 1];
			strcpy(m_name, newDescription);
			m_capacity = newCapacity;
			m_contenVolume = 0;
		}
		return *this;
	}

	Container::~Container()
	{
		delete[] m_name;
	}
	std::ostream& operator<<(std::ostream& out, Container& rhs)
	{
		if (rhs.isValid()) {
			out << rhs.m_name << ": (" << rhs.m_contenVolume << "cc/" << rhs.m_capacity << ")" << std::endl;
		}
		else {
			out << "****: (**cc/***)" << std::endl;
		}
		return out;
	}
	std::istream& operator>>(std::istream& in, Container& rhs)
	{
		if (rhs.isValid()) {
			std::cout << "Add to " << rhs.m_name << ": (" << rhs.m_contenVolume << "cc/" << rhs.m_capacity << ")" << std::endl;
			std::cout << ">";
			int res;
			bool flag = true;
			while (flag) {
				in >> res;
				if (in.fail()) {
					in.clear(); // Clear the error state
					in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
					std::cout << "Invalid Integer, retry: " << std::endl;
				}
				else if (res < 0 || res > 999) {
					std::cout << "Value out of range" << std::endl;
				}
				else {
					flag = false;
				}
			}
			res = rhs.operator+=(res);
			std::cout << "Added " << res << "CCs" << std::endl;
		}
		else {
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
		}
		

		return in;
	}


}
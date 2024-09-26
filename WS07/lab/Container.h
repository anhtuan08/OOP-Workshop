#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <cstring>
#include <iostream>

namespace sdds {

	const int MAXLENGTH = 50;

	class Container
	{
	public:
		Container();
		Container(const char* name, int capacity, int contentVolume);
		Container(const char* name, int capacity);
		bool isValid();

		friend std::ostream& operator << (std::ostream& out, Container& rhs);
	
		int operator += (const int value);
		int operator -= (const int value);

		friend std::istream& operator >> (std::istream& in, Container& rhs);
		Container& clear(int newCapacity, const char* newDescriptiom);

		~Container();

	protected:
		char* m_name;
		int m_capacity;
		int m_contenVolume;
	};


}

#endif
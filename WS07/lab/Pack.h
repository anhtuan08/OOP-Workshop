#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <cstring>
#include <iostream>
#include "Container.h"

namespace sdds {

	class Pack : public Container
	{
	public:
		Pack(const char* name, int Size, int numberofSize, int unitSize);
		Pack(const char* name, int Size);
		int unit();
		Pack& clear(int size, int unitSize, const char* packName);
		friend std::ostream& operator << (std::ostream& ostream, Pack& rhs);
		
		int operator += (const int value);
		int operator -= (const int value);

		bool isValid();

		friend std::istream& operator >> (std::istream& in, Pack& rhs);

		~Pack();

	private:
		char* m_namePack;
		int m_Size;
		int m_unitSize;
		int m_numbersofUnit;
	};


}

#endif
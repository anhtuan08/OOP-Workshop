#ifndef _CARINVENTORY_HEADER_
#define _CARINVENTORY_HEADER_

#include <iomanip>
#include <iostream>

	class CarInventory
	{
	public:
		CarInventory();

		CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price);

		CarInventory(const char* type, const char* brand, const char* model);

		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

		bool isValid() const;

		bool isSimilarTo(const CarInventory& car) const;

		void printInfo();


		~CarInventory();

	private:
		const char* type;
		const char* brand;
		const char* model;
		int year;
		int code;
		double price;
		void resetInfor();
	};

	namespace sdds {
		bool find_similar(CarInventory car[], const int num_cars);

	}



#endif
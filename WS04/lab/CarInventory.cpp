#include "CarInventory.h"

CarInventory::CarInventory()
{
	resetInfor();
}

CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
{
	this->type = type;
	this->brand = brand;
	this->model = model;
	this->year = year;
	this->code = code;
	this->price = price;

}

CarInventory::CarInventory(const char* type, const char* brand, const char* model)
{
	this->type = type;
	this->brand = brand;
	this->model = model;
	this->year = 2022;
	this->code = 100;
	this->price = 1;

}

CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
{
	resetInfor();

	this->type = type;
	this->brand = brand;
	this->model = model;
	this->year = year;
	this->code = code;
	this->price = price;

	return *this;

}

bool CarInventory::isValid() const
{
	if (this->type != nullptr
		&& this->brand != nullptr
		&& this->model != nullptr
		&& this->year >= 1990
		&& (this->code >= 100 && this->code <= 999)
		&& this->price > 0)
		return true;
	
	return false;
}

bool CarInventory::isSimilarTo(const CarInventory& car) const
{
	if (type == car.type
		&& brand == car.brand
		&& model == car.model
		&& year == car.year
		) {
		return true;
	}

	return false;
}

void CarInventory::printInfo()
{
	//| 10  spaces | 16        spaces | 16        spaces | 9999 |  999 | 999999.99 |
		// Print the formatted table row
	std::cout << "| "
		<< std::setw(10) << std::left << type << " | "
		<< std::setw(15) << std::left << brand << " | "
		<< std::setw(15) << std::left << model << " | "
		<< std::setw(4) << year << " | "
		<< std::setw(3) << code << " | "
		<< std::setw(10) << std::fixed << std::setprecision(2) << price
		<< " |"
		<< std::endl;

}

CarInventory::~CarInventory()
{
	resetInfor();
}

void CarInventory::resetInfor()
{
	this->type = nullptr;
	this->brand = nullptr;
	this->model = nullptr;
	this->year = 0;
	this->code = 0;
	this->price = 0;
}


bool sdds::find_similar(CarInventory car[], const int num_cars)
{

	for (int i = 0; i < num_cars; i++) {
		for (int j = i + 1; j < num_cars; j++) {
			if (car[i].isSimilarTo(car[j])) {
				return true;
			}
		}
	}
	return false;
}

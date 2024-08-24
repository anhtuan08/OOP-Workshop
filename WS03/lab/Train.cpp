#include "Train.h"

Train::Train()
{
	this->numberOfPeople = 0;
	this->speedOfTrain = 0;
	this->nameOfTrain = nullptr;

}

void Train::set(const char* name, int numberPeople, double speed)
{
	this->nameOfTrain = name;
	this->numberOfPeople = numberPeople;
	this->speedOfTrain = speed;
}

int Train::getNumberOfPeople() const
{
	if (this->numberOfPeople < 0 || this->numberOfPeople > MAX_PEOPLE)
		return 0;
	return this->numberOfPeople;
}

const char* Train::getName() const
{
	if (this->nameOfTrain == nullptr || this->nameOfTrain == "") {
		return nullptr;
	}
	return this->nameOfTrain;
}

double Train::getSpeed() const
{
	if (this->speedOfTrain < 0 || this->speedOfTrain > 320)
		return 0;
	return this->speedOfTrain;
}

bool Train::isSafeEmpty() const
{
	if (getName() == nullptr || getSpeed() == 0 || getNumberOfPeople() == 0)
		return true;
	return false;
}

Train::~Train()
{

}

void Train::display() const {
	if (isSafeEmpty()) {
		cout << "Safe Empty State!" << endl;
	}
	else {
		cout << "NAME OF THE TRAIN: " << this->nameOfTrain << endl;
		cout << "NUMBER OF PEOPLE: " << this->numberOfPeople << endl;
		cout << "SPEED" << this->speedOfTrain << "km/h" << endl;
	}
}
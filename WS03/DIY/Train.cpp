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
	if (this->numberOfPeople < 0)
		return 0;
	else if (this->numberOfPeople > MAX_PEOPLE) {
		return MAX_PEOPLE;
	}
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
	if (this->speedOfTrain < 0)
		return 0;
	else if (this->speedOfTrain > MAX_SPEED) {
		return MAX_SPEED;
	}
	return this->speedOfTrain;
}

bool Train::isSafeEmpty() const
{
	if (getName() == nullptr || getSpeed() < 0 || getNumberOfPeople() < 0)
		return true;
	return false;
}

void Train::display() const {

		cout << "\tNAME OF THE TRAIN	:" << this->nameOfTrain << endl;
		cout << "\tNUMBER OF PEOPLE		:" << this->numberOfPeople << endl;
		cout << "\tSPEED				:" << this->speedOfTrain << " km/h" << endl;
	}

int Train::loadPeople(int numberPeople)
{
	this->numberOfPeople = this->numberOfPeople + numberPeople;
	if(this->numberOfPeople < 0 )
	{
		this->numberOfPeople = 0;
	}
	else if (this->numberOfPeople > MAX_PEOPLE) {
		this->numberOfPeople = MAX_PEOPLE;
	}
	return this->numberOfPeople;
}

double Train::changeSpeed(double speedTrain)
{
	this->speedOfTrain = this->speedOfTrain + speedTrain;
	if (this->speedOfTrain < 0) {
		this->speedOfTrain = 0;
	}
	else if (this->speedOfTrain > MAX_SPEED) {
		this->speedOfTrain = MAX_SPEED;
	}
	return this->speedOfTrain;
}


ostream& operator <<(ostream& out, const Train& train)
{
	out << train.getName() << endl;
	out << train.getNumberOfPeople() << endl;
	out << train.getSpeed() << endl;
	
	return out;
}

int transfer(Train &train1, Train &train2)
{
	if (train1.isSafeEmpty() || train2.isSafeEmpty()) {
		return -1;
	}
	int a = MAX_PEOPLE - train1.getNumberOfPeople();
	train1.loadPeople(train2.getNumberOfPeople());
	train2.loadPeople(-a);

	return train1.getNumberOfPeople();

}

Train::~Train()
{

}
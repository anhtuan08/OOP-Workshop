#pragma once
#ifndef _TRAIN_H_
#define _TRAIN_H_

#include <string>
#include <iostream>

#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320

using namespace std;

namespace sdds {

}

class Train
{
public:
	Train();

	void set(const char* a, int b, double c);

	int getNumberOfPeople() const;

	const char* getName() const;

	double getSpeed() const;

	bool isSafeEmpty() const;

	void display() const;

	

	~Train();

private:
	const char* nameOfTrain;
	int numberOfPeople;
	double speedOfTrain;


};


#endif // !_TRAIN_H_



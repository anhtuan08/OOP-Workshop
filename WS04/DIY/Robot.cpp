#include "Robot.h"
#include <cstring>
Robot::Robot(): name(""), location(nullptr), weight(0.0), width(0.0), height(0.0), speed(0.0), deployed(false)
{
}

Robot::Robot(string name,const char* location, double weight, double width, double height, double speed, bool deployed):
	name(name), location(location), weight(weight), width(width), height(height), speed(speed), deployed(deployed)
{
}

Robot::~Robot()
{
}

void Robot::display()
{
		// Print the details in the desired format
		std::cout << "| "
			<< std::left << std::setw(10) << name << " | "
			<< std::left << std::setw(15) << location << " | "
			<< std::right << std::setw(6) << weight << " | "
			<< std::right << std::setw(6) << width<< " | "
			<< std::right << std::setw(6) << height << " | "
			<< std::right << std::setw(6) << speed << " | "
			<< std::left << std::setw(7) << (deployed ? "YES" : "NO") << " |"
			<< std::endl;
}


double Robot::getSpeed()
{

	return this->speed;
}

bool Robot::isDeployed()
{
	return this->deployed;
}

string Robot::getName()
{
	return this->name;
}


Robot& Robot::set(string name, const char* location, double weight, double width, double height, double speed, bool deployed)
{
	this->name = name;
	this->location = location;
	this->weight = weight;
	this->width = width;
	this->height = height;
	this->speed = speed;
	this->deployed = deployed;

	return *this;
}

int sdds::controlRooomReport(Robot robot[], int numberRobots)
{
	std::cout << "       ------ Robot Control Room -----\n";
	std::cout << "                    ---------------------------------------\n";
	std::cout << "| Robot ID   | Location        | Weight | Width  | Height | Speed  | Deployed |\n";
	std::cout << "|------------+-----------------+--------+--------+--------+--------+----------|\n";

	int countDeployeds = 0;
	double maxSpeed = 0;
	int indexSpeed = 0;
	for (int i = 0; i < numberRobots; i++) {
		if (robot[i].getSpeed() == 0 || robot[i].getName() == "") {
			return i;
		}
		if (robot[i].isDeployed() == true) {
			countDeployeds++;
		}
		if (robot[i].getSpeed() > maxSpeed) {
			maxSpeed = robot[i].getSpeed();
			indexSpeed = i;
		}

		robot[i].display();
	}

	cout << "Summary:" << endl;
	cout << countDeployeds << "robots are deployed" << endl;
	cout << "The fastest robot is:" << endl;
	robot[indexSpeed].display();

	return -1;

}

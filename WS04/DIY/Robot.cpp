#include "Robot.h"

Robot::Robot()
{
	this->name = nullptr;
	this->location = nullptr;
	this->weight = 0;
	this->height = 0;
	this->speed = 0;
	this->deployed = false;

}

Robot::Robot(const char* name,const char* location, double weight, double height, double speed, bool deployed)
{
	this->name = name;
	this->location = location;
	this->weight = weight;
	this->height = height;
	this->speed = speed;
	this->deployed = deployed;
}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Robot
{
	
public:
	Robot();
	
	Robot(string name,const char* location, double weight, double width, double height, double speed, bool deployed);

	~Robot();

	void display();

	double getSpeed();

	bool isDeployed();
	
	string getName();

	Robot& set(string name, const char* location, double weight, double width, double height, double speed, bool deployed);


private:
	string name;
	const char* location;
	double weight;
	double width;
	double height;
	double speed;
	bool deployed;
};

namespace sdds {
	int controlRooomReport(Robot robot[], int numberRobots);

}


class Robot
{
	
public:
	Robot();
	
	Robot(const char* name,const char* location, double weight, double height, double speed, bool deployed);

	~Robot();

private:
	const char* name;
	const char* location;
	double weight;
	double height;
	double speed;
	bool deployed;
};

namespace sdds {

}

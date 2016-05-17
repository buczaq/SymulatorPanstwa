#include <string>
#include <vector>
#include <iterator>

using namespace std;
enum e_employment
{
	standard,
	criminal,
	politician
};

struct s_ideas
{
	int economy;
	int freedom;
};

class Citizen
{
private:
	static vector <string> names;
	static vector <string> surnames;
	string name;
	string surname;
	int age;
	int happiness;
	e_employment employment;
	s_ideas ideas;
	float earnings;
	int commitment;
	int charisma;
	int truthfulness;

	static void init();

public:
	Citizen();
	void description();
	//int vote();
	int r_economy() { return ideas.economy; }
	int r_freedom() { return ideas.freedom; }
	string r_name() { return name; }
	string r_surname() { return surname; }
	e_employment r_employment() { return employment; }
};
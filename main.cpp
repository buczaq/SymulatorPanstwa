#define CITIZENS 100

#include "Citizen.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	vector <Citizen *> vectorOfPoliticians;
	Citizen citizens[CITIZENS];
	/*for (int i=0; i<CITIZENS; i++)
	{
		if (i%10==0)
		{
			citizens[i] = Citizen(politician);
			vectorOfPoliticians.push_back(citizens[i]);
		}
		if (i%10==9)
			citizens[i] = Citizen(criminal);
	}*/
	for (int i=0; i<CITIZENS; i++)
		citizens[i].description();
	for (int i=0; i<CITIZENS; i++)
	{
		if (citizens[i].r_employment() == politician)
			vectorOfPoliticians.push_back(&(citizens[i]));
	}
	int numberOfPoliticians = vectorOfPoliticians.size();
	int *results = new int[numberOfPoliticians];
	for (int i = 0; i<numberOfPoliticians; i++)
		results[i] = 0;
	//vector<Citizen **>::iterator it = vectorOfPoliticians.begin();
	for (int i=0; i<CITIZENS; i++)
	{
		int endorsement[numberOfPoliticians];
		for (int i = 0; i<numberOfPoliticians; i++)
			endorsement[i] = 0;
		for (int j=0; j<numberOfPoliticians; j++)
		{
			endorsement[j] += abs(citizens[i].r_economy()) - abs((vectorOfPoliticians[j])->r_economy());
			endorsement[j] += abs(citizens[i].r_freedom()) - abs((vectorOfPoliticians[j])->r_freedom());
		}

		int choice = 0;
		for (int i=0; i<numberOfPoliticians; i++)
		{
			if (endorsement[i]<endorsement[choice])
				choice = i;
		}

		for (int i=0; i<numberOfPoliticians; i++)
		endorsement[i] = 0;

		results[choice]++;
	
	}


	int winner = 0;
	for (int i = 0; i < numberOfPoliticians; i++)
	{
		if (results[i] > results[winner])
			winner = i;
	}
	cout << endl << endl << "WYBORY WYGRAL KANDYDAT NR " << winner+1 << ", " << (vectorOfPoliticians[winner])->r_name() << " " << (vectorOfPoliticians[winner])->r_surname() << "!";

}
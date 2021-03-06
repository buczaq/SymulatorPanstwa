#include "Citizen.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>

vector <string> Citizen::names;
vector <string> Citizen::surnames;

void Citizen::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
	ifstream file2("surnames.dat");
	copy(istream_iterator<string>(file2),
		istream_iterator<string>(),
		back_inserter(surnames));
	file2.close();
}

Citizen::Citizen()
{
	static int amountOfNames = (init(), names.size());
	static int amountOfSurnames = (init(), surnames.size());
	name = names[rand()%amountOfNames];
	surname = surnames[rand()%amountOfSurnames];
	age = rand()%80;
	happiness = rand()%71 + 30;
	commitment = rand()%81 + 20;
	ideas.economy = rand()%101;
	ideas.freedom = rand()%101;
	int i = rand()%100;
	if (i<80)
		employment = standard;
	if (i>=80 && i<90)
		employment = criminal;
	if (i>=90)
		employment = politician;
	charisma = rand()%101;
	truthfulness = rand()%101;
}

void Citizen::description()
{
	cout << "Imie: " << name << endl << "Nazwisko: " << surname << endl 
	<< "Wiek:" << age << endl << 
	"Zatrudnienie: ";
	if (employment==standard) cout << "Sektor prywatny";
	if (employment==criminal) cout << "Przestepca";
	if (employment==politician) cout << "Polityk";
	cout << endl << "Zadowolenie: "<< happiness << endl << 
	"Zaangazowanie: " << commitment << endl 
	<< "Poglady: " << endl << "\tGospodarka: ";
	if (ideas.economy<30) cout << "wolnorynkowy ";
	if (ideas.economy>=30 && ideas.economy<=70) cout << "neutralny ";
	if (ideas.economy>70) cout << "socjalista ";
	cout << "(" << ideas.economy << ")" << endl << "\tSwobody: ";
	if (ideas.freedom<30) cout << "wolnosciowiec ";
	if (ideas.freedom>=30 && ideas.freedom<=70) cout << "neutralny ";
	if (ideas.freedom>70) cout << "konserwatywny ";
	cout << "(" << ideas.freedom << ")" << endl << endl;
	if (employment==politician)
		cout << "Charyzma: " << charisma << endl << "Prawdomownosc: " << truthfulness << endl << endl;
}

/*int Citizen::vote()
{
	float *endorsement = new float[vectorOfPoliticians.size()];
	int i = 0;
	for (vector<Politician **>::iterator it = vectorOfPoliticians.begin(); it != vectorOfPoliticians.end(); it++, i++)
	{
		endorsement[i] += abs(r_economy() - abs((*it)->r_economy()));
		endorsement[i] += abs(r_freedom() - abs((*it)->r_freedom()));
	}

	int choice = 0;

	for (int i = 1; i < vectorOfPoliticians.size(); i++)
	{
		if (endorsement[i] > endorsement[choice])
			choice = i;
	}
	return i;
}*/
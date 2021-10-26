#include "Expertise.h"


void Expertise::setExpertise()
{
	cout << "Enter your Expertise\n";
	string x = "", temp;
	while (temp != ".") {
		cin >> temp;
		if (temp != ".") {
			x = x + " "; x = x + temp;
		}
	}
	expert = x;
}

void Expertise::setExpertise(string s)
{
	expert = s;
}

string Expertise::getexpert()
{
	return expert;
}

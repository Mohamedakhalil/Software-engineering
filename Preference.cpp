#include "Preference.h"

void Preference::setPreference()
{
	cout << "Enter your preference\n";
	string x="", temp;
	while (temp != ".") {
		cin >> temp;
		if (temp != ".") {
			x = x + " "; x = x + temp;
		}
	}
	pref = x;
}

void Preference::setPreference(string s)
{
	pref = s;
}


string Preference::getPref()
{
	return pref;
}

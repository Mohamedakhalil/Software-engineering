#include "TourGuide.h"

void TourGuide::setLang(string s)
{
	Lang = s;
}

string TourGuide::getLang()
{
	return Lang;
}

void TourGuide::signUp(string name, string pass)
{
	fstream data;
	data.open("myUsers.txt", ios::app);
	User::signUp(name, pass);
	cout << "Enter your preferred language for communication\n";
	cin >> Lang;
	Expertise expert;
	expert.setExpertise();
	experts.push_back(expert);
	data << 0 << ',' << experts[0].getexpert() << ',' << Lang << endl;
}

void TourGuide::changeState()
{
	available = !available;
}

void TourGuide::addexpert()
{
	Expertise x;
	x.setExpertise();
	experts.push_back(x);
}

bool TourGuide::getState()
{
	return available;
}

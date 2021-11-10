#include "TourGuide.h"

TourGuide TourGuide::login(string name, string pass)
{
	if (User::login(name, pass)) {
		TourGuide x;
		ifstream data;
		data.open("myUsers.txt");
		string searcher, sub;
		while (!data.eof()) {
			getline(data, searcher);
			sub = searcher.substr(0, searcher.find(','));
			if (name == sub) {
				break;
			}
		}
		x.setName(sub);
		searcher.erase(0, searcher.find(',') + 1);
		searcher.erase(0, searcher.find(',') + 1);
		sub = searcher.substr(0, searcher.find(','));
		int num = stoi(sub);
		x.setPriceRange(num);
		searcher.erase(0, searcher.find(',') + 1);
		sub = searcher.substr(0, searcher.find(','));
		num = stoi(sub);
		x.setRate(num);
		searcher.erase(0, searcher.find(',') + 1);
		searcher.erase(0, searcher.find(',') + 1);
		sub = searcher.substr(0, searcher.find(','));
		x.setDestination(sub);
		while (sub != "0") {
			searcher.erase(0, searcher.find(',') + 1);
			sub = searcher.substr(0, searcher.find(','));
			if (sub != "0")
				x.activities.push_back(sub);
		}
		searcher.erase(0, searcher.find(',') + 1);
		sub = searcher.substr(0, searcher.find(','));
		Expertise exp;
		exp.setExpertise(sub);
		x.experts.push_back(exp);
		searcher.erase(0, searcher.find(',') + 1);
		x.setLang(searcher);
		return x;
	}
}

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
	data << getState() << ',' << 0 << ',' << experts[0].getexpert() << ',' << Lang << endl;
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

void TourGuide::updateUser()
{
}

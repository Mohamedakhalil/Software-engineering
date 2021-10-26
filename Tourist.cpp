#include "Tourist.h"

Tourist Tourist::login(string name, string pass)
{
	if (User::login(name, pass)) {
		Tourist x;
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
		while (sub != "1") {
			searcher.erase(0, searcher.find(',') + 1);
			sub = searcher.substr(0, searcher.find(','));
			if (sub != "1")
				x.activities.push_back(sub);
		}
		searcher.erase(0, searcher.find(',') + 1);
		sub = searcher.substr(0, searcher.find(','));
		Preference pref;
		pref.setPreference(sub);
		x.prefs.push_back(pref);
		searcher.erase(0, searcher.find(',') + 1);
		x.setLang(searcher);
		return x;
	}
}

void Tourist::rateTourist(double r)
{
	setRate(r);
}

void Tourist::signUp(string name, string pass)
{
	fstream data;
	data.open("myUsers.txt", ios::app);
	User::signUp(name, pass);
	cout << "Enter your preferred language for communication\n";
	cin >> prefLang;
	Preference pree;
	pree.setPreference();
	prefs.push_back(pree);
	data << 1  << ',' << prefs[0].getPref() << ',' << prefLang << endl;
}

void Tourist::setStart(int x)
{
	start = x;
}

void Tourist::setEnd(int x)
{
	end = x;
}

void Tourist::setLang(string x)
{
	prefLang = x;
}

void Tourist::addpref()
{
	Preference x;
	prefs.push_back(x);
}

int Tourist::getStart()
{
	return start;
}

int Tourist::getEnd()
{
	return end;
}

string Tourist::getLang()
{
	return prefLang;
}

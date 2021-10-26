#include "User.h"
string User::getDestination() {
	return destination;
}
double User::getPriceRange() {
	return priceRange;
}
double User::getRate() {
	return rate;
}
int User::getAge() {
	return age;
}
vector<string> User::getActivities() {
	return activities;
}
void User::setPriceRange(double x) {
	priceRange = (x>0) ? x:0;
}
void User::setRate(double x) {
	rate = (x > 0) ? (x + rate) / 2 : 0+rate/2;
	rate = (x < 5) ? (x + rate) / 2 : 2.5+rate/2;
}
void User::setAge(int x) {
	age = (x > 0) ? x : 0;
}
void User::setDestination(string x) {
	destination = x;
}
void User::setActivities(vector<string> v) {
	activities = v;
}
void User::addUser(string name, string pass, vector<string> act, double range = 0, double r = 5, int a = 0, string dest = "") {
	Username = name;
	password = pass;
	setActivities(act);
	setDestination(dest);
	setPriceRange(range);
	rate = r;
	age = a;
	fstream data;
	data.open("myUsers.txt",ios::app);
	data << Username << ',' << password << ',' << priceRange << ',' << rate << ',' << age << ',' << destination;
	for (int i = 0; i < activities.size(); i++) {
		data << ',' << activities[i];
	}
	data << ',';
}
void User::setName(string s)
{
	Username = s;
}
string User::getName()
{
	return Username;
}
//void User::updateUser(double range = 0, double r = 5, string dest = "", vector<string> act) {
//	for (int i = 0; i < act.size(); i++) {
//		activities.push_back(act[i]);
//	}
//	if (range != priceRange && range != 0)
//		setPriceRange(range);
//	if (r != rate && r != 0)
//		setRate(r);
//	if (dest != destination && dest != "")
//		setDestination(dest);
//}
void User::signUp(string name, string pass) {
	ifstream data;
	data.open("myUsers.txt");
	bool found = false;
	string search;
	while (!data.eof()) {
		getline(data, search);
		search = search.substr(0, search.find(','));
		if (name == search)
			found = true;
	}
	if (found) {
		cout << "Choose another username as this is one is already taken\n";
		exit(1);
	}
	else {
		cout << "Enter your age\n";
		int age; cin >> age;
		cout << "Enter your preferred price range\n";
		double range; cin >> range;
		cout << "Enter your preferred Destination\n";
		string dest; cin >> dest;
		vector<string> act; string hobb;
		cout << "Enter your hobbies\n";
		while (hobb!=".") {
			cin >> hobb;
			if (hobb != ".")
				act.push_back(hobb);
		} 
		this->addUser(name, pass, act, range, 5, age, dest);
	}
}
bool User::login(string name, string pass) {
	ifstream data;
	data.open("myUsers.txt");
	bool found = false;
	string search, sub;
	while (!data.eof()) {
		getline(data, search);
		sub = search.substr(0, search.find(','));
		if (name == sub) {
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "This user has not been found\n try to sign up\n";
		return false;
	}
	else {
		search.erase(0, search.find(',') + 1);
		sub = search.substr(0, search.find(','));
		if (pass != sub) {
			cout << "You have enterred incorrect password\n";
			return false;
		}
		else {
			cout << "Login Successful\n";
			return true;
		}
	}
}
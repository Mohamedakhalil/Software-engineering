#include "contractors.h"

void contract::calcDuration(Tourist t)
{
	cout << "Enter the starting date of your trip in the form dd/mm/yyyy\n";
	string s[2], sub; cin >> s[0];
	cout << "Enter the ending date of your trip in the form dd/mm/yyyy\n";
	cin >> s[1];
	int day[2], month[2], year[2];
	t.setStart(s[0]);
	t.setEnd(s[1]);
	for (int i = 0;i < 2;i++) {
		sub = s[i].substr(0, s[i].find('/'));
		day[i] = stoi(sub);
		s[i].erase(0, s[i].find('/') + 1);
		sub = s[i].substr(0, s[i].find('/'));
		month[i] = stoi(sub);
		s[i].erase(0, s[i].find('/') + 1);
		year[i] = stoi(s[i]);
	}
	duration = abs(day[0] - day[1]) + abs(month[0] - month[1]) * 30 + abs(year[0] - year[1]) * 365;
}

bool contract::bookTourguide(Tourist t, TourGuide TG)
{
	calcDuration(t);
	setPrice(TG);
	cout << "Tourist Details\n\tClient: " << t.getName() << "\n\n";
	cout << "Tourguide Details\n\tName of Tourguide: " << TG.getName() << "\n\tDestination: " << TG.getDestination()<< endl;
	cout << "\tTotal cost of the program: " << getPrice() << "\n\n";
	cout << "Refund Policy\n\tIf for any reason the tour is cancelled by the tourguide, a full refund will be made to the contracting party\n";
	cout << "If you want to confirm your booking enter 1, otherwise enter 0\n\n";
	int choice; cin >> choice;
	if (choice == 1) {
		TG.changeState();
		TG.deleteUser();
		fstream data;
		data.open("myUsers.txt", ios::app);
		TG.addUser(TG.getName(), TG.getPass(), TG.getActivities(), TG.getPriceRange(), TG.getRate(), TG.getAge(), TG.getDestination());
		data << TG.getState()  << ',' << 0 << ',' << TG.experts[0].getexpert() << ',' << TG.getLang() << endl;
		payment();
		fstream crm;
		crm.open("myCRM.txt", ios::app);
		crm << TG.getName() << ',' << getPrice() << ',' << t.getName() << endl;
		cout << "Your booking has been confirmed\n";
		return false;
	}
	else
		return true;
}

void contract::payment()
{
	cout << "Payment Information\n\tName on Card\n";
	string name;
	cin >> name;
	cout << "\tCard Number\n";
	long long num1; cin >> num1;
	cout << "\tCVV\n";
	int num2; cin >> num2;
	cout << "\tExpiry Date\n";
	string date; cin >> date;
}

void contract::setPrice(TourGuide TG)
{
	price = getDuration() * TG.getPriceRange();
}


int contract::getPrice()
{
	return price;
}

int contract::getDuration()
{
	return duration;
}

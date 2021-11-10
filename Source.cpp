#include "User.h"
#include "TourGuide.h"
#include "Tourist.h"
#include "Matcher.h"
#include "MatchNum.h"
#include "contractors.h"

void main() {
	cout << "For Tourist menu press 1\nFor Tourguide menu press 2\n";
	int choice; cin >> choice;
	if (choice == 1) {
		Tourist x;
		cout << "To sign up press 1\nTo log in press 2\n";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter your Username\n";
			string name, pass;
			cin >> name;
			cout << "Enter your password \n";
			cin >> pass;
			x.signUp(name, pass);
		}
		else {
			cout << "Enter your Username\n";
			string name, pass;
			cin >> name;
			cout << "Enter your password \n";
			cin >> pass;
			Tourist z;
			z= x.login(name, pass);
			cout << "Login Successful\n";
			cout << "If you want to look for matching tourguides enter 1\nIf you want to delete your account enter 2\n";
			int command; cin >> command;
			if (command == 1) {
				Matcher match;
				for (int i = 0; i < match.getSearches().size(); i++) {
					match.compareAct(z, match.getSearches().at(i));
					for (int j = 0;i < match.getValids().size();j++) {
						match.comparePrice(z, match.getValids().at(j));
						match.compareDest(z, match.getValids().at(j));
						match.compareLang(z, match.getValids().at(j));
					}
				}
				if (match.getValids().empty()) {
					cout << "You have got no available matches at the moment\n";
					return;
				}
				bool checker=true;
				while (checker) {
					cout << "Out of " << match.getSearches().size() << " available Tourguides, you have been matched with " << match.getValids().size() << endl;
					cout << "Select the profile you want to view\n";
					for (int i = 0; i < match.getValids().size(); i++)
						cout << i + 1 << ". " << match.getValids().at(i).getName() << endl;
					int tourorder; cin >> tourorder;
					TourGuide g = match.getValids().at(tourorder - 1);
					cout << "You are now viewing " << g.getName() << "'s profile" << endl << g.getName() << " charges "
						<< g.getPriceRange() << " per trip" << endl;
					cout << g.getName() << "'s rating is " << g.getRate() << " and is specializied in the following cities " << g.getDestination()
						<< " and the following activities";
					for (int i = 0; i < g.getActivities().size(); i++) {
						cout << " " << g.getActivities().at(i);
					}
					cout << endl << "Finally, He/She is an expert in " << g.experts.at(0).getexpert() << endl;
					contract c;
					checker = c.bookTourguide(z, g);
				}
			}
			else {
				z.deleteUser();
			}
		}
	}
	else if (choice == 2) {
		TourGuide x;
		cout << "To sign up press 1\n To log in press 2\n";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter your Username\n";
			string name, pass;
			cin >> name;
			cout << "Enter your password \n";
			cin >> pass;
			x.signUp(name, pass);
		}
		else {
			cout << "Enter your Username\n";
			string name, pass;
			cin >> name;
			cout << "Enter your password \n";
			cin >> pass;
			TourGuide z;
			z=x.login(name, pass);
			cout << "Login Successful\n";
			cout << "If you want to know the number of your tourists matches enter 1\nIf you want to delete your account enter 2\n";
			int command; cin >> command;
			if (command == 1) {
				MatchNum match;
				for (int i = 0; i < match.getSearches().size(); i++) {
					match.compareAct(match.getSearches().at(i), z);
					for (int j = 0;i < match.getValids().size();j++) {
						match.comparePrice(match.getValids().at(j), z);
						match.compareDest(match.getValids().at(j), z);
						match.compareLang(match.getValids().at(j), z);
					}
				}
				cout << "Out of " << match.getSearches().size() << " Tourists, you have been matched with " << match.getValids().size() << " tourist\n";
			}
			else {
				z.deleteUser();
			}
		}
	}
	else
		cout << "Unknown choice was picked\n";
}
#include "User.h"
#include "TourGuide.h"
#include "Tourist.h"
#include "Matcher.h"

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
			Matcher match;
			for (int i = 0; i < match.getSearches().size(); i++) {
				match.compareAct(z,match.getSearches().at(i));
				match.comparePrice(z, match.getSearches().at(i));
				match.compareDest(z, match.getSearches().at(i));
				match.compareLang(z, match.getSearches().at(i));
			}
			cout << "Out of " << match.getSearches().size() << " Tourguides, you have been matched with " << match.getValids().size() << endl;
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
			cout << endl << "Finally, He/She is an expert in " << g.experts.at(0).getexpert() << endl << "Would you like to reserve them for your vacation";
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
			x.login(name, pass);
		}
	}
	else
		cout << "Unknown choice was picked\n";
}
#include "MatchNum.h"
MatchNum::MatchNum()
{
	ifstream data;
	data.open("myUsers.txt");
	string searcher, sub;
	while (!data.eof()) {
		getline(data, searcher);
		if (searcher == "")
			return;
		reverse(searcher.begin(), searcher.end());
		int i = 0;
		while (!isdigit(searcher.at(i)))
			i++;
		if (searcher.at(i) == '1') {
			reverse(searcher.begin(), searcher.end());
			Tourist x;
			sub = searcher.substr(0, searcher.find(','));
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
			x.addpref(pref);
			searcher.erase(0, searcher.find(',') + 1);
			x.setLang(searcher);
			searches.push_back(x);
		}
	}
}

void MatchNum::compareLang(Tourist g, TourGuide t)
{
	if (t.getLang() == g.getLang())
		valids.push_back(g);
}

void MatchNum::compareDest(Tourist g, TourGuide t)
{
	if (t.getDestination() == g.getDestination())
		valids.push_back(g);
}

void MatchNum::comparePrice(Tourist g, TourGuide t)
{
	if (t.getPriceRange() == g.getPriceRange())
		valids.push_back(g);
}

void MatchNum::compareAct(Tourist g, TourGuide t)
{
	for (int i = 0; i < t.activities.size(); i++) {
		for (int j = 0; j < g.activities.size(); j++) {
			if (t.activities[i] == g.activities[j]) {
				valids.push_back(g);
				return;
			}
		}
	}
}

vector<Tourist> MatchNum::getValids()
{
	return valids;
}

vector<Tourist> MatchNum::getSearches()
{
	return searches;
}

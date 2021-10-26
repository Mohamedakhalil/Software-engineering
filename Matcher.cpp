#include "Matcher.h"
Matcher::Matcher()
{
	ifstream data;
	data.open("myUsers.txt");
	string searcher,sub;
	while (!data.eof()) {
		getline(data, searcher);
		if (searcher == "")
			return;
		reverse(searcher.begin(), searcher.end());
		int i = 0;
		while (!isdigit(searcher.at(i)))
			i++;
		if (searcher.at(i) == '0') {
			reverse(searcher.begin(), searcher.end());
			TourGuide x;
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
			while (sub != "0") {
				searcher.erase(0, searcher.find(',') + 1);
				sub = searcher.substr(0, searcher.find(','));
				if(sub!="0")
				x.activities.push_back(sub);
			}
			searcher.erase(0, searcher.find(',') + 1);
			sub = searcher.substr(0, searcher.find(','));
			Expertise exp;
			exp.setExpertise(sub);
			x.experts.push_back(exp);
			searcher.erase(0, searcher.find(',') + 1);
			x.setLang(searcher);
			searches.push_back(x);
		}
	}
}

void Matcher::compareLang(Tourist t, TourGuide g)
{
	if (t.getLang() == g.getLang())
		valids.push_back(g);
}

void Matcher::compareDest(Tourist t, TourGuide g)
{
	if (t.getDestination() == g.getDestination())
		valids.push_back(g);
}

void Matcher::comparePrice(Tourist t, TourGuide g)
{
	if (t.getPriceRange() == g.getPriceRange())
		valids.push_back(g);
}

void Matcher::compareAct(Tourist t, TourGuide g)
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

vector<TourGuide> Matcher::getValids()
{
	return valids;
}

vector<TourGuide> Matcher::getSearches()
{
	return searches;
}

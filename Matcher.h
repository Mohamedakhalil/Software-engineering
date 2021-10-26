#pragma once
#include "TourGuide.h"
#include "Tourist.h"
class Matcher
{
private:
	vector<TourGuide> searches;
	vector<TourGuide> valids;
public:
	Matcher();
	void compareLang(Tourist,TourGuide);
	void compareDest(Tourist, TourGuide);
	void comparePrice(Tourist, TourGuide);
	void compareAct(Tourist, TourGuide);
	vector<TourGuide> getValids();
	vector<TourGuide> getSearches();

};


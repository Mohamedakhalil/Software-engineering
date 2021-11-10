#pragma once
#include "TourGuide.h"
#include "Tourist.h"
class MatchNum
{
private:
	vector<Tourist> searches;
	vector<Tourist> valids;
public:
	MatchNum();
	void compareLang(Tourist, TourGuide);
	void compareDest(Tourist, TourGuide);
	void comparePrice(Tourist, TourGuide);
	void compareAct(Tourist, TourGuide);
	vector<Tourist> getValids();
	vector<Tourist> getSearches();
};


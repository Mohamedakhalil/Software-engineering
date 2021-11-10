#pragma once
#include "TourGuide.h"
#include "Tourist.h"
class contract
{
private:
	int price, duration;
public:
	void calcDuration(Tourist);
	bool bookTourguide(Tourist, TourGuide);
	void payment();
	void setPrice(TourGuide);
	int getPrice();
	int getDuration();
};


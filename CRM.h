#pragma once
#include "TourGuide.h"
#include "Tourist.h"
#include "contractors.h"

class CRM
{
public:
	bool checkTourist(string);
	bool checkTourguide(string);
	void deleteCRM(string);
	void contr(TourGuide);
	string tourguide(string);
};


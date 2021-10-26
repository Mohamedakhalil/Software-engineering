#pragma once
#include "User.h"
#include "Expertise.h"
class TourGuide:public User
{
private:
	string Lang;
	bool available=true;
public:
	vector<Expertise> experts;
	void setLang(string);
	string getLang();
	void signUp(string, string);
	void changeState();
	void addexpert();
	bool getState();
};

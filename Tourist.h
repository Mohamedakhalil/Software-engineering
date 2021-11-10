#pragma once
#include "User.h"
#include "Preference.h"
class Tourist:public User
{
private:
	string start="", end = "";
	string prefLang;
	vector<Preference> prefs;
public:
	Tourist login(string, string);
	void rateTourist(double);
	void signUp(string, string);
	void setStart(string);
	void setEnd(string);
	void setLang(string);
	void addpref(Preference);
	string getStart();
	string getEnd();
	string getLang();
};


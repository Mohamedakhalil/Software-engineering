#pragma once
#include "User.h"
#include "Preference.h"
class Tourist:public User
{
private:
	int start=0,end=0;
	string prefLang;
	vector<Preference> prefs;
public:
	Tourist login(string, string);
	void rateTourist(double);
	void signUp(string, string);
	void setStart(int);
	void setEnd(int);
	void setLang(string);
	void addpref();
	int getStart();
	int getEnd();
	string getLang();
};


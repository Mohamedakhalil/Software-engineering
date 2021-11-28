#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;



class User
{
private:
	string Username;
	string password;
	double priceRange=0, rate=5;
	int age=0;
	string destination;

public:
	vector<string> activities;
	void signUp(string, string);
	bool login(string, string);
	void addUser(string, string, vector<string>, double, double, int, string);
	void setName(string);
	void setPass(string);
	string getName();
	string getPass();
	void deleteUser();
	double getPriceRange();
	double getRate();
	int getAge();
	string getDestination();
	vector<string> getActivities();
	void setAge(int);
	void setRate(double);
	void setPriceRange(double);
	void setDestination(string);
	void setActivities(vector<string>);
	string acts[6] = { "Sightseeing", "Hiking", "Watching Sports", "Swimming" , "Religious" , "Horse riding" };
	string langs[5] = { "Arabic", "English", "German" , "French" , "Spanish" };
	string dests[7] = { "Cairo", "Alexandria", "Luxor", "Rome", "Paris", "Athens", "Mekkah" };
};
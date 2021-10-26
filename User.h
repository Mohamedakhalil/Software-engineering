#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <set>
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
	string getName();
	//void deleteUser();
	//void updateUser(double, double, string, vector<string>);
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
};
#include "CRM.h"

bool CRM::checkTourist(string name)
{
    bool check = false;
    fstream crm;
    crm.open("myCRM.txt");
    string s;
    while (!crm.eof()) {
        getline(crm, s);
        s.erase(0, s.find(',') + 1);
        s.erase(0, s.find(',') + 1);
        if (name == s)
            check = true;

    }
    return check;
}

bool CRM::checkTourguide(string name)
{
    bool check = false;
    fstream crm;
    crm.open("myCRM.txt");
    string s;
    while (!crm.eof()) {
        getline(crm, s);
        s = s.substr(0, s.find(','));
        if (name == s)
            check = true;
    }
    return check;
}

void CRM::deleteCRM(string name)
{
    fstream crm;
    crm.open("myCRM.txt", ios::app);
    string s, sub;
    vector <string> others;
    while (!crm.eof()) {
        getline(crm, s);
        sub = s.substr(0, s.find(','));
        if (name != sub)
            others.push_back(s);
    }
    crm.close();
    remove("myCRM.txt");
    ofstream newfile("myCRM.txt");
    for (int i = 0;i < others.size();i++) {
        newfile << others[i];
        if (i < others.size() - 1)
            newfile << endl;
    }
}

void CRM::contr(TourGuide TG)
{
    fstream crm;
    crm.open("myCRM.txt");
    string s, tg, price;
    while (!crm.eof()) {
        getline(crm, s);
        tg = s.substr(0, s.find(','));
        if (TG.getName() == tg) {
            s.erase(0, s.find(',') + 1);
            price = s.substr(0, s.find(','));
            s.erase(0, s.find(',') + 1);
            cout << "You have been booked by " << s << " for a deal of value: " << price << endl;
            cout << "If you want to accept the deal press 1, otherwise enter 0\n";
            int choice;cin >> choice;
            if (choice) {
                cout << "The deal has been agreed on\n";
            }
            else {
                deleteCRM(TG.getName());
                cout << "Your deal is cancelled\n";
                TG.setState(true);
                TG.deleteUser();
                fstream data;
                data.open("myUsers.txt", ios::app);
                TG.addUser(TG.getName(), TG.getPass(), TG.getActivities(), TG.getPriceRange(), TG.getRate(), TG.getAge(), TG.getDestination());
                data << TG.getState() << ',' << 0 << ',' << TG.experts[0].getexpert() << ',' << TG.getLang() << endl;
            }
        }
    }
}

string CRM::tourguide(string name)
{
    fstream crm;
    crm.open("myCRM.txt");
    string s, tg;
    while (!crm.eof()) {
        getline(crm, s);
        tg = s.substr(0, s.find(','));
        s.erase(0, s.find(',') + 1);
        s.erase(0, s.find(',') + 1);
        if (name == s)
            return tg;
    }
}

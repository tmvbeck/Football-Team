#pragma once
#include <cstring>
#include "string"
#include "stdafx.h"
using namespace std;

class FootballTeam
{
public:
	enum Conference { NFC, AFC };
	FootballTeam(Conference conference, string city, string name);
	FootballTeam();
	Conference getConference();
	string getCity();
	string getName();
	int getHomeWins();
	int getHomeLosses();
	int getHomeTies();
	int getRoadWins();
	int getRoadLosses();
	int getRoadTies();
	void gameScore(int us, int them, bool homeGame);
	string homeRecord();
	string roadRecord();
	string overallRecord();
private:
	Conference mConference;
	string mCity;
	string mName;
	int mHomeWins;
	int mHomeLosses;
	int mHomeTies;
	int mRoadWins;
	int mRoadLosses;
	int mRoadTies;
};
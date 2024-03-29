// FootballTeam.cpp : Defines the entry point for the console application.
// Project 5

#include "stdafx.h"
#include "FootballTeam.h"
#include <cstring>
#include "string"
using namespace std;

FootballTeam::FootballTeam(Conference conference, string city, string name)
{
	mConference = conference;
	mCity = city;
	mName = name;
	mHomeWins = 0;
	mHomeLosses = 0;
	mHomeTies = 0;
	mRoadWins = 0;
	mRoadLosses = 0;
	mRoadTies = 0;
}
FootballTeam::FootballTeam()
{
	mConference = NFC;
	mCity = "";
	mName = "";
	mHomeWins = 0;
	mHomeLosses = 0;
	mHomeTies = 0;
	mRoadWins = 0;
	mRoadLosses = 0;
	mRoadTies = 0;
}
FootballTeam::Conference FootballTeam::getConference()
{
	return mConference;
}
string FootballTeam::getCity()
{
	return mCity;
}
string FootballTeam::getName()
{
	return mName;
}
int FootballTeam::getHomeWins()
{
	return mHomeWins;
}
int FootballTeam::getHomeLosses()
{
	return mHomeLosses;
}
int FootballTeam::getHomeTies()
{
	return mHomeTies;
}
int FootballTeam::getRoadWins()
{
	return mRoadWins;
}
int FootballTeam::getRoadLosses()
{
	return mRoadLosses;
}
int FootballTeam::getRoadTies()
{
	return mRoadTies;
}
void FootballTeam::gameScore(int us, int them, bool homeGame)
{
	if (homeGame == true)
	{
		if (us > them)
		{
			mHomeWins += 1;
		}
		else if (us < them)
		{
			mHomeLosses += 1;
		}
		else
		{
			mHomeTies += 1;
		}
	}
	else
	{
		if (us > them)
		{
			mRoadWins += 1;
		}
		else if (us < them)
		{
			mRoadLosses += 1;
		}
		else
		{
			mRoadTies += 1;
		}
	}
}
string FootballTeam::homeRecord()
{
	string s = std::to_string(mHomeWins) + " - " + std::to_string(mHomeLosses) + " - " + std::to_string(mHomeTies);
	return s;
}
string FootballTeam::roadRecord()
{
	string t = std::to_string(mRoadWins) + " - " + std::to_string(mRoadLosses) + " - " + std::to_string(mRoadTies);
	return t;
}
string FootballTeam::overallRecord()
{
	string u = std::to_string(mHomeWins + mRoadWins) + " - " + std::to_string(mHomeWins + mRoadWins) + " - " + std::to_string(mHomeTies + mRoadTies);
	return u;
}
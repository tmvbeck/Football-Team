// main.cpp : Defines the entry point for the console application.
// Project 5

#include "stdafx.h"
#include "FootballTeam.h"
#include <cstring>
#include "string"
#include <cassert>
#include <iostream>
using namespace std;

bool betterRecord(FootballTeam f, FootballTeam g);

int main()
{
	FootballTeam f;
	FootballTeam pats(FootballTeam::Conference::AFC, "Foxboro", "New England Patriots");

	assert(f.getCity() == "");
	assert(f.getName() == "");
	assert(f.getConference() == FootballTeam::Conference::NFC);
	assert(f.overallRecord() == "0 - 0 - 0");
	assert(f.roadRecord() == "0 - 0 - 0");
	assert(f.homeRecord() == "0 - 0 - 0");

	pats.gameScore(20, 3, true);
	pats.gameScore(20, 40, true);
	pats.gameScore(20, 3, false);
	pats.gameScore(20, 40, false);
	pats.gameScore(20, 20, true);
	assert(pats.overallRecord() == "2 - 2 - 1");
	assert(pats.roadRecord() == "1 - 1 - 0");
	assert(pats.homeRecord() == "1 - 1 - 1");

	assert(pats.getHomeWins() == 1);
	assert(pats.getHomeLosses() == 1);
	assert(pats.getHomeTies() == 1);
	assert(pats.getRoadWins() == 1);
	assert(pats.getRoadLosses() == 1);
	assert(pats.getRoadTies() == 0);
	assert(betterRecord(pats, f) == true);
	assert(betterRecord(f, pats) == false);
	assert(betterRecord(pats, pats) == false);
	assert(betterRecord(f, f) == false);
	cout << "all tests passed" << endl;
	return 0;
}
bool betterRecord(FootballTeam f, FootballTeam g)
{
	if ((f.getHomeWins() + f.getRoadWins()) == (g.getHomeWins() + g.getRoadWins()))
	{
		if ((f.getHomeLosses() + f.getRoadLosses()) == (g.getHomeLosses() + g.getRoadLosses()))
		{
			if ((f.getHomeTies() + f.getRoadTies()) > (g.getHomeTies() + g.getRoadTies()))
			{
				return true;
			}
			else if ((f.getHomeLosses() + f.getRoadLosses()) < (g.getHomeLosses() + g.getRoadLosses()))
			{
				return false;
			}
			else
			{
				return false;
			}
		}
		else if ((f.getHomeLosses() + f.getRoadLosses()) < (g.getHomeLosses() + g.getRoadLosses()))
		{
			return true;
		}
		else if ((f.getHomeLosses() + f.getRoadLosses()) > (g.getHomeLosses() + g.getRoadLosses()))
		{
			return false;
		}
		else
		{
			return false;
		}
	}
	else if ((f.getHomeWins() + f.getRoadWins()) < (g.getHomeWins() + g.getRoadWins()))
	{
		return false;
	}
	else
	{
		return true;
	}
}
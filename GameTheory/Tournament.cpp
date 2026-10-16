#include "Tournament.h"
#include "Strategies.hpp"
#include <algorithm>

#include <iostream>


void Tournament::PopulateStrategy() {
	strategies.reserve(7);
	strategies.push_back(new Cooperater());
	strategies.push_back(new Betrayer());
	strategies.push_back(new TitForTat());
	strategies.push_back(new Coward());
	strategies.push_back(new Random());
	strategies.push_back(new Pavlov());
	strategies.push_back(new Prober());

}

void Tournament::Simulate() {
	for (IStrategy* strategy : strategies)
		strategy->reset();

	for (int i = 0; i < strategies.size(); i++)
		for (int y = i; y < strategies.size(); y++)
			PlayMatch(strategies[i], strategies[y]);
}

void Tournament::PlayMatch(IStrategy* p1, IStrategy* p2) {
	std::vector<Choice> p1Choices, p2Choices;
	p1Choices.reserve(50); p2Choices.reserve(50);
	p1->points = 0; p2->points = 0;

	//std::cout << p1->Name << " vs " << p2->Name << std::endl;

	for(int i = 0; i < 50; i++) {
		Choice p1Choice = p1->Decide(p1Choices, p2Choices),
			   p2Choice = p2->Decide(p2Choices, p1Choices);
		p1Choices.push_back(p1Choice);
		p2Choices.push_back(p2Choice);

		/*std::cout << "\t" << (p1Choice == Choice::Cooperate ? "Cooperate" : "Betray") << " vs "
			      << (p2Choice == Choice::Cooperate ? "Cooperate" : "Betray") << std::endl;*/


		if (p1Choice == Choice::Cooperate) {
			if (p2Choice == Choice::Cooperate) {
				p1->addPoint(3);
				p2->addPoint(3);
			}
			else {
				p1->addPoint(0);
				p2->addPoint(5);
			}
		}
		else {
			if (p2Choice == Choice::Cooperate) {
				p1->addPoint(5);
				p2->addPoint(0);
			}
			else {
				p1->addPoint(1);
				p2->addPoint(1);
			}
		}

	}

	//std::cout << p1->points << " - " << p2->points << " : ";

	if (p1->points == p2->points) {
		//std::cout << "Draw" << std::endl << std::endl;
		p1->rank.Draw++; p2->rank.Draw++;
	}
	else if (p1->points > p2->points) {
		//std::cout << p1->Name << std::endl << std::endl;
		p1->rank.Win++; p2->rank.Lose++;
	}
	else if (p1->points < p2->points) {
		//std::cout << p2->Name << std::endl << std::endl;
		p1->rank.Lose++; p2->rank.Win++;
	}
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const {
	std::vector<Ranking> r;
	for (IStrategy* strategy : strategies)
		r.push_back(strategy->rank);

	std::sort(r.begin(), r.end(), [](Ranking& r1, Ranking& r2)
		{
			if (r1.TotalPoint != r2.TotalPoint)
				return r1.TotalPoint > r2.TotalPoint;
			if (r1.Win != r2.Win)
				return r1.Win > r2.Win;
			else
				return r1.Draw > r2.Draw;
		});
	return r;
}
std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const {
	std::vector<Ranking> r;
	for (IStrategy* strategy : strategies)
		r.push_back(strategy->rank);

	std::sort(r.begin(), r.end(), [](Ranking& r1, Ranking& r2)
		{
			if (r1.Win != r2.Win)
				return r1.Win > r2.Win;
			else
				return r1.Draw > r2.Draw;
		});
	return r;
}
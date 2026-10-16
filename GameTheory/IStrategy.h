#pragma once

#include "Choice.h"
#include "Ranking.h"

#include <string>
#include <vector>

class IStrategy
{
public:

	IStrategy(const std::string& name) :
		Name(name), points(0) {
		rank = Ranking{name};
	}

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) = 0;

	void reset() {
		points = 0;
		rank.TotalPoint = 0;
		rank.Win = 0;
		rank.Draw = 0;
		rank.Lose = 0;
	}

	void addPoint(int p) {
		points += p;
		rank.TotalPoint += p;
	}

	std::string Name;

	unsigned points;
	Ranking rank;
};
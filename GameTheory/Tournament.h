#pragma once

#include "Ranking.h"

#include <vector>

class IStrategy;

class Tournament
{
public:
	void PopulateStrategy();

	void Simulate();

	void PlayMatch(IStrategy*, IStrategy*);

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;
private:
	std::vector<IStrategy*> strategies;
};
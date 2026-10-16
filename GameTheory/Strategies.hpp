#include "IStrategy.h"
#include <cstdlib>
#include <ctime>

class Cooperater : public IStrategy {
public:
	Cooperater() : IStrategy("Cooperater") {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		return Choice::Cooperate;
	}
};

class Betrayer : public IStrategy {
public:
	Betrayer() : IStrategy("Betrayer") {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		return Choice::Betray;
	}
};

class TitForTat : public IStrategy {
public:
	TitForTat() : IStrategy("TitForTat") {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		return (opponentPreviousDecisions.size() != 0 ?
			opponentPreviousDecisions[opponentPreviousDecisions.size()-1]:
			Choice::Cooperate);
	}
};

class Coward : public IStrategy {
public:
	Coward() : IStrategy("Coward") {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		for (const Choice& choice : opponentPreviousDecisions)
			if (choice == Choice::Betray)
				return Choice::Betray;
		return Choice::Cooperate;
	}
};

class Random : public IStrategy {
public:
	Random() : IStrategy("Random") { std::srand(std::time(nullptr)); }
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		return (std::rand()%2==0 ? Choice::Cooperate : Choice::Betray);
	}
};


class Pavlov : public IStrategy {
public:
	Pavlov() : IStrategy("Pavlov") {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		if (previousDecisions.size() == 0)
			return Choice::Cooperate;
		else {
			if ((previousDecisions[previousDecisions.size() - 1] == Choice::Cooperate && opponentPreviousDecisions[opponentPreviousDecisions.size() - 1] == Choice::Cooperate) ||
				(previousDecisions[previousDecisions.size() - 1] == Choice::Betray && opponentPreviousDecisions[opponentPreviousDecisions.size() - 1] == Choice::Cooperate))
				return previousDecisions[previousDecisions.size() - 1];
			else
				return (previousDecisions[previousDecisions.size() - 1]==Choice::Cooperate? Choice::Betray: Choice::Cooperate);
		}
	}
};


class Prober : public IStrategy {
public:
	Prober() : IStrategy("Prober") {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) {
		if (previousDecisions.size() == 0)
			return Choice::Betray;
		else if (previousDecisions.size() < 3)
			return Choice::Cooperate;
		else {
			bool hasBetray = false;
			for (int i = 0; i < 3; i++)
				if (opponentPreviousDecisions[i] == Choice::Betray)
					hasBetray = true;
			if (hasBetray)
				return Choice::Betray;
			else
				return opponentPreviousDecisions[opponentPreviousDecisions.size() - 1];
		}
	}
};

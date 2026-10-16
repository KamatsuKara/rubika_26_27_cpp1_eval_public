#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

struct Position {
	int x;
	int y;

	// Constructors

	Position() :x(0), y(0) {}
	Position(int _x, int _y) :x(_x), y(_y) {}
	Position(const Position& pos) :x(pos.x), y(pos.y) {}
	Position(int xy) :x(xy), y(xy) {}

	// Operators

	Position operator=(const Position& pos) {
		this->x = pos.x;
		this->y = pos.y;
		return *this;
	}

	Position operator+(const Position& pos) const {
		return Position(this->x + pos.x, this->y + pos.y);
	}

	Position operator-(const Position& pos) const {
		return Position(this->x - pos.x, this->y - pos.y);
	}

	bool operator==(const Position& pos) {
		return this->x == pos.x && this->y == pos.y;
	}

	bool operator!=(const Position& pos) {
		return this->x != pos.x || this->y != pos.y;
	}
	
	friend bool operator<(const Position& lhs, const Position& rhs) {
		if (lhs.x == rhs.x)
			return lhs.y < rhs.y;
		else return lhs.x < rhs.x;
	}

	friend bool operator>(const Position& lhs, const Position& rhs) {
		if (lhs.x == rhs.x)
			return lhs.y > rhs.y;
		else return lhs.x > rhs.x;
	}

};

#endif
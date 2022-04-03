#pragma once
#include "Music.h"

class Classical : public Music {
	std::string instrument;
	std::string author;
public:
	Classical() {}
	~Classical() {}
	std::ostream& print() override {
		Music::print();
		std::cout << "instrument: " << instrument << "  author: " << author<<"\n";
		return std::cout;
	}
	void read(std::istringstream& in) override {
		Music::read(in);
		in >> instrument >> author;
	}
};


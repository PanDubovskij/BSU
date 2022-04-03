#pragma once
#include "Music.h"
class Pop :public Music {
	std::string singer;
	std::string theme;
public:
	Pop(){}
	~Pop() {}
	std::ostream& print() override {
		Music::print();
		std::cout << "singer: " << singer << "  theme: " << theme << "\n";
		return std::cout;
	}
	void read(std::istringstream& in) override {
		Music::read(in);
		in >> singer >> theme;
	}
};
#pragma once
#include "Music.h"
class Chanson :public Music {
	std::string singer;
	int year;
public:
	Chanson();
	~Chanson() {}
	std::ostream& print() override {
		Music::print();
		std::cout << "singer: " << singer << "  year: " << year << "\n";
		return std::cout;
	}
	void read(std::istringstream& in) override {
		Music::read(in);
		in >> singer >> year;
	}
};
Chanson::Chanson() {
	year = 0;
}
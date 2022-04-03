#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include <iterator>
#include <algorithm>

class Music {
	double duration_;
	std::string name_;
	std::string style_;
	std::vector<std::string> styles;
public:
	Music() { duration_ = 0; }
	virtual ~Music() {}
	virtual std::ostream& print();
	virtual void read(std::istringstream&);
	double duration() const { return duration_; }
	std::string name() const { return name_; }
	std::string style() const { return style_; }
	void push_style_in_path() {
		styles.push_back(style_);
	}
	
	friend std::ostream& operator<<(std::ostream&, Music*&);
};
std::ostream& Music::print() {
	std::cout <<"style: "<<style_<< "  name: " << name_ << "  duration: " << duration_;
	return std::cout;
}
void Music::read(std::istringstream& in) {
	in >>style_>> name_ >> duration_;
}
std::ostream& operator<<(std::ostream& out, Music*& music) {
	(*music).print();
	return out;
}


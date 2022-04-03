#pragma once
#include<string>
#include<iostream>
class TRAIN{
	public:
		TRAIN()=default;
		TRAIN(std::string SityName_,int TrainNumber_,bool Express_);
		TRAIN(const TRAIN&tr);
		~TRAIN()=default;
		friend std::ostream& operator<<(std::ostream& out, const TRAIN&tr);
		friend std::ostream& operator>>(std::ostream& in, const TRAIN&tr);
		void Sity(TRAIN *timetable, int size);
		void SityExpress(TRAIN *timetable, int size);
	private:
	    std::string SityName;
	    int TrainNumber;
	    bool Express;	
};

#include"TRAIN.h"
#include<string>

TRAIN::TRAIN(std::string SityName_,int TrainNumber_,bool Express_):SityName(SityName_),TrainNumber(TrainNumber_),Express(Express_){}

TRAIN::TRAIN(const TRAIN&tr):SityName(tr.SityName),TrainNumber(tr.TrainNumber),Express(tr.Express){}

std::ostream& operator<<(std::ostream& out, const TRAIN&tr){
	out << tr.SityName << " "<< tr.TrainNumber << " "<< tr.Express;
}

std::ostream& operator>>(std::ostream& in, const TRAIN&tr){
	in << tr.SityName << " "<< tr.TrainNumber << " "<< tr.Express;
}

void TRAIN::Sity(TRAIN *timetable,int size){
	std::string sity;
	std::cout << "\nenter sity:\n";
	std::cin >> sity;
	for(int i=0; i<size; i++){
		if(timetable[i].SityName==sity){
			std::cout << timetable[i].TrainNumber << " " << timetable[i].Express << "\n";
		}
	}
}

void TRAIN::SityExpress(TRAIN *timetable, int size){
	std::string sity;
	std::cout << "\nenter sity:\n";
	std::cin >> sity;
	for(int i=0; i<size; i++){
		if(timetable[i].SityName==sity&&timetable[i].Express==true){
			std::cout << timetable[i].TrainNumber << "\n";
		}
	}
}

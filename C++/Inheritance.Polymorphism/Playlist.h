#pragma once
#include"Music.h"
#include"Classical.h"
#include "Pop.h"
#include "Chanson.h"
class Playlist {
	std::vector<Music*> music_ptrs;
	Music* get_ptr(char marker);
public:
	
	void ReadFromFile(std::string file_name);
	double CountDuration();
	void SortStyle();
	void Print();
	void SortDuration();
	std::vector<Music*> WriteToDisk(double duration_);
	void FindStyleDuration(std::string style_, double durat);
	~Playlist() {
		std::for_each(music_ptrs.begin(), music_ptrs.end(), [](Music*& for_del) {delete for_del; });
	}
};
Music* Playlist::get_ptr(char marker)
{
	if (marker == 'c') {
		return new Chanson;
	}
	else if (marker == 'l') {
		return new Classical;
	}
	else if (marker == 'p') {
		return new Pop;
	}
	else {
		std::cout << "error";
		return nullptr;
	}
}
void Playlist::ReadFromFile(std::string file_name) {
	std::ifstream in(file_name);
	if (!in.is_open())
	{
		std::cout << "error\n";
		exit(1);
	}
	while (!in.eof())
	{
		char marker;
		in >> marker;
		music_ptrs.push_back(get_ptr(marker));
		std::string str;
		getline(in, str);
		std::istringstream stream(str);
		music_ptrs.back()->read(stream);
	}
}
double Playlist::CountDuration() {
	double Duration = 0;
	for (int i = 0; i < music_ptrs.size(); i++) {
		Duration += music_ptrs.back()->duration();
	}
	return Duration;
}
void Playlist::SortStyle() {
	sort(music_ptrs.begin(), music_ptrs.end(), [](Music*& music1, Music*& music2)
		{
			return music1->style() < music2->style();
		}
	);
}
void Playlist::Print() {
	std::ostream_iterator<Music*&> out_music(std::cout);
	copy(music_ptrs.begin(), music_ptrs.end(), out_music);
}
void Playlist::SortDuration() {
	sort(music_ptrs.begin(), music_ptrs.end(), [](Music*& music1, Music*& music2)
		{
			return music1->duration() > music2->duration();
		}
	);
}
std::vector<Music*> Playlist::WriteToDisk(double duration_) {
	std::vector<Music*> disk;
	bool flag = true;
	while (duration_ > 0 && flag)
	{
		for (Music*& nope_music : music_ptrs) {
			if (nope_music->duration() <= duration_)
			{
				disk.push_back(nope_music);
				duration_ -= nope_music->duration();
			}
			else if (duration_ < music_ptrs.back()->duration())
				flag = false;
		}
	}
	return disk;
}
void Playlist::FindStyleDuration(std::string style_, double durat) {
		for (Music*& nope_music : music_ptrs) {
			if (nope_music->duration() == durat)
			{
				if (nope_music->style() == style_) {
					nope_music->print();
				}
			}
			else {
				std::cout << "Nothing is finded";
				exit(1);
			}
		}
}
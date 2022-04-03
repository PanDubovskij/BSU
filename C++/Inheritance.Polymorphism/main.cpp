#include"Music.h"
#include"Classical.h"
#include "Pop.h"
#include "Chanson.h"
#include "Playlist.h"
int main()
{
	Playlist disk;
	disk.ReadFromFile("input.txt");
	std::cout << "All duration: " << disk.CountDuration()<<"\n";
	disk.SortStyle();
	std::cout << "Sorted music(style): \n";
	disk.SortDuration();
	std::cout << "Sorted music(duration): \n";
	disk.Print();
	std::vector<Music*> disk1;
	double duration_;
	std::cout << "Enter duration\n";
	std::cin >> duration_;
	disk1 = disk.WriteToDisk(duration_);
	std::cout << "Our disk:\n";
	std::ostream_iterator<Music*&> out_music(std::cout);
	copy(disk1.begin(), disk1.end(), out_music);
	std::string style_;
	double durat;
	std::cout << "Enter style and duration\n";
	std::cin >> style_ >> durat;
	disk.FindStyleDuration(style_, durat);
	return 0;

}
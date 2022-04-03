#include "headers.h"
int main() {
  RaceTrack raceTrack;
  raceTrack.ReadHorses("horses.txt");
  raceTrack.ReadJockeys("jockeys.txt");
  raceTrack.ReadCompletedraces("output.txt");
  std::cout << "Do you want to add new races: enter 'yes' or 'no': ";
  std::string answer;
  std::cin >> answer;
  if (answer == "yes") {
    bool flag = true;
    while (flag) {
      std::string jockey_surname;
      std::cout << "Enter the surname of jockey: ";
      std::cin >> jockey_surname;
      raceTrack.AddCompletedRace(jockey_surname);
      std::cout << "If want to end, enter 'end', else 'continue'";
      std::string flag_name;
      std::cin >> flag_name;
      if (flag_name == "end") {
        flag = false;
      }
    }
  }
  std::cout << "Enter number of race, which information you want to edit: ";
  int numb0;
  std::cin >> numb0;
  raceTrack.EditRace(numb0); 
  std::cout << "Enter number of race, which information you want to get: ";
  int numb;
  std::cin >> numb;
  raceTrack.SearchRace(numb);
  std::cout << "Enter number of race, which you want to delete: ";
  int numb2;
  std::cin >> numb2;
  raceTrack.DeleteRace(numb2);
  raceTrack.PrintCompletedRaces("output.txt");
  return 0;
}
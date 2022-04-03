#pragma once

#include "headers.h"

class RaceTrack {
  std::vector<Horse> horses;
  std::vector<Jockey> jockeys;
  std::vector<CompletedRace> completed_races;

 public:
  RaceTrack() = default;
  ~RaceTrack() = default;
  void ReadHorses(std::string filename);
  void PrintHorses(std::string filename);
  void ReadJockeys(std::string filename);
  void PrintJockeys(std::string filename);
  void ReadCompletedraces(std::string filename);
  void PrintCompletedRaces(std::string filename);
  void AddCompletedRace(std::string route_name);
  void SearchRace(int number);
  void DeleteRace(int number);
  void EditRace(int number);
};

void RaceTrack::ReadHorses(std::string filename) {
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cout << "Error!";
    return;
  }
  while (!in.eof()) {
    Horse horse;
    in >> horse;
    horses.push_back(horse);
  }
}

void RaceTrack::ReadJockeys(std::string filename) {
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cout << "Error!";
    return;
  }
  while (!in.eof()) {
    Jockey jockey;
    in >> jockey;
    jockeys.push_back(jockey);
  }
}
void RaceTrack::ReadCompletedraces(std::string filename) {
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cout << "Error!";
    return;
  }
  while (!in.eof()) {
    CompletedRace race;
    in >> race;
    completed_races.push_back(race);
  }
}
void RaceTrack::PrintHorses(std::string filename) {
  std::ofstream out(filename);
  std::copy(horses.begin(), horses.end(),
            std::ostream_iterator<Horse>(out, "\n"));
}

void RaceTrack::PrintJockeys(std::string filename) {
  std::ofstream out(filename);
  std::copy(jockeys.begin(), jockeys.end(),
            std::ostream_iterator<Jockey>(out, "\n"));
}

void RaceTrack::PrintCompletedRaces(std::string filename) {
  std::ofstream out(filename);
  std::copy(completed_races.begin(), completed_races.end(),
            std::ostream_iterator<CompletedRace>(out, "\n"));
}
void RaceTrack::AddCompletedRace(std::string jockey_surname) {
  auto iterator = std::find_if(jockeys.begin(), jockeys.end(),
                               [jockey_surname](const Jockey& jockey) {
                                 return jockey.getSurname() == jockey_surname;
                               });
  if (iterator == jockeys.end()) {
    std::cout << "Jockey is not found";
    return;
  }
  CompletedRace completed_race;
  completed_race.setSurname(iterator->getSurname());
  std::cout << "All horses:\n";
  std::copy(horses.begin(), horses.end(),
            std::ostream_iterator<Horse>(std::cout, "\n"));
  std::cout << "Enter the owner of the horses ";
  std::string owner;
  std::cin >> owner;
  auto iterator2 = std::find_if(
      horses.begin(), horses.end(),
      [owner](const Horse& horse) { return horse.getOwner() == owner; });
  if (iterator2 == horses.end()) {
    std::cout << "Horse is not found";
    return;
  }
  completed_race.setNickname(iterator2->getNickname());
  std::cout << "Enter the data of a race: ";
  std::string data;
  std::cin >> data;
  completed_race.setData(data);
  std::cout << "Enter number of a race: ";
  int number;
  std::cin >> number;
  completed_race.setNumber(number);
  std::cout << "Enter award: ";
  int award;
  std::cin >> award;
  completed_race.setAward(award);
  completed_races.push_back(completed_race);
}

void RaceTrack::SearchRace(int number) {
  std::vector<CompletedRace> search_by_route;
  std::copy_if(completed_races.begin(), completed_races.end(),
               std::back_inserter(search_by_route),
               [number](const CompletedRace& completed_race) {
                 return completed_race.getNumber() == number;
               });
  std::copy(search_by_route.begin(), search_by_route.end(),
            std::ostream_iterator<CompletedRace>(std::cout, "\n"));
  std::set<Horse> horses_by_race;
  for (size_t i = 0; i < search_by_route.size(); i++) {
    CompletedRace element = search_by_route[i];
    std::copy_if(horses.begin(), horses.end(),
                 std::inserter(horses_by_race, horses_by_race.begin()),
                 [element](const Horse& horse) {
                   return horse.getNickname() == element.getNickname();
                 });
  }
  std::cout << "Horse for this race:\n";
  std::copy(horses_by_race.begin(), horses_by_race.end(),
            std::ostream_iterator<Horse>(std::cout, "\n"));
  std::set<Jockey> jockeys_by_race;
  for (size_t i = 0; i < search_by_route.size(); i++) {
    CompletedRace element = search_by_route[i];
    std::copy_if(jockeys.begin(), jockeys.end(),
                 std::inserter(jockeys_by_race, jockeys_by_race.begin()),
                 [element](const Jockey& jockey) {
                   return jockey.getSurname() == element.getSurname();
                 });
  }
  std::cout << "Jockey for this race:\n";
  std::copy(jockeys_by_race.begin(), jockeys_by_race.end(),
            std::ostream_iterator<Jockey>(std::cout, "\n"));
}
void RaceTrack::DeleteRace(int number) {
  std::remove_if(completed_races.begin(), completed_races.end(),
                 [number](const CompletedRace& race) {
                   return race.getNumber() == number;
                 });
}
void RaceTrack::EditRace(int number) {
  auto race = std::find_if(completed_races.begin(), completed_races.end(),
                           [number](const CompletedRace& compl_race) {
                             return compl_race.getNumber() == number;
                           });
  if (race == completed_races.end()) {
    std::cout << "Wrong number";
    return;
  }
  std::remove_if(completed_races.begin(), completed_races.end(),
                 [number](const CompletedRace& race) {
                   return race.getNumber() == number;
                 });
  std::cout << "Enter new data of race: ";
  std::string data;
  std::cin >> data;
  race->setData(data);
  std::cout << "Enter new award: ";
  int award;
  std::cin>>award;
  race->setAward(award);
  race->setNickname(race->getNickname());
  race->setSurname(race->getSurname());
}
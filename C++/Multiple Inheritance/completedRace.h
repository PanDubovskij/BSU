#pragma once

#include "headers.h"

class CompletedRace : private Horse,private Jockey {
  std::string data;
  int number;
  int award;

 public:
  CompletedRace() = default;
  ~CompletedRace() = default;

  using Horse::getNickname;
  using Horse::setNickname;
  using Horse::getOwner;
  using Jockey::getSurname;
  using Jockey::setSurname;

  std::string getData() const { return data; }
  int getNumber() const { return number; }
  int getAward() const { return award; }
  void setData(std::string data_) { data = data_; }
  void setNumber(int number_) { number = number_; }
  void setAward(int award_) { award = award_; }
  friend std::istream& operator>>(std::istream& in, CompletedRace&);
  friend std::ostream& operator<<(std::ostream& out, const CompletedRace&);
};
std::ostream& operator<<(std::ostream& out, const CompletedRace& race) {
  out << race.getData()<< " " << race.getNumber() << " " << race.getNickname() << " "<< race.getSurname() << " "<<race.getAward();
  return out;
}
std::istream& operator>>(std::istream& in, CompletedRace& race) {
  std::string nickname;
  std::string surname;
  in >> race.data >> race.number >> nickname >> surname >> race.award;
  race.setNickname(nickname);
  race.setSurname(surname);
  return in;
}

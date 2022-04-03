#pragma once

#include"headers.h"

class Horse {
  std::string nickname;
  int age;
  int experience;
  std::string owner;

 public:
  Horse() = default;
  ~Horse() = default;

  std::string getNickname() const { return nickname; }
  int getAge() const { return age; }
  int getExperience() const { return experience; }
  std::string getOwner() const { return owner; }
  void setNickname(std::string name) { nickname = name; }
  friend std::istream& operator>>(std::istream& in, Horse&);
  friend std::ostream& operator<<(std::ostream&, const Horse&);
  bool operator<(const Horse& horse_1) const { return horse_1.getNickname() < nickname; }
};

std::ostream& operator<<(std::ostream& out, const Horse& horse) {
  out << "Nickname: " << horse.getNickname() << " Age: " << horse.getAge()
      << " Experience: " << horse.getExperience()<<"  Owner: "<<horse.getOwner();
  return out;
}

std::istream& operator>>(std::istream& in, Horse& horse) {
  in >> horse.nickname >> horse.age >> horse.experience >> horse.owner;
  return in;
}
#pragma once

#include "headers.h"

class Jockey {
  std::string surname;
  int jockeyExperience;
  std::string birthday;
  std::string address;

 public:
  Jockey() = default;
  ~Jockey() = default;
  std::string getSurname() const { return surname; }
  int getJockeyExperience() const { return jockeyExperience; }
  std::string getBirthday() const { return birthday; }
  std::string getAdress() const { return address; }
  void setSurname(std::string surname_) { surname = surname_; }
  friend std::istream& operator>>(std::istream& in, Jockey&);
  friend std::ostream& operator<<(std::ostream&, const Jockey&);
  bool operator<(const Jockey& jockey_1) const {
    return jockey_1.getSurname() < surname;
  }
};
std::ostream& operator<<(std::ostream& out, const Jockey& jockey) {
  out << "Surname: " << jockey.getSurname()
      << " Experience: " << jockey.getJockeyExperience()
      << " Birthday: " << jockey.getBirthday()
      << " Address: " << jockey.getAdress();
  return out;
}

std::istream& operator>>(std::istream& in, Jockey& jockey) {
  in >> jockey.surname >> jockey.jockeyExperience >> jockey.birthday >> jockey.address;
  return in;
}

#pragma once
#include <string>

#include "Visitor.h"

class VisitorToString : public Visitor {
 public:
  void Visit(int elem) { str += std::to_string(elem) + " "; };
  std::string GetString() { return str; };

 private:
  std::string str;
};
#pragma once
#include "Visitor.h"

class CardinalityVisitor : public Visitor {
 public:
  void Visit(int elem) { 
   if (elem != 0) {
    cardinality++;
   }
    };
  int GetCardinality() { return cardinality; };

 private:
  int cardinality = 0;
};
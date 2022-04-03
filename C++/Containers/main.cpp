#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

#include "Flowerbed.h"
#include "FlowerbedManager.h"

int main() {
  FlowerbedManager flowerbeds;
  flowerbeds.WriteFromFileToVector("input.txt");
  flowerbeds.PrintVector();
  flowerbeds.SortByShape();
  std::cout << "Sorted flowerbeds by shape :\n";
  flowerbeds.PrintVector();
  flowerbeds.WriteFromVectorToMultimap();
  std::cout << "Flowerbeds (multimap)\n";
  flowerbeds.PrintMultimap();
  std::cout << "Different shapes of flowerbed:\n";
  flowerbeds.DifferentShapesOfFlowerbeds();
  std::cout << "\nEnter number of flowerbed\n";
  int numb;
  std::cin >> numb;
  flowerbeds.PrintFlowersOfFlowerbed(numb);
  std::cout << "\nFlowerbed with max number of flowers:\n";
  flowerbeds.FindFlowerbedWithMaxNumberOfFlowers();
  std::cout << "\nEnter number of flowers\n";
  int num;
  std::cin >> num;
  flowerbeds.FindAppropriateNumberOfFlowers(num);
   std::cout << "Appropriate flowerbeds:\n";
   flowerbeds.FindFlowerbedsWithNumberOfFlowers(num);
   std::cout << "\nNumber of flowers in circle flowerbeds = " << flowerbeds.CountFlowersinCircle();
    std::cout << "\nEnter shape of flowerbed\n";
    std::string shap;
    std::cin >> shap;
    flowerbeds.FindFlowerbedsbyShape(shap);
     std::cout << "\nEnter name of flower, which you want to delete\n";
     std::string flower;
     std::cin >> flower;
     flowerbeds.DeleteFlower(flower);
     flowerbeds.PrintMultimap();
 return 0;
}
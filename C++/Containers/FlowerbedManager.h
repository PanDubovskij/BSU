#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include "Flowerbed.h"
class FlowerbedManager {
  std::vector<Flowerbed> vector_flowerbed;
  std::multimap<std::string, Flowerbed> multimap_flowerbed;

 public:
  FlowerbedManager() = default;
  ~FlowerbedManager() = default;
  void WriteFromFileToVector(std::string filename);//из файла в вектор
  void PrintVector();//печать вектора
  void SortByShape();//сортировка по форме
  void WriteFromVectorToMultimap();//запись из вектора в мультимэп
  void PrintMultimap();//печать мультимэп
  void DifferentShapesOfFlowerbeds();//вывести список различных форм для клумб
  void PrintFlowersOfFlowerbed(int numb);//вывести список всех цветов указанной клумбы
  void FindFlowerbedWithMaxNumberOfFlowers();//найти клумбу с наибольшим количеством цветов;
  void FindFlowerbedsWithNumberOfFlowers(int num);//найти клумбы с указанным количеством цветов
  void FindAppropriateNumberOfFlowers(int num);//найти клумбы с указанным количеством цветов
  int CountFlowersinCircle();//подсчет числа цветков на всех круглых клумбах
  void FindFlowerbedsbyShape(std::string shap);//поиск всех клумб указанной формы 
  void DeleteFlower(std::string flowВer);//удаление  указанного цветка со всех клумб
  int CalculateFlowersOnRoundFlowerbeds();
};

void FlowerbedManager::WriteFromFileToVector(std::string filename) {
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cout << "error\n";
  } else {
    while (!in.eof()) {
      Flowerbed flbed;
      std::string str;
      getline(in, str);
      std::istringstream stream(str);
      flbed.read(stream);
      vector_flowerbed.push_back(flbed);
    }
  }
}
void FlowerbedManager::PrintVector() {
  for (int i = 0; i < vector_flowerbed.size(); i++) {
    std::cout << vector_flowerbed[i];
  }
}
void FlowerbedManager::SortByShape() {
  std::sort(vector_flowerbed.begin(), vector_flowerbed.end(),
            [](Flowerbed& flowerbed1, Flowerbed& flowerbed2) {
              return flowerbed1.getShape() < flowerbed2.getShape();
            });
}
void FlowerbedManager::WriteFromVectorToMultimap() {
  for (int i = 0; i < vector_flowerbed.size(); i++) {
    multimap_flowerbed.insert(std::pair<std::string, Flowerbed>(
        vector_flowerbed[i].getShape(), vector_flowerbed[i]));
  }
}
void FlowerbedManager::PrintMultimap() {
  for (std::multimap<std::string, Flowerbed>::iterator it =
           multimap_flowerbed.begin();
       it != multimap_flowerbed.end(); it++) {
    std::cout << it->first << "\t" << it->second;
  }
}
void FlowerbedManager::DifferentShapesOfFlowerbeds() {
  int count_oval = multimap_flowerbed.count("oval");
  if (count_oval > 0) {
    std::cout << "oval\t";
  }
  int count_circle = multimap_flowerbed.count("circle");
  if (count_circle > 0) {
    std::cout << "circle\t";
  }
  int count_romb = multimap_flowerbed.count("romb");
  if (count_romb > 0) {
    std::cout << "romb\t";
  }
  if (count_oval == 0 && count_circle == 0 && count_romb == 0) {
    std::cout << "There is no flowerbeds";
  }
}
void FlowerbedManager::PrintFlowersOfFlowerbed(int numb) {
  for (std::multimap<std::string, Flowerbed>::iterator it =
           multimap_flowerbed.begin();
       it != multimap_flowerbed.end(); it++) {
    Flowerbed flbed = it->second;
    if (flbed.getNumber() == numb) {
      for (int i = 0; i < flbed.getFlowers().size(); i++) {
        std::cout << flbed.getFlowers()[i] << " ";
      }
    }
  }
}
void FlowerbedManager::FindFlowerbedWithMaxNumberOfFlowers() {
  std::vector<int> number_of_flowers;
  for (std::multimap<std::string, Flowerbed>::iterator it =
           multimap_flowerbed.begin();
       it != multimap_flowerbed.end(); it++) {
    Flowerbed flbed = it->second;
    number_of_flowers.push_back(flbed.getFlowers().size() - 1);
  }
  std::vector<int>::iterator result;
  result = std::max_element(number_of_flowers.begin(), number_of_flowers.end());
  for (std::multimap<std::string, Flowerbed>::iterator it =
           multimap_flowerbed.begin();
       it != multimap_flowerbed.end(); it++) {
    Flowerbed flbed = it->second;
    if ((flbed.getFlowers().size() - 1) ==
        number_of_flowers[std::distance(number_of_flowers.begin(), result)]) {
      std::cout << flbed;
    }
  }
}
void FlowerbedManager::FindFlowerbedsWithNumberOfFlowers(int num) {
  for (std::multimap<std::string, Flowerbed>::iterator it =
           multimap_flowerbed.begin();
       it != multimap_flowerbed.end(); it++) {
    Flowerbed flbed = it->second;
    if ((flbed.getFlowers().size() - 1) == num) {
      std::cout << flbed;
    }
  }
}
  void FlowerbedManager::FindAppropriateNumberOfFlowers(int num) {
  std::cout << "Appropriate flowerbeds:\n";
  std::for_each(multimap_flowerbed.begin(), multimap_flowerbed.end(),
                [num](const std::pair<const std::string, Flowerbed>& fl) {
                  Flowerbed flbed = fl.second;
                  if ((flbed.getFlowers().size() - 1) == num) {
                    std::cout << flbed;
                    return true;
                  } else {
                    return false;
                  }
                });
  }
 
 /* int FlowerbedManager::CountFlowersinCircle() {
    int count = 0;
    for (std::multimap<std::string, Flowerbed>::iterator it =
             multimap_flowerbed.begin();
         it != multimap_flowerbed.end(); it++) {
      if (it->first == "circle") {
        Flowerbed flowerbed = it->second;
        count += (flowerbed.getFlowers().size() - 1);
      }
    }
    return count;
  }*/

  void FlowerbedManager::FindFlowerbedsbyShape(std::string shap) {
    std::cout << "Appropriate flowerbeds:\n";
    std::for_each(multimap_flowerbed.begin(), multimap_flowerbed.end(),
                 [shap](const std::pair<const std::string, Flowerbed>& fl) {
                   Flowerbed flbed = fl.second;
                   if (flbed.getShape() == shap) {
                     std::cout << flbed;
                     return true;
                   } else {
                     return false;
                   }
                 });
  }
  void FlowerbedManager::DeleteFlower(std::string flower) {
    std::cout << "Flowerbeds without this flower\n";
    for (std::multimap<std::string, Flowerbed>::iterator it =
             multimap_flowerbed.begin();
         it != multimap_flowerbed.end(); it++) {
      Flowerbed flbed = it->second;
      std::remove_if(flbed.getFlowers().begin(), flbed.getFlowers().end(),
                     [flower](std::string fl) { return fl == flower; });
    }
  }
  int CalcFlowers(int sum, const std::pair<std::string, Flowerbed>& pair) {
    if (pair.first != "circle") {
      return sum;
    }
    return sum + pair.second.getFlowers().size();
  }
  int FlowerbedManager::CountFlowersinCircle() {
    return std::accumulate(multimap_flowerbed.begin(), multimap_flowerbed.end(), 0,
                           CalcFlowers);
  }
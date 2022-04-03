#pragma once
class Flowerbed {
  int number;
  std::string shape;
  std::vector<std::string> flowers;

 public:
  Flowerbed() = default;
  ~Flowerbed() = default;
  int getNumber() const { return number; }
  std::string getShape() const { return shape; }
  std::vector<std::string> getFlowers() const { return flowers; }
  void read(std::istringstream&);
};
void Flowerbed::read(std::istringstream& in) {
  in >> number >> shape;
  std::string str;
  std::string marker = "\n";
  while (getline(in, str, ' ')) {
    flowers.push_back(str);
  }
}
std::ostream& operator<<(std::ostream& out, Flowerbed& flowerbed) {
  std::cout << "number: " << flowerbed.getNumber()
            << "  shape: " << flowerbed.getShape() << "  flowers: ";
  for (auto i : flowerbed.getFlowers()) {
    std::cout << i << "  ";
  }
  std::cout << "\n";
  return std::cout;
}

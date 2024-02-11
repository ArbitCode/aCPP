#include <iostream>
#include<string>
using namespace std;
class Singletone {
  static Singletone *instance;
  string data;
  Singletone(string val) : data(val) {}

public:
  static Singletone *getInstance() {
    if (instance == nullptr) {
      instance = new Singletone("Object created!");
    }
    return instance;
  }
  void getData() {
    cout << "Data: " << data << endl;
  }
};
Singletone* Singletone::instance = nullptr;
int main() {

  Singletone *instance = Singletone::getInstance();
  instance->getData();
}

#include <format>
#include <iostream>

using std::cout;
using std::format;

int main(){
  int x;
  auto k = 47;
  const int i{}; //initialized with 0
  int j{1}; //initialized with 1
  x = 42;
  int* ip;
  ip = &x;
  int y = *ip;
  auto str = format("x is {}\n", x);
  cout << str;
}

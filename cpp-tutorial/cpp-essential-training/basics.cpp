#include <format>
#include <iostream>

using std::cout;
using std::format;

int main(){
  int x;
  x = 42;
  auto str = format("x is {}\n", x);
  cout << str;
}

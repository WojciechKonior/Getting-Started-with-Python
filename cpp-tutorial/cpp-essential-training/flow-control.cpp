#include <format>
#include <iostream>

using std::format;
using std::cout;

int main(){
  auto x = 42;
  auto y = 7;
  if(x>y){
    cout << "condition is true\n";
  }
  else if(x<=y){
    cout << "condition is true\n";
  }
  else if(x!=y){
    cout << "condition is true\n";
  }
  else{
    cout << "all conditions are false\n";
  }
  cout << "after\n";
}

#include <format>
#include <iostream>

using std::format;
using std::cout;

int func(int i, const char* str){
  cout << "this is func(): " << i << << ": " << str << "\n";
  return i*2;
}

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

  int array[] {1, 2, 3, 4, 5};
  int i {0};

  while(i<5){
    if(i==3) break;
    cout << format("element {} is {}\n", i, array[i]);
    ++i;
  }

  do{
    if(i==3) break;
    cout << format("element {} is {}\n", i, array[i]);
    ++i;
  } while(i<5);

  for(int i {0}; i<5; ++i){
    cout << format("element {} is {}\n", i, array[i]);
  }

  const char string[] {"string"};
  for(int i{0}; string[i]; ++i){
    cout << format("element {} is {}\n", i, string[i]);
  }

  for(auto* p = string; *p, ++p){
    cout << format("char is {}\n", *p);
  }

  for(const auto& e : array){
    cout << "format("element is {}\n", e);
  }

  auto x = func(2, "two");
  cout << "after\n";
}

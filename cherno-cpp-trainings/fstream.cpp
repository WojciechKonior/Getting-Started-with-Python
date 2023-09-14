#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("sample.txt");
    std::string line;
    while(std::getline(file, line)){
        cout << line << endl;
    }

    cout << "Hello World\n";
    return 0;
}
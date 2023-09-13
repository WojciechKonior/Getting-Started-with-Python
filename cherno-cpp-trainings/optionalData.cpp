#include <iostream>
#include <fstream>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if(stream)
    {
        std::string result = "Wojtek";
        stream.close();
        return result;
    }

    return {};
}

int main()
{
    std::optional<std::string> str = ReadFileAsString("some.txt");
    if(str.has_value())
        std::cout << "file read successfully" << std::endl;
    else
        std::cout << "str has no value\n";

    return 0;
}
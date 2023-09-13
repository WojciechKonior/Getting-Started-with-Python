#include <iostream>
#include <fstream>
#include <optional>
#include <variant>
#include <any>

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
        std::cout << "file read successfully " << *str << str.value() << std::endl;
    else
        std::cout << "str has no value\n";

    std::string value = str.value_or("has no value");

    std::variant<std::string, int> val;
    val = "Wojtek";
    val = 2;

    int *v = std::get_if<int>(&val);
    std::cout << *v << std::endl;

    std::any var1;
    var1 = std::string("Wojtek");

    std::string& str1 = std::any_cast<std::string&>(var1);
    std::cout << str1 << std::endl;

    return 0;
}
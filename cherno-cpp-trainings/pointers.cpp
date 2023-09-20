#include <iostream>

using namespace std;

template <typename T>
std::string to_bin(const T &num)
{
    std::string num_str;
    long long mask = (long long)1 << (8 * sizeof(T));
    for (int i = 0; i < 32; i++)
    {
        mask >>= 1;
        if (mask & num)
            num_str.append("1");
        else
            num_str.append("0");

        cout << mask << endl;
    }
    return std::move(num_str);
}
int main()
{
    int a = 10;
    int b = ~a;
    int c = a & b;
    int d = a | b;
    std::cout << to_bin<int>(a) << std::endl;

    return 0;
}

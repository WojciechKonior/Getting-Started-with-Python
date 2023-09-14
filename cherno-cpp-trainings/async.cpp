#include <iostream>
#include <mutex>
#include <future>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    os << "[";
    for(auto& r : vec)
        os << r << " ";
    os << "]";
    return os;
}

std::mutex mtx;

void do_something(std::vector<int>& vec)
{
    std::lock_guard<std::mutex> lock(mtx);
    vec.push_back(1);
}

int main()
{
    std::vector<std::future<void>> futures;
    std::vector<int> vec;

    // for(int i = 0 ; i<10; i++)
    //     futures.push_back(std::async(std::launch::async, [&](){do_something(vec);}));

    std::future<void> a = std::async(std::launch::async, []()->void{int a = 10;});

    std::cout << "Hello World\n";
    return 0;
}
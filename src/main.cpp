#include "header.h"
#include "iostream"
#include "vector"

auto main () -> int
{
    std::cout << "Test\n";
    std::vector<int> a{};

    for (int i = 0; i < 10; ++i)
    {
        a.push_back (i);
    }

    for (auto &n : a)

    {
        std::cout << n;
    }
    std::cout << "\n";

    Test g;
    std::cout << g.getA () << "\n";
    std::cout << g.getB () << "\n";
}

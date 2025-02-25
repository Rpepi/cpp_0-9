#include "iter.hpp"

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    std::string strs[] = {"Hello", "World"};

    ::iter(tab, 5, print);
    ::iter(strs, 2, print);
    
    return 0;
}